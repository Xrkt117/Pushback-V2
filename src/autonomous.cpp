#include "vex.h"
#include "auton-config.h"
#include "interface.h"

// Define PI here to avoid relying on platform-specific M_PI macro
constexpr double PI = 3.14159265358979323846;

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

// Chassis helpers
void chassisSetVelocity(int pct) {
    LeftMotors.setVelocity(pct, percent);
    RightMotors.setVelocity(pct, percent);
}
void chassisStop() {
    LeftMotors.stop();
    RightMotors.stop();
}
void chassisSpin(directionType dir, double leftPct, double rightPct) {
    LeftMotors.spin(dir, leftPct, percent);
    RightMotors.spin(dir, rightPct, percent);
}

// If true, autonomous motor directions will be inverted to match driver control
// Set to true when autonomous movement is observed to be reversed compared to driver control
const bool invertAuton = true;
//Eaach autonomous routine will be varied in the future
void autonomous(void) {
    IMU.setHeading(0, degrees);

        //Auton Skills 
    if (selectedAuton == 0) {
       // picking up 3||4 balls auton (in work) ----------------------------------------------------------------------------------------
        drive(65, 55); 
        turnTo(339, 40, false);
        intake();
        wait(100, msec);
        drive(43.5, 15);
        wait(250, msec);
        stop();
        turnTo(225, 35, true);
        drive(-35, 50);
        scoring();
        wait(500, msec);
        stop();
        outtake();
        wait(500, msec);
        stop();
        scoring();
        wait(2500, msec);
        stop();
        drive(90, 45);
        turnTo(270, 65, true);
        drive(25, 40);
        turnTo(180, 65, true);
        matchloader.set(true);
        wait(200, msec);
        drive(50, 70); //faster for loader & drive less distance (10cm?) for matchloader distance (subtract approximate distance of matchloader from current drive)
        
        intake();
        wait(2000, msec);
        stop();
        longGoal.set(true);
        drive(-75, 60);
        matchloader.set(false);
        scoring();
        wait(4000, msec);
        stop();
        longGoal.set(false);
        drive(35, 30);
        turnTo(130, 35, true);
        drive(-45, 45);
        turnTo(180, 35, true);
        drive(-180, 45);


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
    double totalDeg = (fabs(distanceCm * 0.393701) / (4.25 * PI)) * 360.0;
    double sign = ((distanceCm >= 0) != invertAuton) ? 1.0 : -1.0;
    int maxPct = abs(speed);

    // PID constants (error normalized to 0-100%)
    const double kP = 0.75;
    const double kI = 0.6;
    const double kD = 0.1;

    // Heading correction
    double startHeading = IMU.heading();
    const double hkP = 2.0;

    LeftMotors.resetPosition();
    RightMotors.resetPosition();

    double prevError = 100.0;
    double integral = 0.0;

    while (true) {
        double traveled = (fabs(LeftMotors.position(degrees)) + fabs(RightMotors.position(degrees))) / 2.0;
        double rawError = totalDeg - traveled;
        if (rawError <= 0.0) break;

        // normalize error to 0-100
        double error = (rawError / totalDeg) * 100.0;

        integral += error * 0.02;
        if (integral > 100) integral = 100;
        double derivative = (error - prevError) / 0.02;
        prevError = error;

        int pct = (int)(error * kP + integral * kI + derivative * kD);
        if (pct < 8) pct = 8;
        if (pct > maxPct) pct = maxPct;

        double hError = startHeading - IMU.heading();
        if (hError > 180) hError -= 360;
        if (hError < -180) hError += 360;
        double correction = hError * hkP;

        LeftMotors.spin(fwd, (pct + correction) * sign, percent);
        RightMotors.spin(fwd, (pct - correction) * sign, percent);

        wait(20, msec);
    }

    chassisStop();
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

        // proportional: slow down near target
        int turnSpeed = (int)(fabs(error) * kP);
        if (turnSpeed < minSpeed) turnSpeed = minSpeed;
        if (turnSpeed > maxSpeed) turnSpeed = maxSpeed;

        if (error > 0) {
            LeftMotors.spin(fwd, turnSpeed, percent);
            RightMotors.spin(reverse, turnSpeed, percent);
        } else {
            LeftMotors.spin(reverse, turnSpeed, percent);
            RightMotors.spin(fwd, turnSpeed, percent);
        }

        wait(20, msec);
    }

    chassisStop();
    IMU.setHeading(targetHeading, degrees);
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