#include <Servo.h>


int pulsaciones = 0; // variable que cuenta las pulsaciones del boton
int flanco = 0; // variable para detectar cambios de estado
#define pin 3 // pin de boton

Servo miservo; //clase para usar el servo

#define PIN_SERVO 9 //pin del servo


void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  miservo.attach(PIN_SERVO); //inicializo el servo
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (detectarFlanco(digitalRead(pin))) { // si detectamos tension en el pin y es el flanco de subida hacemos lo de abajo
    miservo.write(pulsaciones);
    Serial.println(pulsaciones);
  }
  if (pulsaciones == 170) { // cuando lleguemos a 170 lo mandamos de nuevo a 10
    pulsaciones = 0;
  }
}
boolean detectarFlanco(boolean estado) { // funcion para detectar el cambio de estado del pin
  if (estado == HIGH && flanco == 0) {
    flanco = 1;
    pulsaciones = pulsaciones += 10;
    return true;
  }
  if (estado == LOW) { // si pin deja de estar high ponemos el flanco a 0
    flanco = 0;
  }
}
