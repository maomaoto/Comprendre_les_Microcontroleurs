/*
  Ligne série

  Encore un SOS ! Mais cette fois, 
  c'est sur un ligne série asynchrone que vous devez envoyer les trois caractères, en code ASCII. 
  
  La sortie à utiliser est L1, pour vous permettre de contrôler votre programme à faible vitesse, 
  avant de le régler à une vitesse de 300 bauds (durée d'un bit 3.33 ms). 
  
  Attendez environ une seconde entre chaque SOS.

  really wired, need to inverse bits for pass 

  LearnCbot assignment:
    Poussoir P1: pin2 with pull-up resistor
    Poussoir P2: pin3 with pull-up resistor
    LED L1: pin4, active high
    LED L2: pin5, active high
*/

const int L1 = 4;    // LED L1 on pin4

void setup() {
  pinMode(L1, OUTPUT);
  Serial.begin(9600);
  digitalWrite(L1, HIGH);  // initial L1 as HIGH
}



void letter(int LED, char letter, int duration) {
  Serial.println(letter);
//  digitalWrite(LED, LOW);  // Start bit
  DDRD |= (1<<4);
  PORTD &= ~(1<<4);
  delayMicroseconds(duration);
  
  for (int i = 0; i<8; i++ ) {  // Send letter for lower bit
    if (letter & (1<<i)) {
//    digitalWrite(LED, HIGH);
//    Serial.println("HIGH");
      DDRD |= (1<<4);
//      PORTD |= (1<<4);
      PORTD &= ~(1<<4);
    } else {
//    digitalWrite(LED, LOW);
//    Serial.println("LOW");
      DDRD |= (1<<4);
//      PORTD &= ~(1<<4);
      PORTD |= (1<<4);
    }
    delayMicroseconds(duration);
  }
  
//  digitalWrite(LED, HIGH);  // 2 Stop bits
  DDRD |= (1<<4);
  PORTD |= (1<<4);
  delayMicroseconds(duration);
  delayMicroseconds(duration);
}

void loop(){
  digitalWrite(L1, HIGH);  // for delay between two words
  delay(1000);
  letter(L1, 'S', 3000);
//  digitalWrite(L1, HIGH);
//  delay(333);
  letter(L1, 'O', 3000);
//  digitalWrite(L1, HIGH);
//  delay(333);
  letter(L1, 'S', 3000);
//  digitalWrite(L1, HIGH);  // for delay between two words
//  delay(1000);
}
