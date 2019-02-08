//output LED Vars
int blueLED = 10;
int greenLED = 9;
int blueLEDState;
int greenLEDState;

//analog input vars
int pot = A0;
int photo = A1;
int potVal;
int photoVal;

//mapped vars
int potMapped;
int photoMapped;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  //no need to declate analog pins for input
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  greenLEDState = digitalRead(greenLED);
  blueLEDState = digitalRead(blueLED);
  potVal = analogRead(pot);
  photoVal = analogRead(photo);

  Serial.print("GREEN: ");
  Serial.print(greenLEDState);
  Serial.print("\t");
  Serial.print("BLUE: ");
  Serial.print(blueLEDState);
  Serial.print("\t");
  Serial.print("POTENTIOMETER: ");
  Serial.print(potVal);
  Serial.print("\t");
  Serial.print("PHOTOCELL: ");
  Serial.print(photoVal);
  Serial.print("\t");
  Serial.println();
  delay(500);

  potMapped = map(potVal, 0, 1023, 1, 10);
  photoMapped = map(photoVal, 0, 890, 0, 10);
  Serial.println("MAPPED:");
  Serial.print("POTENTIOMETER: ");
  Serial.print(potMapped);
  Serial.print("\t");
  Serial.print("PHOTOCELL: ");
  Serial.println(photoMapped);
  delay(500);

  //as pot increases, increase flashing speed for green LED
  digitalWrite(greenLED, HIGH);
  delay(potMapped * 100);
  digitalWrite(greenLED, LOW);
  delay(potMapped * 100);

  //turn on blue LED when it gets darker
  if (photoMapped < 5) {
    digitalWrite(blueLED, HIGH);
  }
  else {
    digitalWrite(blueLED, LOW);
  }
}
