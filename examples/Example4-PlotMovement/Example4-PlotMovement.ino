/*
    An example for Grove - Human Presence Sensor

    Copyright (c) 2018 seeed technology co., ltd.
    Author      : Jack Shao
    Create Time: June 2018
    Change Log :

    The MIT License (MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include <Wire.h>

#include "Grove_Human_Presence_Sensor.h"

AK9753 movementSensor;

// need to adjust these sensitivities lower if you want to detect more far
// but will introduce error detection
float sensitivity_presence = 6.0;
float sensitivity_movement = 10.0;
int detect_interval = 30; //milliseconds
PresenceDetector detector(movementSensor, sensitivity_presence, sensitivity_movement, detect_interval);

uint32_t last_time;

void setup() {
    Serial.begin(9600);
    Serial.println("Grove - Human Presence Sensor example");

    Wire.begin();

    //Turn on sensor
    if (movementSensor.initialize() == false) {
        Serial.println("Device not found. Check wiring.");
        while (1);
    }

    last_time = millis();
}

void loop() {
    detector.loop();

    uint32_t now = millis();
    if (now - last_time > 100) {
        uint8_t m = detector.getMovement();  //read movement state will clear it

        Serial.print(detector.getDerivativeOfDiff13());
        Serial.print(" ");

        //plot a pulse for movement between 1-3
        if (m & MOVEMENT_FROM_1_TO_3) {
            Serial.print("20 ");
        } else if (m & MOVEMENT_FROM_3_TO_1) {
            Serial.print("-20 ");
        } else {
            Serial.print("0 ");
        }

        Serial.print(detector.getDerivativeOfDiff24());
        Serial.print(" ");

        //plot a pulse for movement between 2-4
        if (m & MOVEMENT_FROM_2_TO_4) {
            Serial.println("20 ");
        } else if (m & MOVEMENT_FROM_4_TO_2) {
            Serial.println("-20 ");
        } else {
            Serial.println("0 ");
        }

        last_time = now;
    }

    delay(1);
}
