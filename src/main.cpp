/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Xrkt (Matvii Tsariuk) & spertia (Dries Schoenly)          */
/*    Created:      Thu Sep 18 2025                                           */
/*    Description:  Vex code test                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightFront           motor         14               
// RightBack            motor         13              
// LeftFront            motor         12              
// LeftBack             motor         11  
// Scoring              motor         16            
// S1Mechanism          motor         15                                       
// S2Mechanism          motor         17
// Flexwheel            motor         18                            
// ExtendoOutA          digital_out   A    
// ExtendoOutB          digital_out   B           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "interface.h"
#include "auton-config.h"

using namespace vex;

// A global instance of competition
competition Competition;

// Pneumatics toggle state
bool matchloaderState = false;
bool longGoalState = false;
bool descorerState = false;

void toggleMatchloader() {
  matchloaderState = !matchloaderState;
  matchloader.set(matchloaderState);
}

void toggleLongGoal() {
  longGoalState = !longGoalState;
  longGoal.set(longGoalState);
}

void toggleDescorer() {
  descorerState = !descorerState;
  Descorer.set(descorerState);
}

/*---------------------------------------------------------------------------*/
/*                             Mode Picker                                   */
/*---------------------------------------------------------------------------*/
void pickMode() {
  Brain.Screen.clearScreen(color(20, 20, 20));

  // Skills button (left half)
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(color(0, 150, 150));
  Brain.Screen.drawRectangle(20, 40, 210, 160);
  Brain.Screen.setFont(prop40);
  Brain.Screen.printAt(60, 130, "SKILLS");

  // Match button (right half)
  Brain.Screen.setFillColor(color(200, 100, 0));
  Brain.Screen.drawRectangle(250, 40, 210, 160);
  Brain.Screen.printAt(290, 130, "MATCH");

  while (true) {
    if (Brain.Screen.pressing()) {
      int x = Brain.Screen.xPosition();
      if (x < 240) {
        selectedAuton = 0;  // Skills
      } else {
        selectedAuton = 1;  // Match
      }
      wait(300, msec);
      break;
    }
    wait(20, msec);
  }
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
  vexcodeInit();
  // runAutonSelector();
  selectedAuton = 0;
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {

  // Initialize pneumatics default states and register toggle handlers (once)
  matchloader.set(matchloaderState);
  longGoal.set(longGoalState);
  Descorer.set(descorerState);
  Controller1.ButtonY.pressed(toggleMatchloader);
  Controller1.ButtonX.pressed(toggleLongGoal);
  Controller1.ButtonA.pressed(toggleDescorer);
  bool inactive = true;
  while (true) {
  // joystick values
  // Negate Axis3 so pushing the joystick forward produces positive forward motion
  int forwardVal = -Controller1.Axis3.position(percent); // forward/backward
    int turnVal = Controller1.Axis1.position(percent); // left/right

    // drivetrain - use voltage for direct linear response (no internal PID ramping)
    // 12V is max; scale joystick percent (-100 to 100) to volts (-12 to 12)
    double leftVolt  = (forwardVal - turnVal) * 12.0 / 100.0;
    double rightVolt = (forwardVal + turnVal) * 12.0 / 100.0;

    LeftMotors.spin(fwd, leftVolt, volt);
    RightMotors.spin(fwd, rightVolt, volt);

    //Intake Controls
    if (Controller1.ButtonR1.pressing()) {
      inactive = false;
      SMechanism.spin(reverse, 100, percent);
      Intake.spin(reverse, 100, percent);  
    }
    else if (Controller1.ButtonR2.pressing()) {
      inactive = false;
      SMechanism.spin(fwd, 100, percent);
      Intake.spin(fwd, 100, percent);
      Scoring.spin(fwd, 100, percent);
     }

    else {
      inactive = true;
    }

    if(inactive){
      SMechanism.stop();
      Intake.stop();
      Scoring.stop();
    }

    
    
    if (Controller1.ButtonL1.pressing()) {
      inactive = false;
      Flexwheel.spin(fwd, 100, percent);
      Scoring.spin(reverse, 100, percent);
    }

    else if (Controller1.ButtonL2.pressing()) {
      inactive = false;
      Flexwheel.spin(reverse, 100, percent);
    }
   
    else {
      Flexwheel.stop();
      inactive = true;
    }

    wait(20, msec);
   }
  
  }

  // end of usercontrol loop and function

/*---------------------------------------------------------------------------*/
/*                                   Main                                    */
/*---------------------------------------------------------------------------*/
int main() {
  // Set up callbacks for autonomous and driver control periods
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

    // Run the rest of pre-autonomous initialization
    pre_auton();

  // Print IMU heading every ~1 degree change
  thread imuPrintThread([] {
    double lastPrinted = IMU.heading(degrees);
    while (true) {
      double current = IMU.heading(degrees);
      if (fabs(current - lastPrinted) >= 1.0) {
        printf("IMU heading=%.1f\n", current);
        lastPrinted = current;
      }
      wait(20, msec);
    }
  });


  // Start menu interface thread for autonomous selection
  thread interfaceThread([] {
    drawMainMenu();
    while (true) {
      if (Brain.Screen.pressing()) {
        handleTouch();
        this_thread::sleep_for(250);
      }
      wait(20, msec);
    }
  });


  // Competition control - let the system manage state transitions
  while (true) {
    wait(100, msec);
  }
}
