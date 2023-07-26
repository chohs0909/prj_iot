#define ON HIGH
#define OFF LOW

const int pinSW1 = 4;
const int pinLED = 13;
const int debounce_delay = 180;
int led_state = 0;
void setup() {
  pinMode(pinSW1, INPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED Toggle by SW~");

}

void loop() {
int sw_in = digitalRead(pinSW1);
if(sw_in == ON)
{
  delay(debounce_delay);
  int sw_in = digitalRead(pinSW1);
  if(sw_in == ON)
  {
    led_state = !led_state;
    digitalWrite(pinLED, led_state);
  }
  
}
}
