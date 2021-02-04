#include <IRremote.h>

// IR data pin (can be changed)
int RECV_PIN = 11;

// Commands from the remote
double stopIR = 16753245;
double volP = 16736925;
double funcStop = 16769565;

double goBack = 16720605;
double playPause = 16712445;
double goForward = 16761405;

double goDown = 16769055;
double volM = 16754775;
double goUp = 16748655;

double touch_0 = 16738455;
double eq = 16750695;
double stReset = 16756815;

double touch_1 = 16724175;
double touch_2 = 16718055;
double touch_3 = 16743045;

double touch_4 = 16716015;
double touch_5 = 16726215;
double touch_6 = 16734885;

double touch_7 = 16728765;
double touch_8 = 16730805;
double touch_9 = 16732845;

long valueIR = 0;
int sentValue = 0;
int cpt = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Initialisation du capteur
}

void loop() {
    while(!irrecv.decode(&results)){
    }
    do{
          if (irrecv.decode(&results)) {
          valueIR = (results.value);
          irrecv.resume(); // Recoit la valeur suivant
          //Serial.println(valueIR);
          }
        }
    while(valueIR == -1);
    int currentValue = 0;
    while(valueIR == touch_1 || valueIR == touch_2 || valueIR == touch_3 || valueIR == touch_4 || valueIR == touch_5 || valueIR == touch_6 || valueIR == touch_7 || valueIR == touch_8 || valueIR == touch_9 || valueIR == touch_0){
        if(valueIR == touch_0)
        {
          currentValue = 0;
        }
        if(valueIR == touch_1)
        {
          currentValue = 1;
        }
        if(valueIR == touch_2)
        {
          currentValue = 2;
        }
        if(valueIR == touch_3)
        {
          currentValue = 3;
        }
        if(valueIR == touch_4)
        {
          currentValue = 4;
        }
        if(valueIR == touch_5)
        {
          currentValue = 5;
        }
        if(valueIR == touch_6)
        {
          currentValue = 6;
        }
        if(valueIR == touch_7)
        {
          currentValue = 7;
        }
        if(valueIR == touch_8)
        {
          currentValue = 8;
        }
        if(valueIR == touch_9)
        {
          currentValue = 9;
        }
        sentValue = sentValue*pow(10,cpt) + currentValue;
        cpt++;
        while(!irrecv.decode(&results)){
        }
        do{
          if (irrecv.decode(&results)) {
          valueIR = (results.value);
          irrecv.resume(); // Recoit la valeur suivant
          //Serial.println(valueIR);
          }
        }
        while(valueIR == -1);
      }
    if(valueIR == stopIR){
      sentValue = 10;
    }
    if(sentValue != 0){
        Serial.println(sentValue);
    }
    valueIR = 0;
    sentValue = 0;
    cpt = 0;
  }
