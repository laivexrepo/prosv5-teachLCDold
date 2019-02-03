#include "main.h"
#include "portdef.h"
#include "auto.h"

/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/


// for the ball launcher
pros::Motor shooterMotorAuto(SHOOTER_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, true);

void skillRun() {
  pros::lcd::print(2, "Auto:  skillRun");
  if(DEBUG_ON) {
    std::cout << "Running Auto - SkillRun Code " << "\n";
  }
	// skills run //
	//shooterControllerAuto.setTarget(-1*600);
  //shooterControllerAuto.waitUntilSettled();    // Have the shooter finsish shooting before the next action
	//shooterControllerAuto.tarePosition();				 // what ever the current posiiton is is the new '0'

	shooterMotorAuto.tare_position();
	shooterMotorAuto.move_absolute(2700, 100); // Moves 100 units forward
	while (!((shooterMotorAuto.get_position() < 2710) && (shooterMotorAuto.get_position() > 2690))) {
		 pros::delay(2);
	}

	//driveAuto.turnAngle(-1*8_deg);
	//driveAuto.moveDistance(-1*0.9_m);
	//driveAuto.moveDistance(1.4_m);
	//driveAuto.turnAngle(90_deg);
	//driveAuto.moveDistance(1.8_m);


	if(DEBUG_ON) {
    //std::cout << "Motor Position: " << liftGroupAuto.getPosition() << "\n";
  }
  //driveAuto.waitUntilSettled();
  //liftControlAuto.setTarget(LIFT_HIGH_POLE);
  if(DEBUG_ON) {
    //liftControlAuto.waitUntilSettled();                 // this causes all next
                                                        // moves to be blocked until lift complets
    //std::cout << "Motor Position: " << liftGroupAuto.getPosition() << "\n";
  }


};

void autoRedLeft() {
  pros::lcd::print(2, "Auto:  autoRedLeft");
	//shooterControllerAuto.setTarget(1200);
  //shooterControllerAuto.waitUntilSettled();    // Have the shooter finsish shooting before the next action
	//shooterControllerAuto.tarePosition();				 // what ever the current posiiton is is the new '0'
	//leftDriveAuto.moveVelocity(25);
	//rightDriveAuto.moveVelocity(-25);

	//driveAuto.turnAngle(-1*10_deg);
  //driveAuto.moveDistance(-1*1_m);
	//driveAuto.moveDistance(1.37_m);

	//shooterMotorAuto.tare_position();
	//shooterMotorAuto.move_absolute(2700, 100); // Moves 100 units forward
	//while (!((shooterMotorAuto.get_position() < 2710) && (shooterMotorAuto.get_position() > 2690))) {
	//	 pros::delay(2);
	//}
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
