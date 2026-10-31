int touchStart = 0;
bool touching = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(A2, INPUT);
}

void loop() {
  
  int elbowDown = digitalRead(A2);

  if (elbowDown == HIGH && !touching) {   // elbow just landed
    touching = true;
    touchStart = millis();
  }
  if (elbowDown == LOW) {                 // elbow lifted
    touching = false;
    digitalWrite(13, LOW);
  }

  // if elbow has been touching for more than 1 second, caught slouching
  if (touching && millis() - touchStart > 1000) {
    digitalWrite(13, HIGH);
  }

}
