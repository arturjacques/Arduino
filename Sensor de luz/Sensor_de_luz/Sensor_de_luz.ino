int anaPin=0; //pin analógico zero. Recebimento do sinal
int leitura=0; //leitura do sinal
int led=11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //comunicação serial

}

void loop() {
  // put your main code here, to run repeatedly:
  leitura=analogRead(anaPin);
  Serial.println(leitura);
  delay(20);
  if (leitura>700){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
