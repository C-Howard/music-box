
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
    playTune(happyBirthday(), 50);
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

// Returns array containing happy birthday, encoded.
long happyBirthday() {
  long hbd[50] = {
    146.83, 0.75,   // D
    146.83, 0.25,   // D
    164.81, 1,      // E
    146.83, 1,      // D
    196.00, 1,      // G
    174.61, 2,      // F

    146.83, 0.75,   // D
    146.83, 0.25,   // D
    164.81, 1,      // E
    146.83, 1,      // D
    220.00, 1,      // A
    196.00, 2,      // G

    146.83, 0.75,   // D
    146.83, 0.25,   // D
    293.66, 1,      // D
    246.94, 1,      // B
    196.00, 1,      // G
    174.61, 1,      // F
    164.81, 1,      // E

    261.63, 0.75,   // C
    261.63, 0.25,   // C
    246.94, 1,      // B
    196.00, 1,      // G
    220.00, 1,      // A
    196.00, 3       // G
  };
  return hbd;
}


