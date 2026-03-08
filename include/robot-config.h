using namespace vex;

extern brain Brain;

// VEXcode devices (declared in src/robot-config.cpp)
extern controller Controller1;
extern motor RightFront;
extern motor RightBack;
extern motor LeftFront;
extern motor LeftBack;
extern motor Scoring;
extern motor Intake;
extern motor SMechanism;
extern motor_group RightMotors;
extern motor_group LeftMotors;
extern digital_out matchloader; //top flex scoring
extern digital_out longGoal; //match loader
extern digital_out Descorer;
extern motor Flexwheel;
extern inertial IMU;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );