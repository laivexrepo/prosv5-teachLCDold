#include "main.h"
#include "portdef.h"
#include "lift.h"

pros::Motor liftMotor1(LIFT_RIGHT_MOTOR_PORT);
pros::Motor liftMotor2(LIFT_RIGHT_MOTOR_PORT_TWO);
pros::Motor liftMotor3(LIFT_LEFT_MOTOR_PORT);

void setLiftHeight(int height, int rpms) {
  //set lift height at rpms
  liftMotor1.move_absolute(height, rpms);
  liftMotor2.move_absolute(height, rpms);
  liftMotor3.move_absolute(height, rpms);
}

void liftSetZero(int speed) {
  // reset zero position of each encoded motor.
  liftMotor1.tare_position();
  liftMotor2.tare_position();
  liftMotor3.tare_position();
  if(DEBUG_ON){
    std::cout << "Lift ZERO point reset \n";
  }
}

void liftRaiseManual(int speed) {
  // Raises lift manual based using speed provided
  liftMotor1.move_velocity(speed);
  liftMotor2.move_velocity(speed);
  liftMotor3.move_velocity(speed);
}

void liftEncoderValue() {
  // gets the encoder value and prints it to the std::std::cout
  std::cout << "Lift Encoder: -- M1: " << liftMotor1.get_position();
  std::cout << " M2: " << liftMotor2.get_position();
  std::cout << " M23 " << liftMotor3.get_position() << "\n";
  pros::delay(2);
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

  int zeroPointUpper = LIFT_FULL_RETRACT + 5;
  int zeroPointLower = LIFT_FULL_RETRACT;

  switch(level) {
    case 0:
      // move all the way back down
      liftMotor1.move_absolute(0, speed); // Moves LIFT_LOW_POLE units forward
      liftMotor2.move_absolute(0, speed); // Moves LIFT_LOW_POLE units forward
      liftMotor3.move_absolute(0, speed); // Moves LIFT_LOW_POLE units forward
      while (!((liftMotor1.get_position() < zeroPointUpper) && (liftMotor1.get_position() > zeroPointLower))) {
          // Continue running this loop as long as the motor is not within +-5 units of its goal
          pros::delay(2);
      }

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
  if(DEBUG_ON){
    std::cout << "Lift Encoder: -- M1: " << liftMotor1.get_position();
    std::cout << " M2: " << liftMotor2.get_position();
    std::cout << " M23 " << liftMotor3.get_position() << "\n";
    pros::delay(2);           // Give thread time to catch up.
  }
}
