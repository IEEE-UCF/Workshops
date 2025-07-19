#include <Servo.h>

int buttonState = 0;
int count = 0;
int L1 = 3;
int L2 = 4;
int L3 = 5;
int L4 = 6;
int L5 = 7;
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);

  servo.attach(8);
  servo.write(0);
}

void loop() {
  if (buttonState == digitalRead(2)) {
  return;
  }

  if (count == 31) {
  servo.write(180);
    count = 0;
  }
  else if (count == 0) {
  servo.write(0);
    count++;
  }

  buttonState = digitalRead(2);

  if (buttonState == HIGH) {
  count++;
  }
  delay(300);

  if ((count % 2) > 0) {
  digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

  if ((count % 4) > 1) {
  digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }

  if ((count % 8) > 3) {
  digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }

  if ((count % 16) > 7) {
  digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }

  if ((count % 32) > 15) {
  digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }

}
