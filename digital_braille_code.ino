#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

// --- Pin mapping (Standard Braille: 1-2-3 left, 4-5-6 right) ---
int dots[6] = {16, 14, 26, 13, 27, 25};

// --- Braille patterns for a–z ---
bool braille[][6] = {
  {1,0,0,0,0,0}, // a
  {1,1,0,0,0,0}, // b
  {1,0,0,1,0,0}, // c
  {1,0,0,1,1,0}, // d
  {1,0,0,0,1,0}, // e
  {1,1,0,1,0,0}, // f
  {1,1,0,1,1,0}, // g
  {1,1,0,0,1,0}, // h
  {0,1,0,1,0,0}, // i
  {0,1,0,1,1,0}, // j
  {1,0,1,0,0,0}, // k
  {1,1,1,0,0,0}, // l
  {1,0,1,1,0,0}, // m
  {1,0,1,1,1,0}, // n
  {1,0,1,0,1,0}, // o
  {1,1,1,1,0,0}, // p
  {1,1,1,1,1,0}, // q
  {1,1,1,0,1,0}, // r
  {0,1,1,1,0,0}, // s
  {0,1,1,1,1,0}, // t
  {1,0,1,0,0,1}, // u
  {1,1,1,0,0,1}, // v
  {0,1,0,1,1,1}, // w
  {1,0,1,1,0,1}, // x
  {1,0,1,1,1,1}, // y
  {1,0,1,0,1,1}  // z
};

// --- Timing constants ---
const unsigned long LETTER_HOLD_MS   = 2000; // letter stays ON
const unsigned long LETTER_GAP_MS    = 300;  // short blank gap
const unsigned long SPACE_PAUSE_MS   = 3000; // space pause

// --- State machine variables ---
enum State { IDLE, LETTER_ON, LETTER_OFF, SPACE_PAUSE };
State state = IDLE;

String text = "";
int letterIndex = 0;
unsigned long stateStart = 0;

void allOff() {
  for (int i = 0; i < 6; i++) digitalWrite(dots[i], LOW);
}

void showLetter(char c) {
  allOff();
  if (c < 'a' || c > 'z') return;
  int id = c - 'a';
  for (int i = 0; i < 6; i++) digitalWrite(dots[i], braille[id][i] ? HIGH : LOW);

  Serial.print("Letter: ");
  Serial.println(c);
}

// --- Setup ---
void setup() {
  Serial.begin(115200);
  SerialBT.begin("Braille_Display");
  for (int i = 0; i < 6; i++) {
    pinMode(dots[i], OUTPUT);
    digitalWrite(dots[i], LOW);
  }
  Serial.println("✅ Ready. Send text via Bluetooth.");
}

// --- Main loop ---
void loop() {
  // --- 1️⃣ Handle incoming text immediately ---
  if (SerialBT.available()) {
    String incoming = "";
    while (SerialBT.available()) {
      incoming += (char)SerialBT.read();
      delay(2);
    }
    incoming.trim();
    incoming.toLowerCase();

    if (incoming.length() > 0) {
      Serial.print("📨 New text received: ");
      Serial.println(incoming);
      text = incoming;
      letterIndex = 0;
      state = IDLE;
      allOff();
    }
  }

  // --- 2️⃣ State machine ---
  unsigned long now = millis();

  switch (state) {
    case IDLE:
      if (text.length() > 0 && letterIndex < text.length()) {
        char c = text[letterIndex];
        if (c == ' ') {
          Serial.println("[Space]");
          allOff();
          state = SPACE_PAUSE;
          stateStart = now;
        } else if (c >= 'a' && c <= 'z') {
          showLetter(c);
          state = LETTER_ON;
          stateStart = now;
        } else {
          letterIndex++; // skip invalids
        }
      }
      break;

    case LETTER_ON:
      if (now - stateStart >= LETTER_HOLD_MS) {
        allOff();
        state = LETTER_OFF;
        stateStart = now;
      }
      break;

    case LETTER_OFF:
      if (now - stateStart >= LETTER_GAP_MS) {
        letterIndex++;
        state = IDLE; // move to next
      }
      break;

    case SPACE_PAUSE:
      if (now - stateStart >= SPACE_PAUSE_MS) {
        letterIndex++;
        state = IDLE;
      }
      break;
  }
}
