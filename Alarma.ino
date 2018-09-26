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
// Allow wake up pin to trigger interrupt on low.
    attachInterrupt(0, wakeUp, LOW);
    
    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    
    // Disable external pin interrupt on wake up pin.
    detachInterrupt(0);
digitalWrite(buzzer,HIGH);
}

// Metodo encargado de eliminar el rebote y denota el "wake up" del arduino
void wakeUp(){
  if(millis()> tiempo +150){
    tiempo = millis();
  }
}
