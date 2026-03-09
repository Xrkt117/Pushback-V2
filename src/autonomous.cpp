#include "vex.h"
#include "auton-config.h"
#include "interface.h"

constexpr double PI = 3.14159265358979323846;

// -------------------- TUNE THESE FIRST --------------------
const double WHEEL_DIAMETER_IN = 4.25;   // your wheel diameter
const double DRIVE_GEAR_RATIO  = 1.0;    // wheel revs per motor rev
const double DRIVE_SIGN = 1.0;           // if forward auton goes backward, change to -1.0
const double TURN_SIGN  = 1.0;           // if turns the wrong way, change to -1.0
// ---------------------------------------------------------

// Define auton names to display in the interface
const char* autonNames[] = {
    "Skills",
    "Match Left",
    "Match Right"
};

// drive declarations so autonomous() can call these functions
// The last parameter 'coast' controls whether motors should coast (true)
// or actively brake (false) after completing the movement. Default is false
// to preserve existing behavior.
void drive(double distance, int speed);
void turnTo(double targetHeading, int speed, bool coast = false);
void intake();
void outtake();
void scoring();
void stop();

// If true, autonomous motor directions will be inverted to match driver control
// Set to true when autonomous movement is observed to be reversed compared to driver control
const bool invertAuton = true;
//Eaach autonomous routine will be varied in the future
void autonomous(void) {

        //Auton Skills 
    if (selectedAuton == 0) {
       // picking up 3||4 balls auton (in work) ----------------------------------------------------------------------------------------
        drive(65, 55); 
        turnTo(340, 40, false);
        intake();
        drive(42.5, 20);
        stop();
        turnTo(225, 35, true);
        drive(-35, 50);
        scoring();
        // wait(500, msec);
        // stop();
        // outtake();
        // wait(500, msec);
        // stop();
        // scoring();
        wait(2500, msec);
        stop();
        drive(120, 55);
        turnTo(190, 45, true);
        wait(100, msec);
        matchloader.set(true);
        wait(100, msec);
        intake();
        drive(50, 60); //faster for loader & drive less distance (10cm?) for matchloader distance (subtract approximate distance of matchloader from current drive)
        wait(1750, msec);
        stop();
        longGoal.set(true);
        drive(-75, 70);
        matchloader.set(false);
        scoring();
        wait(4000, msec);
        stop();
        longGoal.set(false);
        drive(35, 60);
        turnTo(130, 45, true);
        drive(-45, 75);
        turnTo(180, 45, true);
        drive(-180, 85);


        //make motors stop so keep intaking without dispense blocks








        wait(10000, msec);

        // turnTo(-93, 50, true);
        //     wait(100, msec);
        // drive(-8.1, 70, true);
        // Flexwheel.spin(fwd, 100, percent);
        // outtake();
        //     wait(3000, msec);
        // stop();
        // Flexwheel.stop();
        // turnTo(-10, 60, true);
        // drive(28.5, 150, true); //Drive into match loader
        //     wait(300, msec);
        // turnTo(-30, 80, true);
        // ExtendoOutA.set(true);
        // wait(300, msec);
        // drive(15, 150, true);
        // intake();
        //     wait(1000, msec);
        // drive(2.0, 60, true);
        //     wait(2000,msec);
        // stop();
        // ExtendoOutB.set(true);
        // wait(1000, msec);
        // drive(-12.0, 160, true);
        // ExtendoOutA.set(false);
        // outtake();
        // wait(3000, msec);
        // drive(4, 100, true);
        // turnTo(-90, 60, true);
    }

    if(selectedAuton == 1){
        drive(40, 45);
        drive(40, 25);
        drive(40, 65);
        drive(-120, 25);

    }

    //match auton
    if(selectedAuton == 2){
        drive(82.5, 80);
        wait(100, msec);
        turnTo(275, 65, true);
        matchloader.set(true);
        intake();
        wait(50, msec);
        drive(25, 60);
        wait(700, msec);
        longGoal.set(true);
        drive(-80, 100);
        stop();
        scoring();
        wait(2350, msec);
        stop();
        matchloader.set(false);
        longGoal.set(false);
        drive(35, 60);
        turnTo(150, 45, true);
        intake();
        drive(90, 75);
        matchloader.set(true);
        turnTo(315, 45, true);
        stop();
        drive(-37.5, 45);
        scoring();
        wait(2000, msec);
        stop();
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

// distance = cm, speed = percent. coast = true to coast at end.
void drive(double distanceCm, int speed) {
    double revolutions = fabs(distanceCm * 0.393701) / (4.25 * PI);
    directionType dir = ((distanceCm >= 0) != invertAuton) ? forward : reverse;

    LeftMotors.setVelocity(abs(speed), percent);
    RightMotors.setVelocity(abs(speed), percent);
    LeftMotors.spinFor(dir, revolutions, rev, false);
    RightMotors.spinFor(dir, revolutions, rev, true);
}

// Turn to an absolute heading (0-360). Automatically takes the shortest path.
// e.g. if facing 0° and you call turnTo(20), it turns 20° clockwise.
// if facing 0° and you call turnTo(350), it turns 10° counter-clockwise.
void turnTo(double targetHeading, int speed, bool coast) {
    while (targetHeading >= 360.0) targetHeading -= 360.0;
    while (targetHeading < 0.0) targetHeading += 360.0;

    int maxSpeed = abs(speed);
    const double kP = 0.8;
    const int minSpeed = 8;

    LeftMotors.setStopping(coast ? brakeType::coast : brakeType::brake);
    RightMotors.setStopping(coast ? brakeType::coast : brakeType::brake);

    while (true) {
        double current = IMU.heading();
        double error = targetHeading - current;

        if (error > 180) error -= 360;
        if (error < -180) error += 360;

        if (fabs(error) < 2.0) break;

        int turnSpeed = (int)(fabs(error) * kP);
        if (turnSpeed < minSpeed) turnSpeed = minSpeed;
        if (turnSpeed > maxSpeed) turnSpeed = maxSpeed;

        // positive error = turn right (clockwise)
        // Try one way first. If robot turns wrong, swap fwd/reverse here.
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
    Flexwheel.spin(reverse, 100, percent);
}

void outtake(){
    SMechanism.spin(fwd, 100, percent);
    Intake.spin(fwd, 100, percent);
    Scoring.spin(fwd, 100, percent); 
    Flexwheel.spin(reverse, 100, percent);
}

void scoring(){
    SMechanism.spin(reverse, 100, percent);
    Intake.spin(reverse, 100, percent);
    Scoring.spin(reverse, 100, percent); 
    Flexwheel.spin(fwd, 100, percent);
}

void stop(){
    SMechanism.stop();
    Intake.stop();
    Scoring.stop(); 
    Flexwheel.stop();
}