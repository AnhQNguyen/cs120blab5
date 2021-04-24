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

enum c_states {smstart, init, wait, plus, minus, waitplus, waitminus, reset} state;
unsigned char inc = 0x00;
unsigned char dec = 0x00;

void c_counter() {
	inc = ~PINA & 0x01; //A0
	dec = ~PINA & 0x02; //A1

	//state transitions
	switch(state) {
		case smstart:
			state = init; 
			break;
		case init:
			state = wait; 
			break;
		case wait:
			if(inc && !dec) {
				state = plus;
			}
			else if(dec && !inc) {
				state = minus;
			}
			else if(inc && dec) {
				state = reset;
			
			}
			else {
				state = wait;
			}
			break;
		case plus:
			if(!inc) {
				state = wait;
			}
			else if(inc && dec) {
				state = reset;
			}
			else {
				state = waitplus;
			}
			break;
		case waitplus:
			if(!inc) {
				state = wait;
			}
			else if(inc && dec) {
				state = reset;
			}
			else {
				state = waitplus;
			}
			break;
		case minus:
			if(!dec){
				state = wait;
			}
			else if(inc && dec) {
				state = reset;
			}
			else {
				state = waitminus;
			}
			break;
		case reset:
			if(inc && dec) {
				state = reset;
			}
			else {
				state = wait;
			}
			break;
		default:
			state = smstart;
			break;

	}

	//state actions
	switch(state) {
		case smstart:
			break;
		case init:
			PORTC = 0x07;
			break;
		case wait:
			break;
		case plus:
			if(PORTC < 0x09) {
				PORTC = PORTC + 0x01;
			}
			
			break;
		case waitplus:
			break;
		case minus:
			if(PORTC > 0x00) {
				PORTC = PORTC - 0x01;
			}
			break;
		case waitminus:
			break;
		case reset:
			PORTC = 0x00;
			break;
		default:
			break;
	}




}


int main(void) {
  //initialize ports
  DDRA = 0x00; PORTA = 0xFF;
  DDRC = 0xFF; PORTC = 0x00;
  DDRC = 0x00; PORTB = 0xFF;

  state = smstart;
  PORTC = 0x07;
	
  //testing
  PORTB = state;

  while(1) {
  	c_counter();
  
  }  

  return 1;




}
