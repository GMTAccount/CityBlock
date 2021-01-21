void setup()
{
  Serial.begin(9600);
}

void loop()
{
    Serial.print(6, DEC);
  Serial.print(1, DEC);
  delay(1000);
  Serial.print(2, DEC);
  delay(1000);
      Serial.print(4, DEC);
    Serial.print(5, DEC);
  Serial.print(3, DEC);
  delay(1000);
}
