#define LIGHT_PIN A0

void setup()
{
  Serial.begin(9600);
  
  // Some number magic
  byte n = 300;
  Serial.print("300 as a byte: ");
  Serial.println(n);
  
  int m = 300;
  Serial.print("300 as an int: ");
  Serial.println(m);
  
  pinMode(13, OUTPUT);
}

void loop()
{
  int light_level = analogRead(LIGHT_PIN);
  
  //if (light_level < 512) {
  //  digitalWrite(13, HIGH);
  //} else {
  // 	digitalWrite(13, LOW);
  //}
  
  digitalWrite(13, light_level < 512);
  
  //delay(1000);
  //Serial.println(light_level);
}