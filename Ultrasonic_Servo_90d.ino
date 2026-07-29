#include <Servo.h>

const int TRIG_PIN = 9;   
const int ECHO_PIN = 10;  
const int SERVO_PIN = 7;  

Servo myServo;            

void setup() {
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  
  myServo.attach(SERVO_PIN);
  
  myServo.write(0);
  
  
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  long duration = pulseIn(ECHO_PIN, HIGH);
  
  
  int distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance > 0 && distance <= 10) {
    myServo.write(90); 
  } else {
    myServo.write(0);  
  }

  delay(100); 
}