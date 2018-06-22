#include "Keyboard.h"

const int zBut = 6;
const int xBut = 9;
const int spaceBut = 7;
const int refBut = 8;

int zPres = 0;
int xPres = 0;
int spacePres = 0;
int refPres = 0;

/*
const int but1 = 9;
const int but2 = 8;
const int but3 = 7;
const int but4 = 6;

//4 1 3 2 
*/
void setup() {
  // make the pushButton pin an input:
  pinMode(xBut, INPUT);
  pinMode(zBut, INPUT);
  pinMode(spaceBut, INPUT);
  pinMode(refBut, INPUT);
  
  // initialize control over the keyboard:
  Serial.begin(9600);
  Keyboard.begin();
}


void loop() {
  
  if (digitalRead(zBut) == 1) {
    Keyboard.press('z');
    zPres = 1;
  } else {
    if (zPres == 1) {
      Keyboard.release('z');
      zPres = 0;
    }
  }

  if (digitalRead(xBut) == 1) {
    Keyboard.press('x');
    xPres = 1;
  } else {
    if (xPres == 1) {
      Keyboard.release('x');
      xPres = 0;
    }
  }
  
  if (digitalRead(spaceBut) == 1) {
    Keyboard.press(' ');
    spacePres = 1;
  } else {
    if (spacePres == 1) {
      Keyboard.release(' ');
      spacePres = 0;
    }
  }
  
  if (digitalRead(refBut) == 1) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('r');
    refPres = 1;
  } else {
    if (refPres == 1) {
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release('r');
      refPres = 0;
    }
  }
  
}
