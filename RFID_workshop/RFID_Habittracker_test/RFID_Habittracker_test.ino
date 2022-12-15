const int piezo = 5;
const int button = 9;
int buttonIncrementer = 1;
const int pin1 = 4;
const int pin2 = 5;
const int pin3 = 6;
const int pin4 = 7;
const int pin5 = 8;

void setup() {

  pinMode(piezo, OUTPUT); // Set piezo - pin 9 as an output
  pinMode(button, INPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);

}

void loop() {

  if (digitalRead(button) == HIGH) {
    buttonIncrementer++;
    Serial.println("Reading button 1");
  }
  else if(digitalRead(button) == LOW) {
    Serial.println("Nothing");
  }

  if ((buttonIncrementer % 2) > 0) {
    digitalWrite(pin1, HIGH);
  } else {
    digitalWrite(pin1, LOW);
  }
  if ((buttonIncrementer % 4) > 1) {
    digitalWrite(pin2, HIGH);
  } else {
    digitalWrite(pin2, LOW);
  }
  if ((buttonIncrementer % 8) > 3) {
    digitalWrite(pin3, HIGH);
  } else {
    digitalWrite(pin3, LOW);
  }
  if ((buttonIncrementer % 16) > 7) {
    digitalWrite(pin4, HIGH);
  } else {
    digitalWrite(pin4, LOW);
  }
  if ((buttonIncrementer % 32) > 15) {
    digitalWrite(pin5, HIGH);
  } else {
    digitalWrite(pin5, LOW);
  }

  delay(1000);
}
