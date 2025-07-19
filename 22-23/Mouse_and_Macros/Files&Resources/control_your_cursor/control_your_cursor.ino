/*
  Controls the mouse from a joystick.
  Uses the button on the joystick to turn on and off mouse control
  and two pushbuttons to click the left and right mouse buttons. 
  The rotary encoder controls the scroll wheel and middle mouse button

  Hardware:
  - 2-axis joystick
  - two pushbuttons
  - rotary encoder with button

  The mouse movement is always relative. This sketch reads two analog inputs
  that range from 0 to 1023 (or less on either end) and translates them into
  ranges of -6 to 6.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the command. This sketch
  includes a pushbutton to toggle the mouse control state, so you can turn on
  and off mouse control.
*/

#include "Mouse.h"
#include "Keyboard.h"

// pin declarations for the joystick
const int onOffBtn = A1;      // switch to turn on and off mouse control, located on joystick
const int xAxis = A3;         // joystick X axis
const int yAxis = A2;         // joystick Y axis
bool mouseIsActive = false;    // whether or not to control the mouse

// pin declarations for the two pushbuttons
const int leftMouseBtn = A0;    // input pin for the left push button
const int rightMouseBtn = 15;   // input pin for the right push button

// pin declarations for the rotary encoder
const int middleMouseBtn = 14; //sw pin on encoder
const int clk = 10; //clk pin on encoder
const int dt = 16; //dt pin on encoder
int state, lastState;

// parameters for reading the joystick:
int range = 9;               // output range of X or Y movement. Changing this value can be thought of as changing the m`ouse's "DPI"
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value

void setup() {

  // pin modes for the four button inputs
  // must be written as INPUT_PULLUP to use the Pro Micro's internal pullup resistors,
  pinMode(onOffBtn, INPUT_PULLUP);
  pinMode(leftMouseBtn, INPUT_PULLUP);
  pinMode(rightMouseBtn, INPUT_PULLUP);
  pinMode(middleMouseBtn, INPUT_PULLUP);

  // pin modes for the two data pins on the rotary encoder
  pinMode(dt, INPUT);
  pinMode(clk, INPUT);

  lastState = digitalRead(dt); //set the last state of the rotary encoder to the current reading

  // take control of the mouse:
  Mouse.begin();
}

void loop() {
  // if button on joystick is pressed, toggle the mouse to active
  if (digitalRead(onOffBtn) == LOW)
    mouseIsActive = !mouseIsActive;

  if (mouseIsActive) {
    controlMouse();
  }
}

void controlMouse() {
  // read and scale the two axes:
  int upDownReading = readAxis(xAxis);
  int sideToSideReading = -readAxis(yAxis); //side to side movement is inverted

  Mouse.move(sideToSideReading, upDownReading, 0);

  //Call functions to check and see if a mouse button is pressed
  leftMouse();
  rightMouse();
  middleMouse();
  scrollWheel();

  delay(responseDelay);
}

// Reads an axis (0 or 1 for x or y) and scales the analog input range to a range from 0 to <range>
int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  return distance;
}

void leftMouse() {
  // if the left mouse button is pressed:
  if (digitalRead(leftMouseBtn) == LOW) {
    // if the left mouse button is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }

  // else the left mouse button is not pressed:
  else {
    // if the left mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }
}

void rightMouse() {
  // if the right mouse button is pressed:
  if (digitalRead(rightMouseBtn) == LOW) {
    // if the right mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT);
    }
  }

  // else the right mouse button is not pressed:
  else {
    // if the right mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.release(MOUSE_RIGHT);
    }
  }
}

void middleMouse() {
  // if the middle mouse button is pressed:
  if (digitalRead(middleMouseBtn) == LOW) {
    // if the right mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_MIDDLE)) {
      Mouse.press(MOUSE_MIDDLE);
    }
  }

  // else the right mouse button is not pressed:
  else {
    // if the right mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_MIDDLE)) {
      Mouse.release(MOUSE_MIDDLE);
    }
  }
}

void scrollWheel() {
  state = digitalRead(dt);

  if (state != lastState) {

    if (digitalRead(clk) != state) {
      Keyboard.press(KEY_PAGE_DOWN);
      Keyboard.release(KEY_PAGE_DOWN);
    }
    else {
      Keyboard.press(KEY_PAGE_UP);
      Keyboard.release(KEY_PAGE_UP);
    }
  }
  lastState = state;
}
