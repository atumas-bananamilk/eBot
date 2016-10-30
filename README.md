# eBot - self-driven robot using Rover 5 & Arduino

First of all, you can see the slides of a presentation from the Local Hack Day in Manchester (Sep 2015):
https://docs.google.com/presentation/d/1v9KD7Bw1jIURd7tnK8fcEKZrVEBv6im_QR0Mm5ftNnM/edit?usp=sharing

# eBot Tutorial

![alt tag](http://aivarastumas.weebly.com/uploads/4/9/8/0/49800285/743813120.png)

Rover 5 is a chassis of a robot, which is responsible for robot's movements.
You can add some sensors of your choice to it after you set it up for moving.
In this tutorial we are going to be controlling Rover 5 robot with our Arduino!

Part 1 - robot moving forwards, backwards, left, right.
Part 2 - robot with the front-camera avoiding obstacles (self-controlled).


# PART 1

Connecting Rover's board to Arduino:

So, Rover 5 comes with a 9V battery stack (6 AA batteries of 1.5V each) AND its micro-controller board, which you communicate with through Arduino.
You don't really need to use the 9V battery stack provided, in fact, any 9V battery will be just fine. Rover's micro-controller board looks like this:

![alt tag](http://aivarastumas.weebly.com/uploads/4/9/8/0/49800285/709226603.png)

Ch1, Ch2, Ch3, Ch4 - motor 1, motor 2, motor 3, motor 4 channels to communicate with them.
Ch current - returns analog value of the amount of current the motor is using (0-511).
Ch direction - returns digital value of motor's direction (0 - backwards, 1 - forwards).
Ch PWM - returns analog value of motor's power supply, which is speed basically (0-255).


Rover has 4 DC Motors (exactly the same as Arduino's DC Motors) and nothing else! We are going to be using only 2 of the motors to simplify the task.
Now, connect the board like that:

![alt tag](http://aivarastumas.weebly.com/uploads/4/9/8/0/49800285/522057396.png)

Note:
D4, D5, D6, D7 - digital pins (4, 5, 6, 7) in Arduino.
A0 - analog pin (A0) in Arduino.
Pins for 9V, GND of the battery and 5V, GND of the Arduino could be inserted in 2 ways: either by inserting them into the holder, or fixing them with the screw.

![alt tag](http://aivarastumas.weebly.com/uploads/4/9/8/0/49800285/365793188.png)

That's it! Let's move on to coding.
Controlling the robot with Arduino:

The connection you should now have: Rover 5 connected to its board, this board connected to Arduino, Arduino connected to your computer.
Now, let's do the following task:

4 phases:

        1. Robot moves forwards for 1.5s with speed 120.
        2. Robot moves backwards for 1.5s with speed 120.
        3. Robot turns left for 2.2s with speed 120.
        4. Robot turns right for 2.2s with speed 120.
        5. Repeats.

Code:

https://github.com/atumas-bananamilk/eBot/blob/master/part_1.ino

Note:

DigitalWrite() - robot's direction (0 OR 1). <br />
AnalogWrite() - robot's speed (0-255).

Done! Now your robot should be moving forwards, backwards, left and right. Just watch out for the cables to not be cut while it's moving.

# PART 2

Connecting sonar sensor to Arduino:

For detecting obstacles in front of the Rover, I suggest you use MaxSonar sensor from our Hardware Library (accuracy of 1cm).
Sonar sensor's pins are:

![alt tag](http://aivarastumas.weebly.com/uploads/4/9/8/0/49800285/431750418.png)

Now, connect your circuit like the following (keep in mind that we didn't draw connections from Rover's board to the Arduino):

![alt tag](http://aivarastumas.weebly.com/uploads/4/9/8/0/49800285/594165019.png)

Now, connect your circuit like the following (keep in mind that we didn't draw connections from Rover's board to the Arduino):

Finally, stick your sensor in front of the robot pointing forwards, so it doesn't measure the distance from the ground. 
Done! Let's move on to coding.

# Controlling the robot with a sensor

Let's do the following task:

        1. Sonar checks the distance of an object pointing forward.
        2. If object's distance from the sensor is < 30cm:
            Robot turns right for 0.7s with speed 110.
        else:
            Robot moves forward for 0.3s with speed 90.
        3. Repeats.

Code:

https://github.com/atumas-bananamilk/eBot/blob/master/part_2.ino

Note:

analogRead(sensor) - returns analog voltage, NOT the distance, so we need to do some calculations to convert it to centimetres. <br />
We are averaging sensor's readings (10 readings each time), because sensor sometimes sends completely random values to us, so we need to get some average.

Done! You have just made your own self-controlled robot.
