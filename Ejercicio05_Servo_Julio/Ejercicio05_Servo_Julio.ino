/* Ejemplo 5
    Servo desde el codigo de Enrique
*/


#include <Servo.h>

#define PIN_SERVO 9
#define PIN_BOTON_A 2

Servo miservo;

int grados = 10;  //Variable global

void setup() {
  //<<< <<< < Updated upstream
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  Serial.begin(9600); //
  pinMode(PIN_BOTON_A, INPUT_PULLUP);// Pulsar y soltar el boton A
  //>>> >>> > Stashed changes
  miservo.attach(PIN_SERVO); // fundamental para trabajar con servos... modifica el comportamiento del pin
  miservo.write(grados); // ademas del attach necesitas este write para indicar el angulo de la posicion.
}

void loop()
{
  Serial.println(grados);
  detectaFlanco();
}

void detectaFlanco()
{
  static boolean anterior_a = digitalRead(PIN_BOTON_A); //Variable local
  boolean estado_a = digitalRead(PIN_BOTON_A);  //Variable local

  if (anterior_a != estado_a)
  {
    if (estado_a == HIGH)
    { //flanco ascendente pull-up
      if (grados >= 170)
        grados = 10;      // Cuando alcanza los 170 grados el eje vuelve a los 10
      else
      {
        grados += 10;
        miservo.write(grados);
      }
      anterior_a = estado_a;  // No olvidar actualizar esto...
    }
  }

}
