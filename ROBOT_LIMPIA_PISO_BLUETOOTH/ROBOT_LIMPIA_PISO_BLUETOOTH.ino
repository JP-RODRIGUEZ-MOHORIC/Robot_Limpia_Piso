#include <SoftwareSerial.h>
SoftwareSerial bt (1, 0); //RX, TX (Conectados a Bluetooth de esta forma RX -> TX | TX -> RX)
//MOTOR IZQUIERDO
#define MOTOR_1A 5 
#define MOTOR_1B 6
#define PIN_ENA 9
//MOTOR DERECHO
#define MOTOR_2A 7
#define MOTOR_2B 8
#define PIN_ENB 10
const int speed = 100;
int PULSADOR;
char btdata;
#define BOTON_AVANZAR 'a'
#define BOTON_RETROCEDER 'e'
#define BOTON_IZQUIERDA 'b'
#define BOTON_DERECHA 'd'
#define BOTON_DETENIDO 'c'

void setup() {
  bt.begin(9600);
  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_1B, OUTPUT);
  pinMode(MOTOR_2A, OUTPUT);
  pinMode(MOTOR_2B, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(13, INPUT_PULLUP);
}
void loop() {
  PULSADOR = digitalRead(13);
  if (PULSADOR == LOW)
  { 
   Serial.print("pulsador");
   while (PULSADOR ==LOW)
   {
    if (bt.available()) {
    btdata = bt.read();
      switch (btdata) {
      case BOTON_AVANZAR:
      avanzar();
      break;
      case BOTON_RETROCEDER:
      retroceder();
       break;
      case BOTON_IZQUIERDA:
      izquierda();
       break;
      case BOTON_DERECHA:
      derecha();
       break;
      case BOTON_DETENIDO:
      detenido();
      break;
    } 
  }
 }
}
}
void avanzar() {
 digitalWrite(MOTOR_1A, HIGH);
 digitalWrite(MOTOR_1B, LOW);
 analogWrite(PIN_ENA, speed);
 digitalWrite(MOTOR_2A, HIGH);
 digitalWrite(MOTOR_2B, LOW);
 analogWrite(PIN_ENB, speed);
}

void retroceder () {
 digitalWrite(MOTOR_1A, LOW);
 digitalWrite(MOTOR_1B, HIGH);
 analogWrite(PIN_ENA, speed);
 digitalWrite(MOTOR_2A, LOW);
 digitalWrite(MOTOR_2B, HIGH);
 analogWrite(PIN_ENB, speed);
}

void izquierda() { 

 digitalWrite(MOTOR_1A, HIGH);
 digitalWrite(MOTOR_1B, LOW);
 analogWrite(PIN_ENA, speed);
 digitalWrite(MOTOR_2A, LOW);
 digitalWrite(MOTOR_2B, LOW);
 analogWrite(PIN_ENB, speed);
}

void derecha () {

 digitalWrite(MOTOR_1A, LOW);
 digitalWrite(MOTOR_1B, LOW);
 analogWrite(PIN_ENA, speed);
 digitalWrite(MOTOR_2A, HIGH);
 digitalWrite(MOTOR_2B, LOW);
 analogWrite(PIN_ENB, speed);
}

void detenido () {
  digitalWrite(MOTOR_1A, LOW);
 digitalWrite(MOTOR_1B, LOW);
 analogWrite(PIN_ENA, speed);
 digitalWrite(MOTOR_2A, LOW);
 digitalWrite(MOTOR_2B, LOW);
 analogWrite(PIN_ENB, speed);
}
