
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
  // put your main code here, to run repeatedly:

}
