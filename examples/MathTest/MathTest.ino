/**
 * Argochamber interactive 2016
 * Math Test/Example of Vectors
 */
#include <Vector.h>
#define DEFAULT_BAUDRATE 9600
#define SerialBegin() Serial.begin(DEFAULT_BAUDRATE)
#define sprint(x) Serial.print(x)

Vector a(1,2,3);
Vector b(4,5,6);
int r = 5;
Vector i(1,0,0);
int imod = i.length();

void setup() {
  SerialBegin();
  sprint("Vector A = ");
  sprint(a.toString());
  sprint("\nVector B = ");
  sprint(b.toString());
  sprint("\nVector a+b = ");
  sprint((a+b).toString());
  sprint("\nVector a*");
  sprint(r);
  sprint(" = ");
  sprint((a*r).toString());
  sprint("\nOrthonormal vector i = ");
  sprint(i.toString());
  sprint("\nModulo |i| = ");
  sprint(imod);
  sprint("\nModulo |a| = ");
  sprint((float)a.length());
}

void loop() {
  // put your main code here, to run repeatedly:

}
