//Link to Keyboard library key names: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
//Link to windows 10 shortcuts: https://www.windowscentral.com/best-windows-10-keyboard-shortcuts

#include <Keypad.h>
#include "Keyboard.h"

//Define dimensions of keyboard matrix
const byte ROWS = 4;
const byte COLS = 4;

//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class Keypad
Keypad customKeyboard = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Keyboard.begin();
}

void loop() {
  char customKey = customKeyboard.getKey();

  if (customKey)
    switch (customKey) {
      case '1':
        copy();
        break;
      case '2':
        paste();
        break;
      case '3':
        save();
        break;
      case '4':
        undo();
        break;
      case '5':
        redo();
        break;
      case '6':
        selectAll();
        break;
      case '7':
        screenShot();
        break;
      case '8':
        logout();
        break;
      case '9':
        myMacro();
        break;
      case '0':
        dominosOrder();
        break;
      case '*':
        //Put your macro here
        break;
      case '#':
        //Put your macro here
        break;
      case 'A':
        //Put your macro here
        break;
      case 'B':
        //Put your macro here
        break;
      case 'C':
        //Put your macro here
        break;
      case 'D':
        //Put your macro here
        break;
    }
}

//Common Shortcuts
void copy() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();
}

void paste() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  Keyboard.releaseAll();
}

void save() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('s');
  Keyboard.releaseAll();
}

void undo() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  Keyboard.releaseAll();
}

void redo() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('y');
  Keyboard.releaseAll();
}

void selectAll() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a');
  Keyboard.releaseAll();
}

void screenShot() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_GUI); //Command key on mac
  Keyboard.press('s');
  Keyboard.releaseAll();
}

//Logs you out of your computer
void logout() {
  // CTRL-ALT-DEL:
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(100);
  Keyboard.releaseAll();
  // ALT-l:
  delay(2000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('l');
  Keyboard.releaseAll();
}
//Create your own macros
void myMacro() {
  delay(300);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();

  delay(300);
  Keyboard.print("sound");
  Keyboard.releaseAll();

  delay(300);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(4000);
  Keyboard.press(KEY_RIGHT_ARROW);
  delay(5000);
  Keyboard.releaseAll();

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(300);
  Keyboard.print("firefox");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  Keyboard.releaseAll();

  delay(1000);
  Keyboard.print("https://www.youtube.com/watch?v=z4OrgZVV8B8");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  //delay(1000);
  //Keyboard.press(KEY_F6);
  //delay(500);
  //Keyboard.releaseAll();

  delay(5000);
  Keyboard.press('f');
  Keyboard.releaseAll();
}

void dominosOrder() {

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(300);
  Keyboard.print("firefox");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(300);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  Keyboard.releaseAll();

  delay(300);
  Keyboard.print("https://www.dominos.com/");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(13000);
  Keyboard.press(KEY_ESC);

  delay(1000);
  multiTab(14);

  multiTab(2);

  multiTab(1);

  delay(10000);
  multiTab(49);

  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(10000);
  multiTab(20);


}

void multiTab(int tabs) {
  for (int i  = 0; i < tabs; i++) {
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
  }
  delay(300);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}


/*
  Keyboard.press(KEY_SOMEKEY);
  Keyboard.press(KEY_ANOTHERKEY);
  ...
  Keyboard.releaseAll();
*/
