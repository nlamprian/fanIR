/**
 * Name: fanRemote
 * Author: Nick Lamprianidis { paign10.ln@gmail.com }
 * Version: 1.0
 * Description: This is a slightly modified version of the IRRemoteControl 
 *              library ( https://github.com/pAIgn10/IRRemoteControl ).
 *              I tweaked the library to allow for the callbacks to ask 
 *              for the pressed button
 * License: Copyright (c) 2014 Nick Lamprianidis
 *          This library is licensed under the MIT license
 *          http://www.opensource.org/licenses/mit-license.php
 *
 * Filename: fanRemote.h
 * File description: Definitions and methods for the fanRemote library
 */

#ifndef fanRemote_h
#define fanRemote_h

#include <Arduino.h>
#include <IRremote.h>

// List of the remote's buttons
enum button
{
	POWER,
	A,
	B,
	C,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SELECT
};

const uint8_t numButtons = 9;  // # of buttons on the remote

// Commands for the buttons, in the order they appear in the enumeration "button"
const uint32_t address[] = { 0x10EFD827, 0x10EFF807, 0x10EF7887,
							 0x10EF58A7, 0x10EFA05F, 0x10EF00FF,
							 0x10EF10EF, 0x10EF807F, 0x10EF20DF };

// Signature of the functions that will be paired with buttons
// !!! Change: The signature of the function was modified to include 
//             a parameter for the pressed button
typedef void (*func) (uint8_t);

// Class for setting up a remote and controlling responses to remote triggers
class fanRemote
{
public:
    fanRemote (uint8_t recvPin);
    void enable ();
    void pair (button b, func f);
    void check ();

private:
	const uint32_t *buttonAddress;
	func funcPointer[numButtons];
	IRrecv *irrecv;
	decode_results results;
};

#endif  // fanRemote
