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