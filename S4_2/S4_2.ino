/*
Serrure codée

Pour allumer la Led L1, il faut successivement : 
  - appuyer sur P1 
  - relâcher P1 
  - appuyer à nouveau sur P1 
  - appuyer sur P2 (sans relâcher P1) 
  - relâcher P2 
  - relâcher P1. C'est alors que L1 doit s'allumer durant trois seconde.
  
  -> transform into state machine
  - State1: init state
  - State1 -> 2: P1 LOW, P2 HIGH
  - State2 -> 3: P1 HIGH, P2 HIGH
  - State3 -> 4: P1 LOW, P2 HIGH
  - State4 -> 5: P1 LOW, P2 LOW
  - State5 -> 6: P1 LOW, P2 HIGH
  - State6 -> 7: P1 HIGH, P2 HIGH
  - State7: L1 HIGH pendent trois seconde, apres -> State1
  
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

enum {STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, STATE_7};  
int curr_state = STATE_1;
unsigned long last_action_time;
unsigned long duration;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  Serial.begin(9600);
  // init as STATE_1, (L1, L2) = (0, 0)
  digitalWrite(L1, LOW);
  last_action_time = millis();
  duration = 0;
}

void loop(){
  // read the state of input pins
  P1_state = digitalRead(P1);
  P2_state = digitalRead(P2);
  duration = millis() - last_action_time;
  switch (curr_state) {
    case(STATE_1):
      if ((P1_state == LOW) && (P2_state == HIGH)) {
        curr_state = STATE_2;
      }
      break;
    case(STATE_2):
      if ((P1_state == HIGH) && (P2_state == HIGH)) {
        curr_state = STATE_3;
      }
      break;
    case(STATE_3):
      if ((P1_state == LOW) && (P2_state == HIGH)) {
        curr_state = STATE_4;
      }
      break;
    case(STATE_4):
      if ((P1_state == LOW) && (P2_state == LOW)) {
        curr_state = STATE_5;
      }
      break;
    case(STATE_5):
      if ((P1_state == LOW) && (P2_state == HIGH)) {
        curr_state = STATE_6;
      }
      break;
    case(STATE_6):
      if ((P1_state == HIGH) && (P2_state == HIGH)) {
        curr_state = STATE_7;
      }
      break;
    case(STATE_7):
      digitalWrite(L1, HIGH);
      delay(3000);
      digitalWrite(L1, LOW);
      delay(1000);
      break;
  }  
  delay(1);
}
