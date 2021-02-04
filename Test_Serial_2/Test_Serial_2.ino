int currentRead = 0;
int readValue = 0;
int cpt = 0;
bool reading = true;

void setup() {
    for(int i = 2; i <= 13; i++){
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);
  }
  Serial.begin(9600);

}

void loop() {
  if(Serial.available() > 0){
    currentRead = Serial.read();
    currentRead = currentRead - 48;
    if(currentRead >= 0){
    readValue = readValue*pow(10,cpt) + currentRead;
    cpt++;
    reading = true;
  }
  else{
    if(reading){
          Serial.println(readValue);
          reading = false;
    }
    currentRead = 0;
    readValue = 0;
    cpt = 0;
    }
  }
  currentRead = 0;
  

}
