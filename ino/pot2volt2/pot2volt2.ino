const unsigned int pinVR = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long int adc = analogRead(pinVR);
  /*
   5000(mv):1023 = x(mv):adc
    
  */
  long int mv = 5000 * adc / 1023;
  
  Serial.print("Volt =  ");
  Serial.print(mv/1000);
  Serial.print(".");
  Serial.print(mv%1000);
  Serial.println("(V)");
  delay(500);
}
