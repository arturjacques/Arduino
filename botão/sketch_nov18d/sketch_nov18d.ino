/*
Leitura de tecla
O exemplo le uma tecla conectada ao pino 2 e aciona um led conectado ao pino 13
*/
 
const int ledPin = 13; // cria uma constante com o numero do pino ligado ao LED
const int inputPin = 2; // cria uma constante com o numero do pino conectado a tecla
const int rele = 7; // cria constante para controlar o relê
 
void setup()
{
  pinMode(ledPin, OUTPUT); // declara o pino do led como saída
  pinMode(rele, OUTPUT); // declara o pino do led como saída
  pinMode(inputPin, INPUT); // declara o pino da tecla como entrada
}

bool a=false;

void loop()
{
  int val = digitalRead(inputPin); // le o valor na entrada
  if (val == LOW) // se valor está em zero( tecla pressionada)
  {
    while (val == LOW){
      val = digitalRead(inputPin); // le o valor na entrada
    }
    if (a==true){
       digitalWrite(ledPin, LOW); // Desliga LED indicando tecla solta
       digitalWrite(rele, LOW); // Desliga LED indicando tecla solta
       a=false;
    }
    else{
      digitalWrite(ledPin, HIGH); // Liga LED indicando tecla pressionada
      digitalWrite(rele, HIGH); // Desliga LED indicando tecla solta
      a=true;
    }
    
  }
}
