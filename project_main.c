//project_main.c
#include <LPC21xx.h>
#include "types.h"
#include "pins_main.h"
#include "defines.h"
#include "adc.h"
#include "kpm.h"
#include "delay.h"
#include "Lcd.h"
#include "rtc.h"
#include "interupt_main.h"
#include "Lcd_defines.h"
volatile u32 eint0_flag = 0;
volatile u8 in_menu = 0;
#define button 16
s32 hour, min, sec, date, month, year, day;
#define SLED 25

    u32 adcVal;
    float eAR;

int main()
{

    Init_KPM();
    InitLCD();
	  Init_ADC();
	RTC_Init();
    delay_ms(1);
    enable_eint0();
	  IODIR0|=1<<SLED;
	  //IOCLR0=1<<SLED;
    // Initial display
	SetRTCTimeInfo(0,27,40);
    GetRTCTimeInfo(&hour, &min, &sec);
    DisplayRTCTime(hour, min, sec);
    GetRTCDateInfo(&date, &month, &year);
    DisplayRTCDate(date, month, year);
    GetRTCDay(&day);
    DisplayRTCDay(day);
while(1) {
    // Auto streetlight logic
    if((hour >= 18 && hour <= 23) || (hour >= 0 && hour <= 6)) {
        Read_ADC(1, &adcVal, &eAR);			// adjust channel if needed
			  CmdLCD(GOTO_LINE2_POS0+9);
			  F32LCD(eAR,3);
			
        if(eAR >3.0f) {  // adcVal came 0x174 still it going to this if condition 
            IOSET0 = 1 << SLED;   // Turn ON LED in dark
        } else {
            IOCLR0 = 1 << SLED;   // Turn OFF LED in light
        }
    }

    // Handle external interrupt for menu
    if(eint0_flag) {
         
        handleMenu();
        eint0_flag = 0;
   
    } else {
        
            GetRTCTimeInfo(&hour, &min, &sec);
            DisplayRTCTime(hour, min, sec);
            GetRTCDateInfo(&date, &month, &year);
            DisplayRTCDate(date, month, year);
            GetRTCDay(&day);
            DisplayRTCDay(day);
        }
    

    delay_ms(100);
}

}

