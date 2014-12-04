/*
  Commande d'un moteur pas-à-pas

  Press P1: faire tourner le moteur dans le sans horaire
  Press P2: faire tourner le moteur dans le sans anti-horaire
  
  Sequence horaire: (L1, L2): (0, 0) -> (1, 0) -> (1, 1) -> (0, 1)
  Sequence anti-horaire: (L1, L2): (0, 0) -> (0, 1) -> (1, 1) -> (1, 0)
  
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

enum {STATE_1, STATE_2, STATE_3, STATE_4};  // STATE_1: (L1, L2)=(0, 0); etc. 
int curr_state = STATE_1;

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
  // read the state of input pins
  P1_state = digitalRead(P1);
  P2_state = digitalRead(P2);
  
  if (P1_state == LOW) {
    // dans le sans horaire
    // (L1, L2): (0, 0) -> (1, 0) -> (1, 1) -> (0, 1)
    switch (curr_state) {
      case (STATE_1):
        digitalWrite(L1, HIGH);
        digitalWrite(L2, LOW);
        curr_state = STATE_2;
        break;
      case (STATE_2):
        digitalWrite(L1, HIGH);
        digitalWrite(L2, HIGH);
        curr_state = STATE_3;
        break;
      case (STATE_3):
        digitalWrite(L1, LOW);
        digitalWrite(L2, HIGH);
        curr_state = STATE_4;
        break;
      case (STATE_4):
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        curr_state = STATE_1;
        break;
    }
  }
  
  if (P2_state == LOW) {
    // dans le sans anti-horaire
    // (L1, L2): (0, 0) <- (1, 0) <- (1, 1) <- (0, 1)
    switch (curr_state) {
      case (STATE_1):
        digitalWrite(L1, LOW);
        digitalWrite(L2, HIGH);
        curr_state = STATE_4;
        break;
      case (STATE_2):
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        curr_state = STATE_1;
        break;
      case (STATE_3):
        digitalWrite(L1, HIGH);
        digitalWrite(L2, LOW);
        curr_state = STATE_2;
        break;
      case (STATE_4):
        digitalWrite(L1, HIGH);
        digitalWrite(L2, HIGH);
        curr_state = STATE_3;
        break;
    }
  }
  
  delay(1);
}
