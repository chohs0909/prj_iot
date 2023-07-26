#define ON HIGH
#define OFF LOW

const int pinLED = 13;
const int pinSW1 = 4;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinSW1, INPUT);
  Serial.begin(9600);
  Serial.println("PROGRAM START");

}

void loop() {
int sw_in = digitalRead(pinSW1);
if(sw_in == ON)
digitalWrite(pinLED, HIGH);
else
digitalWrite(pinLED, LOW);

  
if(Serial.available()>0)
{
  char ch = Serial.read();
  if(ch == '1') digitalWrite(pinLED, HIGH);
  else if(ch == '0') digitalWrite(pinLED, LOW);
  else;
}



}
