
const int switchAPin = 2;
const int switchBPin = 4;
const int switchCPin = 7;
const int switchDPin = 10;

const int ledAPin = 3;
const int ledBPin = 5;
const int ledCPin = 6;
const int ledDPin = 9;

const int soundPin = 13;

int noteDur = 500; // ms per 1 beat

long happyBirthday[50] = { 146.83, 0.75, 146.83, 0.25, 
164.81, 1, 146.83, 1, 196.00, 1, 174.61, 2, 146.83, 0.75, 
146.83, 0.25, 164.81, 1, 146.83, 1, 220.00, 1, 196.00, 2, 
146.83, 0.75, 146.83, 0.25, 293.66, 1, 246.94, 1, 196.00, 
1, 174.61, 1, 164.81, 1, 261.63, 0.75, 261.63, 0.25, 
246.94, 1, 196.00, 1, 220.00, 1, 196.00, 3};

void setup() {
  pinMode(switchAPin, INPUT);
  pinMode(switchBPin, INPUT);
  pinMode(switchCPin, INPUT);
  pinMode(switchDPin, INPUT);

  pinMode(ledAPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(ledCPin, OUTPUT);
  pinMode(ledDPin, OUTPUT);
}

void loop() {
  if (digitalRead(switchAPin) == HIGH) {
    digitalWrite(ledAPin, HIGH);
    playTune(happyBirthday, 50);
    digitalWrite(ledAPin, LOW);
  }
}

//  Plays song contained within tune.
//    tune : long array containing encoded song
//    len : length of tune array
void playTune(long tune[], int len) {
  for (int i = 0; i < len; i += 2) {
    int freq = int(tune[i]);
    long dur = tune[i+1]*noteDur;
    tone(soundPin, freq, dur);
    delay(dur);
  }
  noTone(soundPin);
}

