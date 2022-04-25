/*
* 12-MAR-2022
* Name: Nkosilathi Mpala
* SID:  10714539
*/

#include <tc74.hpp>

TC74::TC74(PinName sdapin, PinName sclpin, int i2cAddress): I2C(sdapin, sclpin), sensorAddress(i2cAddress)
{
    cmd[0] = 0x00;
}

TC74::~TC74()
{}

int TC74::get_temperature()
{
    char data[1];
    data[0] = 0x00;
    this->write(sensorAddress, cmd, 1);
    this->read(sensorAddress, data, 1);
    return (int)data[0];
}
