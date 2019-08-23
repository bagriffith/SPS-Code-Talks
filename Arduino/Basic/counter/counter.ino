#define PULSE_PIN 8

long pulses;
  
void setup()
{  
  pinMode(PULSE_PIN, INPUT);
  pinMode(13, OUTPUT);
  
  pulses = 0;
}

void loop()
{
  if (digitalRead(PULSE_PIN)) {
  	pulses++;

    // Wait for the pin to go low again
    while (digitalRead(PULSE_PIN)) { }
  }
  
  
  if ((pulses % 1000) == 0) {
     // Print out multiples of 1000
     Serial.println(pulses);
  }
}