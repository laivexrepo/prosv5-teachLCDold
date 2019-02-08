#include "main.h"
#include "portdef.h"
#include "auto.h"
#include "chassis.h"
#include "lift.h"
#include "shooter.h"
#include "claw.h"
#include "intake.h"


/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/


// for the ball launcher
//pros::Motor shooterMotorAuto(SHOOTER_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, true);

void skillRun() {
  pros::lcd::print(2, "Auto:  skillRun");
  if(DEBUG_ON) {
    std::cout << "Running Auto - SkillRun Code " << "\n";
  }
	// skills run //
  shootBall(200);               // Shoot the ball at target from starting square


	//driveAuto.turnAngle(-1*8_deg);
	//driveAuto.moveDistance(-1*0.9_m);
	//driveAuto.moveDistance(1.4_m);
	//driveAuto.turnAngle(90_deg);
	//driveAuto.moveDistance(1.8_m);
};

void autoRedLeft() {
  pros::lcd::print(2, "Auto:  autoRedLeft");
  driveForDistancePID(24, 50);                    // 24 inches at 50RPM - we are on GREEN
  pivotTurn(60, -90);
  driveForDistancePID(24, 50);                    // 24 inches at 50RPM - we are on GREEN
  pivotTurn(60, 90);

};

void autoBlueLeft() {
  pros::lcd::print(2, "Auto:  autoBlueLeft");

};

void autoRedRight() {
  pros::lcd::print(2, "Auto:  autoRedRight");

};

void autoBlueRight() {
  pros::lcd::print(2, "Auto:  autoBlueRight");

};
