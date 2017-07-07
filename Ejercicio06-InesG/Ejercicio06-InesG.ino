#define PIN_TMP36 A2
#define NOTE_C5  523
#define umbral 30
#define PIN_BUZZER 8
boolean estado = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperatura = lee_temperatura();
    Serial.print( temperatura);
  if ((temperatura > umbral) && (estado == 0)) {
    tone(PIN_BUZZER, NOTE_C5);
    estado = 1;
    Serial.print( 'alerta temperatura');
  }
  Serial.println(estado);
  if ((temperatura < umbral) && (estado == 1)) {
    noTone(PIN_BUZZER);
    estado = 0;
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
