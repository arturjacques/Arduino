const int ledPin=12;
const int tempo=50;
const int entrada=2;
const int saida=7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(entrada,INPUT);
  pinMode(saida,OUTPUT);
  digitalWrite(saida,HIGH);
}

void loop() {
 digitalWrite(ledPin,HIGH);
 delay(tempo);
 digitalWrite(ledPin,LOW);
 delay(tempo);
}
