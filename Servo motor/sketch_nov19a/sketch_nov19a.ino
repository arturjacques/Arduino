#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
 
const int pinoMotor = 6; //PINO DIGITAL UTILIZADO PELO SERVO  

void setup (){
  Serial.begin(9600);
  Servo motor;
  motor.attach(pinoMotor); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  motor.write(0); //INICIA O MOTOR NA POSIÇÃO 0º
}
void loop(){
  char c = Serial.read();
}
