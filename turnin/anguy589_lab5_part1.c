/*	Author: anguy589
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.*/

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

  //initialize ports
  DDRA = 0x00; PORTA = 0xFF;
  DDRC = 0x00; PORTC = 0x00;

  //temporary variables
  unsigned char tmpA = 0x00;
  unsigned char tmpC = 0x00;


  while(1) {
    tmpA = PINA & 0x0F;
    
      if((tmpA >= 0x01 && tmpA <= 0x02)) {
          PORTC = 0x60; //C5 and C6
      }
      else if(tmpA >= 0x03 && tmpA <= 0x04) {
        PORTC = 0x70; //C5C4 and C6

      }
      else if(tmpA >= 0x05 && tmpA <= 0x06) {
        PORTC = 0x38; //C5C4C3
      }
      else if(tmpA >= 0x07 && tmpA <= 0x09) {
        PORTC = 0x3C; //C5C4C3C2
      }
      else if(tmpA >= 0x0A && tmpA <= 0x0C) {
        PORTC = 0x3E; //C5C4C3C2C1
      }
      else if(tmpA >= 0x0D && tmpA < 0x0F) {
        PORTC = 0x3F; //C5C4C3C2C1C0
      }
    else {
        PORTC = 0x40;
      
    }

  }

  return 1;

}
