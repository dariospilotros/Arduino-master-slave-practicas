//master

#include <Wire.h>

void setup() {
  Wire.begin();
}

byte pin[]={2,3,4,5,6};
byte estado=0;

void loop() {
  for(int i=0;i<5;i++){
    Wire.beginTransmission(1);  //empieza transmision
    Wire.write(pin[i]);         //envia byte, pin a cencender
    Wire.write(estado);         //envia byte,L o H
    Wire.endTransmission();     //Fin transmision
    delay(1000);
  }

  if(estado == 0){     //cambio estado
    estado = 1;
  }else{
    estado = 0;
  }
  

  

}
