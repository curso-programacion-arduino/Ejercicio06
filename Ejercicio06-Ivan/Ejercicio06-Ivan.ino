#define PIN_TMP36 A2
#define UMBRAL 28.00
#define PIN_BUZZER 8

#define NOTE_C5  523  //Frecuencia de sonido del buzzer




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if   (lee_temperatura() >= UMBRAL) {
    Serial.println("ALARMA");
    Serial.println(lee_temperatura());
    tone(PIN_BUZZER, NOTE_C5);
  } else {
    Serial.println("RECUPERACION");
    noTone(PIN_BUZZER);
  }

}

float lee_temperatura () {
  //getting the voltage reading from the temperature sensor
  int reading = analogRead(PIN_TMP36);

  // converting that reading to voltage
  float voltage = reading * 5.0 / 1023.0;

  // now print out the temperature
  //converting from 10 mv per degree with 500 mV offset
  float temperatureC = (voltage - 0.5) * 100 ;

  return temperatureC;
}
