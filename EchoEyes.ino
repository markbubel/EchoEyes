int trigPin = 11;
int echoPin = 12;
long duration, cm;
int piezoPin = 8;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  
  if (cm < 300) {
    tone(8, 1500, 250);
  }
  
  if (cm < 200) {
    tone(8, 2500, 250);
  }
  
  if (cm < 140) {
    tone(8, 3500, 250);
  }
  
  if (cm < 70) {
    tone(8, 4500, 250);
  }
  
  if (cm < 30) {
    tone(8, 5500, 250);
  }
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
