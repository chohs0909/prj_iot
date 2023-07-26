/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#define MAX 180
#define MIN 0
#define STEP 3
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  Serial.println("serial to servo");
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
}

void loop() {
if(Serial.available() > 0){
  
  char ch = Serial.read();
  if(ch == '=') //'+'
  {  
  if(pos + STEP <= MAX) pos = pos + STEP;
  else pos = MAX;
}
  else if(ch == '-') //'-'
  {
  if(pos - STEP >= MIN) pos = pos - STEP;
  else pos = MIN;
}
  else;
  myservo.write(pos);
  Serial.print("pos = ");
  Serial.println(pos, DEC);
    }
}
