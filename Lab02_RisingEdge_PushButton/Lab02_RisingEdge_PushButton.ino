/*
  Edge Detection using Push Button 
  -----------------------------------------------------------------------------

  Write a program to switch ON the built-In LED with rising edge of push button.

    The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground (or use the built-in LED on most
    Arduino boards)

  created  5 Sep 2021
  by Atta ul Wasay

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 8;       // the pin that the LED is attached to

// Variables will change:
int CurrentbuttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  CurrentbuttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (CurrentbuttonState != lastButtonState) {
    // if the state has changed, turn ON the led
    if (CurrentbuttonState == HIGH) {
      // if the current state is HIGH then the button went from OFF to ON (Rising Edge):
      digitalWrite(ledPin, HIGH);
      Serial.print("Rising Edge");
      Serial.print("\t");
      Serial.println("LED is ON");
     

    } else {
      // if the current state is LOW then the button went from ON to OFF (Falling Edge):
      digitalWrite(ledPin, LOW);
      Serial.print("Falling Edge");
      Serial.print("\t");
      Serial.println("LED is OFF");
      
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = CurrentbuttonState;
     

}
