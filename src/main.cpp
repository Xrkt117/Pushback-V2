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

//Team Variable
bool isRedTeam = true;

// Pneumatics toggle state
bool extendoAState = false;
bool extendoBState = false;
bool descorerState = false;

void toggleExtendoA() {
  extendoAState = !extendoAState;
  ExtendoOutA.set(extendoAState);
}

void toggleExtendoB() {
  extendoBState = !extendoBState;
  ExtendoOutB.set(extendoBState);
}

void toggleDescorer() {
  descorerState = !descorerState;
  Descorer.set(descorerState);
}

/*---------------------------------------------------------------------------*/
/*                             Team Picker                                   */
/*---------------------------------------------------------------------------*/
void pickTeam() {
  Brain.Screen.clearScreen();
  drawTeamSelect();

  while(true) {
    if (Brain.Screen.pressing()) {
      int x = Brain.Screen.xPosition();
      Brain.Screen.setFont(mono60);
      if (x < 240) {
        isRedTeam = true;
      } else {
        isRedTeam = false;
      }
      Brain.Screen.setFont(mono20);
      wait(2, seconds);
      break;
    }
    wait(20, msec);
  }
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  pickTeam();
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // Color sensor not present/defined in this build; skip initialization
  // ColorSensor.setLightPower(100, percent);
  // ColorSensor.setLight(ledState::on);

  // Initialize pneumatics default states and register toggle handlers (once)
  ExtendoOutA.set(extendoAState);
  ExtendoOutB.set(extendoBState);
  Descorer.set(descorerState);
  Controller1.ButtonY.pressed(toggleExtendoA);
  Controller1.ButtonX.pressed(toggleExtendoB);
  Controller1.ButtonA.pressed(toggleDescorer);

  while (true) {
  // joystick values
  // Negate Axis3 so pushing the joystick forward produces positive forward motion
  int forwardVal = -Controller1.Axis3.position(percent); // forward/backward
    int turnVal = Controller1.Axis1.position(percent); // left/right

    // drivetrain commands instead of raw motor spins
    int leftSpeed = forwardVal - turnVal;
    int rightSpeed = forwardVal + turnVal;

    //motor speed appliance
    LeftMotors.spin(fwd, leftSpeed, percent);
    RightMotors.spin(fwd, rightSpeed, percent);

    //Intake Controls
    if (Controller1.ButtonR1.pressing()) {
      SMechanism.spin(reverse, 100, percent);
      Intake.spin(reverse, 100, percent);
      Scoring.spin(reverse, 100, percent);  
    }
    else if (Controller1.ButtonR2.pressing()) {
      SMechanism.spin(fwd, 100, percent);
      Intake.spin(fwd, 100, percent);
      Scoring.spin(fwd, 100, percent);
    }
    else {
      SMechanism.stop();
      Intake.stop();
      Scoring.stop();
    }

    if (Controller1.ButtonL1.pressing()) {
      Flexwheel.spin(fwd, 100, percent);
    }
    else if (Controller1.ButtonL2.pressing()) {
      Flexwheel.spin(reverse, 100, percent);
    }
    else {
      Flexwheel.stop();
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