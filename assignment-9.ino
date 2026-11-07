bool covered = false;
int led = 9;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT);

}

void loop() {
  // used to map brightness of LED to sensorValue
  int buttonState = digitalRead(A1);
  int sensorValue = analogRead(A2);
  sensorValue = constrain(sensorValue, 875, 930);
  brightness = map(sensorValue,930,875,0,255);

  // prints sensor value in the serial terminal
  // used to adjust constraints
  Serial.println(sensorValue);

  // change brightness of LED
  analogWrite(led, brightness);
  
  // if brightness == 255, then the photocell is covered, otherwise it isn't
  if (brightness == 255)
    covered = true;
  else if (brightness == 0)
    covered = false;

  // if the button is pressed and the photocell is covered, turn on the green LED
  if (buttonState == HIGH && covered == true)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
