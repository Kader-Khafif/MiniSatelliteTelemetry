/* Custom library for Battery management
By Kader Khafif
08/27/2025
*/

#include "BatteryModule.h"

BatteryModule::BatteryModule(uint8_t pin/*, float R1, float R2*/) {
  _pin = pin;
  //_R1 = R1;
  //_R2 = R2;
  analogReadResolution(12); // ESP32 ADC resolution
}

void BatteryModule::begin() {
  pinMode(_pin, INPUT);
}
float R1=22000; float R2= 12000;
float BatteryModule::getVoltage() {
  int rawValue = analogRead(_pin);
  float voltage = (rawValue / 4095.0) * 3.3 * ((R1 + R2) / R2); // Assuming a 12-bit ADC and 3.3V reference. To be modified as needed
  return voltage;
}

float BatteryModule::getCurrent() {
  // Implement current sensing here
  return 0.0;
}

float BatteryModule::getCharge() {
  float charge = (getVoltage() / 5.0) * 100; // Assuming 5.0V is the fully charged voltage. To be modified as needed
  return charge;
}
// Definition of the global instance with the actual pin
BatteryModule battery(33);  // GPIO33 for ADC

