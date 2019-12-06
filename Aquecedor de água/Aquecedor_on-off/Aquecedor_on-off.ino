#include <LiquidCrystal_I2C.h>

#include <DallasTemperature.h>
#include <OneWire.h>
#include <Wire.h>

//inicialização do sensor de temperatura
OneWire pino(3);
DallasTemperature barramento(&pino);
DeviceAddress sensor;

//Display LCD 16x2 e modulos I2C
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

//Relês
const int rele1=5;
const int rele2=6;

//Set Point

int set=70;


void setup() {
  //Relês
  pinMode(rele1,OUTPUT);
  pinMode(rele2,OUTPUT);
  digitalWrite(rele1,LOW);
  digitalWrite(rele2,LOW);
  // Sensor de temperatura
  Serial.begin(9600);
  barramento.begin();
  barramento.getAddress(sensor, 0);
  //LCD
  lcd.begin(16,2);
}


void loop() {
  lcd.setBacklight(HIGH);
  barramento.requestTemperatures(); 
  float temperatura = barramento.getTempC(sensor);
  String TC1 =String(temperatura,2);
  String saida =String("Temp:"+TC1);
  saida =saida+",Rele:"+digitalRead(rele1)+",Set Point:"+set;
  Serial.println(saida);
  //leitura dos dados
  if (Serial.available()>0){
    String leitura=Serial.readString();
    String info = leitura.substring(0,4);
    if(info.equals("Set:")){
      String novoset=leitura.substring(4);
      Serial.println(novoset);
      set=novoset.toInt();
    }
  }
  //LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: "+TC1+" C");
  lcd.setCursor(0,1);
  String strset1 = String(set);
  String strset2 = String("Set-Point: " + strset1 +" C");
  lcd.print(strset2);
  if(temperatura<set){
    digitalWrite(rele1,HIGH);
    digitalWrite(rele2,HIGH);
  }else{
    digitalWrite(rele1,LOW);
    digitalWrite(rele2,LOW);
  }
}
