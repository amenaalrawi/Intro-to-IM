// naming our pins
int button1Pin = A3
int button2Pin = A0
int button3Pin = A2
int sensorPin =A1
int speakerPin = 8

int pitch = 0;

void setup() {
  //setting up all the pins as input
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
}

void loop() {
  // reading state from each pin
  int buttonState1 = digitalRead(button1Pin);
  int buttonState2 = digitalRead(button2Pin);
  int buttonState3 = digitalRead(button3Pin);
  
  // reading value from sensor
  int sensorValue = analogRead(sensorPin);
  // constrain sensor based off min and max readings
  sensorValue = constrain(sensorValue,210,315);
  // map pitch to sensor value
  pitch = map(sensorValue, 210, 315, 1500, 0);

  // if button 1 is pressed, play note
  if (buttonState1 == HIGH){
    tone(8,131 + pitch , 200);
    delay(300);
  }
  
  // if button 2 is pressed, play note
  if (buttonState2 == HIGH){
    tone(8, 147 + pitch, 200);
    delay(300);
  }
  
  // if button 3 is pressed, play note
  if (buttonState3 == HIGH){
    tone(8, 165 + pitch, 200);
    delay(300);
  }
  
}
