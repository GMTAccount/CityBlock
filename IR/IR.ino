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

double valueIR = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Initialise le recepteur
}

void loop() {
  if (irrecv.decode(&results)) {
    //valueIR = (results.value, DEC);
    Serial.println(results.value, DEC);
    irrecv.resume(); // Recoit la valeur suivante
    if(valueIR == stopIR){
      Serial.println(0);
    }
    if(valueIR == volP){
      Serial.println("Volume goes up");
    }
    Serial.println(valueIR);*/
  }
}
