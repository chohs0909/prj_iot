const int pinRed = 5;
const int pinGreen = 6;
const int pinBlue = 11;

void setup() {

  set_color(255, 0, 0);
  delay(1000);
  set_color(0, 255, 0);
  delay(1000);
  set_color(0, 0, 255);
  delay(1000);
  set_color(0xbf, 0xff, 0x00);
  delay(1000);
  set_color(0, 0, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
}

void set_color(int red, int green, int blue)
{
  analogWrite(pinRed, red);
  analogWrite(pinGreen, green);
  analogWrite(pinBlue, blue);
}
