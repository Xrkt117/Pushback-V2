// Single, clean implementation of the Brain UI for the Pushback project.
// Contains: drawSelectedAuton, drawMainMenu, drawAutonMenu, backButton, handleTouch

#include "vex.h"
#include "interface.h"
#include "auton-config.h"

using namespace vex;

int currentScreen = 0;  // 0 = main, 1 = skills/match, 2 = left/right
int selectedAuton = 0;

void drawSelectedAuton() {
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(265, 20, 200, 40, color(30, 30, 30));

  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(260, 15, 200, 40, color(0, 150, 150));
  Brain.Screen.setPenColor(color(0, 200, 200));
  Brain.Screen.setFillColor(color(50, 50, 50));
  Brain.Screen.drawRectangle(262, 17, 196, 36);
  Brain.Screen.setFont(prop20);
  Brain.Screen.printAt(270, 40, autonNames[selectedAuton]);
}

void drawMainMenu() {
  drawMainBackground();
  drawSelectedAuton();

  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(265, 80, 200, 40, color(30, 30, 30));
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(260, 75, 200, 40, white);
  Brain.Screen.setPenColor(black);
  Brain.Screen.setFillColor(color(50, 50, 50));
  Brain.Screen.drawRectangle(262, 77, 196, 36);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(prop20);
  Brain.Screen.printAt(300, 100, "Auton Selector");
}

void drawAutonMenu() {
  drawMainBackground();

  Brain.Screen.setFont(prop30);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(140, 30, "SELECT AUTON");

  // Skills button
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(color(0, 150, 150));
  Brain.Screen.drawRectangle(40, 50, 190, 140);
  Brain.Screen.setFont(prop30);
  Brain.Screen.printAt(80, 130, "SKILLS");

  // Match button
  Brain.Screen.setFillColor(color(200, 100, 0));
  Brain.Screen.drawRectangle(250, 50, 190, 140);
  Brain.Screen.printAt(290, 130, "MATCH");

  backButton();
}

void drawSideMenu() {
  drawMainBackground();

  Brain.Screen.setFont(prop30);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(130, 30, "SELECT SIDE");

  // Left button
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(color(50, 150, 50));
  Brain.Screen.drawRectangle(40, 50, 190, 140);
  Brain.Screen.setFont(prop30);
  Brain.Screen.printAt(100, 130, "LEFT");

  // Right button
  Brain.Screen.setFillColor(color(150, 50, 50));
  Brain.Screen.drawRectangle(250, 50, 190, 140);
  Brain.Screen.printAt(300, 130, "RIGHT");

  backButton();
}

void backButton() {
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(color(40, 40, 40));
  Brain.Screen.drawRectangle(10, 205, 80, 30, color(30, 30, 30));
  Brain.Screen.drawRectangle(8, 203, 80, 30, black);
  Brain.Screen.setFillColor(color(50, 50, 50));
  Brain.Screen.drawRectangle(10, 205, 76, 26);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(20, 223, "< BACK");
}

void handleTouch() {
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();

  if (currentScreen == 0) {
    if (x > 260 && x < 460 && y > 75 && y < 115) {
      currentScreen = 1;
      drawAutonMenu();
    }
  } else if (currentScreen == 1) {
    // Skills
    if (x > 40 && x < 230 && y > 50 && y < 190) {
      selectedAuton = 0;
      currentScreen = 0;
      drawMainMenu();
    }
    // Match -> go to side select
    if (x > 250 && x < 440 && y > 50 && y < 190) {
      currentScreen = 2;
      drawSideMenu();
    }
    // Back
    if (x < 90 && y > 200) {
      currentScreen = 0;
      drawMainMenu();
    }
  } else if (currentScreen == 2) {
    // Left
    if (x > 40 && x < 230 && y > 50 && y < 190) {
      selectedAuton = 1;  // Match Left
      currentScreen = 0;
      drawMainMenu();
    }
    // Right
    if (x > 250 && x < 440 && y > 50 && y < 190) {
      selectedAuton = 2;  // Match Right
      currentScreen = 0;
      drawMainMenu();
    }
    // Back
    if (x < 90 && y > 200) {
      currentScreen = 1;
      drawAutonMenu();
    }
  }
}