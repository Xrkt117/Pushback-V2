#ifndef MOTION_H
#define MOTION_H

#include "vex.h"

namespace motion {

// Physical constants (tune these in one place)
constexpr double WHEEL_DIAMETER_IN = 3.25;      // inches
constexpr double TRACK_WIDTH_IN = 12.3;         // inches (distance between wheel centers)

// Ramping profile (segment-based)
constexpr int DEFAULT_SEGMENTS = 8;
constexpr int ACCEL_SEGMENTS = 2;
constexpr int DECEL_SEGMENTS = 2;
constexpr int MIN_RAMP_VEL = 12; // percent - minimum to overcome stiction
constexpr double DECEL_EPSILON = 0.05; // fraction of speed remaining at end of decel

// Turn controller (IMU-based)
constexpr double TURN_KP = 0.7;        // proportional gain for turn controller
constexpr double TURN_TOLERANCE = 1.5; // degrees
constexpr int TURN_MIN_POWER = 10;     // percent minimum power for turning
constexpr int TURN_LOOP_MS = 15;       // control loop period
constexpr int TURN_TIMEOUT_MS = 4000;  // timeout for safety

// Whether to invert autonomous directions to match driver control
extern bool invertAuton;

// Initialization (calibrates IMU if present)
void init();

// Motion helper APIs
double wheelRevsForInches(double inches);
void rampedDrive(double distance, int speed);
void turnToRelativeIMU(double degrees, int maxPower);
void turnToAbsoluteIMU(double targetAngle, int maxPower);

// Small self-test / telemetry helper
void selfTest();
 c
// Visual helper: make the Brain screen pink and show a short message
void pleaseTurnPink();

// IMU framing helpers
// Call setHeadingZero() while the robot is facing the direction you consider
// "forward" to define the IMU zero reference. Use setHeadingSign(-1) if
// the IMU reports heading with opposite sign to your desired convention.
void setHeadingZero();
void setHeadingSign(int sign);
double getHeading();

} // namespace motion

#endif // MOTION_H