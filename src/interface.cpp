// Single, clean implementation of the Brain UI for the Pushback project.
// Contains: drawSelectedAuton, drawMainMenu, drawAutonMenu, backButton, handleTouch

#include "vex.h"
#include "interface.h"
#include "auton-config.h"

using namespace vex;

int currentScreen = 0;  // 0 = main, 1 = auton, 2 = stats,
int selectedAuton = 0;

void drawSelectedAuton() {
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(265, 20, 200, 40, color(30, 30, 30));  // shadow

  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(260, 15, 200, 40, color(0, 150, 150));  // border
  Brain.Screen.setPenColor(color(0, 200, 200));
  Brain.Screen.setFillColor(color(50, 50, 50));
  Brain.Screen.drawRectangle(262, 17, 196, 36); // button face
  Brain.Screen.setFont(prop20);
  Brain.Screen.printAt(270, 40, autonNames[selectedAuton]);
}

void drawMainMenu() {
  drawMainBackground();
  drawSelectedAuton();

  // Draw Stats button with 3D effect
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(265, 80, 200, 40, color(30, 30, 30));  // shadow
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(260, 75, 200, 40, white);  // border
  Brain.Screen.setPenColor(black);
  Brain.Screen.setFillColor(color(50, 50, 50));
  Brain.Screen.drawRectangle(262, 77, 196, 36); // button face
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(prop20);
  Brain.Screen.printAt(300, 100, "Auton Selector");
}

void drawAutonMenu() {
  if (isRedTeam) {
    // drawRedAuton();
  } else {
    // drawBlueAuton();
  }
  backButton();
}

void backButton(){
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(color(40, 40, 40));
  Brain.Screen.drawRectangle(10, 205, 80, 30, color(30, 30, 30));  // shadow
  Brain.Screen.drawRectangle(8, 203, 80, 30, black);  // border
  Brain.Screen.setFillColor(color(50, 50, 50));
  Brain.Screen.drawRectangle(10, 205, 76, 26);  // button face
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(20, 223, "< BACK");
}

void handleTouch() {
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();

  if (currentScreen == 0) {
    // Auton Selector button (top menu item)
    if (x > 260 && x < 460 && y > 75 && y < 115) {
      currentScreen = 1;
      drawAutonMenu();
      // wait for finger release so the same touch doesn't register as a selection

    }
    // Stats/Diagnostics button (bottom menu item) NOT FUNCTIONING YET
    else if (x > 260 && x < 460 && y > 135 && y < 175) {
      currentScreen = 2;

    }
  } else if (currentScreen == 1) {
    // Auton selection depending on which team you are on
    if(isRedTeam){
      drawAutonMenu();
      if(x > 40 && x < 200 && y > 40 && y < 200){
        selectedAuton = 1;  // Left Red
        currentScreen = 0;
        // drawMainMenu();

      }
      if(x > 280 && x < 440 && y > 40 && y < 200){
        selectedAuton = 2;  // Right Red
        currentScreen = 0;
        // drawMainMenu();
      }
    } else {
      drawAutonMenu();
      if(x > 40 && x < 200 && y > 40 && y < 200){
        selectedAuton = 3;  // Left Blue
        currentScreen = 0;
        // drawMainMenu();
      }
      if(x > 280 && x < 440 && y > 40 && y < 200){
        selectedAuton = 4;  // Right Blue
        currentScreen = 0;
        // drawMainMenu();
      }
    }
    // Back button
    if (x < 80 && y > 200) {
      currentScreen = 0;
      // drawMainMenu();

    }
  } else if (currentScreen == 2) {
    if (x < 80 && y > 200) {
      currentScreen = 0;
      // drawMainMenu();
    }
  }

}