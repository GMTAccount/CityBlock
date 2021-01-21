int r = 0;

void setup()
{
  for(int i = 2; i <= 13; i++){
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);
  }
  Serial.begin(9600);
}

void loop()
{  
  if (Serial.available() > 0){
      r = Serial.read();
    Serial.println(r);
    if(r == 49)
    {
        digitalWrite(12, HIGH);
    }
    if(r == 50){
      digitalWrite(11, HIGH);
    }
    if(r == 51){
          digitalWrite(10, HIGH);
    }
    if(r == 52)
    {
        digitalWrite(12, LOW);
    }
    if(r == 53){
      digitalWrite(11, LOW);
    }
    if(r == 54){
          digitalWrite(10, LOW);
    }
  }
    
  /*digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW);*/
}
