/***************************************
***************** Analog ***************
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

#define SBIT_ADON 0
#define SBIT_CHS0 2
#define SBIT_ADFM 7


void ADC_Init();
unsigned int ADC_Read(unsigned char canal);

const char degreeCharacter[] = {6,9,6,0,0,0,0,0};
void CustomChar(char pos_row, char pos_char);

void separarDigitos(float temp, int *cent, int *dezn, int *und, int *dec1, int *dec2);

float temperatura;
int centena, dezena, unidade, decimal1, decimal2;

void main() {

    TRISB2_bit = 1;
    TRISB3_bit = 1;

    ANSELH.ANS8 = 1;
    ANSELH.ANS9 = 1;

    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

    Lcd_Out(1,3,"Temperatura");

    ADC_Init();
    delay_ms(200);

    while(1){

        temperatura = ((int)ADC_Read(8) - (int)ADC_Read(9))*(5.0f/1023.0f/0.01f);
        
        if(temperatura < 0){
            LCD_OUT(2,3,"-");
        }else{
            LCD_OUT(2,3,"+");
        }

        separarDigitos(temperatura,&centena,&dezena,&unidade,&decimal1,&decimal2);

        LCD_CHR(2,5,centena +48);
        LCD_CHR_CP(dezena +48);
        LCD_CHR_CP(unidade +48);
        LCD_CHR_CP('.');
        LCD_CHR_CP(decimal1 +48);
        LCD_CHR_CP(decimal2 +48);

        CustomChar(2,12);
        LCD_OUT(2,13,"C");

        delay_ms(1000);

    }

}

void ADC_Init(){
    ADCON0 = 0x80;
    ADCON1 = (1<<SBIT_ADFM);
}

unsigned int ADC_Read(unsigned char canal) {
    ADCON0 = (1<<SBIT_ADON) | (canal<<SBIT_CHS0);
    Delay_us(20);
    GO_bit = 1;
    while(GO_bit == 1);
    return((ADRESH<<8) | ADRESL);
}

void separarDigitos(float temp, int *cent, int *dezn, int *und, int *dec1, int *dec2){

    if(temp < 0){
        temp = temp *-1;
    } 
    
    *cent = (((int)(temp/100))%10);
    *dezn = (((int)(temp/10))%10);
    *und  = (((int)(temp/1))%10);
    *dec1 = ((((int)(temp*100))%100)/10);
    *dec2 = (((int)((((int)(temp*100))%100)/1))%10);
}

void CustomChar(char pos_row, char pos_char){
    char i;
    Lcd_Cmd(64);
    for (i = 0; i<=7; i++) LCD_CHR_CP(degreeCharacter[i]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    LCD_CHR(pos_row, pos_char, 0);
}
  