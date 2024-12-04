#include "Sensor.h"
#include "LightSensor.h"
#include "SoundSensor.h"
#include "TemperatureSensor.h"
#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"


rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
Ultrasonic ultra = Ultrasonic(15);
LightSensor light = LightSensor();
SoundSensor sound = SoundSensor();
TemperatureSensor temp = TemperatureSensor();
void setup() {
  // put your setup code here, to run once:
  
  lcd.begin(16, 2);

  lcd.setRGB(colorR, colorG, colorB);
  light.init(A0);
  sound.init(A0);
  temp.init(1);

  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(1000);
}

void loop() {
 // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  
  lcd.print(sound.readValue());
}
