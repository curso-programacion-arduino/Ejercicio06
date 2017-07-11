void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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
