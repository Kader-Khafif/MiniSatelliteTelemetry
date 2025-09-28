/* Custom library for Battery management
By Kader Khafif
08/27/2025
*/

#ifndef BATTERYMODULE_H
#define BATTERYMODULE_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>


class BatteryModule {
  public:
    BatteryModule(uint8_t pin/*, float R1, float R2*/);
    void begin();
    float getVoltage(); // Return battery voltage in Volts
    float getCurrent(); // Return battery current in Amperes
    float getCharge(); // Return battery state of charge in percentage

    private:
    uint8_t _pin;
    //float _R1, _R2;

};
// declaration of the global instance
extern BatteryModule battery;
#endif