// Keystorm X3 — the firmware

#define BTN_1  D0   // switch 1
#define BTN_2  D1   // switch 2
#define BTN_3  D2   // switch 3

#define LED_GREEN   D3   // GREEN LED
#define LED_YELLOW  D4   // YELLOW LED
#define LED_RED     D5   // RED LED

#define BUZZER  D6

void setup() {
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  // when the board starts
  int leds[]  = { LED_GREEN, LED_YELLOW, LED_RED };
  int notes[] = { 600, 900, 1200 };
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
    tone(BUZZER, notes[i], 80);
    delay(120);
    digitalWrite(leds[i], LOW);
  }
}

// beep function
void chirp(int freq, int beeps) {
  for (int i = 0; i < beeps; i++) {
    tone(BUZZER, freq, 70);
    delay(110);
  }
}

void loop() {
  if (digitalRead(BTN_1) == LOW) {
    digitalWrite(LED_GREEN, HIGH);
    chirp(988, 2);
    while (digitalRead(BTN_1) == LOW);
    digitalWrite(LED_GREEN, LOW);
    delay(20);
  }

  if (digitalRead(BTN_2) == LOW) {
    digitalWrite(LED_YELLOW, HIGH);
    chirp(1568, 2);
    while (digitalRead(BTN_2) == LOW);
    digitalWrite(LED_YELLOW, LOW);
    delay(20);
  }

  if (digitalRead(BTN_3) == LOW) {
    digitalWrite(LED_RED, HIGH);
    chirp(300, 2);
    while (digitalRead(BTN_3) == LOW);
    digitalWrite(LED_RED, LOW);
    delay(20);
  }
}
