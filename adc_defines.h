//clock defines

#define FOSC  12000000
#define CCLK  (FOSC*5)
#define PCLK  (CCLK/4)
#define ADCLK (3000000)
#define CLKDIV ((PCLK/ADCLK)-1)


//DEFINES FOR adcr sfrs
#define CLKDIV_BITS          8 //@8 to 15
#define pdn_bit              21
#define ADC_CONV_START_BIT   24


//DEFINES FOR ADDR SFRS
#define DIGITAL_DATA_BITS  6  //6 TO 15
#define DONE_BIT 31

