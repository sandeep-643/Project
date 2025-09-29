<h1>🌍 EcoLight Maestro – Time & Intensity Adaptive Street Light Automation</h1>
📖 Introduction

EcoLight Maestro is a smart streetlight automation system that controls streetlight LEDs in real-time using a Real-Time Clock (RTC), Light Dependent Resistor (LDR), LCD display, and keypad input.
It saves energy by turning on lights only when needed — based on both time (18:00–06:00) and ambient light intensity.

This project combines embedded systems, sensors, and automation for practical applications in smart cities and energy-efficient lighting.

<h2>📑 Table of Contents</h2>

Features

System Workflow

Hardware Requirements

Software Requirements

Installation

Usage

Configuration

Troubleshooting

Contributors

License

<h2>✨ Features</h2>h2

Real-time date, time, and day display on LCD

Automatic streetlight LED control based on:

Time window (18:00–06:00)

Ambient light (LDR input)

RTC edit mode via external interrupt + keypad

Low-power and energy-efficient design

User-friendly hardware and software interface

<h2>🔄 System Workflow</h2>
Power ON → Initialize peripherals
↓
Main Loop → Display Date/Time
↓
Check Time (18:00–06:00)?
↓ Yes                No ↓
Read LDR (ADC)     Just display RTC info
↓
Below Threshold → LEDs ON
Above Threshold → LEDs OFF

Interrupt Occurs?
↓
Yes → Show Edit Menu → Validate & Update RTC
No  → Continue main loop

🛠 Hardware Requirements

Microcontroller (Arduino / ATmega / PIC)

RTC module (DS1307 / DS3231)

LDR sensor + resistor divider

16x2 LCD Display

Keypad (for RTC editing)

LEDs (streetlight simulation)

Push button (external interrupt trigger)

Power supply & jumper wires

<h2>💻 Software Requirements</h2>

Arduino IDE / AVR Studio / MPLAB (depending on MCU)

Embedded C for firmware

Git for version control

📥 Installation

Clone the repository:

git clone https://github.com/sandeep-643/Project.git
cd Project


Open the code in your preferred IDE.

Connect hardware components as per the schematic.

Compile and upload the code to your microcontroller.

🚦 Usage

Power on the system → LCD shows time, date, and day.

Between 18:00–06:00, the LDR controls LEDs:

Dark environment (below threshold) → LEDs ON

Bright environment (above threshold) → LEDs OFF

Press interrupt button → Edit RTC values via keypad.

System continues to loop, automatically adjusting lights.

⚙️ Configuration

LDR Threshold → set in firmware (#define LDR_THRESHOLD ...).

RTC Settings → user-configurable via keypad.

LED pins & LCD pins → update in code to match hardware wiring.

🛠 Troubleshooting

LCD not showing data → Check contrast pin, wiring, or I2C/SPI connections.

RTC not updating → Verify battery and SDA/SCL wiring.

LEDs not switching → Adjust LDR threshold or check ADC wiring.

Interrupt not working → Ensure button is connected to correct INT pin.

<h2>👥 Contributors</h2>

Sandeep
 – Developer & Maintainer

<h2>📜 License</h2>

This project is licensed under the MIT License – you are free to use, modify, and distribute with attribution.
