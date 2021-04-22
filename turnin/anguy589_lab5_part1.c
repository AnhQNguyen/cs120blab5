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
 unsigned char tmpA4 = 0x00;
 unsigned char tmpA5 = 0x00;
 unsigned char tmpA6 = 0x00;
 unsigned char tmpC = 0x00;


 while(1) {
  tmpA4 = PINA & 0x10; //reading from individual pins
  tmpA5 = PINA & 0x20;
  tmpA6 = PINA & 0x40;

   tmpA = PINA & 0x0F; //clear A6-A4, bc we only care about A3-A0

     if(tmpA >= 0x01 && tmpA <= 0x02) {
         tmpC = 0x60; //C5 and C6
     }
     else if(tmpA >= 0x03 && tmpA <= 0x04) {
       tmpC = 0x70; //C5C4 and C6

     }
     else if(tmpA >= 0x05 && tmpA <= 0x06) {
       tmpC = 0x38; //C5C4C3
     }
     else if(tmpA >= 0x07 && tmpA <= 0x09) {
       tmpC = 0x3C; //C5C4C3C2
     }
     else if(tmpA >= 0x0A && tmpA <= 0x0C) {
       tmpC = 0x3E; //C5C4C3C2C1
     }
     else if(tmpA >= 0x0D && tmpA <= 0x0F) {
       tmpC = 0x3F; //C5C4C3C2C1C0
     }
     else {
      tmpC = 0x40;
   
   }

     //C7 iff tmpA4 && tmpA5 && !tmpA6
     if((tmpA4 && tmpA5) && !tmpA6){
        PORTC = tmpC | 0x80; //retain existing 1s

     }
    else {
      PORTC = tmpC;
    }

    
 }

 return 1;

}
