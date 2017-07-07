#define PIN_BOTON_B 3
#define PIN_SERVO 9

#include <Servo.h>

Servo miservo;
int grados = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  miservo.attach(PIN_SERVO);
  pinMode(PIN_BOTON_B, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  detecta_flanco();
  Serial.println(grados);
  miservo.write(grados);

}

int detecta_flanco() {
  static boolean anterior_b = digitalRead(PIN_BOTON_B);
  boolean estado_b = digitalRead(PIN_BOTON_B);
  if (anterior_b != estado_b) {
    if (estado_b == HIGH) {  //flanco ascendente pull-down
      if (grados >= 170) {
        grados = 10;
      } else
        grados = grados + 10;
    }
    anterior_b = estado_b;

  }
}



