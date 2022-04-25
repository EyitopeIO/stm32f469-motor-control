/*
* 12-MAR-2022
* Contributors: Eyitope ADELOWO (SID:11398686), Nkosilathi Mpala (SID:10714539)
*/


#include <mbed.h>

#include "motor.hpp"
#include "tc74.hpp"

#include <app_touchgfx.h>

#define MOTOR_PWM_PIN PB_1

#define TEMP_SDA_PIN PB_9
#define TEMP_SCL_PIN PB_8
#define TEMP_I2C_ADDRESS 0x9A

Thread ui_thread;       // Update the display
Thread se_thread;       // Read sensor and control motor

DigitalOut ml_status(LED1);
DigitalOut status1(LED2);
DigitalOut se_status(LED3);
DigitalOut ui_status(LED4);

MOTOR dc_motor(MOTOR_PWM_PIN);
TC74 tmp_sensor(TEMP_SDA_PIN, TEMP_SCL_PIN, TEMP_I2C_ADDRESS);

float temperature_to_dutycc(int temperature);
void se_thread_loop(void);      // sensing & control
void ui_thread_loop(void);      // user interface

extern "C" void MX_TouchGFX_Init(void);
extern "C" void MX_TouchGFX_Process(void);

const float math_e = 2.71828f;                      // Available in C++ from C++20
const float motor_period = 8332.0f;                 // 120Hz in microseconds.



int main() {
    
    ui_status = 0;
    status1 = 0;
    ml_status = 0;
    se_status = 0;

    wait_us(100000);

    status1 = 1;
    ml_status = 1;
    se_status = 1;

    // MX_TouchGFX_Init();
    dc_motor.start(motor_period);
    se_thread.start(se_thread_loop);
    ui_thread.start(ui_thread_loop);

    while(1) {
        ml_status = !ml_status;
        ThisThread::sleep_for(1s);
    }

    return 0;
}


/* Mapping of temperature to duty cycle should be defined here */
float temperature_to_dutycc(int temperature) {
    const float tempMin = 16.0f;
    const float tempMax = 37.0f;
    const float dutyMax = 100.0f;
    const float dutyMin = 0.0f; 
    return (((((float)temperature-tempMin)*(dutyMax-dutyMin))/(tempMax-tempMin)) + tempMin)/100;
}

void se_thread_loop(void) {

    int current_temperature = 0;
    float current_dutycc = 0;

    while(true) {
        se_status = !se_status;

        current_temperature = tmp_sensor.get_temperature();
        
        if (!current_temperature) {
            // printf("No temperature to read.\n");
            ThisThread::sleep_for(1s);
            continue;
        }
    
        current_dutycc = temperature_to_dutycc(current_temperature);
        
        // printf("The duty cycle is %d\n", (int)(current_dutycc * 100));
        // printf("The temperature is %d\n\n", current_temperature);

        /* Do */
        if (current_dutycc > 1.0) {
            current_dutycc = 1.0;
        }
        
        /* Let us have a minimum duty cycle so that motor does not completely stop */
        else if (current_dutycc < 0.1) {
            current_dutycc = 0.2;
        }
        
        dc_motor.change_speed(current_dutycc);
        
        // So the UI will be updated here.
        se_status = !se_status;
        ThisThread::sleep_for(3s);
    }
}

void ui_thread_loop(void)
{
    ui_status = 0;
    while (1) 
    {
        
        /* Comment out this sleep if the GUI works */
        ThisThread::sleep_for(1s);
        
        /* This will block */
        // MX_TouchGFX_Process();
    }
}
