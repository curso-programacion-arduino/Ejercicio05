#include <Servo.h>

#define PIN_SERVO 9 //pin del servo
#define PIN_BOTON_A 2 //pin del botón A

Servo miservo; //variable "miservo" de tipo "Servo"
int grados = 10; //posición inicial, variable global

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);//el botón A no tiene resistencia
  miservo.attach(PIN_SERVO);//asocia la variable "miservo" de tipo "Servo" al pin
  miservo.write(grados);//coloca el servo en esta posición
}

void loop() {
  Serial.println(grados);
  detectaFlanco();
}

void detectaFlanco() {
  static boolean anterior_a = digitalRead(PIN_BOTON_A); //Variable local
  boolean estado_a = digitalRead(PIN_BOTON_A);  //Variable local

  if (anterior_a != estado_a) {
    if (estado_a == HIGH) {  //flanco ascendente pull-up
      if (grados >= 170)
        grados = 10;
      else
        grados += 10;
      miservo.write(grados);
    }
    anterior_a = estado_a;  //
  }
}




