//eslave

#include <Wire.h>

void setup() {
  
  //Pines de salida
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);

  Wire.begin(1);                  //Se une el dispositivo del bus I2C al 1
  Wire.onReceive(receiveEvent);   // Registramos el evento al recibir datos
  Serial.begin(9600);             // se monitorea la comunicacion

}

void loop() {
  delay(300);
}

void receiveEvent(int howMany){
  int pinOut=0;
  int estado=0;

  if(Wire.available()==2){
    pinOut=Wire.read();
    Serial.print("LED ");
    Serial.println(pinOut);
  }
  
  if(Wire.available()==1){
    estado = Wire.read();
    Serial.print("Estado ");
    Serial.println(estado);
  }
  
  digitalWrite(pinOut,estado);
  
}
