/*
  Feu a l'entree d'un parking
  Pous1: la barriere placee a l'entree
  Pous2: la barriere placee a la sortie
  LED L1: allumer si le parking est plein
  LED L2: allumer si le parking est vide
  Il y a 5 places dans le parking
  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    Poussoir P2: pin3 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int enterPin = 2;  // l'entree on pin2
const int leavePin = 3;  // la sortie on pin3
const int L1Pin = 4;    // LED L1 on pin4
const int L2Pin = 5;    // LED L2 on pin5

int enterState = 0;  // variable for reading the enterPin status
int leaveState = 0;  // variable for reading the leavePin status
int numberCar = 0;   // number of cars in the parking


void setup() {
  pinMode(L1Pin, OUTPUT);
  pinMode(L2Pin, OUTPUT);
  pinMode(enterPin, INPUT);
  pinMode(leavePin, INPUT);
  Serial.begin(9600);
}

void loop(){
  // read the state of input pins
  enterState = digitalRead(enterPin);
  leaveState = digitalRead(leavePin);
  
  if (enterState == LOW) {
    if ( numberCar < 5) {
      numberCar += 1;
    }
  }
  
  if (leaveState == LOW) {
    if (numberCar > 0) {
      numberCar -=1;
    }
  }
  
  if (numberCar == 5) {
    digitalWrite(L1Pin, HIGH);
  } else {
    digitalWrite(L1Pin, LOW);
  }
  
  if (numberCar == 0) {
    digitalWrite(L2Pin, HIGH);
  } else {
    digitalWrite(L2Pin, LOW);
  }
  
  Serial.println(numberCar);
  delay(20);
}
