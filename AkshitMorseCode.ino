#include "thingProperties.h"

const int ledPin = LED_BUILTIN;

const int dotDuration = 200;
const int dashDuration = 3 * dotDuration;
const int elementSpace = dotDuration;
const int letterSpace = 3 * dotDuration;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(2,INPUT_PULLUP);

  delay(1500);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  Serial.print("LED Value: ");
  Serial.println(led);
  int switchpin = digitalRead(2);
  if (!switchpin) {
    blinkA();
    blinkK();
    blinkS();
    blinkH();
    blinkI();
    blinkT();
  }
}

void onLedChange() {
  Serial.println("LED state changed from IoT Cloud");
}

void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(elementSpace);
}

void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(elementSpace);
}

void blinkA() {
  blinkDot();
  blinkDash();
  delay(letterSpace);
}

void blinkK() {
  blinkDash();
  blinkDot();
  blinkDash();
  delay(letterSpace);
}

void blinkS() {
  blinkDot();
  blinkDot();
  blinkDot();
  delay(letterSpace);
}

void blinkH() {
  blinkDot();
  blinkDot();
  blinkDot();
  blinkDot();
  delay(letterSpace);
}

void blinkI() {
  blinkDot();
  blinkDot();
  delay(letterSpace);
}

void blinkT() {
  blinkDash();
  delay(letterSpace);
}
