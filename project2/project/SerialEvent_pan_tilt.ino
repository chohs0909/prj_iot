#include<stdlib.h>
#include <Servo.h>

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

int pan_pos = 90;
int tilt_pos = 80;

Servo pan, tilt;


void setup() {
  // initialize serial:
 
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(20);     
  pan.attach(12);
  tilt.attach(13);
  pan.write(pan_pos);  delay(40);
  tilt.write(tilt_pos); delay(40);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    
    //Serial.println(inputString);
    // clear the string:
    
    if(inputString.substring(0,3) == "pan")
    {
      pan_pos = atoi(inputString.substring(3).c_str());
      Serial.print("pan :");      Serial.println(pan_pos);   
      pan.write(pan_pos);   
    }
    if(inputString.substring(0,4) == "tilt")
    {
      tilt_pos = atoi(inputString.substring(4).c_str());
      Serial.print("tilt :");      Serial.println(tilt_pos);   
      tilt.write(tilt_pos);    
    }
    inputString = "";
    stringComplete = false;
  }
}



/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
