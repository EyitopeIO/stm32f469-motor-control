/*
* 12-MAR-2022
* Name: Nkosilathi Mpala
* SID:  10714539
*/

#include <mbed.h>


class TC74: public I2C
{
    private:
        char cmd[1];
        const int sensorAddress;
        
    public:
        int last_temperature;
        TC74(PinName sdapin, PinName sclpin, int i2cAddress);
        ~TC74();
        int get_temperature(void);
};
