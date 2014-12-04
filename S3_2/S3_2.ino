/*
  SOS du Titanic !

  Le programme doit produire un signal de détresse lumineux en code Morse, sur la Led L1. 
  Voici la succession des traits et des point pour former "S O S" : - - - . . . - - - 
  (Actuellement, les codes des lettre S et O ont été inversés...)
  Le message doit être répété toutes les 2 secondes.

  Voici les contraintes temporelles : 
    - durée d'un point (dot) : 0.2s 
    - durée d'un trait (dash) : 0.6s 
    - espace entre traits ou points : 0.2s 
    - espace entre lettres : 0.6s 
    - espace entre mots : 1.4s
  
  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    Poussoir P2: pin3 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int L1 = 4;    // LED L1 on pin4

void setup() {
  pinMode(L1, OUTPUT);
}



void point(int LED){
  digitalWrite(LED, HIGH);
  delay(200);
}

void trait(int LED){
  digitalWrite(LED, HIGH);
  delay(600);
}

void espace_signal(int LED){
  digitalWrite(LED, LOW);
  delay(200);
}

void espace_lettre(int LED){
  digitalWrite(LED, LOW);
  delay(600);
}

void espace_mot(int LED){
  digitalWrite(LED, LOW);
  delay(1400);
}

void morse_S(int LED){
  trait(LED);
  espace_signal(LED);
  trait(LED);
  espace_signal(LED);
  trait(LED);
}

void morse_O(int LED){
  point(LED);
  espace_signal(LED);
  point(LED);
  espace_signal(LED);
  point(LED);
}

void loop(){
  morse_S(L1);
  espace_lettre(L1);
  morse_O(L1);
  espace_lettre(L1);
  morse_S(L1);
  espace_mot(L1);
}
