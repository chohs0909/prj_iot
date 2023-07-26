const int pinBuz = 3;
unsigned int note[] = {262, 294,330, 349, 392, 440, 494, 523};
void setup() {
  for(int i = 0; i< 8; i++)
  {
  tone(pinBuz,note[i]);
  delay(500);
  noTone(pinBuz);
  }
}

void loop() {

}
