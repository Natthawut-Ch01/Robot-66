#include <Servo.h>

Servo myServo;

// กำหนดขาเซ็นเซอร์
const int hallPin1 = 2;
const int hallPin2 = 3;
const int ENA = 10;
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;
const int ENB = 5;
const int trigPin = 13;
const int echoPin = 12;

// ตัวแปรสำหรับเซ็นเซอร์และการคำนวณ
volatile byte counter1 = 0;
volatile byte counter2 = 0;
unsigned long lastTime = 0;
float wheelCircumference = 0.2;

void setup() {
  Serial.begin(9600);
  pinMode(hallPin1, INPUT_PULLUP);
  pinMode(hallPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hallPin1), countRpm1, FALLING);
  attachInterrupt(digitalPinToInterrupt(hallPin2), countRpm2, FALLING);

  myServo.attach(11);
  myServo.write(0);
  delay(1000);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 225);
  analogWrite(ENB, 200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= 1000) {
    detachInterrupt(digitalPinToInterrupt(hallPin1));
    detachInterrupt(digitalPinToInterrupt(hallPin2));
    
    float speed1 = (counter1 * wheelCircumference) / 1.0;
    float speed2 = (counter2 * wheelCircumference) / 1.0;
    
    Serial.print("Speed from sensor 1: ");
    Serial.print(speed1);
    Serial.println(" m/s");
    
    Serial.print("Speed from sensor 2: ");
    Serial.print(speed2);
    Serial.println(" m/s");
    
    counter1 = 0;
    counter2 = 0;
    lastTime = currentTime;
    
    attachInterrupt(digitalPinToInterrupt(hallPin1), countRpm1, FALLING);
    attachInterrupt(digitalPinToInterrupt(hallPin2), countRpm2, FALLING);
  }

  bool objectDetected = false;

  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(15);
    float distance = getDistance();
    Serial.print("Servo position: ");
    Serial.print(pos);
    Serial.print(" degrees, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 50) { // ถ้าระยะทางน้อยกว่าหรือเท่ากับ 5 เมตร
      objectDetected = true;
      break;
    }
  }

  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
    float distance = getDistance();
    Serial.print("Servo position: ");
    Serial.print(pos);
    Serial.print(" degrees, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 500) { // ถ้าระยะทางน้อยกว่าหรือเท่ากับ 5 เมตร
      objectDetected = true;
      break;
    }
  }

  if (objectDetected) {
    stopMotors();
  }
}

void countRpm1() {
  counter1++;
}

void countRpm2() {
  counter2++;
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2;
  return distance;
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  myServo.write(90); // ตั้งค่าเซอร์โวที่ 90 องศา
  myServo.detach(); // หยุดการทำงานของเซอร์โว
}
