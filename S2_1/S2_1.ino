/*
  Sequence L1-L2
  Press P1 -> L1 light 1sec -> L1/L2 light 1sec -> L2 light 1sec -> L1/L2 off
  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int buttonPin = 2;  // pushbutton on pin2
const int L1Pin = 4;    // LED L1 on pin4
const int L2Pin = 5;    // LED L2 on pin5

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  pinMode(L1Pin, OUTPUT);
  pinMode(L2Pin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  // read the state of pushbutton
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    digitalWrite(L1Pin, HIGH);
    delay(1000);
    digitalWrite(L2Pin, HIGH);
    delay(1000);
    digitalWrite(L1Pin, LOW);
    delay(1000);
    digitalWrite(L2Pin, LOW);
  }
}
