const int motor = 2;
const int cinturon = 3;
const int led = 13;

void setup() {
  pinMode(cinturon, INPUT);
  pinMode(motor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if(digitalRead(motor) == LOW && digitalRead(cinturon) == HIGH) {
      digitalWrite(led, HIGH);
      beep(100);
    } else {
      digitalWrite(led, LOW);  
    }
}

 void beep(unsigned char pausa)
        {
            analogWrite(9, 20);
            delay(pausa);                 // Espera
            analogWrite(9, 0);            // Apaga
            delay(pausa);                 // Espera
        }
