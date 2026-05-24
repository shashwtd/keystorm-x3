#include <Keyboard.h>

#define BTN_1  D0
#define BTN_2  D1
#define BTN_3  D2

#define LED_1  D3
#define LED_2  D4
#define LED_3  D5

#define BUZZER  D6


void setup() {
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Keyboard.begin();

  // do a nice lil animation when board starts up
  int leds[] = { LED_1, LED_2, LED_3 };
  int tones[] = { 600, 900, 1200 };
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
    tone(BUZZER, tones[i], 80);
    delay(120);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  // for button 1 (copy key):
  if (digitalRead(BTN_1) == LOW) {
    digitalWrite(LED_1, HIGH);
    tone(BUZZER, 1200, 60);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(50);
    Keyboard.releaseAll();
    while (digitalRead(BTN_1) == LOW);
    delay(20);
    digitalWrite(LED_1, LOW);
  }

  // for button 2 (paste key): 
  if (digitalRead(BTN_2) == LOW) {
    digitalWrite(LED_2, HIGH);
    tone(BUZZER, 900, 60);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(50);
    Keyboard.releaseAll();
    while (digitalRead(BTN_2) == LOW);
    delay(20);
    digitalWrite(LED_2, LOW);
  }

  // for button 3 (enter key): 
  if (digitalRead(BTN_3) == LOW) {
    digitalWrite(LED_3, HIGH);
    tone(BUZZER, 600, 60);
    Keyboard.press(KEY_RETURN);
    delay(50);
    Keyboard.releaseAll();
    while (digitalRead(BTN_3) == LOW);
    delay(20);
    digitalWrite(LED_3, LOW);
  }
}
