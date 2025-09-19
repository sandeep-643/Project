#ifndef RTC_DEFINES_H
#define RTC_DEFINES_H
#define CPU LPC2148
// System clock and peripheral clock Macros
#define FOSC	12000000
#define CCLK  (5*FOSC)   
#define PCLK  (CCLK/4)

// RTC Macros

#define PREINT_VAL 	(int)((PCLK / 32768) - 1)
#define PREFRAC_VAL (PCLK - ((PREINT_VAL + 1) * 32768))

#define RTC_CLKSRC  (1<<4)

#define RTC_ENABLE  (1<<0)
#define RTC_RESET   (1<<1)

#define AMRSEC_B 0
#define AMRMIN_B 1
#define AMRHOUR_B 2
#define AMRDOM_B 3
#define AMRDOW_b 4
#define AMRDOY_B 5
#define AMRMON_B 6
#define AMRYEAR_B 7

#endif
