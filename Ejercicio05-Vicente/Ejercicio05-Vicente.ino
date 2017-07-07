#include <Servo.h>

#define PIN_SERVO 9
#define PIN_BOTON_A 2
#define TIM_DELAY_BUTTON 100  // Delay en milisegundos para evitar rebote de Boton

Servo miservo;

int grados = 10;  //Variable global
int grados_ant = 0;
bool NoRebote = false;
long int timRebote;

void setup() {
  Serial.begin(9600); //
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  miservo.attach(PIN_SERVO);
  miservo.write(grados);
  timRebote = millis();
}

void loop() {
  if (grados_ant != grados) {
    Serial.println(grados);
    grados_ant = grados;
  }
  detectaFlanco();
}

void detectaFlanco() {
  static boolean anterior_a = digitalRead(PIN_BOTON_A); //Variable local
  boolean estado_a = digitalRead(PIN_BOTON_A);  //Variable local

  // Evitamos el rebote
  if ((millis() - timRebote) > TIM_DELAY_BUTTON) {
    NoRebote = true;
  } else {
    NoRebote = false;
  }

  if ((anterior_a != estado_a) && NoRebote) {
    if (estado_a == HIGH) {  //flanco ascendente pull-up
      if (grados >= 170)
        grados = 10;
      else
        grados += 10;
      miservo.write(grados);
    }
    anterior_a = estado_a;  //
    timRebote = millis();
  }
}
