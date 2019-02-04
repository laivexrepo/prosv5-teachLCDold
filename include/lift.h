#ifndef _LIFT_H_
#define _LIFT_H_

// ----------- SETTINGS FOR AUTO LIFT CONTROL -------
#define LIFT_FULL_RETRACT 0       // fully down Position
#define LIFT_LOW_POLE 2750        // encoder target ticks for low scoring pole
#define LIFT_HIGH_POLE 4230       // encoder target ticks for high scoring pole

void liftSetZero(int speed);      // reset encoders Zero position

void liftRaise(int speed, int level);   // move to one of three positions at speed RPM
                                        // 0 = retracted fully
                                        // 1 = low pole
                                        // 2 = high pole

void liftRaiseSteps(int speed, int increment); // move lift up or down in
                                               // given increment at speed in RPM

#endif
