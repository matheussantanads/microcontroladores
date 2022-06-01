/***************************************
***************** Blink ****************
****************************************
*  Autor: github.com/matheussantanads  *
*  Microcontrolador: PIC16F887         *
*  IDE: MikroC Pro for PIC             *
****************************************
****************************************
****************************************/

#define PIN_LED PORTD.RD2

void main(){

    TRISD2_bit = 0;
    PIN_LED = 0;

    while(1){
        PIN_LED = 1;
        delay_ms(500);
        PIN_LED = 0;
        delay_ms(500);
    }

}