#include <Servo.h>

#define PIN_SERVO 9 //servo
#define PIN_BOTON_A 2 //boton rojo
#define PIN_BOTON_B 3 //boton amarillo

Servo miservo;

int grados = 10;  //Variable global

void setup() {
  Serial.begin(9600); 
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  miservo.attach(PIN_SERVO);
  miservo.write(grados);
}

void loop() {
  Serial.println(grados);
  detectaFlanco();
}

void detectaFlanco() {
  static boolean anterior_a = digitalRead(PIN_BOTON_A); //Variable local
  boolean estado_a = digitalRead(PIN_BOTON_A);  //Variable local
  static boolean anterior_b = digitalRead(PIN_BOTON_B); //Variable local
  boolean estado_b = digitalRead(PIN_BOTON_B);  //Variable local

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
  if (anterior_b != estado_b) {
    if (estado_b == HIGH) {  //flanco ascendente pull-up
      if (grados <= 170)
        grados -= 10;
      else
        grados -= 10;
      miservo.write(grados);
    }
    anterior_b = estado_b;  //
  }
}
