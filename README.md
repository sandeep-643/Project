# Project
EcoLight Maestro-Time-Intensity Adaptive Street Light Automation
his project implements a real-time streetlight control system using an RTC, LDR, LCD, keypad, LEDs, and external interrupt. The system displays the current time, date, and day on an LCD and automatically controls streetlight LEDs based on both time and ambient light intensity.



Power ON → Initialize peripherals  
        ↓  
Main Loop → Display Date/Time  
        ↓  
Check Time (18:00–06:00)?  
        ↓ Yes                                No ↓  
   Read LDR (ADC)                         Just display RTC info  
   ↓  
   Below Threshold → LEDs ON  
   Above Threshold → LEDs OFF  

Interrupt Occurs? → Yes → Show Edit Menu → Validate & Update RTC  
                 → No  → Continue main loop
