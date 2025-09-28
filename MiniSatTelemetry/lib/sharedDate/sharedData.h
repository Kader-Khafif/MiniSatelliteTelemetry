/* This file is the library for shared data structures and functions 
by Kader Khafif the 08/27/2025*/

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <Arduino.h>
#include <RTClib.h>

struct sharedData {
    DateTime now;
    float voltage;
    float charge;
    float ax,ay,az;
    float gx, gy, gz;
    float temp;
    float pitch, roll, yaw;
};

// initiate Shared instance
extern sharedData sharedD;

void updateSharedData();

#endif 