# -Opti-Home-Automation-System-using-IOT
The Opti Home System is an innovative smart home solution designed to enhance convenience, security, and energy efficiency. By integrating advanced technologies such as automatic password-protected doors, motion detection sensors, LDR-based auto night lights, fire alarm and extinguisher systems, and earthquake alarms, the system ensures a comprehensive and reliable home automation experience. Each feature works seamlessly to safeguard homes from various threats while optimizing energy usage. This system is aimed at improving the quality of life by providing a secure, efficient, and user-friendly environment for homeowners.


The Opti Home System is a smart home automation solution that integrates advanced technologies toenhance security, convenience, and energy efficiency. It features functionalities such as password-protected doors, motion detection sensors, auto night lights, fire alarm and extinguisher systems, and earthquake alarms. These innovations work together to create a safer and smarter living environment, addressing modern household needs with efficiency and reliability.


Methodology/Working Principle:

SMART DOOR: It’s an automatic password door whenever a correct password putting in the keypad it’ll pass the signal to the Arduino and Arduino will check if it is a correct password or not. If it is correct, it’ll pass a signal to the servo motor which will rotate 120 degree and open the door. “888” is the correct password we have set into the ARDUINO UNO. Without this password it won’t be opened. So, it’ll ensure the security. And again, when we press * or # the door will be closed.
PIR MOTION SECURITY SENSOR: Whenever a motion is detected in front of the PIR the digital output pin will make a signal and on will turn on the buzzer. It is for the security purpose which will concern us when an object entered into our home gate.
EARTHQUAKE ALARM: It’s very simple when the (+) and (–) pin touched the alarm will be turned on. We have made 2 terminals POSITIVE & NEGATIVE. The Positive terminal is static with a round shape ring and in the ring side area we have set a single wire with negative connection and fitted a weight at the bottom of the wire. So, whenever it’ll shake the POSITIVE and NEGATIVE pin touched the alarm will be turned on.
 AUTO NIGHT LIGHT:  When the LDR sensor detect the light, it’ll be turned off and otherwise the LED will be turned on.
FIRE ALARM AND EXTINGUISHER: Here we used a PHOTODIODE to detect the fire. when PHOTODIODE detect the fire, it will pass a signal to LED & WATER PUMP. The water pump will release the water from water tank to put out the fire.



STEPS OF CODE
1. Include the necessary libraries: Servo.h and Keypad.h.
2. Define a Servo object named "ServoMotor."
3. Set the password as a character array with the value "888".
4. Declare an integer variable called "position" and initialize it to 0. This variable will keep track of the current position in the password.
5. Define the keypad configuration:
   a. Set the number of rows and columns of the keypad to 4 each.
   b. Create a 2D array named "keys" that represents the keypad layout.
      - Numbers 1-9 and letters A-D are assigned to their respective positions.
      - The '*' and '#' symbols are also assigned to their positions.
   c. Define the row and column pins for the keypad.
6. Create a Keypad object named "keypad" with the defined configuration.
8. In the setup function:
   a. Attach the ServoMotor object to pin 11.
   b. Call the "LockedPosition" function with the argument "true" to lock the servo motor initially.

9. In the main loop:
   a. Get the current key pressed using the "getKey" function of the Keypad object.
   b. If the key is "*" or "#", reset the "position" variable to 0 and call the "LockedPosition" function with the argument "true" to lock the servo motor.
   c. If the pressed key matches the digit at the current "position" in the password, increment the "position" variable.
   d. Check if the "position" variable equals 3. If it does, call the "LockedPosition" function with the argument "false" to unlock the servo motor.
   e. Add a delay of 100 milliseconds to avoid rapid key presses.
10. Define the "LockedPosition" function that takes a boolean parameter named "locked":
    a. If "locked" is true
       - Set the servo motor position to 110 degrees (unlocked position).








