
String state;
int green = 7;
int yellow = 6;
int pink = 5;

void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(pink, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(10);
    char c = Serial.read();

    if (c == '#') {
      break;
    }
    state += c;
  }

  if (state.length() > 0) {
    Serial.println(state);

    if (state == "turn on leds") {
      pinkOn();
      yellowOn();
      greenOn();
    } else if (state == "turn off leds") {
      pinkOff();
      yellowOff();
      greenOff();
    } else if (state == "blink alternately") {
      blinkAlternately();
    } else if (state == "green") {
      greenOn();
    } else if (state == "turn off green") {
      greenOff();
    } else if (state == "yellow") {
      yellowOn();
    } else if (state == "turn off yellow") {
      yellowOff();
    } else if (state == "pink") {
      pinkOn();
    } else if (state == "turn off pink") {
      pinkOff();
    }
    state = "";
  } 
}

void blinkAlternately() {
  pinkOn();
  delay(500);
  pinkOff();
  delay(500);
  yellowOn();
  delay(500);
  yellowOff();
  delay(500);
  greenOn();
  delay(500);
  greenOff();
  delay(500);
  pinkOn();
  delay(500);
  pinkOff();
  delay(500);
  yellowOn();
  delay(500);
  yellowOff();
  delay(500);
  greenOn();
  delay(500);
  greenOff();
  delay(500);
}

void pinkOn() {
  digitalWrite(pink, HIGH);
}

void pinkOff() {
  digitalWrite(pink, LOW);
}

void yellowOn() {
  digitalWrite(yellow, HIGH);
}

void yellowOff() {
  digitalWrite(yellow, LOW);
}

void greenOn() {
  digitalWrite(green, HIGH);
}

void greenOff() {
  digitalWrite(green, LOW);
}
