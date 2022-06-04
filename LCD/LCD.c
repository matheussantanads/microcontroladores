/***************************************
****************** LCD *****************
****************************************
*  Autor: github.com/matheussantanads  *
*  Microcontrolador: PIC16F887         *
*  IDE: MikroC Pro for PIC             *
****************************************
****************************************
****************************************/

sbit LCD_RS at RC5_bit;
sbit LCD_RS_Direction at TRISC5_bit;

sbit LCD_EN at RC4_bit;
sbit LCD_EN_Direction at TRISC4_bit;

sbit LCD_D4 at RC3_bit;
sbit LCD_D4_Direction at TRISC3_bit;

sbit LCD_D5 at RC2_bit;
sbit LCD_D5_Direction at TRISC2_bit;

sbit LCD_D6 at RC1_bit;
sbit LCD_D6_Direction at TRISC1_bit;

sbit LCD_D7 at RC0_bit;
sbit LCD_D7_Direction at TRISC0_bit;

void main() {

    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

    while(1){

        Lcd_Chr(1,4,'O');
        Lcd_Chr(1,5,'L');
        Lcd_Chr(1,6,'A');
        Lcd_Chr(1,7,' ');
        Lcd_Chr(1,8,'M');
        Lcd_Chr(1,9,'U');
        Lcd_Chr(1,10,'N');
        Lcd_Chr(1,11,'D');
        Lcd_Chr(1,12,'O');

        delay_ms(1000);
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_Cmd(_LCD_CURSOR_OFF);
        delay_ms(1000);

        Lcd_Out(1,4,"OLA MUNDO");
        
        delay_ms(1000);
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_Cmd(_LCD_CURSOR_OFF);
        delay_ms(1000);


    }

}