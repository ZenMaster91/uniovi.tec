/*
Robot TEC: declaración de constantes
*/
// los pines digitales 2 y 3 controlan el motor derecho
const int In1 = 2; // pin motor derecho
const int In2 = 3; // pin motor derecho
// los pines digitales 4 y 5 controlan el motor izquierdo
const int In3 = 4; // pin motor izquierdo
const int In4 = 5; // pin motor izquierdo
//los pines digitales 9 y 10 habilitan los motores
const int ENA = 9; // habilita el motor derecho
const int ENB = 10; // habilita el motor izquierdo
//configuración de señales para el movimiento de los motores
//giro hacia adelante del motor derecho
//In1=HIGH In2=LOW
//giro hacia adelante del motor izquierdo
//In3=HIGH In4=LOW
//giro hacia atrás del motor derecho
//In1=LOW In2=HIGH
//giro hacia atrás del motor izquierdo
//In3=LOW In4= HIGH
//Parar el motor derecho
//In1= In2
//Parar el motor izquierdo
//In3= In4 
const int PhotoSensorLeft = 6; // pin del Arduino conectado al sensor óptico Izquierdo
const int PhotoSensorRight = 7; // pin del Arduino conectado al sensor óptico Derecho
// constantes
const int BLANCO = 0;
const int NEGRO = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(PhotoSensorLeft, INPUT);
  pinMode(PhotoSensorRight, INPUT);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  analogWrite(ENA,1000);
  analogWrite(ENB,1000);

}

void loop() {
  //parar();
  programa2();
}

void programa1() {
  //parar();
  if(digitalRead(PhotoSensorLeft)==NEGRO && digitalRead(PhotoSensorRight)==NEGRO) {
      avanza();
      delay(50);
    } else if (digitalRead(PhotoSensorLeft)==BLANCO && digitalRead(PhotoSensorRight)==NEGRO) {
      derecha();  
      delay(50);
    } else if (digitalRead(PhotoSensorLeft)==NEGRO && digitalRead(PhotoSensorRight)==BLANCO) {
      izquierda();
      delay(50);
    } else if(digitalRead(PhotoSensorLeft)==BLANCO && digitalRead(PhotoSensorRight)==BLANCO) {
      atras();
      delay(50);
    }  
}

void programa2() {
  //parar();
  if(digitalRead(PhotoSensorLeft)==NEGRO && digitalRead(PhotoSensorRight)==NEGRO) {
      derecha();
      delay(50);
    } else if (digitalRead(PhotoSensorLeft)==BLANCO && digitalRead(PhotoSensorRight)==NEGRO) {
      avanza();  
      delay(50);
    } else if (digitalRead(PhotoSensorLeft)==NEGRO && digitalRead(PhotoSensorRight)==BLANCO) {
      avanza();
      delay(50);
    } else if(digitalRead(PhotoSensorLeft)==BLANCO && digitalRead(PhotoSensorRight)==BLANCO) {
      izquierda();
      delay(50);
    }  
}

void parar() {
    digitalWrite(In1,LOW);
    digitalWrite(In2,LOW);
    digitalWrite(In3,LOW);
    digitalWrite(In4,LOW); 
}

void avanza() {
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW); 
}

void atras() {
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH); 
}

void izquierda() {
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH); 
}

void derecha() {
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW); 
}
