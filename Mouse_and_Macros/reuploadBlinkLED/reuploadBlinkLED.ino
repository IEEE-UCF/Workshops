#include "Keyboard.h"

const int buttonPin = 14; //rotary encoder button on the breadboard

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(buttonPin) == LOW) {

    // new document:
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('n');
    delay(100);
    Keyboard.releaseAll();

    // wait for new window to open:
    delay(1000);

    // delete the pre-populated text
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('a');
    delay(500);
    Keyboard.releaseAll();
    Keyboard.write(KEY_BACKSPACE);
    delay(500);

    // Type out "blink":
    Keyboard.println("void setup() {");
    Keyboard.println("pinMode(17, OUTPUT);");
    Keyboard.println("}");
    Keyboard.println();

    Keyboard.println("void loop() {");
    Keyboard.println("digitalWrite(17, HIGH);");
    Keyboard.println("delay(1000);");

    Keyboard.println("digitalWrite(17, LOW);");
    Keyboard.println("delay(1000);");

    // tidy up:
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('t');
    delay(100);

    Keyboard.releaseAll();
    delay(3000);

    // upload code:
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('u');
    delay(100);
    Keyboard.releaseAll();

    //upload without saving
    delay(1000);
    Keyboard.press(KEY_ESC);
    delay(100);
    Keyboard.releaseAll();

    // wait for reprogramming
    while (true);
  }
}
