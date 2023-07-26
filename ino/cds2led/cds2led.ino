const unsigned int pinCdS = A1;
const unsigned int pinLED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  long int adc = analogRead(pinCdS);

 if(adc < 200)  digitalWrite(pinLED, HIGH);
 else           digitalWrite(pinLED, LOW);
  Serial.print("adc =  ");
  Serial.println(adc);
  delay(500);
}
