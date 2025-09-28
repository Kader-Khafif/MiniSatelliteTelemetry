/* Custom library for DS137 real-time clock module 
By kader khafif
08/27/2025
*/

#ifndef DS137MODULE_H
#define DS137MODULE_H

#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>   // force include in case BusIO needs it


class DS1307Module {
  
  public:
    DS1307Module();
    void begin();
    DateTime getTime();
    void adjustTime(const DateTime& dt);

};
// Declaration of the global instance rtc
extern RTC_DS1307 rtc;

#endif