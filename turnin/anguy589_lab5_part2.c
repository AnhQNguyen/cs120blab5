/*	Author: anguy589
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.*/

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//global variables
enum c_states {c_smstart, c_init, c_wait, c_waitplus, c_plus, c_waitminus,c_minus, c_reset} c_state;

unsigned char tempC = 0x00;


void  c_counter() {
	unsigned char tempA0 = ~PINA & 0x01; 
	unsigned char tempA1 = ~PINA & 0x02;

	//state transitions
	switch(c_state)  {
		case c_smstart:
			c_state = c_init;
			break;
		case c_init:
			break;
		case c_wait:
			if(tempA0 && !tempA1) {
				c_state = c_waitplus;
			}
			else if(!tempA0 && tempA1){
				c_state = c_waitminus;
			}
			else if(tempA0 && tempA1) {
				c_state = c_reset;
			}
			else {
				c_state = c_wait;
			}
			break;
		case c_waitplus:
			if(tempA0 && !tempA1) {
				//holding down A0
				c_state = c_waitplus;
			}
			else if(!tempA0 && !tempA1){
				c_state = c_plus;
			}
			else if (tempA0 && tempA1) {
				c_state = c_reset;
			}
			else if(!tempA0 && tempA1) {
				c_state = c_waitminus;
			}
			else {
				c_state = c_wait;
			}
			break;
		case c_plus:
			c_state = c_wait;
			break;
		case c_waitminus:
			if(!tempA0 && tempA1) {
                                //holding down A1
                                c_state = c_waitminus;
                        }
                        else if(!tempA0 && !tempA1){
                                c_state = c_minus;
                        }
                        else if (tempA0 && tempA1) {
                                c_state = c_reset;
                        }
                        else if(!tempA0 && tempA1) {
                                c_state = c_waitplus;
                        }
                        else {
                                c_state = c_wait;
                        }
                        break;
		case c_minus:
			c_state = c_wait;
			break;
		case c_reset:
			if(tempA0 && tempA1) {
			 	c_state = c_reset;
			}
			else {
				c_state = c_wait;
			}
			break;
		default:
			break;
	
	}

	//state actions
	switch(c_state) {
		case c_smstart:
			break;
		case c_init:
			break;
		case c_wait:
			break;
		case c_waitplus:
			break;
		case c_plus:
			if(tempC < 0x09) {
				tempC = tempC + 1;
			}
			break;
		case c_waitminus:
			break;
		case c_minus:
			if(tempC > 0 ) {
				tempC = tempC - 1;
			}
		case c_reset:
			tempC = 0;
			break;
		default:
			break;
	
	
	
	
	}


}

int main() {

  //initialize ports
  DDRA = 0x00; PORTA = 0xFF;
  DDRC = 0x00; PORTC = 0x00;

  //start
  c_state = c_smstart;
  tempC = 0x07;
  while(1) {
 
  	c_counter();
	PORTC = tempC;
  	
  }

  return 1;
}
