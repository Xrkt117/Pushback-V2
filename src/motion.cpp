#include "vex.h"
#include "robot-config.h"
#include "motion.h"

#include <cmath>

using namespace vex;

namespace motion {

// internal PI constant
static constexpr double PI = 3.14159265358979323846;

bool invertAuton = true; // default; can be changed at runtime

void init() {
  // Calibrate inertial sensor if present
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Calibrating IMU...");
  // If Inertial is not defined on the robot config this will be a compile-time error
  Inertial.calibrate();
  while (Inertial.isCalibrating()) {
    wait(100, msec);
  }
  Brain.Screen.clearScreen();
}

double wheelRevsForInches(double inches) {
  return inches / (WHEEL_DIAMETER_IN * PI);
}

// segmented ramped drive implementation (distance in inches, speed in percent)
void rampedDrive(double distance, int speed) {
  double absDist = (distance >= 0.0) ? distance : -distance;
  double revolutions = wheelRevsForInches(absDist);

  directionType dir = (distance >= 0.0) ? directionType::fwd : directionType::rev;
  if (invertAuton) dir = (dir == directionType::fwd) ? directionType::rev : directionType::fwd;

  int absSpeed = (speed >= 0) ? speed : -speed;
  LeftMotors.setStopping(brake);
  RightMotors.setStopping(brake);

  int segments = DEFAULT_SEGMENTS;
  if (revolutions < 0.5) {
    int tmp = (int)ceil(revolutions * 4.0);
    segments = (tmp > 1) ? tmp : 1;
  }

  if (segments <= 1) {
    LeftMotors.setVelocity(absSpeed, percent);
    RightMotors.setVelocity(absSpeed, percent);
    LeftMotors.spinFor(dir, revolutions, rev, false);
    RightMotors.spinFor(dir, revolutions, rev, true);
    return;
  }

  double segRevs = revolutions / (double)segments;
  double lambda = 1.0;
  if (DECEL_SEGMENTS > 1) lambda = -log(DECEL_EPSILON) / (double)(DECEL_SEGMENTS - 1);

  for (int i = 0; i < segments; ++i) {
    int vel = absSpeed;
    if (i < ACCEL_SEGMENTS) {
      double t = (double)(i + 1) / (double)ACCEL_SEGMENTS;
      vel = (int)round(MIN_RAMP_VEL + t * (absSpeed - MIN_RAMP_VEL));
    } else if (i >= segments - DECEL_SEGMENTS) {
      int idx = i - (segments - DECEL_SEGMENTS);
      double factor = exp(-lambda * (double)idx);
      vel = (int)round(MIN_RAMP_VEL + (absSpeed - MIN_RAMP_VEL) * factor);
    } else {
      vel = absSpeed;
    }

    LeftMotors.setVelocity(vel, percent);
    RightMotors.setVelocity(vel, percent);
    bool waitLast = (i == segments - 1);
    LeftMotors.spinFor(dir, segRevs, rev, false);
    RightMotors.spinFor(dir, segRevs, rev, waitLast);
  }
}

static double normalizeAngle(double a) {
  while (a > 180.0) a -= 360.0;
  while (a <= -180.0) a += 360.0;
  return a;
}

// IMU heading offset/sign (to adapt to how the sensor is mounted)
static double headingOffset = 0.0;
static int headingSign = 1;

void setHeadingZero() {
  headingOffset = normalizeAngle(Inertial.rotation(deg));
}

void setHeadingSign(int sign) {
  headingSign = (sign >= 0) ? 1 : -1;
}

double getHeading() {
  return headingSign * normalizeAngle(Inertial.rotation(deg) - headingOffset);
}

// relative IMU turn (degrees, maxPower percent)
void turnToRelativeIMU(double degrees, int maxPower) {
  if (invertAuton) degrees = -degrees;

  double start = getHeading();
  double target = normalizeAngle(start + degrees);

  auto now = vex::timer();
  double startTime = now.time(msec);

  while (true) {
    double current = getHeading();
    double err = normalizeAngle(target - current);
    double absErr = (err >= 0.0) ? err : -err;

    if (absErr <= TURN_TOLERANCE) break;

    double p = TURN_KP * err;
    int power = (int)round(p);
    if (power > maxPower) power = maxPower;
    if (power < -maxPower) power = -maxPower;

    if (power > 0 && power < TURN_MIN_POWER) power = TURN_MIN_POWER;
    if (power < 0 && power > -TURN_MIN_POWER) power = -TURN_MIN_POWER;

    // Apply differential drive to rotate in place
    if (power > 0) {
      LeftMotors.spin(fwd, power, percent);
      RightMotors.spin(reverse, power, percent);
    } else {
      LeftMotors.spin(reverse, -power, percent);
      RightMotors.spin(fwd, -power, percent);
    }

    wait(TURN_LOOP_MS, msec);

    double elapsed = now.time(msec) - startTime;
    if (elapsed > TURN_TIMEOUT_MS) break;
  }

  LeftMotors.stop(brake);
  RightMotors.stop(brake);
}

// absolute IMU turn (targetAngle in degrees absolute in IMU frame)
void turnToAbsoluteIMU(double targetAngle, int maxPower) {
  double current = normalizeAngle(Inertial.rotation(deg));
  double err = normalizeAngle(targetAngle - current);
  turnToRelativeIMU(err, maxPower);
}

void selfTest() {
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1, 20, "Running motion self-test");
  // quick short movements for validation
  rampedDrive(6.0, 30);
  wait(300, msec);
  turnToRelativeIMU(45, 30);
  wait(300, msec);
  turnToRelativeIMU(-45, 30);
  wait(300, msec);
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1, 20, "Self-test done");
}

// Make the Brain screen pink and display a short message
void pleaseTurnPink() {
  // Soft pink RGB (you can adjust values)
  vex::color pink = vex::color(255, 182, 193);
  Brain.Screen.setFillColor(pink);
  Brain.Screen.clearScreen();
  Brain.Screen.setPenColor(black);
  Brain.Screen.setFont(mono20);
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("Please turn pink");
}

} // namespace motion
