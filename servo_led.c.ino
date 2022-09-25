#include <Servo.h>
int led = 13;
Servo servo; 

int servo_pin = 9; // PWM pin for servo control
int pos = 0;    // servo starting position
void setup() {
  servo.attach(servo_pin); // start servo control
  Serial.begin(9600); // start serial monitor
  servo.write(pos); // move servo to 0 degrees
  Serial.println("Positioned at 0 Degrees");
  Serial.println("Input Desired Angle and Press Enter");
}

void loop() {
digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  while (Serial.available()){
    String in_char = Serial.readStringUntil('\n'); // read until the newline
    Serial.print("Moving to: ");
    Serial.print(in_char);
    Serial.println(" Degrees");
    servo.write(in_char.toInt()); // convert angle and write servo
    delay(in_char.toFloat()*(10.0/6.0)); // delay for maximum speed
  }
}
