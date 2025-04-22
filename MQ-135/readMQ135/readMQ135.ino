/***
Name: Chris
Date: 2025.04.22
Function : Read MQ-135
Ref:


***/


#ifdef DIGI
int digitalValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalValue = digitalRead(0);
  Serial.println(digitalValue, DEC);
  delay(2000);
}
#else
int sensorValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(0);
  Serial.println(sensorValue, DEC);
  delay(2000);
}
#endif
