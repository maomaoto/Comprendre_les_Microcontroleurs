/*
  Remplissage d'une bouteille avec apprentissage du temps

  Dans un atelier artisanal de production de boissons, 
  on cherche à accélérer la production. Deux boutons vont permettre de remplir une bouteille : 
  - P1 doit être pressé pour activer la vanne de remplissage et maintenu pressé jusqu'à ce que la bouteille soit pleine. 
    Le système apprends alors le temps de remplissage adapté à ce type de bouteilles. 
  - P2 peut ensuite être simplement pressé et relâché : la bouteille va se remplir pendant la durée apprise.

  L1 est utilisé pour la commande de la vanne de remplissage.

  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    Poussoir P2: pin3 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int P1 = 2;    // Input P1 on pin2 with pull-up
const int P2 = 3;    // Input P2 on pin3 with pull-up
const int L1 = 4;    // LED L1 on pin4
const int L2 = 5;    // LED L2 on pin5

int P1_state = HIGH;
int old_P1_state = HIGH;
int P2_state = HIGH;
int old_P2_state = HIGH;

int P1_count = 0;
int P2_count = 0;
boolean P2_flag = false;  // true if P2 rising edge detected
float ratio = 0.0;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  Serial.begin(9600);
  // init L1 and L2 as LOW
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
}


void loop(){
  
  P1_state = digitalRead(P1);
  P2_state = digitalRead(P2);
  
  if (P1_state == LOW) {
    if (old_P1_state == HIGH) {  // P1 rising edge -> reset counter
      P1_count = 1;  
      Serial.println("1");
    } else {
      P1_count += 1;
      Serial.println("2");
    }
    digitalWrite(L1, HIGH);
    delay(1);
  } else {  // if P1 is active, ignore P2 action
    digitalWrite(L1, LOW);
    if (P2_state == LOW) {
      Serial.println("3");
      if (old_P2_state == HIGH) {  // P2 rising edge
        Serial.println("4");
        P2_flag = true;
        for (int i = 0; i<P1_count; i++){
            digitalWrite(L1, HIGH);
            delay(1);
        }
      }
    } else {
      if (old_P2_state == LOW) {  // P2 falling edge
        if (P2_flag == true) {  // falling edge with rising edge detected, turn on L1 with the period pressing P1
//          for (int i = 0; i<P1_count; i++){
//            digitalWrite(L1, HIGH);
//            delay(1);
//          }
//          digitalWrite(L1, LOW);
//          Serial.println("5");
        }
        P2_flag = false;
      }
    }
  }
  
  old_P1_state = P1_state;
  old_P2_state = P2_state;
  
}
