/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            22
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 22 : -1)
#define digitalPinHasPWM(p)         ((((p) == 2) || (p) >= 4 && (p) <= 6) || (p) >= 19 && (p) <= 21))

static const uint8_t SS   = 9;
static const uint8_t MOSI = 10;
static const uint8_t MISO = 11;
static const uint8_t SCK  = 12;

static const uint8_t SDA = 16;
static const uint8_t SCL = 15;
static const uint8_t LED_BUILTIN = 21;

static const uint8_t CHG_STATUS = 17;
static const uint8_t BATT_CHECK = 18;
static const uint8_t LED_BLUE = 19;
static const uint8_t LED_RED = 20;
static const uint8_t LED_GREEN = 21;

static const uint8_t A0 = 22;
static const uint8_t A1 = 23;
static const uint8_t A2 = 24;
static const uint8_t A3 = 25;
static const uint8_t A4 = 26;
static const uint8_t A5 = 27;
static const uint8_t A6 = 28;
static const uint8_t A7 = 29;

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 24) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 24) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t)&DDRB,
	NOT_A_PORT,
	(uint16_t)&DDRD,
	(uint16_t)&DDRE,
	(uint16_t)&DDRF,
	(uint16_t)&DDRG,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t)&PORTB,
	NOT_A_PORT,
	(uint16_t)&PORTD,
	(uint16_t)&PORTE,
	(uint16_t)&PORTF,
	(uint16_t)&PORTG,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	NOT_A_PIN,
	(uint16_t)&PINB,
	NOT_A_PIN,
	(uint16_t)&PIND,
	(uint16_t)&PINE,
	(uint16_t)&PINF,
	(uint16_t)&PING,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// ~: PWM, *: external interrupt
	// -------------------------------------------		
	PE	, // PE 0 ** D0  ** USART0_RX	
	PE	, // PE 1 ** D1  ** USART0_TX	
	PB	, // PB 7 ** D2  ** D2~
	PE	, // PE 2 ** D3  ** D3
	PE	, // PE 3 ** D4  ** D4~
	PE	, // PE 4 ** D5  ** D5*~
	PE	, // PE 5 ** D6  ** D6*~
	PE	, // PE 6 ** D7  ** D7*
	PE	, // PE 7 ** D8  ** D8*
	PB	, // PB 0 ** D9  ** SPI_SSN
	PB	, // PB 2 ** D10 ** SPI_MOSI
	PB	, // PB 3 ** D11 ** SPI_MISO
	PB	, // PB 1 ** D12 ** SPI_SCK
	PD	, // PD 2 ** D13 ** USART1_RX*
	PD	, // PD 3 ** D14 ** USART1_TX*	
	PD	, // PD 0 ** D15 ** I2C_SCL*
	PD	, // PD 1 ** D16 ** I2C_SDA*
	PD	, // PD 6 ** D17 ** CHG_STATUS
	PD	, // PD 7 ** D18 ** BATT_CHECK
	PB	, // PB 4 ** D19 ** LED_BLUE~
	PB	, // PB 5 ** D20 ** LED_RED~
	PB	, // PB 6 ** D21 ** LED_GREEN~	
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT
	// ~: PWM, *: external interrupt		
	// -------------------------------------------		
	_BV(PE0)	, // PE 0 ** D0  ** USART0_RX
	_BV(PE1)	, // PE 1 ** D1  ** USART0_TX
	_BV(PB7)	, // PB 7 ** D2  ** D2~
	_BV(PE2)	, // PE 2 ** D3  ** D3
	_BV(PE3)	, // PE 3 ** D4  ** D4~
	_BV(PE4)	, // PE 4 ** D5  ** D5*~
	_BV(PE5)	, // PE 5 ** D6  ** D6*~
	_BV(PE6)	, // PE 6 ** D7  ** D7*
	_BV(PE7)	, // PE 7 ** D8  ** D8*
	_BV(PB0)	, // PB 0 ** D9  ** SPI_SSN
	_BV(PB2)	, // PB 2 ** D10 ** SPI_MOSI
	_BV(PB3)	, // PB 3 ** D11 ** SPI_MISO
	_BV(PB1)	, // PB 1 ** D12 ** SPI_SCK
	_BV(PD2)	, // PD 2 ** D13 ** USART1_RX*
	_BV(PD3)	, // PD 3 ** D14 ** USART1_TX* 	
	_BV(PD0)	, // PD 0 ** D15 ** I2C_SCL*
	_BV(PD1)	, // PD 1 ** D16 ** I2C_SDA*
	_BV(PD6)	, // PD 6 ** D17 ** CHG_STATUS
	_BV(PD7)	, // PD 7 ** D18 ** BATT_CHECK
	_BV(PB4)	, // PB 4 ** D19 ** LED_BLUE~
	_BV(PB5)	, // PB 5 ** D20 ** LED_RED~
	_BV(PB6)	, // PB 6 ** D21 ** LED_GREEN~
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
    // TIMERS		
    // ~: PWM, *: external interrupt
	// -------------------------------------------
    NOT_ON_TIMER 	, // PE 0 ** D0  ** USART0_RX
	NOT_ON_TIMER 	, // PE 1 ** D1  ** USART0_TX
	TIMER0A     	, // PB 7 ** D2  ** D2~
	NOT_ON_TIMER    , // PE 2 ** D3  ** D3
	TIMER3A      	, // PE 3 ** D4  ** D4~
	TIMER3B	        , // PE 4 ** D5  ** D5*~
	TIMER3C      	, // PE 5 ** D6  ** D6*~
	NOT_ON_TIMER	, // PE 6 ** D7  ** D7*
	NOT_ON_TIMER    , // PE 7 ** D8  ** D8*
	NOT_ON_TIMER	, // PB 0 ** D9  ** SPI_SSN
	NOT_ON_TIMER	, // PB 2 ** D10 ** SPI_MOSI
	NOT_ON_TIMER	, // PB 3 ** D11 ** SPI_MISO
	NOT_ON_TIMER	, // PB 1 ** D12 ** SPI_SCK
	NOT_ON_TIMER	, // PD 2 ** D13 ** USART1_RX*
	NOT_ON_TIMER	, // PD 3 ** D14 ** USART1_TX* 		
	NOT_ON_TIMER	, // PD 0 ** D15 ** I2C_SCL*
	NOT_ON_TIMER	, // PD 1 ** D16 ** I2C_SDA*
	NOT_ON_TIMER	, // PD 6 ** D17 ** CHG_STATUS
	NOT_ON_TIMER	, // PD 7 ** D18 ** BATT_CHECK
	TIMER2A     	, // PB 4 ** D19 ** LED_BLUE~
	TIMER1A     	, // PB 5 ** D20 ** LED_RED~
	TIMER1B     	, // PB 6 ** D21 ** LED_GREEN~
};

#endif

#endif