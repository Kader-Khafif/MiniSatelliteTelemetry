/* Custom Module library for DS1307 real-time clock module
By kader khafif
08/27/2025
*/

#include "DS1307Module.h"

DS1307Module::DS1307Module() {}

void begin() {
  Wire.begin();
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // resetting time if device lose power
  }
  Serial.println("RTC initialized");
}

DateTime getTime() {
  // Get the current time from the RTC
 DateTime now = rtc.now();

  return rtc.now();

}

void adjustTime(const DateTime& dt) {
//  rtc.adjust(dt);// resetting time only if device was never used before
}

// Definition of the global instance
RTC_DS1307 rtc;
