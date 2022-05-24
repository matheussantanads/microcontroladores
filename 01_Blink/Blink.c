void main() {

     /*Configures analog pins as digital.*/
     ANSEL = 0;
     ANSELH = 0;
     
     /*Disable comparators.*/
     C1ON_bit = 0;
     C2ON_bit = 0;

     TRISB = 0b00000000; /*All pins on port B will be output.*/
     PORTB = 0b00000000; /*All pins on port B start at logic level 0.*/
     
     while(1){
          PORTB.RB0 = 0; /*Pin B0 receives logic level 0.*/
          delay_ms(500); /*Wait 0.5s*/
          PORTB.RB0 = 1; /*Pin B0 receives logic level 1.*/
          delay_ms(500); /*Wait 0.5s*/
     }
}