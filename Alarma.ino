/* Incluyendo la libreria */
#include "LowPower.h"

#define reedSwitch 2
#define buzzer 3

// Variables para eliminar el rebote del switch
long tiempo = 0;

void setup() {
  pinMode(reedSwitch,INPUT); // Entrada del switch
  pinMode(buzzer,OUTPUT); // Salida para el buzzer
}

void loop() {
LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF); 
digitalWrite(buzzer,HIGH);
}

// Metodo encargado de eliminar el rebote y denota el "wake up" del arduino
void wakeUp(){
  if(millis()> tiempo +150){
    tiempo = millis();
  }
}
