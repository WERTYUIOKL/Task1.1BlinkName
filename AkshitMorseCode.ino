#include "thingProperties.h"

const int ledPin = LED_BUILTIN;

const int dotDuration = 200; // // Duration of a dot in milliseconds
const int dashDuration = 3 * dotDuration; // // Duration of a dash(i.e. 3 times a dot duration)
const int elementSpace = dotDuration; // space between elements(i.e. dot and dash)
const int letterSpace = 3 * dotDuration; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); //sets the led pin as an output
  pinMode(2,INPUT_PULLUP); //set pin 2 as an input with a pull-up resistor

  delay(1500); // provide a delay 1.5 seconds

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection); // connects the arduino to the iot cloud
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update(); 

  Serial.print("LED Value: ");
  Serial.println(led); // Print the current value of the LED
  int switchpin = digitalRead(2); // Read the state of the switch connected to pin 2 

   // If the switch is pressed, blink the Morse code for "A", "K", "S", "H", "I", and "T"
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
  Serial.println("LED state changed from IoT Cloud"); // Notify that LED state has changed 
}

// Function to blink a dot in Morse code
void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(elementSpace);
}

// Function to blink a dash in Morse code
void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(elementSpace);
}

// Function to blink the Morse code for the letter 'A' (.-)
void blinkA() {
  blinkDot();
  blinkDash();
  delay(letterSpace);
}

// Function to blink the Morse code for the letter 'K' (-.-)
void blinkK() {
  blinkDash();
  blinkDot();
  blinkDash();
  delay(letterSpace);
}

// Function to blink the Morse code for the letter 'S' (...)
void blinkS() {
  blinkDot();
  blinkDot();
  blinkDot();
  delay(letterSpace);
}

// Function to blink the Morse code for the letter 'H' (....)
void blinkH() {
  blinkDot();
  blinkDot();
  blinkDot();
  blinkDot();
  delay(letterSpace);
}

// Function to blink the Morse code for the letter 'I' (..)
void blinkI() {
  blinkDot();
  blinkDot();
  delay(letterSpace);
}

// Function to blink the Morse code for the letter 'T' (-)
void blinkT() {
  blinkDash();
  delay(letterSpace);
}
