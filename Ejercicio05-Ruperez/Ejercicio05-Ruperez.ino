#include <Servo.h>
#define PIN_SERVO 9
#define BOTON_A 2

int pos = 0; //variable pos global
int grados=10;
Servo miservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(BOTON_A, INPUT_PULLUP);
  Serial.begin (9600);
  miservo.attach(PIN_SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:

}
