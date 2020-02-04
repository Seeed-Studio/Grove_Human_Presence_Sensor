# Grove - Human Presence Sensor  [![Build Status](https://travis-ci.com/Seeed-Studio/Grove_Human_Presence_Sensor.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Grove_Human_Presence_Sensor)

![](https://user-images.githubusercontent.com/5130185/52988647-0ac66600-343b-11e9-8f00-adda01de7555.png)

The Grove - Human Presence Sensor can be used to detect the presence of the human body or any other infrared objects. As it has four IR sensors, it can be used to detect the motion of the IR object and the relative position where the IR object moves. The locations of the four IR sensors are defined as:

![](https://user-images.githubusercontent.com/5130185/41015465-fb40d898-697c-11e8-91cd-d3bcc094c1e1.png)

(Please note that the location description of the four IR sensors in the datasheet might be wrong)

## Features

- Basic register read/write
- Simple detection algorithm to detect the presence and movement event

## Usage Tips

This library has two classes - `AK9753` and `PresenceDetector`. The `AK9753` class does basic read/write with the sensor. Taking the AK9753 as an input paramenter, the `PresenceDetector` class does some upper level calculation based on the readings from the sensor.

The sensor needs an issue of `start sample` signal before every conversion. Calling `AK9753::startNextSample()` does this trick. The `AK9753::startNextSample()` will be called in the `PresenceDetector::loop()` method, also in the `loop` method, it will read the sensor, do calculations and save the result. 

Typically the class you need to use is the `PresenceDetector` class, but you need to ensure that `AK9753::initialize()` is successful before calling any method of `PresenceDetector`.

There're two parameters you might need to adjust:
- threshold_presence
- threshold_movement

These parameters are used to determine the sensitivity of the detection. `threshold_presence` compares with the derivative of the readings of a specific IR sensor (1/2/3/4). `threshold_movement` compares with the derivative of the difference value between IR sensor 1-3 or 2-4. Without a lens, the readings of the IR sensor attenuate very quickly when the distance gets longer. So you need to lower down the threshold in order to detect a distant object.


## Examples

### 1. Read the raw data and print in serial console

File name: examples/Example1-BasicReadings/Example1-BasicReadings.ino

This example reads the raw (uint16_t) data of four IR sensors, and print these raw data in the serial.

### 2. Read the raw data and plot in the serial plotter

File name: examples/Example2-DiffPlot/Example2-DiffPlot.ino

This example reads the data of four IR sensors and converts them into current (pA), then plot diff13 and diff24 into the [Arduino IDE Serial Plotter](http://www.instructables.com/id/Ultimate-Guide-to-Adruino-Serial-Plotter/).

```
diff13 = IR1 - IR3  // blue line
diff24 = IR2 - IR4  // red line
```
![plot](https://user-images.githubusercontent.com/5130185/41019698-5d1d43b6-6992-11e8-89b4-fec7770f5044.png)

### 3. Detect the presence of IR object

File name: examples/Example3-DetectPresence/Example3-DetectPresence.ino

This example detects the presence of IR object. The detection is based on the derivative of the sensor value. If the derivative is greater than a threshold, we think that some IR object entered the view of the sensor.

### 4. Detect the movement and plot in the serial plotter

File name: examples/Example4-PlotMovement/Example4-PlotMovement.ino

The detection is based on the derivative of the difference value of IR1/IR3 or IR2/IR4. The legends of the plot are: (in order)

- diff13
- movement in the direction 1-3 (a pulse, positive pulse mean from 1 to 3, otherwise from 3 to 1)
- diff24
- movement in the direction 2-4 (a pulse, positive pulse mean from 2 to 4, otherwise from 4 to 2)

![plot2](https://user-images.githubusercontent.com/5130185/41027658-2dccd88e-69aa-11e8-8c32-4a94eca3f68d.png)


For more information, please refer to [wiki page](http://wiki.seeedstudio.com/Grove-Human_Presence_Sensor-AK9753/).

----

This software is written by Jack Shao for seeed studio and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>


[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/grove-human-presence-sensor)](https://github.com/igrigorik/ga-beacon)







