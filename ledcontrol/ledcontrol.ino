char c;

void setup()
{
  Serial.begin(9600);
  while (Serial.available() == 0){
    Serial.println("Waiting...");
    delay(500);
  }
  c = Serial.read();
}

void loop()
{
  Serial.println(c);
  delay(500); 
}
