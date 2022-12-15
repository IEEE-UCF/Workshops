const int piezo = 5;
const int tone1 = 7;
const int tone2 = 8;
const int tone3 = 9;

void setup() {

  pinMode(piezo, OUTPUT); // Set piezo - pin 9 as an output
  pinMode(tone1, INPUT);
  pinMode(tone2, INPUT);
  pinMode(tone3, INPUT);

}

void loop() {
  bool read1 = !(digitalRead(tone1));
  bool read2 = !(digitalRead(tone2));
  bool read3 = !(digitalRead(tone3));

  if (read1) {
    tone(piezo, 100);
    Serial.println("Reading button 1");
  }
  else if (read2) {

    tone(piezo, 500); // Send 1KHz sound signal...
    Serial.println("Reading button 2");
  }
  else if (read3) {

    tone(piezo, 1000); // Send 1KHz sound signal...
    Serial.println("Reading button 3");
  }
  else {

    Serial.println("Nothing");
  }
  delay(500);
}
