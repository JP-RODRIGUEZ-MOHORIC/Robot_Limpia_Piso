#define DEBUG 1
//MOTOR IZQUIERDO
#define MOTOR_1A 5 
#define MOTOR_1B 6
#define PIN_ENA 9
//MOTOR DERECHO
#define MOTOR_2A 7
#define MOTOR_2B 8
#define PIN_ENB 10
//SENSOR DE DISTANCIA DELANTERO
#define TRIGGER_DEL 3
#define ECHO_DEL 4
//DISTANCIA MINIMA
#define DISTANCIA_MIN 5
unsigned int tiempo_1, distancia_1;
const int speed = 100;
int PULSADOR;
 

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_1B, OUTPUT);
  pinMode(MOTOR_2A, OUTPUT);
  pinMode(MOTOR_2B, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(TRIGGER_DEL, OUTPUT);
  pinMode(ECHO_DEL, INPUT);
  pinMode(13, INPUT_PULLUP);
}
void loop() {
  {
  PULSADOR = digitalRead(13);
  if (PULSADOR == LOW)
  { 
    Serial.println("pulsador");   
  }
  while (PULSADOR == LOW)
   {
      Sensor_Delantero();
      if (distancia_1 > DISTANCIA_MIN) //si distancia es mayor o igual a la distancia minima
      {
        avanzar ();
      }
      else //(distancia_1 <= DISTANCIA_MIN) //si distancia es menor o igual a la distancia minima
      {
      Retroceder_y_Girar ();
      }
   }
  }
}
void Sensor_Delantero() // Sensor de distancia delantero 
{
digitalWrite(TRIGGER_DEL, LOW);  
delayMicroseconds(2);
digitalWrite(TRIGGER_DEL, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_DEL, LOW);
tiempo_1 = pulseIn(ECHO_DEL, HIGH);
distancia_1 = tiempo_1 / 58;
if(DEBUG){
Serial.print(distancia_1);
Serial.println("cm");
delay(10);
}
}

void avanzar () // robot avanza
{
 digitalWrite(MOTOR_1A, HIGH);
 digitalWrite(MOTOR_1B, LOW);
 analogWrite(PIN_ENA, speed);
 digitalWrite(MOTOR_2A, HIGH);
 digitalWrite(MOTOR_2B, LOW);
 analogWrite(PIN_ENB, speed);
 if(DEBUG==1)
 {
 Serial.print("avanzar");
 delay(10);
}
}
void Retroceder_y_Girar () // robot retrocede y gira
{
 digitalWrite(MOTOR_1A, LOW);
 digitalWrite(MOTOR_1B, LOW);
 analogWrite(PIN_ENA, 0);
 digitalWrite(MOTOR_2A, LOW);
 digitalWrite(MOTOR_2B, HIGH);
 analogWrite(PIN_ENB, 50);
 delay(500);
 if(DEBUG==1)
 {
 Serial.print("retroceder y girar");
 delay(10);
}
}
