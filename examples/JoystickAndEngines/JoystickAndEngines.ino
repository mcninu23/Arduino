/**
 * Argochamber interactive 2016
 * Joystick & Engine
 */
#include <Engine.h>
#include <Joystick.h>

#define X_AXIS_PIN 5
#define Y_AXIS_PIN 4
#define PUSHBUTTON_PIN 3

Joystick joystick( X_AXIS_PIN, Y_AXIS_PIN, PUSHBUTTON_PIN );

unsigned char pinMap[] = { 13, 12, 11, 10 };
Engine engine(pinMap);
 
void setup() {
  point MAX;
  MAX.x = 0.98;
  MAX.y = 0.98;

  point MIN;
  MIN.x = 0.01;
  MIN.y = 0.01;

  joystick.setAxisBounds(MAX, MIN);

  //engine.setThrole(-0.8);

  Serial.begin(9600);
}


void loop() {
  //point pt = joystick.getAxis();
  //engine.setThrole(pt.x);
  //engine.loop();
  engine.stepDown();
  
  Serial.println(engine.getPhase());
  delay(10);
}
