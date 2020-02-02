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

int ir1, ir2, ir3, ir4;
float temp;

void setup() {
    Serial.begin(9600);
    Serial.println("Grove - Human Presence Sensor example");

    Wire.begin();

    if (movementSensor.initialize() == false) {
        Serial.println("Device not found. Check wiring.");
        while (1);
    }
}

void loop() {
    if (movementSensor.dataReady()) {
        ir1 = movementSensor.getRawIR1();
        ir2 = movementSensor.getRawIR2();
        ir3 = movementSensor.getRawIR3();
        ir4 = movementSensor.getRawIR4();
        temp = movementSensor.getTMP();

        movementSensor.startNextSample();

        Serial.print("1:[");
        Serial.print(ir1);
        Serial.print("], 2:[");
        Serial.print(ir2);
        Serial.print("], 3[");
        Serial.print(ir3);
        Serial.print("], 4:[");
        Serial.print(ir4);
        Serial.print("], temp[");
        Serial.print(temp);
        Serial.print("], millis[");
        Serial.print(millis());
        Serial.print("]");
        Serial.println();
    }
    delay(1);
}
