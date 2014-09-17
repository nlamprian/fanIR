#include <Servo.h>
#include <IRremote.h>
#include "fanRemote.h"
#include "stateMachine.h"


// Servo variables
const uint8_t servoPin = 9;
const uint8_t servoEnable = 10;
Servo myServo;

// Remote variables
const uint8_t recvPin = 11;
fanRemote remote (recvPin);

// The angular orientations of the servo, for the various fan speeds, were 
// determined with the use of a potentiometer. The potentiometer was used to 
// rotate the servo and set the switch to the right position. Then the values
// returned by the pot were read (analogValues array). At last the map function 
// was used to map these analog values to degrees (angle array) that is 
// needed by the Servo library.
// const uint16_t analogValues[] = { 680, 500, 330, 550, 770, 930 };
const uint8_t angle[] = { 170, 130, 100, 60, 100, 130 };

// State machine current state
uint8_t currentState = OFF;


void setup ()
{
	// Servo initialization
	myServo.attach (servoPin);
	setSpeed (SPEED0_OFF);
  	
  	// Remote initialization
	remote.enable ();
	remote.pair (POWER, transition);
	remote.pair (A, transition);
	remote.pair (B, transition);
	remote.pair (C, transition);
} 


void loop ()
{
	remote.check ();
} 


// Performs state transitions for the state machine
void transition (uint8_t buttonTrigger)
{
	switch (currentState)
	{
		case OFF:
			if (buttonTrigger == T_A)
			{
				currentState = SPEED1;
				setSpeed (SPEED1_FORWARD);
			}
			else if (buttonTrigger == T_B)
			{
				currentState = SPEED2;
				setSpeed (SPEED2_FORWARD);
			}
			else if (buttonTrigger == T_C)
			{
				currentState = SPEED3;
				setSpeed (SPEED3_FORWARD);
			}
			break;
		case SPEED1:
			if (buttonTrigger == T_POWER)
			{
				currentState = OFF;
				setSpeed (SPEED0_OFF);
			}
			else if (buttonTrigger == T_B)
			{
				currentState = SPEED2;
				setSpeed (SPEED2_BACKWARD);
			}
			else if (buttonTrigger == T_C)
			{
				currentState = SPEED3;
				setSpeed (SPEED3_BACKWARD);
			}
			break;
		case SPEED2:
			if (buttonTrigger == T_POWER)
			{
				currentState = OFF;
				setSpeed (SPEED0_OFF);
			}
			else if (buttonTrigger == T_A)
			{
				currentState = SPEED1;
				setSpeed (SPEED1_FORWARD);
			}
			else if (buttonTrigger == T_C)
			{
				currentState = SPEED3;
				setSpeed (SPEED3_BACKWARD);
			}
			break;
		case SPEED3:
			if (buttonTrigger == T_POWER)
			{
				currentState = OFF;
				setSpeed (SPEED0_OFF);
			}
			else if (buttonTrigger == T_A)
			{
				currentState = SPEED1;
				setSpeed (SPEED1_FORWARD);
			}
			else if (buttonTrigger == T_B)
			{
				currentState = SPEED2;
				setSpeed (SPEED2_FORWARD);
			}
			break;
	}
}


// Sets the fan to the requested speed
void setSpeed (uint8_t fanSpeed)
{
	digitalWrite (servoEnable, HIGH);
	myServo.write (angle[fanSpeed]);
	delay (1000);
	digitalWrite (servoEnable, LOW);
}
