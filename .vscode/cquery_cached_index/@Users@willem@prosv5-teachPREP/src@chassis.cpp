#include "main.h"    // includes API.h and other headers
#include "chassis.h" // ensures that the corresponding header file (chassis.h) is included
#include "portdef.h" // All port defintions on the cortex need to be included

// Setup the motor definitions for the motors on the chassis, including GEARSET,
// which in this case is RED cartridge - 100 RPM gear set.
pros::Motor left_wheel_1 (DRIVE_LEFT_MOTOR_PORT);
pros::Motor left_wheel_2 (DRIVE_LEFT_MOTOR_PORT2);
pros::Motor right_wheel_1 (DRIVE_RIGHT_MOTOR_PORT);
pros::Motor right_wheel_2 (DRIVE_RIGHT_MOTOR_PORT2);


// Place all chassis specific functions here, forexample
// void driveForDistancePD(int speed, int distance) {}

void driveRobot(int speed) {
  // This function drives the robot forward/backwards at given speed
  left_wheel_1.move_velocity(speed);
  left_wheel_2.move_velocity(speed);
  right_wheel_1.move_velocity(speed);
  right_wheel_2.move_velocity(speed);
}

void chassisSetOpcontrol(int left, int right) {
  // requires input for the left motor and right motor, typical from thei
  // the joystick
  left_wheel_1.move(left);
  left_wheel_2.move(left);
  right_wheel_1.move(right);
  right_wheel_2.move(right);
}

void chassisStopDrive(){
  // convienance fucntion to stop fhe drive train from moving
  left_wheel_1.move(0);
  left_wheel_2.move(0);
  right_wheel_1.move(0);
  right_wheel_2.move(0);
}

/*
void turnLeft(int speed) {
  // pivot turn the robot 'left' - use delay after the call to
  // turn for a given time = angle
  motorSet(LEFT_M_FRONT, speed);
  motorSet(RIGHT_M_FRONT, speed);
}

void turnRight(int speed) {
  // pivot turn the robot 'right' - use delay after the call to
  // turn for a given time = angle
  motorSet(LEFT_M_FRONT, -speed);
  motorSet(RIGHT_M_FRONT, -speed);
}

*/

void driveForDistancePID(int distance, int speed) {
  // drive the robot using the build in PID control on the drive base for a given
  // distance. Distance is supplied in inches, and speed is givin in velocity
  // meaning depending on your installed cartidege to be either +- 100 (RED), +-200 (GREEN)
  // +-600 (BLUE) cartridge
  //
  // We are using motors in degree settings of the PID controller

  float wheelCircum = WHEEL_DIAMETER * 3.14;    // global WHEEL_DIAMETER is set in chassis.h
  float motorDegree = (distance / wheelCircum) * 360;  // cast into full degrees

  // Calculate the lower and uppor bounds for the while loop ensuring robot drives
  // desired distance
  float motorUpper = motorDegree + 5;
  float motorLower = motorDegree - 5;

  if(DEBUG_ON) {
    std::cout << "Dist: " << motorDegree ;
    std::cout << " Upper: " << motorUpper << " Lower: " << motorLower << "\n";
  }

  // We first need to reset all the encoders
  left_wheel_1.tare_position();
  left_wheel_2.tare_position();
  right_wheel_1.tare_position();
  right_wheel_2.tare_position();

  left_wheel_1.move_relative(motorDegree, speed);    // Moves motorDegree units forward
  left_wheel_2.move_relative(motorDegree, speed);    // Moves motorDegree units forward
  right_wheel_1.move_relative(motorDegree, speed);   // Moves motorDegree units forward
  right_wheel_2.move_relative(motorDegree, speed);   // Moves motorDegree units forward

  while (!((left_wheel_1.get_position() < motorUpper) && (left_wheel_1.get_position() > motorLower))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
  }
  // we have reached our desired distance, so stop the motors.

  left_wheel_1.move(0);
  left_wheel_2.move(0);
  right_wheel_1.move(0);
  right_wheel_2.move(0);

  if(DEBUG_ON){
    std::cout << "Encoder Left: " << left_wheel_1.get_position();
    std::cout << " Encoder Right: " << right_wheel_1.get_position() << "\n";
  }
}

/*
void pivotTurn(int direction, int speed, float angle) {
  // direction -- 1 = left turn, 0 = right pivotTurn
  // speed -- -100 -- 100
  // angle -- desired turn angle in degrees
  //
  // Assumes a quadriatic encoder - 360 tics = 360 degrees

  // incoming speed variable sanity check
  if(speed == 0 ) {
     speed = 30;
  } else if(speed > 110) {
    speed = 100;              // make sure we have head room for slave
                              // motor to increass
  }

  // pivotTurn - turn radius is 1/2 * dimaeter of wheel base
  float turnCircum = WHEEL_BASE * 3.14;           // wheel_base is defind in chassis.h
  float wheelCircum = WHEEL_DIAMETER * 3.14;      // wheel_diameter is defined in chassis.h

  float motorDegree = (((angle/360) * turnCircum) / wheelCircum) * 360;

  if(DEBUG_ON) {
    printf("turnCricum: %1.2f \n", turnCircum);
    printf("wheelCricum: %1.2f \n", wheelCircum);
    printf("turn Angle: %1.2f \n", angle);
    printf("motorDegree: %1.2f \n", motorDegree);
  }

  if(direction == 1) {
    // Left turn
    // we need todo a while loop and count until we get to motorDegree
    // on quadriatic encoders
    encoderReset(encoderLM);
    delay(10);                   // give encoder time to reset

    while(encoderGet(encoderLM) <= motorDegree) {
      if(DEBUG_ON){
        printf("encoderLM: %d \n", encoderGet(encoderLM));
      }
      motorSet(LEFT_M_FRONT, speed);
      motorSet(RIGHT_M_FRONT, speed);

      delay(10);                 // we need to give it a bit of time to settle, but
                                 // if we make thsi time to long we will overshoot!
    }
  } else {
    // Right turn
    // we need todo a while loop and count until we get to motorDegree
    // on quadriatic encoders
    encoderReset(encoderRM);

    while(encoderGet(encoderRM) <= motorDegree) {
      if(DEBUG_ON){
        printf("encoderRM: %d \n", encoderGet(encoderRM));
      }
      motorSet(LEFT_M_FRONT, -speed);
      motorSet(RIGHT_M_FRONT, -speed);

      delay(10);                 // we need to give it a bit of time to settle, but
                                 // if we make thsi time to long we will overshoot!
    }
  }
  // stop the turn when we reach destination
  motorSet(LEFT_M_FRONT, 0);
  motorSet(RIGHT_M_FRONT, 0);
}
*/
