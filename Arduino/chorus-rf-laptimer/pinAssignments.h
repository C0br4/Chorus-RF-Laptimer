/**
   DIY RF Laptimer by Andrey Voroshkov (bshep)
   SPI driver based on fs_skyrf_58g-main.c by Simon Chambers
   fast ADC reading code is by "jmknapp" from Arduino forum
   fast port I/O code from http://masteringarduino.blogspot.com.by/2013/10/fastest-and-smallest-digitalread-and.html

  The MIT License (MIT)

  Copyright (c) 2016 by Andrey Voroshkov (bshep)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

// Pin definitions

#define RX5808DataPin 6
#define RX5808SelectPin 7
#define RX5808ClockPin 8

#define pinRaspiInt 5 //digital
#define rssiPinA 3  //analog (D17)
#define voltagePinA 7  //analog
#define buzzerPin 9 // PWM buzzer

//#definePIN_MAX7219_DATA 11  //hardware SPI MOSI
//#definePIN_MAX7219_CLK 13   //hardware SPI SCK
#define PIN_MAX7219_CS 10

#define PIN_LED1_RED 4
#define PIN_LED1_GREEN 3
#define PIN_LED2_RED 2
#define PIN_LED2_GREEN 15
#define PIN_LED3_RED 16
#define PIN_LED3_GREEN 14

//#ifdef DEBUG    //no pins available atm
//  #define loopTimerPin 4
//  #define serialTimerPin 3
//#endif
