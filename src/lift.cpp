#include "main.h"
#include "portdef.h"
#include "lift.h"

pros::Motor liftMotor1(LIFT_RIGHT_MOTOR_PORT);
pros::Motor liftMotor2(LIFT_RIGHT_MOTOR_PORT_TWO);
pros::Motor liftMotor3(LIFT_LEFT_MOTOR_PORT);

void liftSetZero(int speed) {
  // reset zero position of each encoded motor.
  liftMotor1.tare_position();
  liftMotor2.tare_position();
  liftMotor3.tare_position();
}

void liftRaise(int speed, int level) {
  // move the lift up and down where levle is:
  // 0 -- fully retracted back to 0
  // 1 -- raise to lower pole height
  // 2 -- raise to upper pole height

  int lowPoleUpper = LIFT_LOW_POLE + 5;
  int lowPoleLower = LIFT_LOW_POLE - 5;

  int highPoleUpper = LIFT_HIGH_POLE + 5;
  int highPoleLower = LIFT_HIGH_POLE - 5;

  switch(level) {
    case 0:
      // move all the way back down
      liftMotor1.move_absolute(0, -speed); // Moves LIFT_LOW_POLE units forward
      liftMotor2.move_absolute(0, -speed); // Moves LIFT_LOW_POLE units forward
      liftMotor3.move_absolute(0, -speed); // Moves LIFT_LOW_POLE units forward

      break;

    case 1:
      // move to middle pole position
      liftMotor1.move_absolute(LIFT_LOW_POLE, speed); // Moves LIFT_LOW_POLE units forward
      liftMotor2.move_absolute(LIFT_LOW_POLE, speed); // Moves LIFT_LOW_POLE units forward
      liftMotor3.move_absolute(LIFT_LOW_POLE, speed); // Moves LIFT_LOW_POLE units forward
      while (!((liftMotor1.get_position() < lowPoleUpper) && (liftMotor1.get_position() > lowPoleLower))) {
          // Continue running this loop as long as the motor is not within +-5 units of its goal
          pros::delay(2);
      }
      break;

    case 2:
      // move to heigh pole position
      liftMotor1.move_absolute(LIFT_HIGH_POLE, speed); // Moves LIFT_LOW_POLE units forward
      liftMotor2.move_absolute(LIFT_HIGH_POLE, speed); // Moves LIFT_LOW_POLE units forward
      liftMotor3.move_absolute(LIFT_HIGH_POLE, speed); // Moves LIFT_LOW_POLE units forward
      while (!((liftMotor1.get_position() < highPoleUpper) && (liftMotor1.get_position() > highPoleLower))) {
          // Continue running this loop as long as the motor is not within +-5 units of its goal
          pros::delay(2);
      }
      break;
  }
}
