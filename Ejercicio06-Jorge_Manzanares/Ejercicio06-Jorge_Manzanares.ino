
#define PIN_TMP36 A2
#define CONSIGNA 25
#define PIN_BUZZER 8
#define NOTE_C5  523  //Frecuencia de sonido del buzzer
boolean Alarma = LOW;
boolean Alarma_anterior = LOW;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  int sensorVal = analogRead(PIN_TMP36);
  float voltage = (sensorVal / 1023.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  //Serial.println(temperature);//en temperature tengo la temperatura
  if (temperature > 28) {
    Alarma_anterior = HIGH;
  }

}

void loop() {


  int sensorVal = analogRead(PIN_TMP36);
  float voltage = (sensorVal / 1023.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);//en temperature tengo la temperatura
  delay(1000);
  if ((temperature >= CONSIGNA + 1) && (Alarma_anterior == LOW))
  {
    Serial.println("ALARMA");
    Alarma_anterior = HIGH;
    tone(PIN_BUZZER, NOTE_C5);
  }
  else if ((temperature < CONSIGNA) && (Alarma_anterior == HIGH))
  {
    Serial.println("ALARMA DESACTIVADA");
    Alarma_anterior = LOW;
    noTone(PIN_BUZZER);


  }

}






