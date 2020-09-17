#include <Servo.h>
#define threshold 145                          
#define unpress_angle 10                         
#define press_angle 30                                                                                                                                                
int sensorValue=0;
Servo myservo;

  bool trig=true;

void setup() {
  Serial.begin(9600);

  
  myservo.attach(13);
  myservo.write(unpress_angle);

}

void loop() {
  sensorValue= analogRead(A0);
  Serial.println(sensorValue);
  
  myservo.write(unpress_angle);
  delay(1);
  if(analogRead(A0)<threshold)
  {
    myservo.write(press_angle);
    delay(100);
  }

}
