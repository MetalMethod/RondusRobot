# RondusRobot
A homemade, small, cheap and simple autonomous robot pet built with a Arduino microcontroller.
My desire to learn programming made me research for physical computing applications. For the fun and learning experience, i decided to build my own robot pet, based on Arduino.

The Name RondUS comes from: Rounded Body, guided by UltraSonic sensor. The main concept design is to make it search for obstacles, avoid them and navigate by rotating around its own Y axis, so only one Ultrasonic sensor is needed. When rotating it turns both wheels in oposing directions.

The main propouse of this project is to practicing programming, using a known platform for physical computing. Always with the "As Cheap As Possible" thinking in mind, I searched and bougth all the parts. 

The full amount spent was under US$200, in Brazil. Thats including the tools like a Voltimeter by Ford and soldering equip. All parts are from China, except the orginal Arduino chipset and the chassis, wich is made by a local company, and its was too the most expensive piece (around U$70). 
Thats the list of parts used:
- Original Arduino Board from Italy
- 1 Ultrasonic Sensor HC-SR04
- L293D H-bridge as the motors driver.
- 2 6-12V DC motors: I never found their model but are those straight yellow that are sold in hobby shops and Ali Express.
- a voltimeter digital display for checking battery life on board + switch.
- cables and input jack
- red LED mounted inside as a pulsing heart, always pulsing when the arduino is on.
- 2 IR sensor for cliff/end of table avoidance (not implemented yet)
- Chassis made on acrylics + dummy wheel.
- Power suply: 2 separate packs of 6 rechargeble cells each (soldered in series), getting around 8 Volts each when charged. (Arduino needs al least 7 volts to work with all the sensors and lights). Onde pack gos to the driver input so it powers the motors. Another oack powers the microcontroller. The motors batteries goes fast, around 20 minutes-max of constant walking around. The Arduino pack lasts up to 6 hours with al least 7 volts.

For the code Im building my own algorithm so it has its own personality.

I found the the great NewPing_v1.8 library by Tim Eckel:
http://playground.arduino.cc/Code/NewPing
documentation: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
This library is very helpful as contains objects for acurate Ultrasonic Ping sensors. It returns a distance in cm. It also allows to implement functions using a Timer interrupt method, so it can run separate events at once without using the delay() function.

