#include "Lcd_defines.h"
#include "Lcd.h"
#include "kpm.h"
#include "delay.h"
#include "kpm_calci.h"
int main(void) {
    unsigned char  key;
    char expr[20];
int i=0;
    InitLCD();
    Init_KPM();

    StrLCD("calci...");
	CmdLCD(GOTO_LINE2_POS0);
    while (1) {
        key = keyScan();
			CharLCD(key);
        
        if(key=='c'){
            expr[0]='\0';
            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("               ");
            i=0;
            delay_us(60);
            CmdLCD(GOTO_LINE2_POS0);
        }
        else if(key=='='){
            expr[i++]='=';
            expr[i]='\0';
            dispCalc(expr);
        }	 

        else{
				expr[i++]=key;
				}					
			
        while (ColScan());  // wait for release
        
    }
}
