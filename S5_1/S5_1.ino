/*
Lecture analogique

Votre programme doit lire une valeur analogique et afficher dans quel intervalle elle se trouve par rapport à la tension d'alimentation :
- entre 0 et 25 % : L1 et L2 doivent être éteintes
- entre 25 et 50 % : seule L1 doit être allumée 
- entre 50 et 75 % : seule L2 doit être allumée
- entre 75 et 100 % : L1 et L2 doivent être allumées

Sur l'Arduino, utilisez la patte A1 comme entrée analogique. Sur le Launchpad, utilisez P1_7.
  
  
  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    Poussoir P2: pin3 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int P1 = 2;  // l'entree on pin2
const int P2 = 3;  // la sortie on pin3
const int L1 = 4;    // LED L1 on pin4
const int L2 = 5;    // LED L2 on pin5
const int sensorPin = A1;  // use A1 as analog input

int curr_state = 0;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  Serial.begin(9600);
  // init as STATE_1, (L1, L2) = (0, 0)
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
}

void loop(){
  curr_state = analogRead(sensorPin);
  if (curr_state <= 255) {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  } else if (curr_state <=511) {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  } else if (curr_state <= 767) {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  } else {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
  }  
  delay(10);
}
