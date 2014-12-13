/*
  Détection du rapport cyclique d'un signal rectangulaire

  On cherche à réaliser un dispositif avec une entrée et deux sorties. 
  L'entrée reçoit un signal rectangulaire, dont la fréquence est de 1 à 100 Hz. 
  La première sortie doit s'activer si le rapport cyclique est inférieur à 40%, 
    la seconde s'il est supérieur à 60%. S'il n'y a pas de signal, 
    ou si le signal est carré, aucune sortie ne doit s'activer.

  Comme d'habitude, utilisez P1 comme entrée, L1 et L2 comme sorties.

  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    Poussoir P2: pin3 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int P1 = 2;    // Input P1 on pin2 with pull-up
const int L1 = 4;    // LED L1 on pin4
const int L2 = 5;    // LED L2 on pin5

int P1_state = 0;

float high_count = 0.0;
float low_count = 0.0;
float ratio = 0.0;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(P1, INPUT);
  Serial.begin(9600);
  // init L1 and L2 as LOW
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
}


void loop(){

  // read P1 high-low for 1s, 1000 samples
  for (int i = 0; i<1000; i++){
    P1_state = digitalRead(P1);
    if (P1_state == LOW) {
      low_count += 1;
    } else {
      high_count += 1;
    }
    delay(1);
  }
  
  // compute the high/low ratio
  if ((high_count == 0) || (low_count == 0)) {
    ratio = 0.0;
    Serial.println("no signal");
    Serial.print("high_count: ");
    Serial.print(high_count);
    Serial.print(", low_count: ");
    Serial.println(low_count);
  } else {
    ratio = high_count / (low_count + high_count);
    Serial.println(ratio);  
  }
  
  // take signal
  if (ratio == 0.0) {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  } else if (ratio <= 0.4) {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  } else if (ratio >= 0.6) {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  } else {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  }
  
  // reset counter
  high_count = 0;
  low_count = 0;
}
