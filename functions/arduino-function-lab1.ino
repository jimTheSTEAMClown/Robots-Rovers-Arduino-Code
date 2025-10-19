// ============================================================================
// Source: STEAM Clown - www.steamclown.org 
// GitHub: https://github.com/jimTheSTEAMClown/Robots-Rovers-Arduino-Code
// Hacker: Jim Burnham - STEAM Clown, Engineer, Maker, Propmaster & Adrenologist 
// This example code under the GNU Lesser General Public License v3.0
// and any docs and lesson examples is licensed under the CC BY-NC-SA 3.0.
// https://creativecommons.org/licenses/by-nc-sa/3.0/
// Create Date:			2025-10-17 
// Design Name:			arduino-function-lab1.ino
// Description:     adaptation of blink on http://arduino.cc/
// Dependencies: 
// Target Board: Arduino Uno / Arduino R4 Wifi
// IDE used: 
// Revision: 
// Revision 0.02 - Updated from template to Function Lab1: 2025-10-19
// Revision 0.01 - Created: 2025-10-17
// Additional Comments: 
//
// ============================================================================

// Libraries:

// Global Pins
const int LED1 = 13;		// define as constant integer on pin 13 

// Global Varaibles

// Function Declarations & Global Variable associated with Functions

// Functions (I like to instantiate functions at the top above setup())

// ============================================================================
// The setup routine runs once when you load the sketch or press reset:
// This is where you define pin directions
void setup()
{
	// initialize Serial Communication
  Serial.begin(115200);
  // initialize the pins used in this sketch
	pinMode(LED1, OUTPUT);
}

// ============================================================================
// this "main" loop routine runs over and over again forever:
void loop()
{
	//Set pin LED1 to HIGH and This turns the LED on. 
	digitalWrite(LED1, HIGH);
	delay(1000);	//Wait for a second
	//Set pin LED1 LOW and This turns the LED off
	digitalWrite(LED1, LOW);
	delay(1000);	//Wait for a second
}
