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
enum c_states {c_smstart, c_init, c_wait, c_waitplus, c_plus, c_waitminus,c_minus, c_waitreset, c_reset} c_state;


void  c_counter() {
	unsigned char tempA0 = ~PINA & 0x01; 
	unsigned char tempA1 = ~PINA & 0x02;

	//state transitions
	switch(c_state)  {
		case c_smstart:
			c_state = c_init;
			break;
		case c_init:
			c_state = c_wait;
		case c_wait:
			if(tempA0 && !tempA1) {
				c_state = c_waitplus;
			}
			else if(!tempA0 && tempA1){
				c_state = c_waitminus;
			}
			else if(tempA0 && tempA1) {
				c_state = c_waitreset;
			}
			else {
				c_state = c_wait;
			}
			break;
		case c_waitplus:
			if(!tempA0) {
				c_state = c_plus;
			}
			else if(tempA0) {
				c_state = c_waitplus;
			}
			else {
				c_state = c_wait;
			}


			break;
		case c_plus:
			c_state = c_wait;
			break;
		case c_waitminus:
			if(!tempA1) {
                	    c_state = c_minus;
        		 }
	            	else if(tempA1){
                    		c_state = c_waitminus;
           		 }
			else {
				c_state = c_wait;
			}
    
           
           		 break;
		case c_minus:
			c_state = c_wait;
			break;
		case c_waitreset:
			if (tempA0 && tempA1) {
				c_state = c_waitreset;
			}
			else if (!tempA0 && !tempA1) {
				c_state = c_reset;
			}
			else {
				c_state = c_wait;
			}
			break;
		case c_reset:
			c_state = c_wait;
			break;
		default:
			break;
	
	}

	//state actions
	switch(c_state) {
		case c_smstart:
			break;
		case c_init:
			PORTC = 7;
			break;
		case c_wait:
			break;
		case c_waitplus:
			break;
		case c_plus:
			if(PORTC < 9) {
				PORTC = PORTC + 1;
			}
			break;
		case c_waitminus:
			break;
		case c_minus:
			if(PORTC > 0 ) {
				PORTC = PORTC - 1;
			}
			break;
		case c_waitreset:
			break;
		case c_reset:
			PORTC = 0;
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
  
  while(1) {
  	c_counter();	
  	
  }

  return 1;
}
