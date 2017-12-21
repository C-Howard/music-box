
const int switchAPin = 2;
const int switchBPin = 4;
const int switchCPin = 7;
const int switchDPin = 10;

const int ledAPin = 3;
const int ledBPin = 5;
const int ledCPin = 6;
const int ledDPin = 9;

const int soundPin = 13;

int noteDur = 250; // ms per 1 beat

long happyBirthday[50] = { 146.83, 1, 146.83, 1, 
164.81, 2, 146.83, 2, 196.00, 2, 174.61, 4, 146.83, 1, 
146.83, 1, 164.81, 2, 146.83, 2, 220.00, 2, 196.00, 4, 
146.83, 1, 146.83, 1, 293.66, 2, 246.94, 2, 196.00, 
2, 174.61, 2, 164.81, 2, 261.63, 1, 261.63, 1, 
246.94, 2, 196.00, 2, 220.00, 2, 196.00, 4};

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

    Serial.print("freq: ");
    Serial.print(freq);
    Serial.print(" dur: ");
    Serial.print(dur);
    Serial.println();
    
    tone(soundPin, freq, dur);
    delay(dur);
    noTone(soundPin);
    delay(50);
  }
}

