#include <Servo.h>

Servo myservo;
int pos = 180;  // Initialize servo position
int previous_command = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // Servo control on digital pin 9
  myservo.write(pos);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == '0') {
      // Do nothing (servo stays in the current position)
    } else if (command == '1') {
      if (previous_command == 2){
        myservo.write(90);
        delay(1000);
      }
      pos = 5;
      myservo.write(pos);
      previous_command = 1;
      delay(1000);
    } else if (command == '2') {
      if (previous_command == 1){
        myservo.write(90);
        delay(1000);
      }
      pos = 180;
      myservo.write(pos);
      previous_command = 2;
      delay(1000);
    }
  }
}
