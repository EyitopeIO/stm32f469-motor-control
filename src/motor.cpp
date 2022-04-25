/*
* 12-MAR-2022
* Name: Eyitope ADELOWO
* SID:  11398686
*/


#include <motor.hpp>
#include <mbed.h>



MOTOR::MOTOR(PinName pwm_pin): PwmOut(pwm_pin)
{}

MOTOR::~MOTOR()
{}

/* 
* Start the motor by turning on PWM
* @start_period: The motor period to trigger PWM signal generation.
* A period of 0.0 is equivalent to calling stop()
*/
void MOTOR::start(float start_period)
{
    this->period_us(start_period);
}

/*
* Stop the motor by disabling PWM
*/
void MOTOR::stop(void)
{
    this->period(0.0f);
}

/*
* @percentage: Explicitly set duty cycle.
*/
void MOTOR::change_speed(float duty_cycle)
{   
    dutycc = duty_cycle;
    this->write(duty_cycle);
}
