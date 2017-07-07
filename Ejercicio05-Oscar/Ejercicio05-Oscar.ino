#include <Servo.h>

#define PIN_BOTON_A 2
#define PIN_BOTON_B 3
Servo miservo;
int grados = 10;
#define PIN_SERVO 9
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);

  miservo.attach(PIN_SERVO);
  miservo.write(grados);

}

void loop() {
  static boolean anterior_a = digitalRead(PIN_BOTON_A);
  boolean estado_a = digitalRead(PIN_BOTON_A);
  static boolean anterior_b = digitalRead(PIN_BOTON_B);
  boolean estado_b = digitalRead(PIN_BOTON_B);

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
      if (grados >= 170)
        grados = 10;
      else
        grados += 1;
      miservo.write(grados);
    }
    anterior_b = estado_b;  //
  }
}
