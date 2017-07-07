#define UMBRAL 28
#define BUZZER 8
#define PIN_TEMP A2
int temperatura;

void setup() {
  // put your setup code here, to run once:
  pinMode (BUZZER, OUTPUT);
Serial.begin(9600);
}

void loop() {
  int T = lee_temperatura(PIN_TEMP);
  if (T > UMBRAL) {
    tone (BUZZER,800);
  }
  else
  noTone (BUZZER); 
  Serial.println (T);
}

float lee_temperatura (int pin) {
  //getting the voltage reading from the temperature sensor
  int reading = analogRead(pin);

  // converting that reading to voltage
  float voltage = reading * 5.0 / 1023.0;

  // now print out the temperature
  //converting from 10 mv per degree with 500 mV offset
  float temperatureC = (voltage - 0.5) * 100 ;

  return temperatureC;
}
