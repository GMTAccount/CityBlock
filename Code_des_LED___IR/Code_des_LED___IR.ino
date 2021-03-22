#include <FastLED.h>
#include <IRremote.h>

// Infrared section

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
int sentValue = 0;
int cpt = 0;
int currentValue = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

// LED section

// How many leds in your strip?
#define NUM_LEDS 24

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

int depart = 0;
int arrive = 0;

// NFC section

// General items
int buildingID [12];
char buildingName [12][16];
// NFC elements (to be added)

void setup() { 
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    //FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    // FastLED.addLeds<SM16703, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1829, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1812, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1904, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS2903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2852, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<GS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA106, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<PL9823, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GE8822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD1886, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD1886_8BIT, DATA_PIN, RGB>(leds, NUM_LEDS);
    // ## Clocked (SPI) types ##
    // FastLED.addLeds<LPD6803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    irrecv.enableIRIn(); // Initialise le recepteur
    Serial.begin(9600);
          /*for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = CRGB::Red;
        FastLED.show();
        delay(100);
        leds[i] = CRGB::Green;
        FastLED.show();
      }
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Purple;
      }
      FastLED.show();
      delay(500);
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
      }
      FastLED.show();*/
}

void loop() { 
  while(!irrecv.decode(&results)){
    }
          valueIR = (results.value);
          irrecv.resume(); // Recoit la valeur suivant
    Serial.println(valueIR);
    // Itinerary
    if(valueIR == touch_1 || valueIR == touch_2 || valueIR == touch_3 || valueIR == touch_4 || valueIR == touch_5 || valueIR == touch_6 || valueIR == touch_7 || valueIR == touch_8 || valueIR == touch_9 || valueIR == touch_0){
      depart = 0;
      arrive = 0;
      do
      {
        if(valueIR == touch_0)
        {
          currentValue = 0;
        }
        else if(valueIR == touch_1)
        {
          currentValue = 1;
        }
        else if(valueIR == touch_2)
        {
          currentValue = 2;
        }
        else if(valueIR == touch_3)
        {
          currentValue = 3;
        }
        else if(valueIR == touch_4)
        {
          currentValue = 4;
        }
        else if(valueIR == touch_5)
        {
          currentValue = 5;
        }
        else if(valueIR == touch_6)
        {
          currentValue = 6;
        }
        else if(valueIR == touch_7)
        {
          currentValue = 7;
        }
        else if(valueIR == touch_8)
        {
          currentValue = 8;
        }
        else if(valueIR == touch_9)
        {
          currentValue = 9;
        }
        depart = depart*pow(10,cpt) + currentValue;
        cpt++;
        while(!irrecv.decode(&results)){
        }
        do{
          while(!irrecv.decode(&results)) {
            }
          valueIR = (results.value);
          irrecv.resume(); // Recoit la valeur suivant
        }
        while(valueIR == -1);
      }
      while(valueIR != eq);
      Serial.println(depart);
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
      currentValue = 0;
      do
      {
        if(valueIR == touch_0)
        {
          currentValue = 0;
        }
        else if(valueIR == touch_1)
        {
          currentValue = 1;
        }
        else if(valueIR == touch_2)
        {
          currentValue = 2;
        }
        else if(valueIR == touch_3)
        {
          currentValue = 3;
        }
        else if(valueIR == touch_4)
        {
          currentValue = 4;
        }
        else if(valueIR == touch_5)
        {
          currentValue = 5;
        }
        else if(valueIR == touch_6)
        {
          currentValue = 6;
        }
        else if(valueIR == touch_7)
        {
          currentValue = 7;
        }
        else if(valueIR == touch_8)
        {
          currentValue = 8;
        }
        else if(valueIR == touch_9)
        {
          currentValue = 9;
        }
        else{
          currentValue = -1;
        }
        while(!irrecv.decode(&results)){
        }
        do{
          if (irrecv.decode(&results)) {
          valueIR = (results.value);
          Serial.println(valueIR);
          irrecv.resume(); // Recoit la valeur suivant
          //Serial.println(valueIR);
          }
        }
        while(valueIR == -1);
        if(valueIR != eq){
          arrive = arrive*pow(10,cpt) + currentValue;
          cpt++;
        }
      }
      while(valueIR != eq);
      Serial.println(arrive);
      if(depart > arrive){
        int inverse = depart;
        depart = arrive;
        arrive = inverse;
      }
      /*for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
      }
      FastLED.show();*/
      int retour1 = arrive - depart;
      int retour2 = NUM_LEDS - 1 - arrive + depart;
      /*if(retour1 > retour2){
        for(int i = 0; i <= depart; i++){
          leds[i] = CRGB::White;
      }
      for(int i = arrive; i < NUM_LEDS; i++){
        leds[i] = CRGB::White;

      }
      //FastLED.show();
    }
    else{
      for(int i = depart; i <= arrive; i++){
        leds[i] = CRGB::White;
      }
      FastLED.show();
    }*/
    }
    

    // NFC
    if(valueIR == stReset){
      // NFC reading (to be added)
    }
    
    // Shut down
    /*if(valueIR == stopIR){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Red;
        FastLED.show();
        delay(100);
        leds[i] = CRGB::Green;
        FastLED.show();
      }
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Blue;
      }
      FastLED.show();
      delay(500);
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
      }
      FastLED.show();
    }*/
    valueIR = 0;
    sentValue = 0;
    cpt = 0;
  
}
