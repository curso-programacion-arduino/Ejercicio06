/*
   Ejercicio 6
   Alarma cuando se sobrepase el umbral
   en este caso 28
   Usamos sonda de temperatura analogica TMP36

   sobre la base del codigo de jecrespo:
   https://github.com/jecrespo/aprendiendoarduino-Curso_Programacion_Arduino/tree/master/Ejercicio06-Alarma
*/



#define PIN_BUZZER 8
#define PIN_TMP36 A2
#define UMBRAL 28
#define NOTE_C5  523  //Frecuencia de sonido del buzzer

boolean alarma_temperatura;

void setup()
{
  Serial.begin(9600);

  if (lee_temperatura () > UMBRAL) // funcion "lee_temperatura()"
  {
     if (alarma_temperatura == false) {
        alarma_temperatura = true;
        tone(PIN_BUZZER, NOTE_C5);
        Serial.println("ALARMA!!");
        
     }
  }
  else
  {
     if (alarma_temperatura == true) {
        alarma_temperatura = false;
        noTone(PIN_BUZZER);
     }
  }
}

void loop()
{
  if (lee_temperatura () > UMBRAL)
  {
    if (!alarma_temperatura)
    {
      alarma_temperatura = true;
      tone(PIN_BUZZER, NOTE_C5);
      Serial.println("ALARMA!!");
    }
  }
  else
  {
    if (alarma_temperatura)
    {
      alarma_temperatura = false;
      noTone(PIN_BUZZER);
      Serial.println("RECUPERACION ALARMA");
    }
  }
}

/*
   Ahora definimos la funcion "lee_temperatura()"
   La usamos para transformar la lectura analogica
   de la sonda en grados centigrados que podremos mostrar en un LCD
   o en el monitor serie...
*/
float lee_temperatura ()
{
  //Leemos la señal de la sonda de temperatura.
  int reading = analogRead(PIN_TMP36);

  // Lo convertimos a voltaje en una variable float:
  float voltage = reading * 5.0 / 1023.0;

  // Pasamos el valor a temperatura:
  // Esta es la formula para grados centigrados:
  
  //converting from 10 mv per degree with 500 mV offset
  float temperatureC = (voltage - 0.5) * 100 ;

  return temperatureC;
}

