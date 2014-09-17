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
 * Filename: fanRemote.cpp
 * File description: Implementation of methods for the fanRemote library
 */

#include "fanRemote.h"

// Creates an instance and initializes instance variables
fanRemote::fanRemote (uint8_t recvPin) : buttonAddress (address)
{
	for (uint8_t i = 0; i < 9; ++i) funcPointer[i] = NULL;
	
	irrecv = new IRrecv (recvPin);
}

// Starts the receiver
void fanRemote::enable ()
{
	irrecv->enableIRIn ();
}

// Pairs buttons with functions
// Each time a button is pressed, its paired function will be called
void fanRemote::pair (button b, func f)
{
	funcPointer[b] = f;
}

// Checks if a command has been received
// and executes the appropriate functions
void fanRemote::check ()
{
	if ( irrecv->decode (&results) ) 
	{
		for (uint8_t b = POWER; b < numButtons; ++b)
		{
			if ( results.value == buttonAddress[b] )
			{
				// !!! Change: Provided the pressed button to the callback
				if ( funcPointer[b] ) funcPointer[b] (b);
				break;
			}
		}
    	irrecv->resume ();
	}
}
