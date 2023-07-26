const int pinVR = A0;
const int pinLED = 13;
const int debounce_delay = 180;
int led_state = 0;
unsigned int adc = 0;
double volt = 0.0;
void setup() {
  //pinMode(pinSW1, INPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("adc start");

}

void loop() {
  adc = analogRead(pinVR);
  volt = 5 * adc / 1023.0;

Serial.print("Voltage = ");
Serial.print(volt);
Serial.println("(V)");
delay(500);
}
