#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Initialize LCD (address, columns, rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize Servo
ESP32Servo myServo;

// Define the keypad rows and columns
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// Update with valid ESP32 GPIO pins
byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String password = "123"; // Set your password
String inputPassword = "";

void setup() {
  lcd.init();
  lcd.backlight();
  myServo.attach(18); // Attach servo to GPIO 18
  pinMode(19, OUTPUT); // Buzzer
  
  // Lock the door at startup
  myServo.write(0);
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      if (inputPassword == password) {
        lcd.clear();
        lcd.print("Access Granted");
        digitalWrite(19, HIGH); // Buzzer ON
        delay(500);
        digitalWrite(19, LOW); // Buzzer OFF
        myServo.write(120);    // Unlock the door
        delay(5000);           // Keep door unlocked for 5 seconds
        myServo.write(0);      // Lock the door
        lcd.clear();
        lcd.print("Enter Password:");
      } else {
        lcd.clear();
        lcd.print("Access Denied");

        // Buzzer "teet teet" sound 3 times
        for (int i = 0; i < 3; i++) {
          digitalWrite(19, HIGH); // Buzzer ON
          delay(500);            // Beep for 500ms
          digitalWrite(19, LOW); // Buzzer OFF
          delay(500);            // Pause for 500ms
        }

        lcd.clear();
        lcd.print("Enter Password:");
      }
      inputPassword = ""; // Reset input
    } else if (key == '*') {
      inputPassword = ""; // Clear input
      lcd.clear();
      lcd.print("Enter Password:");
    } else {
      inputPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }
  }
}
