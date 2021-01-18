int R = 0;

int G = 0;

int B = 0;

int i = 0;

void setup()
{
  pinMode(7, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  // Define si enciende por luz percibida o por
  // movimiento captado
  if (digitalRead(7) == 1) {
    // Determina el color del LED según la temperatura
    if (analogRead(A1) <= 125) {
      // Define si el LED enciende según la luz captada
      if (analogRead(A0) < 512) {
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
      } else {
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }
    }
    if (analogRead(A1) > 125 && analogRead(A1) <= 160) {
      // Define si el LED enciende según la luz captada
      if (analogRead(A0) < 512) {
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      } else {
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }
    }
    if (analogRead(A1) > 160) {
      // Define si el LED enciende según la luz captada
      if (analogRead(A0) < 512) {
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
      } else {
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }
    }
  } else {
    // Define el color del LED según la temperatura
    if (analogRead(A1) <= 125) {
      // Enciende el LED durante 5 segundos si capta
      // movimiento
      if (digitalRead(2) == 1) {
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        delay(5000); // Wait for 5000 millisecond(s)
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }
    }
    if (analogRead(A1) > 125 && analogRead(A1) <= 160) {
      // Enciende el LED durante 5 segundos si capta
      // movimiento
      if (digitalRead(2) == 1) {
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(5000); // Wait for 5000 millisecond(s)
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }
    }
    if (analogRead(A1) > 160) {
      // Enciende el LED durante 5 segundos si capta
      // movimiento
      if (digitalRead(2) == 1) {
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(5000); // Wait for 5000 millisecond(s)
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }
    }
  }
}