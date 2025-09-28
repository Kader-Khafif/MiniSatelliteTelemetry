/* This file is the implementation for shared data structures and functions 
by Kader Khafif the 08/27/2025*/

#include "sharedData.h"
#include "MPU6050Module.h"
#include "DS1307Module.h"
#include "BatteryModule.h"

// initiating global instance (allocates memory )
sharedData sharedD;

void updateSharedData() {
    // Update the shared data instance with current readings
    // RTC data
  sharedD.now = rtc.now();

  // Battery data
  sharedD.voltage = battery.getVoltage();
  sharedD.charge = battery.getCharge();

  // MPU6050 data
  mpu.readSensorData();
  sharedD.ax = mpu.getAccelerationX();
  sharedD.ay = mpu.getAccelerationY();
  sharedD.az = mpu.getAccelerationZ();
  sharedD.gx = mpu.getGyroX();
  sharedD.gy = mpu.getGyroY();
  sharedD.gz = mpu.getGyroZ();
  sharedD.temp = mpu.getTemperature();
  sharedD.pitch = mpu.getPitch();
  sharedD.roll  = mpu.getRoll();
  sharedD.yaw   = mpu.getYaw();
}