#include <Arduino.h>

#include "motor.h"
#include "newpwm.h"

void setMotorSpeed(int channel, int dirPin, q16 speed) {
    speed = constrain((PWMPERIOD * speed) >> 16, -PWMPERIOD, PWMPERIOD);

    if (speed < 0) {
        digitalWrite(dirPin, HIGH);
        pwm_set_duty(PWMPERIOD + speed, channel);
    } else {
        digitalWrite(dirPin, LOW);
        pwm_set_duty(speed, channel);
    }
}
