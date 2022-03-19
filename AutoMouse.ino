#include <Bounce.h>
#include "Keyboard.h"
int ledPins[] = {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
int pinCount = 11;
int ROOM_STATE = 0;
int timer = 0;
int led = 0;
Bounce ROOM_1 = Bounce(2, 10);
Bounce ROOM_2 = Bounce(3, 10);
Bounce ROOM_3 = Bounce(4, 10);
Bounce ROOM_4 = Bounce(5, 10);
Bounce ROOM_5 = Bounce(6, 10);
unsigned long previousmicros = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Start Working");
  Mouse.screenSize(1920, 1080);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

int i = 1;

void loop() {
  unsigned long currentmicros = millis();
  ROOM_1.update();
  ROOM_2.update();
  ROOM_3.update();
  ROOM_4.update();
  ROOM_5.update();

  if (ROOM_STATE == 0) {//START
    State0();
  }
  if (ROOM_STATE == 1) {//READY
    State1();
  }
  if (ROOM_STATE == 5) {//ROOM_GREEN 5/6 ห้อง
    State5();
  }

  //---------------------------------------------------------------------------------//

  if (ROOM_1.fallingEdge()) {
    ROOM_STATE = 1;
  }
  if (ROOM_2.fallingEdge()) { //GREEN 5/6
    previousmicros = currentmicros;

//    Mouse.moveTo(255, 994);
//    Mouse.click();
//    //      Mouse.click();
//    delay(1);
    Mouse.moveTo(253, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(702, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(1147, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(1595, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(258, 473);
    Mouse.click();
    //      Mouse.click();
    delay(1);
//    Mouse.moveTo(156, 994);
//    Mouse.click();
//    //      Mouse.click();
    Serial.println(i);
    i++;

    ROOM_STATE = 5;
    timer = 0;
    led = 0;
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
      digitalWrite(ledPins[thisPin], LOW);
    }
  }
  if (ROOM_3.fallingEdge()) {
    ROOM_STATE = 0;
    digitalWrite(ledPins[0], LOW);
  }
  if (ROOM_4.fallingEdge()) {
    timer = timer + 5;
    led = led + 1;
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
      digitalWrite(ledPins[thisPin], LOW);
    }
    if (led >= 0 && led <= 10 && timer >= 5 ) {
      digitalWrite(ledPins[led], HIGH);
    }
    else if (led == 11) {
      digitalWrite(ledPins[1], HIGH);
      led = 1;
    }
    Serial.println(timer);
  }
  if (ROOM_5.fallingEdge()) {
    timer = timer - 5;
    led = led - 1;
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
      digitalWrite(ledPins[thisPin], LOW);
    }
    if (led >= 1 && led <= 10 && timer >= 5 ) {
      digitalWrite(ledPins[led], HIGH);
    }
    else if (led == 0 && timer >= 5) {
      digitalWrite(ledPins[10], HIGH);
      led = 10;
    }
    Serial.println(timer);
  }
}

void State0() {
  for (int thisPin = 1; thisPin < pinCount; thisPin++) {
    digitalWrite(ledPins[thisPin], HIGH);
    delay(10);
    digitalWrite(ledPins[thisPin], LOW);
  }
  for (int thisPin = pinCount - 1; thisPin >= 1; thisPin--) {
    digitalWrite(ledPins[thisPin], HIGH);
    delay(10);
    digitalWrite(ledPins[thisPin], LOW);
  }
}

void State1() {
  digitalWrite(ledPins[0], HIGH);
}

void State5() {
  unsigned long currentmicros = millis();
  if (currentmicros - previousmicros == 300000 - timer) {
    previousmicros += 300000;

    Serial.println(i);

//    Mouse.moveTo(255, 994);
//    Mouse.click();
//    //      Mouse.click();
//    delay(1);
    Mouse.moveTo(253, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(702, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(1147, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(1595, 198);
    Mouse.click();
    //      Mouse.click();
    delay(1);
    Mouse.moveTo(258, 473);
    Mouse.click();
    //      Mouse.click();
    delay(1);
//    Mouse.moveTo(156, 994);
//    Mouse.click();
//    //      Mouse.click();
//    delay(1);

    i++;


    timer = 0;
    led = 0;
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
      digitalWrite(ledPins[thisPin], LOW);
    }
  }
}
