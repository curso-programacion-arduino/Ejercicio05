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
  if (digitalRead(pin) == 1 && flanco == 0) { // si detectamos tension en el pin y es el flanco de subida hacemos lo de abajo
    flanco = 1;
    pulsaciones = pulsaciones += 10;
    miservo.write(pulsaciones);
    Serial.println(pulsaciones);
  }
  if (digitalRead(pin) == 0) { // si pin deja de estar high ponemos el flanco a 0
    flanco = 0;
  }
  if (pulsaciones == 170){ // cuando lleguemos a 170 lo mandamos de nuevo a 10
    pulsaciones = 0;
  }
}
