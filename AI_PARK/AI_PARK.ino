#include <TM1637.h>
#define CLK 3
#define DIO 2


TM1637 tm1637(CLK,DIO);

int num = 0;               //設定數碼管會用到的整數
int numdisplay = 0;
int dig1 = 0;  
int dig2 = 0;  
int dig3 = 0;  
int dig4 = 0;  


int soilMoistureSensorValue;

void setup() {
  // put your setup code here, to run once:
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);


  Serial.begin(115200);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


  soilMoistureSensorValue = analogRead(A0);
  Serial.println(soilMoistureSensorValue,DEC);

  numdisplay = soilMoistureSensorValue ;

  dig4 = numdisplay / 1000;
  numdisplay = numdisplay - (dig4 * 1000);
  dig3 = numdisplay / 100;
  numdisplay = numdisplay - (dig3 * 100);
  dig2 = numdisplay / 10;
  dig1 = numdisplay - ( dig2 * 10 );

  tm1637.display(0,dig4);
  tm1637.display(1,dig3);
  tm1637.display(2,dig2);
  tm1637.display(3,dig1);
  delay(200);

}

