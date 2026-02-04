#include "vex.h"
#include "auton-config.h"
#include "interface.h"

// Define PI here to avoid relying on platform-specific M_PI macro
constexpr double PI = 3.14159265358979323846;

// Define auton names to display in the interface
const char* autonNames[] = {
    "Skills",
    "Left Red",
    "Right Red",
    "Left Blue",
    "Right Blue"
};

// drive declarations so autonomous() can call these functions
void drive(double distance, int speed);
void turnTo(double degrees, int speed);
void intake();
void outtake();
void stop();
// If true, autonomous motor directions will be inverted to match driver control
// Set to true when autonomous movement is observed to be reversed compared to driver control
// Motion / tuning constants (centralized for easier tuning)
constexpr double WHEEL_DIAMETER_IN = 3.25;      // inches
constexpr double TRACK_WIDTH_IN = 12.3;         // inches (distance between wheel centers)

// Ramping profile (segment-based)
const int DEFAULT_SEGMENTS = 8;
const int ACCEL_SEGMENTS = 2;
const int DECEL_SEGMENTS = 2;
const int MIN_RAMP_VEL = 12; // percent - minimum to overcome stiction
const double DECEL_EPSILON = 0.05; // fraction of speed remaining at end of decel

// Turn controller (IMU-based)
const double TURN_KP = 0.7;        // proportional gain for turn controller
const double TURN_TOLERANCE = 1.5; // degrees
const int TURN_MIN_POWER = 10;     // percent minimum power for turning
const int TURN_LOOP_MS = 15;       // control loop period
const int TURN_TIMEOUT_MS = 4000;  // timeout for safety

// Invert autonomous directions to match driver control when necessary
bool invertAuton = true;

// Helper prototypes
double wheelRevsForInches(double inches);
void rampedDrive(double distance, int speed);
void turnToRelativeIMU(double degrees, int speed);
//Eaach autonomous routine will be varied in the future
void autonomous(void) {
        //Auton Skills 
    if (selectedAuton == 0) {
       // picking up 3||4 balls auton (in work) ----------------------------------------------------------------------------------------
    drive(20, 60);
        wait(100, msec);
    turnTo(-30, 30);
        wait(100, msec);
        Flexwheel.spin(reverse, 100, percent);
        intake();
        drive(11, 20);
        wait(500, msec);
        stop();
        turnTo(-95, 60);
        drive(-11, 40);
        Flexwheel.spin(fwd, 100, percent);
        outtake();
        wait(5000, msec);
        stop();
        Flexwheel.stop();
        drive(30, 70);
    }
        

        //one ball auton
        // drive(-32, 70);
        // turnTo(32, 70);
        // drive(-4.5, 70);
        // wait(300, msec);
        // Flexwheel.spin(fwd, 100, percent);
        // outtake();
        // wait(2000, msec);
        // Flexwheel.stop();
        // stop();
        // wait(100, msec);
        // drive(10, 70);
        // turnTo(-60, 100);
        // wait(100, msec);
        // drive(50, 100);

        
        // //parkedstop();
        // //one ball auton --------------------------------------------------------------------------------------------------------
        // drive(-30, 60);
        // turnTo(32, 30);
        // drive(-6, 50);
        // wait(1000, msec);
        // outtake();
        // wait(2000, msec);
        // stop();


        // //potential auton for skills in the future with odometry ---------------------------------------------------------------------------
        // drive(17.5, 100);
        // intake();
        // turnTo(-30, 100);
        // Flexwheel.spin(reverse, 100, percent);
        // drive(15, 20);
        // wait(1000, msec);
        // stop();
        // turnTo(-96, 100);  
        // wait(300, msec);
        // drive(-9.5, 60);
        // outtake();
        // wait(2000, msec);
        // stop(); //reaches goal
        // drive(30.7, 60); //turns back
        // turnTo(-54, 60);
        // drive(15, 50);
        // turnTo(-105, 60);
        // ExtendoOutA.set(true);
        // intake();
        // drive(12.7, 67);
        // wait(3000, msec);
        // stop();
        // ExtendoOutB.set(true);
        // drive(-20, 60);
        // outtake();
        // wait(3000, msec);
        // stop();
        // ExtendoOutB.set(false);
        // ExtendoOutA.set(false);
        // //code created since first match below
        // turnTo(-105, 60);
        // drive(5, 60);
        // turnTo(105, 60);
        // drive(5, 60); //change 5 for measured value of goal length + 1/2* length between tube and goal
        // turnTo(105, 60);
        // drive(5, 60); //change to 1/2 width of goal
        // turnTo(-105, 60);
        // ExtendoOutA.set(true); //ball out of tube remover
        // drive(-5, 60); //x value towards tube
        // intake();
        // drive(15, 60); //towards goal
        // wait(3000, msec);
        // stop();
        // ExtendoOutB.set(true); 
        // drive(5, 60); //reach goal
        // outtake();
        // wait(4000, msec);
        // stop();
        // ExtendoOutB.set(false);
        // ExtendoOutA.set(false);
        // drive(-5, 60); //back away from goal after scoring
        // turnTo(-105, 60);
        // drive(10, 60);
        // turnTo(105, 60);
        // drive(10, 60);
        // turnTo(-105, 60);
        // intake();
        // drive(30, 60); //long distance towards cluster of four cubes and collect
        // turnTo(105, 60);
        // stop();
        // drive(45, 60);
        // turnTo(130, 60);
        // ExtendoOutB.set(true);
        // drive(15.7, 60);
        // outtake();
        // wait(4000, msec);
        // stop();
        // ExtendoOutB.set(false);
        // drive(-30.7, 60);
        // turnTo(-130, 60);
        // drive(10, 60);
        // turnTo(-105, 60);
        // drive(10, 60);
        // turnTo(-105, 60);
        // ExtendoOutA.set(true);
        // wait(3000, msec);
        // intake();
        // drive(-12.5, 60);
        // drive(12.5, 60);
        // stop();
        // ExtendoOutB.set(true);
        // drive(5, 60);
        // outtake();
        // wait(4000, msec);
        // stop();
        // ExtendoOutA.set(false);
        // ExtendoOutB.set(false);
        // drive(-5, 60);
        // turnTo(105, 60);
        // drive(5, 60);
        // turnTo(-105, 60);
        // drive(25, 60);
        // turnTo(-105, 60);
        // drive(5, 60); 
        // turnTo(-105, 60);
        // intake();
        // ExtendoOutA.set(true);
        // drive(-5, 60);
        // wait(3000, msec);
        // drive(5, 60);
        // ExtendoOutB.set(true);
        // drive(5, 60);
        // outtake();
        // wait(4000, msec);
        // stop();
        // ExtendoOutA.set(false);
        // ExtendoOutB.set(false);
        // drive(5, 60);
        // turnTo(-105, 60);
        // drive(10, 60);
        // turnTo(-105, 60);
        // drive(30, 60);
        // turnTo(-105, 60);
        // drive(10, 60);
        // turnTo(195, 60);
        // drive(25, 100);
        // // //parked
    
    // Path

   else if (selectedAuton == 1) {
        // Left Red Auton
        drive(20, 45);
        turnTo(90, 45);
        ExtendoOutB.set(true);
        drive(25, 45);
        turnTo(90, 45); 
        drive(17, 60);
        intake();
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        wait(2, seconds);
        stop();
        ExtendoOutA.set(true);
        drive(-23, 45);
        ExtendoOutB.set(false);
        intake();
        wait(3, seconds);
        stop();

    } else if (selectedAuton == 2) {
        // Right Red Auton
        drive(20, 45);
        turnTo(-90, 45);
        ExtendoOutB.set(true);
        drive(25, 45);
        turnTo(-90, 45); 
        drive(17, 60);
        intake();
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        wait(2, seconds);
        stop();
        ExtendoOutA.set(true);
        drive(-23, 45);
        ExtendoOutB.set(false);
        intake();
        wait(3, seconds);
        stop();

    } else if (selectedAuton == 3) {
        // Left Blue Auton
        drive(20, 45);
        turnTo(90, 45);
        ExtendoOutB.set(true);
        drive(25, 45);
        turnTo(90, 45); 
        drive(17, 60);
        intake();
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        wait(2, seconds);
        stop();
        ExtendoOutA.set(true);
        drive(-23, 45);
        ExtendoOutB.set(false);
        intake();
        wait(3, seconds);
        stop();

    } else if (selectedAuton == 4) {
        // Right Blue Auton
        drive(20, 45);
        turnTo(-90, 45);
        ExtendoOutB.set(true);
        drive(25, 45);
        turnTo(-90, 45); 
        drive(17, 60);
        intake();
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        drive(1, 30);
        wait(250, msec);
        wait(2, seconds);
        stop();
        ExtendoOutA.set(true);
        drive(-23, 45);
        ExtendoOutB.set(false);
        intake();
        wait(3, seconds);
        stop();
    }
}

//distance(inches)
//speed(%)
void drive(double distance, int speed){
    // wrapper that delegates to rampedDrive which uses centralized constants
    rampedDrive(distance, speed);
}

void turnTo(double degrees, int speed) {
}
    // Use IMU-based relative-turn controller for accurate turns
    turnToRelativeIMU(degrees, speed);
}

// Helper: convert inches to wheel revolutions
double wheelRevsForInches(double inches) {
    return inches / (WHEEL_DIAMETER_IN * PI);
}

// Helper: segmented ramped drive implementation using centralized constants
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

// Helper: IMU-based relative turn
static double normalizeAngle(double a) {
    while (a > 180.0) a -= 360.0;
    while (a <= -180.0) a += 360.0;
    return a;
}

void turnToRelativeIMU(double degrees, int speed) {
    if (invertAuton) degrees = -degrees;
    int maxSpeed = (speed >= 0) ? speed : -speed;
    if (maxSpeed > 100) maxSpeed = 100;
    if (maxSpeed < 1) maxSpeed = 1;

    double start = Inertial.rotation();
    double target = start + degrees;

    int elapsed = 0;
    while (true) {
        double current = Inertial.rotation();
        double error = normalizeAngle(target - current);
        double absErr = (error >= 0.0) ? error : -error;
        if (absErr <= TURN_TOLERANCE) break;

        double effort = TURN_KP * error;
        double mag = (effort >= 0.0) ? effort : -effort;
        if (mag < TURN_MIN_POWER) mag = TURN_MIN_POWER;
        if (mag > maxSpeed) mag = maxSpeed;

        if (error > 0) {
            LeftMotors.spin(fwd, mag, percent);
            RightMotors.spin(reverse, mag, percent);
        } else {
            LeftMotors.spin(reverse, mag, percent);
            RightMotors.spin(fwd, mag, percent);
        }

        wait(TURN_LOOP_MS, msec);
        elapsed += TURN_LOOP_MS;
        if (elapsed >= TURN_TIMEOUT_MS) break;
    }
    LeftMotors.stop();
    RightMotors.stop();
    wait(20, msec);
}

void intake(){
    SMechanism.spin(reverse, 100, percent);
    Intake.spin(reverse, 100, percent);
    Scoring.spin(reverse, 100, percent);   
}

void outtake(){
    SMechanism.spin(reverse, 100, percent);
    Intake.spin(reverse, 100, percent);
    Scoring.spin(reverse, 100, percent); 
}

void stop(){
    SMechanism.stop();
    Intake.stop();
    Scoring.stop(); 
}