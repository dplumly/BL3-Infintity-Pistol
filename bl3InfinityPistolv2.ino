/*==========================
  Variables
  ==========================*/
const int triggerPin = 2;
const int barrelPin = 3;
const int recoil = 6;
const int recoilDelay = 75;
const int barrelDelay = 50;
int buttonState = 0;
int pwmValue;

//int speedValue = 5;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, INPUT_PULLUP);
  pinMode(barrelPin, OUTPUT);
  pinMode(recoil, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(triggerPin);

  if (buttonState == HIGH) {
    digitalWrite(barrelPin, LOW);
    digitalWrite(recoil, LOW);
  } else {
    digitalWrite(barrelPin, HIGH);
    recoilBarrel();
  }
}

/*
void barrelSpeedUp()
{
  int barrelSpeed;
  Serial.println("in Function");
  for (int barrelSpeed = 0; barrelSpeed <= 255; barrelSpeed += 5) {
    analogWrite(barrelPin, barrelSpeed);
    delay(barrelDelay);
    Serial.println("in for loop");
  }
  if (barrelSpeed > 250) {
    digitalWrite(barrelPin, HIGH);
  }
}*/

void recoilBarrel()
{
  digitalWrite(recoil, HIGH);
  delay(recoilDelay);
  digitalWrite(recoil, LOW);
  delay(recoilDelay);
}
