# Frequency Measurement with PIC 16F877A

This project demonstrates frequency measurement using the PIC 16F877A microcontroller with 1 Hz uncertainty. It utilizes the MikroC compiler and an LCD for output.

## Description

The project measures frequency by counting the number of pulses in 1s using PIC 16F877A's Timer0 module. It employs an interrupt routine to handle the counting process and displays the frequency on an LCD screen.

## Hardware Setup

### LCD Pinout Settings
```c
sbit LCD_RS at RB1_bit;
sbit LCD_EN at RB2_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D4 at RB4_bit;
```
### Pin Direction
```c
sbit LCD_RS_Direction at TRISB1_bit;
sbit LCD_EN_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB7_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB4_bit;
```
## Variables
- `Fr_string[10]`: String variable to store the frequency value for LCD.
- `comp`: Counter variable to count the number of overflows in 1s.
- `compTime`: Counter variable to keep track of time intervals.
- `freq`: Variable to store the calculated frequency.

## Interrupt Function
- The interrupt function is triggered by an external interrupt (INTF).
- It clears the LCD screen, resets Timer0, and starts counting the number of overflows.
- After counting, it calculates the frequency and displays it on the LCD.

## Main Function
- Initializes the LCD.
- Enables global and external interrupts.
- Configures Timer0 for external clock source and rising edge trigger.
- Enters an infinite loop to keep the program running.

## Usage
1. Set up the hardware according to the provided pinout settings.
2. Compile and upload the code to the PIC 16F877A microcontroller using MikroC.
3. Power up the circuit.
4. Connect the signal source to be measured.
5. The LCD will display the measured frequency in Hertz (Hz).
