#pragma once
#include "vex.h"

extern int selectedAuton;
extern bool isRedTeam;

void drawMainMenu();
void drawAutonMenu();
void handleTouch();
void backButton();

void drawMainBackground();
void drawTeamSelect();
// void drawTeamSelect();
// void drawTeamRed();
// void drawTeamBlue();
// void drawBlueAuton();
// void drawRedAuton();