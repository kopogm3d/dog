// C++ code
//
const int tringPin = 11;
const int echoPin = 12;
const int activeB = 4;


void setup()
{
  Serial.begin(115200);
  
  pinMode(tringPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(activeB, OUTPUT);
}

void loop()
{
  digitalWrite(tringPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tringPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(tringPin, LOW);
  
  
  long timeDistance = pulseIn(echoPin, HIGH);
  long distance = (timeDistance/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("cm");
  
  if(distance < 30) {
    digitalWrite(activeB, HIGH);
    delay(distance*10);
    digitalWrite(activeB, LOW);
    delay(distance*10);
  }
  
  
}
