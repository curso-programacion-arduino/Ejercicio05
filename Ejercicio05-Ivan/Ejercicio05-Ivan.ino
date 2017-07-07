#include <Servo.h>


int pulsaciones = 0;
int flanco = 0;
#define pin 3
Servo miservo;
#define PIN_SERVO 9


void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  miservo.attach(PIN_SERVO);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pin) == 1 && flanco == 0) {
    flanco = 1;
    pulsaciones = pulsaciones += 10;
    miservo.write(pulsaciones);
    Serial.println(pulsaciones);
  }
  if (digitalRead(pin) == 0) {
    flanco = 0;
  }
  if (pulsaciones == 170){
    pulsaciones = 0;
  }
}
