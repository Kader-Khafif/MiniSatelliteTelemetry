/* Custom library for MPU6050 motion sensor module
By kader khafif
08/27/2025
*/

#ifndef MPU6050MODULE_H
#define MPU6050MODULE_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

class MPU6050Module {

  public:
    MPU6050Module();
    // initialization of the sensor
    void begin();
    // reading sensor data
    void readSensorData();
    // accessor methods for sensor data
    float getAccelerationX() const;
    float getAccelerationY() const;
    float getAccelerationZ() const;
    float getGyroX() const;
    float getGyroY() const;
    float getGyroZ() const;
    float getTemperature() const;
    float getPitch() const;
    float getRoll() const;
    float getYaw() const;

    private:
    Adafruit_MPU6050 mpu;
    sensors_event_t accel, gyro, temp;
};

// Declaration of the global instance mpu
extern MPU6050Module mpu;

#endif