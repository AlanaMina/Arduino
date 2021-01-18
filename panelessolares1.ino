#include <Servo.h>

Servo servo_5;

Servo servo_6;

void setup()
{
  pinMode(7, INPUT);
  pinMode(A4, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A0, INPUT);
  servo_5.attach(5, 500, 2500);

  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  servo_6.attach(6, 500, 2500);

}

void loop()
{
  // Los servomotores se manejan desde los sensores o
  // de los potenciómetros (manualmente)
  if (digitalRead(7) >= 1) {
    // La luz roja o verde indica si están activos los
    // paneles o no
    if (analogRead(A4) <= 512) {
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      // El LED blanco corresponde a la iluminación de la
      // casa que se puede regular manualmente la
      // potencia
      analogWrite(3, map(analogRead(A5), 0, 1023, 0, 255));
    } else {
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      analogWrite(3, map(analogRead(A5), 0, 1023, 0, 255));
      // Selección de ubicación del servo ubicado
      // este-oeste
      if (analogRead(A3) > analogRead(A0)) {
        servo_5.write(map(analogRead(A3), 0, 1023, 91, 180));
      }
      if (analogRead(A3) < analogRead(A0)) {
        servo_5.write(map(analogRead(A0), 0, 1023, 90, 0));
      }
      if (analogRead(A3) == analogRead(A0)) {
        servo_5.write(90);
      }
      // Selección de posición de servomotor ubicado
      // Norte-Sur
      if (analogRead(A2) > analogRead(A1)) {
        servo_6.write(map(analogRead(A2), 0, 1023, 91, 180));
      }
      if (analogRead(A2) < analogRead(A1)) {
        servo_6.write(map(analogRead(A1), 0, 1023, 90, 0));
      }
      if (analogRead(A2) == analogRead(A1)) {
        servo_6.write(90);
      }
    }
  } else {
    if (analogRead(A4) <= 512) {
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      analogWrite(3, map(analogRead(A5), 0, 1023, 0, 255));
    } else {
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      analogWrite(3, map(analogRead(A5), 0, 1023, 0, 255));
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      servo_5.write(map(analogRead(A0), 0, 1023, 0, 180));
      servo_6.write(map(analogRead(A1), 0, 1023, 0, 180));
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}