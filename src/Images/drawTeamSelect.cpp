#include "vex.h"
#include "interface.h"

using namespace vex;

// Simple, self-contained team selection screen.
// This avoids depending on any large image arrays and guarantees
// the symbol drawTeamSelect() is defined for link-time.
void drawTeamSelect() {
    Brain.Screen.clearScreen();

    // background
    Brain.Screen.setFillColor(color(30, 30, 30));
    Brain.Screen.drawRectangle(0, 0, 480, 240);

    // title
    Brain.Screen.setFont(prop60);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(100, 50, "SELECT TEAM");

    // Red button (left)
    Brain.Screen.setFillColor(color(200, 50, 50));
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(30, 80, 180, 120);
    Brain.Screen.setFont(prop40);
    Brain.Screen.printAt(80, 130, "RED");
    Brain.Screen.printAt(70, 170, "TEAM");

    // Blue button (right)
    Brain.Screen.setFillColor(color(50, 50, 200));
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(270, 80, 180, 120);
    Brain.Screen.setFont(prop40);
    Brain.Screen.printAt(315, 130, "BLUE");
    Brain.Screen.printAt(310, 170, "TEAM");
}
