#include <Arduino.h>

const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const unsigned long MEASURE_TIMEOUT = 25000UL;
const float SOUND_SPEED = 340.0 / 1000;


const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415; 
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
const int N_B0 = 31;
const int N_C1 = 33;
const int N_CS1 = 35;
const int N_D1 = 37;
const int N_DS1 = 39;
const int N_E1 = 41;
const int N_F1 = 44;
const int N_FS1 = 46;
const int N_G1 = 49;
const int N_GS1 = 52;
const int N_A1 = 55;
const int N_AS1 = 58;
const int N_B1 = 62;
const int N_C2 = 65;
const int N_CS2 = 69;
const int N_D2 = 73;
const int N_DS2 = 78;
const int N_E2 = 82;
const int N_F2 = 87;
const int N_FS2 = 93;
const int N_G2 = 98;
const int N_GS2 = 104;
const int N_A2  = 110;
const int N_AS2 = 117;
const int N_B2 = 123;
const int N_C3 = 131;
const int N_CS3 = 139;
const int N_D3 = 147;
const int N_DS3 = 156;
const int N_E3 = 165;
const int N_F3 = 175;
const int N_FS3 = 185;
const int N_G3 = 196;
const int N_GS3 = 208;
const int N_A3 = 220;
const int N_AS3 = 233;
const int N_B3 = 247;
const int N_C4 = 262;
const int N_CS4 = 277;
const int N_D4 = 294;
const int N_DS4 = 311;
const int N_E4 = 330;
const int N_F4 = 349;
const int N_FS4 = 370;
const int N_G4 = 392;
const int N_GS4 = 415;
const int N_A4 = 440;
const int N_AS4 = 466;
const int N_B4 = 494;
const int N_C5 = 523;
const int N_CS5 = 554;
const int N_D5 = 587;
const int N_DS5 = 622;
const int N_E5 = 659;
const int N_F5 = 698;
const int N_FS5 = 740;
const int N_G5 = 784;
const int N_GS5 = 831;
const int N_A5 = 880;
const int N_AS5 = 932;
const int N_B5 = 988;
const int N_C6 = 1047;
const int N_CS6 = 1109;
const int N_D6 = 1175;
const int N_DS6 = 1245;
const int N_E6 = 1319;
const int N_F6 = 1397;
const int N_FS6 = 1480;
const int N_G6 = 1568;
const int N_GS6 = 1661;
const int N_A6 = 1760;
const int N_AS6 = 1865;
const int N_B6 = 1976;
const int N_C7 = 2093;
const int N_CS7 = 2217;
const int N_D7 = 2349;
const int N_DS7 = 2489;
const int N_E7 = 2637;
const int N_F7 = 2794;
const int N_FS7 = 2960;
const int N_G7 = 3136;
const int N_GS7 = 3322;
const int N_A7 = 3520;
const int N_AS7 = 3729;
const int N_B7 = 3951;
const int N_C8 = 4186;
const int N_CS8 = 4435;
const int N_D8 = 4699;
const int N_DS8 = 4978;

const int A = 550;
const int As = 582;
const int B = 617;
const int C = 654;
const int Cs = 693;
const int D = 734;
const int Ds = 777;
const int E = 824;
const int F = 873;
const int Fs = 925;
const int G = 980;
const int Gs = 1003;
const int Ax = 1100;
const int A2s = 1165;
const int B2 = 1234;
const int C3 = 1308;
const int C3s = 1385;
const int D3 = 1555;


const int buzzerPin = 12;

int counter = 0;

int Undertale[] = {N_D3, N_D3, N_D4, N_A3, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_C3, N_C3, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_B2, N_B2, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_AS2, N_AS2, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_D3, N_D3, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_C3, N_C3, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_B2, N_B2, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_AS2, N_AS2, N_D4, N_A3, 0, N_GS3, N_G3, N_F3, N_D3, N_F3, N_G3, N_D4, N_D4, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_C4, N_C4, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_B3, N_B3, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_AS3, N_AS3, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_D4, N_D4, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_C4, N_C4, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_B3, N_B3, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_AS3, N_AS3, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, N_F4, N_F4, N_F4, N_F4, N_F4, N_D4, N_D4, N_D4, N_F4, N_F4, N_F4, N_G4, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4, 0, N_F4, N_F4, N_F4, N_G4, N_GS4, N_A4, N_C5, N_A4, N_D5, N_D5, N_D5, N_A4, N_D5, N_C5, N_F4, N_F4, N_F4, N_F4, N_F4, N_D4, N_D4, N_D4, N_F4, N_F4, N_F4, N_F4, N_D4, N_F4, N_E4, N_D4, N_C4, 0, N_G4, N_E4, N_D4, N_D4, N_D4, N_D4, N_F3, N_G3, N_AS3, N_C4, N_D4, N_F4, N_C5, 0, N_F4, N_D4, N_F4, N_G4, N_GS4, N_G4, N_F4, N_D4, N_GS4, N_G4, N_F4, N_D4, N_F4, N_F4, N_F4, N_GS4, N_A4, N_C5, N_A4, N_GS4, N_G4, N_F4, N_D4, N_E4, N_F4, N_G4, N_A4, N_C5, N_CS5, N_GS4, N_GS4, N_G4, N_F4, N_G4, N_F3, N_G3, N_A3, N_F4, N_E4, N_D4, N_E4, N_F4, N_G4, N_E4, N_A4, N_A4, N_G4, N_F4, N_DS4, N_CS4, N_DS4, 0, N_F4, N_D4, N_F4, N_G4, N_GS4, N_G4, N_F4, N_D4, N_GS4, N_G4, N_F4, N_D4, N_F4, N_F4, N_F4, N_GS4, N_A4, N_C5, N_A4, N_GS4, N_G4, N_F4, N_D4, N_E4, N_F4, N_G4, N_A4, N_C5, N_CS5, N_GS4, N_GS4, N_G4, N_F4, N_G4, N_F3, N_G3, N_A3, N_F4, N_E4, N_D4, N_E4, N_F4, N_G4, N_E4, N_A4, N_A4, N_G4, N_F4, N_DS4, N_CS4, N_DS4, };

int StarWars[] = {a, a, a, f, cH, a, f, cH, a, 0, eH, eH, eH, fH, cH, gS, f, cH, a};

int Potter[] = {B,E,G,F,E,B2,Ax,Fs,E,G,F,Ds,F,B};

void setup()
{
 //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
}

void beep(int note, int duration)
{
    tone(buzzerPin, note, duration);
}

void firstSectionUndertale()
{

  
  for (int i = 0; i < sizeof(Undertale) -1; i++)
  {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);

    /* 3. Calcul la distance à partir du temps mesuré */
    float distance_mm = measure / 2.0 * SOUND_SPEED;
    Serial.println(distance_mm);
    delay(185);

    if(distance_mm >= 800)
    {
      beep(Undertale[i],100);
    }
    else{
      return;
    }
  }
}

void firstSectionStarWars()
{


  for (int i = 0; i < sizeof(StarWars) -1; i++)
  {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
    float distance_mm = measure / 2.0 * SOUND_SPEED;
    Serial.println(distance_mm);
    delay(400);

    if(distance_mm < 800)
    {
      beep(StarWars[i],100);
    }
    else{
      return;
    }
  }
}

void firstSectionPotter()
{
  for (int i = 0; i < sizeof(Potter) -1; i++)
  {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
    float distance_mm = measure / 2.0 * SOUND_SPEED;
    Serial.println(distance_mm);
    delay(400);

    if(distance_mm>=0 && distance_mm<=799)
    {
      beep(Potter[i],100);
    }
    else{
      return;
    }
  }
}




void loop()
{
  firstSectionUndertale();
  firstSectionStarWars();
  firstSectionPotter();
}






