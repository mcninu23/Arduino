/**
 * Engine Controller
 * Author: Pablo Blanco Celdr�n
 * Argochamber Interactive 2016
 * 23 - 01 - 2016
 */

#ifndef __ENGINE_H
#define __ENGINE_H

#include <Common.h>

#define DEFAULT_DRIVE_MODE MODE_UNIPOLAR
#define DEFAULT_STEP_ANGLE 1.9 //Degrees of step.
#define DEFAULT_PHASE_COUNT 4 //How many coils does the engine have.
#define MAX_DELAY 200 // The longest delay (Smallest frequency)

/**
 * Enumerate the drive modes ensures that the user will not attempt to construct an engine with an unknown
 * drive mode value.
 */
enum DriveMode {
	MODE_UNIPOLAR,
	MODE_BIPOLAR_HALF,
	MODE_BIPOLAR_FULL
};

class Engine {
public:
	Engine(byte_t map[]); // constructor takes the "DEFAULT_MODE" as the desired mode.
	Engine(byte_t map[], DriveMode mode); // Main constructor.
	Engine(byte_t map[], DriveMode mode, byte_t count); // This also sets the phase count.
	
	short getPhase(); // Returns the step phase of the engine.
	void stepUp(); // Drives the engine one step forward
	void stepDown(); // Drives the engine one step backward
	void resetAngle(); // Sets the absolute angle to 0
	long int getAngle(); // Gets the angle that the engine has driven since last reset or the start.
	void gotoAngle(long target); // this will set the drive mode ON.
	void setCoilMapping(byte_t map[]); // Pin mappings.
	void setThrole(long double throle); // Sets the throle forward or backwards to the engine.
	double long getThrole(); // Gets the throle.
	void loop(); // Call every loop.
	
private:
	byte_t phase; // This is the step phase of the engine.
	DriveMode driveMode; // How the engine is being driven.
	long int angle; // This is how many steps the engine has gone forward or backward, from the origin.
	short phaseCount; // How many phases does have the engine.
	byte_t *pinMapping; // Byte array to set the output.
	long double throle; // The forward/backwards throle (-1.0, 0.0, 1.0)
	long int targetAngle = 0; // The target angle if gotoAngle() is invoked.
	bool gotoMode = false; // The go-to mode.
	unsigned long lastTime; // Internal value, used to calculate the throle.
	unsigned long interval; // Internal value, used to calc the interval upon the throle.
	
	void setCoilOutput(); // This adjusts the arduino's pins.
	void setPinMode(int mode); // Pin mode for all the pins of the engine.
	unsigned long calcInterval(); // Calculates the interval upon the throle value.
	void tick(); // Called internally, when the interval value is reached, the engine steps up or down.
};

#endif
