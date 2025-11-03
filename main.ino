const int redPin = 25;
const int greenPin = 26;
const int bluePin = 27;
const int buttonPin = 4;

int colorIndex = 0;
bool lastButtonState = HIGH;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  setColor(colorIndex);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    colorIndex = (colorIndex + 1) % 7; 
    setColor(colorIndex);
    delay(200); // debounce
  }
  lastButtonState = buttonState;
}

void setColor(int index) {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  switch(index) {
    case 0: digitalWrite(redPin, HIGH); break;           // Red
    case 1: digitalWrite(greenPin, HIGH); break;         // Green
    case 2: digitalWrite(bluePin, HIGH); break;          // Blue
    case 3: digitalWrite(redPin, HIGH); digitalWrite(greenPin, HIGH); break;   // Yellow
    case 4: digitalWrite(greenPin, HIGH); digitalWrite(bluePin, HIGH); break;  // Cyan
    case 5: digitalWrite(redPin, HIGH); digitalWrite(bluePin, HIGH); break;    // Magenta
    case 6: digitalWrite(redPin, HIGH); digitalWrite(greenPin, HIGH); digitalWrite(bluePin, HIGH); break; // White
  }
}
