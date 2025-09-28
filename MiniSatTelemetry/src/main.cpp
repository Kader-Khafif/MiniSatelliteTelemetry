/* Main.cpp code for the simulation of a Mini Satellite that communicate with 
a Station on Earth.
By Kader Khafif the 08/25/2025 */

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "DS1307Module.h"
#include "MPU6050Module.h"
#include "BatteryModule.h"
#include "sharedData.h"



// Declaring Task handlers
TaskHandle_t TimeKeeperTask = NULL;
TaskHandle_t AcceleroGyroTask = NULL;
TaskHandle_t BatteryLevelTask = NULL;
TaskHandle_t PrinterTask  = NULL;

void TimeKeeper( void * parameter ) {
  for(;;) { // looping for timekeeping
    // Get the current time from the RTC
    DateTime now = rtc.now();
    //Serial.printf("Time: %02d:%02d:%02d\n", now.hour(), now.minute(), now.second());
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}
void AcceleroGyro( void * parameter ) {
  for(;;) { // looping for reading MPU6050 data
    // Getting acceleration and gyro data from MPU6050
    mpu.readSensorData();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void BatteryLevel( void * parameter ) {
  for(;;) { // looping for reading battery data
    // Getting battery voltage and charge percentage
    battery.begin(); // Ensure the battery module is initialized 
    vTaskDelay(1000 / portTICK_PERIOD_MS);

  }
}
void Printer( void * parameter ) {
  for (;;) {
    Serial.println("----- Satellite Data -----");
    if (sharedD.now.isValid()) {
      Serial.printf("Date: %04d-%02d-%02d  ", 
                    sharedD.now.year(), sharedD.now.month(), sharedD.now.day());

      Serial.printf("Time: %02d:%02d:%02d\n", 
                  sharedD.now.hour(), sharedD.now.minute(), sharedD.now.second());

      Serial.printf("Battery: %.2f V (%.1f %%)\n", 
                  sharedD.voltage, sharedD.charge);

      Serial.printf("Accel X: %.2f, Y: %.2f, Z: %.2f m/s²\n", 
                  sharedD.ax, sharedD.ay, sharedD.az);

      Serial.printf("Gyro  X: %.2f, Y: %.2f, Z: %.2f rad/s\n", 
                  sharedD.gx, sharedD.gy, sharedD.gz);

      Serial.printf("Pitch: %.2f °, Roll: %.2f °, Yaw: %.2f °\n",
                  sharedD.pitch, sharedD.roll, sharedD.yaw);

      Serial.printf("Temp: %.2f °C\n", sharedD.temp);
      Serial.println("---------------------------");
    } else {
      Serial.println("Shared Data: Invalid Data");
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  rtc.begin();
  mpu.begin();
  battery.begin();
  
  xTaskCreatePinnedToCore(
    TimeKeeper,          /* Task function. */
    "TimeKeeper",        /* name of task. */
    10000,              /* Stack size of task */
    NULL,               /* parameter of the task */
    2,                  /* priority of the task */
    &TimeKeeperTask,    /* Task handle to keep track of created task */
    0);                 /* pin task to core 0 */

  xTaskCreatePinnedToCore(
    AcceleroGyro,
    "AcceleroGyro",
    15000,
    NULL,
    1,
    &AcceleroGyroTask,
    0);

  xTaskCreatePinnedToCore(
    BatteryLevel,
    "BatteryLevel",
    10000,
    NULL,
    1,
    &BatteryLevelTask,
    0);

  xTaskCreatePinnedToCore(
    Printer,
    "Printer", 
    20000, 
    NULL, 
    1, 
    NULL, 
    1);
}
void loop() {
  updateSharedData();
  delay(1000);
}