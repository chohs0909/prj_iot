#define ON HIGH
#define OFF LOW

const int pinSW1 = 4;

void setup() {
  pinMode(pinSW1, INPUT);
  Serial.begin(9600);
  Serial.println("PROGRAM START");

}

void loop() {
int sw_in = digitalRead(pinSW1);
if(sw_in == ON)
Serial.println("on");
else;
}
