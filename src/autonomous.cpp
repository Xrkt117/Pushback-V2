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
// The last parameter 'coast' controls whether motors should coast (true)
// or actively brake (false) after completing the movement. Default is false
// to preserve existing behavior.
void drive(double distance, int speed, bool coast = false);
void turnTo(double degrees, int speed, bool coast = false);
void intake();
void outtake();
void stop();
// If true, autonomous motor directions will be inverted to match driver control
// Set to true when autonomous movement is observed to be reversed compared to driver control
const bool invertAuton = true;
//Eaach autonomous routine will be varied in the future
void autonomous(void) {
    IMU.setHeading(0, degrees);

        //Auton Skills 
    if (selectedAuton == 0) {
       // picking up 3||4 balls auton (in work) ----------------------------------------------------------------------------------------
        drive(10, 80, false); 
            wait(100, msec);
        turnTo(-20, 30, true);
        Flexwheel.spin(reverse, 100, percent);
        intake();
            wait(100, msec);
        drive(11, 40);
        stop();
            wait(100, msec);
        turnTo(-93, 50, true);
            wait(100, msec);
        drive(-8.1, 70, true);
        Flexwheel.spin(fwd, 100, percent);
        outtake();
            wait(3000, msec);
        stop();
        Flexwheel.stop();
        turnTo(-10, 60, true);
        drive(28.5, 150, true); //Drive into match loader
            wait(300, msec);
        turnTo(-30, 80, true);
        ExtendoOutA.set(true);
        wait(300, msec);
        drive(15, 150, true);
        intake();
            wait(1000, msec);
        drive(2.0, 60, true);
            wait(2000,msec);
        stop();
        ExtendoOutB.set(true);
        wait(1000, msec);
        drive(-12.0, 160, true);
        ExtendoOutA.set(false);
        outtake();
        wait(3000, msec);
        drive(4, 100, true);
        turnTo(-90, 60, true);
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

//    else if (selectedAuton == 1) {
//         // Left Red Auton
//         drive(20, 45);
//         turnTo(90, 45);
//         ExtendoOutB.set(true);
//         drive(25, 45);
//         turnTo(90, 45); 
//         drive(17, 60);
//         intake();
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         wait(2, seconds);
//         stop();
//         ExtendoOutA.set(true);
//         drive(-23, 45);
//         ExtendoOutB.set(false);
//         intake();
//         wait(3, seconds);
//         stop();

//     } else if (selectedAuton == 2) {
//         // Right Red Auton
//         drive(20, 45);
//         turnTo(-90, 45);
//         ExtendoOutB.set(true);
//         drive(25, 45);
//         turnTo(-90, 45); 
//         drive(17, 60);
//         intake();
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         wait(2, seconds);
//         stop();
//         ExtendoOutA.set(true);
//         drive(-23, 45);
//         ExtendoOutB.set(false);
//         intake();
//         wait(3, seconds);
//         stop();

//     } else if (selectedAuton == 3) {
//         // Left Blue Auton
//         drive(20, 45);
//         turnTo(90, 45);
//         ExtendoOutB.set(true);
//         drive(25, 45);
//         turnTo(90, 45); 
//         drive(17, 60);
//         intake();
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         wait(2, seconds);
//         stop();
//         ExtendoOutA.set(true);
//         drive(-23, 45);
//         ExtendoOutB.set(false);
//         intake();
//         wait(3, seconds);
//         stop();

//     } else if (selectedAuton == 4) {
//         // Right Blue Auton
//         drive(20, 45);
//         turnTo(-90, 45);
//         ExtendoOutB.set(true);
//         drive(25, 45);
//         turnTo(-90, 45); 
//         drive(17, 60);
//         intake();
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         drive(1, 30);
//         wait(250, msec);
//         wait(2, seconds);
//         stop();
//         ExtendoOutA.set(true);
//         drive(-23, 45);
//         ExtendoOutB.set(false);
//         intake();
//         wait(3, seconds);
//         stop();

//     }
}

// distance = inches, speed = percent. coast = true to coast at end.
void drive(double distance, int speed, bool coast) {
    const double WHEEL_DIAMETER_IN = 3.25;
    double revolutions = fabs(distance) / (WHEEL_DIAMETER_IN * PI);

    directionType dir = (distance >= 0.0) ? forward : reverse;
    if (invertAuton) dir = (dir == forward) ? reverse : forward;

    int pct = (speed >= 0) ? speed : -speed;    
    LeftMotors.setVelocity(pct, percent);
    RightMotors.setVelocity(pct, percent);
    LeftMotors.setStopping(coast ? brakeType::coast : brakeType::brake);
    RightMotors.setStopping(coast ? brakeType::coast : brakeType::brake);

    LeftMotors.spinFor(dir, revolutions, rev, false);
    RightMotors.spinFor(dir, revolutions, rev, true);
}

// Normalize angle error to -180..180 (shortest turn)
static double normalizeAngleError(double error) {
    while (error > 180.0)  error -= 360.0;
    while (error < -180.0) error += 360.0;
    return error;
}

// Turn by degrees (relative). Uses inertial to stop when target heading is reached; fixed speed, no PID.
void turnTo(double degrees, int speed, bool coast) {
    const double toleranceDeg = 2.0;
    const int timeoutMs = 3000;
    int turnSpeed = (speed >= 0) ? speed : -speed;
    if (invertAuton) degrees = -degrees;

    double targetHeading = IMU.heading() + degrees;
    while (targetHeading >= 360.0) targetHeading -= 360.0;
    while (targetHeading < 0.0)    targetHeading += 360.0;

    LeftMotors.setStopping(coast ? brakeType::coast : brakeType::brake);
    RightMotors.setStopping(coast ? brakeType::coast : brakeType::brake);

    int startTime = (int)Brain.Timer.time(msec);
    while (true) {
        double current = IMU.heading();
        double error = normalizeAngleError(targetHeading - current);

        if (error > -toleranceDeg && error < toleranceDeg) break;
        if ((int)Brain.Timer.time(msec) - startTime > timeoutMs) break;

        if (error > 0) {
            LeftMotors.spin(reverse, turnSpeed, percent);
            RightMotors.spin(fwd, turnSpeed, percent);
        } else {
            LeftMotors.spin(fwd, turnSpeed, percent);
            RightMotors.spin(reverse, turnSpeed, percent);
        }
        wait(20, msec);
    }
    LeftMotors.stop();
    RightMotors.stop();
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