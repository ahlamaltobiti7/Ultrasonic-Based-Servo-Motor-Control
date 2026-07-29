#include <Servo.h>

const int TRIG_PIN = 9;  
const int ECHO_PIN = 10; 
const int SERVO_PIN = 7;  


const int DISTANCE_THRESHOLD = 15;
const int SERVO_ANGLE = 180;        

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

  
  if (distance > 0 && distance <= DISTANCE_THRESHOLD) {
    myServo.write(SERVO_ANGLE); 
  } else {
    myServo.write(0);          
  }

  delay(100); 
}