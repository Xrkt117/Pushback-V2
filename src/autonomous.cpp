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
    printf("Selected Auton=%.1f\n", selectedAuton);

        //Auton Skills 
    if (selectedAuton == 0) {
        drive(77, 80);
        wait(50, msec);
        turnTo(270, 50, true);
        matchloader.set(true);
        intake(); //prepare to intake matchloader balls
        wait(50, msec);

        drive(25, 55); //drive into matchloader with force 
        wait(1500, msec); //waits at matchloader 
        stop();
        drive(-35, 80); //drives to mid line between matchloader and long goal
        wait(50, msec);
        turnTo(135, 40, true); //turns open
        matchloader.set(false);
        drive(60, 90); //drives to goal
        turnTo(95, 35, true); //turns to face goal
        drive(170, 90); //drives forward a bit to be in optimal scoring position
        turnTo(175, 50, true); //turns to face goal
        drive(-40, 50);
        turnTo(90, 45);
        longGoal.set(true);
        drive(-30, 60);
        scoring(); 
        wait(3000, msec); //scoring at goal

        stop();
        matchloader.set(true);
        drive(75, 75); //drive into matchloader with force 
        intake();
        wait(1350, msec); //waits at matchloader 
        stop();
        drive(-71, 100); //drives to mid line between matchloader and long goal
        scoring(); 
        wait(2350, msec); //scoring at goal
        stop();
        matchloader.set(false);
        longGoal.set(false);


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

    // if(selectedAuton == 1){
    //     drive(40, 45);
    //     drive(40, 25);
    //     drive(40, 65);
    //     drive(-120, 25);

    // }

        if(selectedAuton == 1){
        drive(79.5, 80);
        wait(50, msec);
        turnTo(90, 60, true);
        matchloader.set(true);
        intake(); //prepare to intake matchloader balls
        wait(50, msec);

        drive(24, 55); //drive into matchloader with force 
        wait(300, msec); //waits at matchloader 
        longGoal.set(true);
        drive(-71, 100); //drives to goal
        stop();
        scoring(); 
        wait(2350, msec); //scoring at goal
        stop();
        matchloader.set(false);
        longGoal.set(false);

        drive(15, 70);  //drives forward towards mid of matchloader & high goal (about to turn)
        turnTo(213, 45, true); //angle towards approaching mid goal
        intake();
        drive(100, 40); //drives towards blocks
        stop();
        turnTo(230, 35, true); //angles towards mid goal
        outtake();
        wait(3000, msec);
        stop();
    }

    //left match auton
    if(selectedAuton == 2){
        drive(78, 90);
        wait(50, msec);
        turnTo(270, 50, true);
        matchloader.set(true);
        intake(); //prepare to intake matchloader balls
        wait(50, msec);

        drive(24, 60); //drive into matchloader with force 
        wait(300, msec); //waits at matchloader 
        longGoal.set(true);
        drive(-71, 100); //drives to goal
        stop();
        scoring(); 
        wait(2350, msec); //scoring at goal
        stop();
        matchloader.set(false);
        longGoal.set(false);

        drive(15, 70);  //drives forward towards mid of matchloader & high goal (about to turn)
        turnTo(150, 45, true); //angle towards approaching mid goal
        intake();
        drive(75, 40); //drives towards blocks
        matchloader.set(true); //keep intaking to hold onto blocks and prevent dispense
        stop();
        turnTo(310, 35, true); //angles towards mid goal
        drive(-27.5, 45); //drives up to goal
        // outtake();
        // wait(300, msec);
        matchloader.set(false);
        scoring();
        wait(3000, msec);
        stop();
        drive(-5, 45);
         turnTo(270, 45, true); //turn to next matchloaders on right
        //String x = "I am become psuedo op";
    }

    if (selectedAuton == 3) {
        drive(8, 30);
    }
     
        if (selectedAuton == 4) {

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
    const double kP = 0.4;
    const double settleErrorDeg = 3.0;

    double targetDegrees = (distanceCm * 0.393701) / (4.25 * PI) * 360.0;
    if (invertAuton) targetDegrees = -targetDegrees;

    LeftMotors.resetPosition();
    RightMotors.resetPosition();
    LeftMotors.setStopping(brakeType::brake);
    RightMotors.setStopping(brakeType::brake);

    while (true) {
        double currentDegrees = (LeftMotors.position(deg) + RightMotors.position(deg)) / 2.0;
        double error = targetDegrees - currentDegrees;

        if (fabs(error) < settleErrorDeg) break;

        double output = error * kP;
        if (output > abs(speed)) output = abs(speed);
        if (output < -abs(speed)) output = -abs(speed);

        LeftMotors.spin(fwd, output, percent);
        RightMotors.spin(fwd, output, percent);

        wait(20, msec);
    }

    LeftMotors.stop();
    RightMotors.stop();
}

// Turn to an absolute heading (0-360). Automatically takes the shortest path.
// e.g. if facing 0° and you call turnTo(20), it turns 20° clockwise.
// if facing 0° and you call turnTo(350), it turns 10° counter-clockwise.
void turnTo(double targetHeading, int speed, bool coast) {
    while (targetHeading >= 360.0) targetHeading -= 360.0;
    while (targetHeading < 0.0) targetHeading += 360.0;

    const double kP = 0.9;
    const double maxSpeed = abs(speed);

    LeftMotors.setStopping(coast ? brakeType::coast : brakeType::brake);
    RightMotors.setStopping(coast ? brakeType::coast : brakeType::brake);

    while (true) {
        double current = IMU.heading();
        double error = targetHeading - current;

        if (error > 180) error -= 360;
        if (error < -180) error += 360;

        if (fabs(error) < 3.0) break;

        double turnSpeed = error * kP;
        if (turnSpeed > maxSpeed) turnSpeed = maxSpeed;
        if (turnSpeed < -maxSpeed) turnSpeed = -maxSpeed;

        if (turnSpeed > 0) {
            LeftMotors.spin(reverse, turnSpeed, percent);
            RightMotors.spin(fwd, turnSpeed, percent);
        } else {
            LeftMotors.spin(fwd, -turnSpeed, percent);
            RightMotors.spin(reverse, -turnSpeed, percent);
        }

        wait(10, msec);
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
