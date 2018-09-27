/* Incluyendo la libreria */
#include "LowPower.h"
//Definicion de los pines a usar
#define reedSwitch 2
#define buzzer 5
#define led 6

// Variables para eliminar el rebote del switch
long tiempo = 0;

void setup() {
  pinMode(reedSwitch,INPUT); // Entrada del switch
  pinMode(buzzer,OUTPUT); // Salida para el buzzer
}

void loop() {
  // Creacion de la interrupcion que nos permitira salir del SLEEP mediante PULL UP
  attachInterrupt(0, wakeUp, LOW);
  // Se realiza la reduccion de energia hasta que se detecte un LOW
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  //Se deshabilita la interrupcion para poder implementar acciones al buzzer
  detachInterrupt(0);
  /* <--- Mis acciones --->*/
  // Mientras se active el switch en su modalidad PULL UP (es decir que se detecte LOW) se accionara la alarma
  while(digitalRead(reedSwitch)==LOW){
    // Se implementa el funcionamiento de los pines PWM
    for(int contador=0;contador<=255;contador+=10){
      analogWrite(buzzer,contador);
      analogWrite(led,contador);
      delay(10);
    }
    for(int contador=255;contador>0;contador-=10){
      analogWrite(buzzer,contador);
      analogWrite(led,contador);
      delay(10);
    }
  }
  // Se desactiva la alarma cuando la puerta se cierra
  digitalWrite(buzzer,LOW);
  digitalWrite(led,LOW);
}

// Metodo encargado de eliminar el rebote y denota el "wake up" del arduino
void wakeUp(){
  if(millis()> tiempo +150){
    tiempo = millis();
  }
}
