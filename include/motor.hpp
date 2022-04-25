/*
 * 12-MAR-2022
 * Name: Eyitope ADELOWO
 * SID:  11398686
*/


#include <mbed.h>


class MOTOR: public PwmOut
{

    public:
        MOTOR(PinName pwm_pin);
        ~MOTOR();
        void start(float start_period);
        void stop(void);
        void change_speed(float duty_cycle);

        float dutycc;           // 0.0 - 1.0
};
