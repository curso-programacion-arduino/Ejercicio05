#include <Servo.h>
#define PIN_SERVO 9
#define BOTON_A 2

int pos = 0; //variable pos global
int grados = 10 ;
Servo miservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(BOTON_A, INPUT_PULLUP);
  Serial.begin (9600);
  miservo.attach(PIN_SERVO);

}

void loop()
{
  static boolean anterior_a = digitalRead(BOTON_A);
  boolean estado_a = digitalRead(BOTON_A);
  if (anterior_a != estado_a) {
    if (estado_a == HIGH) {  //flanco descendente pull-up
      grados = grados+10;
      Serial.println (grados);
    }
    if (grados >170) {
      grados = 10;
      
    }
 anterior_a = estado_a;
 delay(50); //Evitar rebotes
 miservo.write (grados);
  }


}
