/*
  Statistique des poussoirs

  On presse alternativement et irrégulièrement sur le poussoir P1 et sur le poussoir P2.
  Le programme doit allumer L1 si on a pressé plus souvent sur P1, et L2 si c'est le contraire.
  Le correcteur enverra des "pression" sur P1 et P2 d'une durée d'environ 0.2s, séparées par une demi-seconde.
  
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

int P1_state = 0;
int P2_state = 0;

int P1_count = 0;
int P2_count = 0;



void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  Serial.begin(9600);
}

void loop(){
  // read the state of input pins
  P1_state = digitalRead(P1);
  P2_state = digitalRead(P2);
  
  if (P1_state == LOW) {
    P1_count += 1;
  }
  
  if (P2_state == LOW) {
    P2_count += 1;
  }
  
  if (P1_count > P2_count) {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  } else {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  }
    
  delay(150);
}
