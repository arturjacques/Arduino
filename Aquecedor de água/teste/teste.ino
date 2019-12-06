#include <OneWire.h>
#include <DallasTemperature.h>
 
OneWire pino(2);
DallasTemperature barramento(&pino);
DeviceAddress sensor;
 
void setup(void)
{
  Serial.begin(9600);
  barramento.begin();
  barramento.getAddress(sensor, 0);  
}
 
void loop()
{
  barramento.requestTemperatures(); 
  float temperatura = barramento.getTempC(sensor);
  Serial.println(temperatura);
  delay(50);
}
