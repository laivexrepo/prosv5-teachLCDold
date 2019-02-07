#ifndef _LIFT_H_
#define _LIFT_H_

// ----------- SETTINGS FOR AUTO LIFT CONTROL -------
#define LIFT_FULL_RETRACT 0       // fully down Position
#define LIFT_LOW_POLE 1450        // encoder target ticks for low scoring pole
#define LIFT_HIGH_POLE 2800       // encoder target ticks for high scoring pole
#define LIFT_MAX_HIEGHT 2950      // Maximum height the lift mechanically can extend to
#define LIFT_STEP_SIZE 30         // Step move increment for liftRaiseStep function

void liftSetZero(int speed);      // reset encoders Zero position

void liftRaise(int speed, int level);   // move to one of three positions at speed RPM
                                        // 0 = retracted fully
                                        // 1 = low pole
                                        // 2 = high pole

void liftRaiseForEncoder(int speed, int encDegrees);  // move lift up or down in
                                                      // given increment at speed in RPM

void liftRaiseStep(int speed, int direction);         // move lift up/down for fixed step size
                                                      // direction 0 - down , 1 - up

void liftEncoderValue();                // print the current encoder settings to the debug console

void liftRaiseManual(int speed);        // manual raise the lift up and down

void liftLock();                        // locks lift in current position forcing PID hold

void liftLockMode();                    // Get current lift motor break (lock) mode

#endif
