/**
 * Argochamber interactive 2016
 * Engine usage example
 */
#include <Engine.h>

unsigned char pinMap[] = { 13, 12, 11, 10 };

Engine engine(pinMap);

void setup() {
  engine.setThrole(0.98);
}

void loop() {
  // And the engine goes forward.
  engine.loop();
}
