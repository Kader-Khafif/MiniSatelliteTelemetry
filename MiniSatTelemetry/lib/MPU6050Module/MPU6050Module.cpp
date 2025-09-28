/* Custom library for MPU6050 motion sensor module
By kader khafif
08/27/2025
*/

#include "MPU6050Module.h"


MPU6050Module::MPU6050Module() {
}

void MPU6050Module::begin() {
  Wire.begin();
  
  Serial.println("Initializing MPU6050...");
 
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Found!");
  
  // Set the accelerometer and gyro ranges (optional)
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  
  // Set the filter bandwidth (optional)
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("MPU6050 initialized successfully!\n");
}

void MPU6050Module::readSensorData() {

  mpu.getEvent(&accel, &gyro, &temp);
}
 
  // --- Accessors ---
float MPU6050Module::getAccelerationX() const {  return accel.acceleration.x; }
float MPU6050Module::getAccelerationY() const {  return accel.acceleration.y; }
float MPU6050Module::getAccelerationZ() const {  return accel.acceleration.z; }

float MPU6050Module::getGyroX() const { return gyro.gyro.x; }
float MPU6050Module::getGyroY() const { return gyro.gyro.y; }
float MPU6050Module::getGyroZ() const { return gyro.gyro.z; }

float MPU6050Module::getTemperature() const { return temp.temperature; }
// --- Compute Pitch & Roll from accelerometer ---

float MPU6050Module::getPitch() const {
  return atan2(accel.acceleration.y, sqrt(pow(accel.acceleration.x,2) + pow(accel.acceleration.z,2))) * 180.0 / PI;
}
float MPU6050Module::getRoll() const {
  return atan2(-accel.acceleration.x, accel.acceleration.z) * 180.0 / PI;
}
float MPU6050Module::getYaw() const {
  return atan2(accel.acceleration.z, sqrt(pow(accel.acceleration.x,2) + pow(accel.acceleration.y,2))) * 180.0 / PI;
}
  MPU6050Module mpu; // Definition of the global instance