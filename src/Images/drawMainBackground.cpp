#include "vex.h"
#include "interface.h"

using namespace vex;

// Minimal, self-contained main background painter.
// The original project previously included a larger image-based implementation;
// this lightweight replacement matches the declared symbol so linking succeeds
// and provides a clean background for the UI.
void drawMainBackground() {
  Brain.Screen.clearScreen();
  // subtle dark background
  Brain.Screen.setFillColor(color(18, 18, 18));
  Brain.Screen.drawRectangle(0, 0, 480, 240);

  // header bar
  Brain.Screen.setFillColor(color(0, 150, 150));
  Brain.Screen.drawRectangle(0, 0, 480, 50);
  Brain.Screen.setFont(prop20);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(10, 30, "REALPushbackV3");

  // clear area for buttons/menu
  Brain.Screen.setFillColor(color(40, 40, 40));
  Brain.Screen.drawRectangle(10, 60, 460, 170);
}
