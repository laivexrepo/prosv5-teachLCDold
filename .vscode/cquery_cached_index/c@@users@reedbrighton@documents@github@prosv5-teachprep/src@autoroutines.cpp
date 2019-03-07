#include "main.h"
#include "portdef.h"
#include "auto.h"
#include "chassis.h"
#include "shooter.h"
/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/



void skillRun() {
  pros::lcd::print(2, "Auto:  skillRun");
  if(DEBUG_ON) {
    std::cout << "Running Auto - SkillRun Code " << "\n";
  }

  shootBall(300);
  pivotTurn(20, -10);
  driveForDistancePID(-45, 100);

  driveForDistancePID(67, 100);

  pivotTurn(30, 81);
  //driveForDistancePID(10, 50);
  driveForDistancePID(-65, 150);



};






void autoRedLeft() {
  pros::lcd::print(2, "Auto:  autoRedLeft");

  shootBall(300);
  pivotTurn(20, -10);
  driveForDistancePID(-45, 100);

  driveForDistancePID(45, 100);
  pivotTurn(30, 78);
  driveForDistancePID(-35, 100);
  driveForDistancePID(37, 100);
  pivotTurn(30, -81);
  driveForDistancePID(20, 100);
  pivotTurn(30, 81);
  //driveForDistancePID(10, 50);
  driveForDistancePID(-75, 150);

};

void autoBlueLeft() {
  pros::lcd::print(2, "Auto:  autoBlueLeft");

};

void autoRedRight() {
  pros::lcd::print(2, "Auto:  autoRedRight");

};

void autoBlueRight() {
  pros::lcd::print(2, "Auto:  autoBlueRight");

  shootBall(300);
  //pivotTurn(20, -10);
  driveForDistancePID(-45, 100);

  driveForDistancePID(67, 100);

  pivotTurn(30, -81);
  //driveForDistancePID(10, 50);
  driveForDistancePID(-65, 150);

};
