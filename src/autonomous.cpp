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
const bool invertAuton = true;
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
    // Convert linear distance (inches) to wheel revolutions.
    // Wheel diameter is 3.25 inches. Update if different.
    const double WHEEL_DIAMETER_IN = 3.25; 
    const double wheel_circumference = WHEEL_DIAMETER_IN * PI; // inches per revolution
    double revolutions = 0.0;
    if (wheel_circumference > 0.0) {
        double absDist = (distance >= 0.0) ? distance : -distance;
        revolutions = absDist / wheel_circumference;
    }

    // Determine direction from sign of distance
    directionType dir = (distance >= 0.0) ? directionType::fwd : directionType::rev;
    // Optionally invert autonomous directions so autonomous matches driver control
    if (invertAuton) {
        dir = (dir == directionType::fwd) ? directionType::rev : directionType::fwd;
    }

    // Use absolute speed for motor velocity
    int absSpeed = (speed >= 0) ? speed : -speed;
    LeftMotors.setVelocity(absSpeed, percent);
    RightMotors.setVelocity(absSpeed, percent);

    // Smooth ramping profile: split the travel into segments and ramp
    // up/down velocities so motors don't instantly jump to max speed.
    // This conserves momentum and gives a snappy but controlled motion.
    const int DEFAULT_SEGMENTS = 8;
    const int ACCEL_SEGMENTS = 2;
    const int DECEL_SEGMENTS = 2;
    const int MIN_RAMP_VEL = 12; // percent - minimum to overcome stiction

    // If very short distance, don't over-segment
    int segments = DEFAULT_SEGMENTS;
    if (revolutions < 0.5) {
        int tmp = (int)ceil(revolutions * 4.0);
        segments = (tmp > 1) ? tmp : 1;
    }

    if (segments <= 1) {
        LeftMotors.spinFor(dir, revolutions, rev, false);
        RightMotors.spinFor(dir, revolutions, rev, true);
        return;
    }

    double segRevs = revolutions / (double)segments;

    for (int i = 0; i < segments; ++i) {
        int vel = absSpeed;
        // accelerating
        if (i < ACCEL_SEGMENTS) {
            double t = (double)(i + 1) / (double)ACCEL_SEGMENTS; // 0..1
            vel = (int)round(MIN_RAMP_VEL + t * (absSpeed - MIN_RAMP_VEL));
        }
        // decelerating
        else if (i >= segments - DECEL_SEGMENTS) {
            int j = segments - i; // 1..DECEL_SEGMENTS
            double t = (double)j / (double)DECEL_SEGMENTS; // 0..1
            vel = (int)round(MIN_RAMP_VEL + t * (absSpeed - MIN_RAMP_VEL));
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

void turnTo(double degrees, int speed) {
    // Track width (distance between wheels) is 12.3 inches
    const double TRACK_WIDTH_IN = 12.3;
    
    // Calculate the arc length for the turn based on track width
    double arcLength = (degrees / 360.0) * (TRACK_WIDTH_IN * PI);
    
    // Set velocities for rotation
    int absSpeed = (speed >= 0) ? speed : -speed;
    LeftMotors.setVelocity(absSpeed, percent);
    RightMotors.setVelocity(absSpeed, percent);
    
    // Convert arc length to wheel revolutions
    const double WHEEL_DIAMETER_IN = 3.25;
    double absArc = (arcLength >= 0.0) ? arcLength : -arcLength;
    double revolutions = absArc / (WHEEL_DIAMETER_IN * PI);
    
    // Determine turn direction based on angle
    // Positive degrees = clockwise (right motors backward, left motors drive)
    if (invertAuton) {
        degrees = -degrees;
    }
    if(degrees >= 0) {
        LeftMotors.spinFor(fwd, revolutions, rev, false);
        RightMotors.spinFor(reverse, revolutions, rev, true);
    } else {
        LeftMotors.spinFor(reverse, revolutions, rev, false);
        RightMotors.spinFor(fwd, revolutions, rev, true);
    }

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