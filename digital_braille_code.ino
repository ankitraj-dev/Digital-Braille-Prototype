// Braille character mapping (6-dot representation)
int braille[26][6] = {
  {1,0,0,0,0,0},  {1,1,0,0,0,0},  {1,0,0,1,0,0},  {1,0,0,1,1,0},  {1,0,0,0,1,0},
  {1,1,0,1,0,0},  {1,1,0,1,1,0},  {1,1,0,0,1,0},  {0,1,0,1,0,0},  {0,1,0,1,1,0},
  {1,0,1,0,0,0},  {1,1,1,0,0,0},  {1,0,1,1,0,0},  {1,0,1,1,1,0},  {1,0,1,0,1,0},
  {1,1,1,1,0,0},  {1,1,1,1,1,0},  {1,1,1,0,1,0},  {0,1,1,1,0,0},  {0,1,1,1,1,0},
  {1,0,1,0,0,1},  {1,1,1,0,0,1},  {0,1,0,1,1,1},  {1,0,1,1,0,1},  {1,0,1,1,1,1},
  {1,0,1,0,1,1}
};

// Arduino pins connected to solenoids
int controlPins[6] = {2,3,4,5,6,7};

// Button to advance letters (Already fixed in your circuit)
int buttonPin = 8;

// Reset button
int resetPin = 9;

// Text to display in Braille
String text = "i am Ankit raj";  // Includes spaces

// Variable to track current letter index
int currentIndex = 0;

// Length of the text
int length = text.length();

void setup(){
  Serial.begin(9600);

  // Set solenoid control pins as outputs
  for(int i = 0; i < 6; i++){
    pinMode(controlPins[i], OUTPUT);
  }

  // Set buttons as inputs with pull-up resistors
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
}

void loop(){
  // If reset button is pressed, restart from first letter
  if (digitalRead(resetPin) == LOW) {  
    Serial.println("Resetting...");
    delay(500);  // Debounce
    currentIndex = 0;  // Start from first letter

    // Turn OFF all solenoids
    for (int k = 0; k < 6; k++) {
      digitalWrite(controlPins[k], LOW);
    }

    // Wait until reset button is released to prevent accidental multiple resets
    while (digitalRead(resetPin) == LOW);
    delay(500);  // Debounce

    return;  // Immediately restart loop() to apply reset
  }

  // Ensure it loops through full text, no skipping
  if (currentIndex >= length) {
    Serial.println("End of text. Waiting for restart...");

    // Wait for button press before restarting
    while (digitalRead(buttonPin) == HIGH);
    delay(500);  // Debounce

    currentIndex = 0;  // Restart the loop after completing full text
    return;
  }

  // Get the current character
  char letter = text[currentIndex];

  // Handle spaces
  if (letter == ' ') {
    Serial.println("Space detected. Waiting...");

    // Turn ON all solenoids (simulating a pause)
    for (int k = 0; k < 6; k++) {
      digitalWrite(controlPins[k], HIGH);
    }

    // Wait for button press before moving on
    while (digitalRead(buttonPin) == LOW);
    delay(1000);  // Debounce

    // Move to the next letter after space pause
    currentIndex++;
    return;  // Skip the normal letter processing
  }

  // Convert letter to Braille index
  int index = tolower(letter) - 'a';  

  // Print for debugging
  Serial.print("Displaying: ");
  Serial.print(letter);
  Serial.print(" (Index: ");
  Serial.print(index);
  Serial.println(")");

  // Activate solenoids
  for (int k = 0; k < 6; k++) {
    digitalWrite(controlPins[k], braille[index][k]);
  }

  // Wait for the advance button press before moving to next letter
  while (digitalRead(buttonPin) == LOW);  // Wait for button press
  delay(1000);  // Debounce
  
  // Move to the next letter
  currentIndex++;  
}
