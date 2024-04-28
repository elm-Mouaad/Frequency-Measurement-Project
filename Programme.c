// Lcd pinout settings
sbit LCD_RS at RB1_bit;
sbit LCD_EN at RB2_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D4 at RB4_bit;
// Pin direction
sbit LCD_RS_Direction at TRISB1_bit;
sbit LCD_EN_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB7_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB4_bit;
char Fr_string[10];
int comp = 0;
int compTime = 0;
int freq;
//interruption fonction
void interrupt(){
     if(INTCON.INTF){

                         INTCON.INTF = 0;
                         Lcd_Cmd(_LCD_CLEAR);
                         TMR0 = 0;
                         INTCON.T0IF = 0;
                         while(compTime<250){
                                              compTime++;
                                              delay_ms(10);
                                              if(INTCON.T0IF){
                                                              INTCON.T0IF = 0;
                                                              comp ++;
                                              }
                         }
                         freq = comp*255 + TMR0;
                         IntToStr(freq,Fr_string);
                         Lcd_Out(1,1,strcat(Fr_string,"Hz"));
                         compTime = 0;
                         comp = 0;
     }
}
void main() {
    Lcd_Init();
    INTCON.GIE = 1;
    INTCON.INTE = 1;
    OPTION_REG.T0CS = 1;
    OPTION_REG.T0SE = 1;
    while(1){}
}
