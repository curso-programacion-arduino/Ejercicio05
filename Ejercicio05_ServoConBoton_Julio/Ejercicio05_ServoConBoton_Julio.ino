
/*
   Ejercicio 5
   Variables locales, globales...
   Mover un servo 10 grados cada vez que pulsamos un boton.
   al llegar a 170 grados volver a 10

   sobre la base del codigo de jecrespo:
   https://github.com/jecrespo/aprendiendoarduino-Curso_Programacion_Arduino/tree/master/Ejercicio05-Ambito_Variables
*/


#include <Servo.h>

#define PIN_SERVO 9
#define PIN_BOTON_A 2

Servo miservo;

int grados = 10;  //Variable global

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_BOTON_A, INPUT_PULLUP);

  miservo.attach(PIN_SERVO);
  /*
     Ahora, lo primero, colocamos el servo a 10 grados.
     porque el valor inicial de grados es 10
     y es el valor que le pasamos al servo con:
     miservo.write:
  */
  miservo.write(grados);
}

void loop()
{
  Serial.print("grados:");
  Serial.println(grados);

  /*
     Llamamos a la funcion "detectaFlanco()"
  */
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
        grados = 10;
      else
        grados += 10; // grados aumenta de 10 en 10
      miservo.write(grados);
    }
    anterior_a = estado_a;
  }
}
