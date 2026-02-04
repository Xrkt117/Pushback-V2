#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightFront = motor(PORT14, ratio18_1, true);
motor RightBack = motor(PORT13, ratio18_1, true);
motor LeftFront = motor(PORT12, ratio18_1, false);
motor LeftBack = motor(PORT11, ratio18_1, false); 
motor Scoring = motor(PORT16, ratio18_1, false);
motor Intake = motor(PORT15, ratio18_1, true);
motor SMechanism = motor(PORT17, ratio18_1, true);
motor Flexwheel = motor(PORT18, ratio18_1, false);
motor_group RightMotors = motor_group(RightFront, RightBack);
motor_group LeftMotors = motor_group(LeftFront, LeftBack);
digital_out ExtendoOutA = digital_out(Brain.ThreeWirePort.A);
digital_out ExtendoOutB = digital_out(Brain.ThreeWirePort.B);
digital_out Descorer = digital_out(Brain.ThreeWirePort.H);
inertial Inertial = inertial(PORT19);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}