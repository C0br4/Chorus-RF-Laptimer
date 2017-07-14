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
#define BLANK "        "
#define DISPLAY_BRIGHTNESS 15         // 0..15
#define DISPLAY_TIMERUPDATECYCLES 300        // redraw lap time every nth loop cycle

LedControl display = LedControl(PIN_MAX7219_CS, 2);

uint8_t loopCycle = 0;


void initTimerDisplay() {
  
  display.shutdown(0, false);
  display.shutdown(1, false);
  display.setIntensity(0, 15);
  display.setIntensity(1, 15);
  display.clearDisplay(0);
  display.clearDisplay(1);
}

void displayString8(uint8_t displaynum, char* str) {

  for (uint8_t i = 0; i < strlen(str) && i < 8; ++i)
  {
    display.setChar(displaynum, 7 - i, str[i], false);
  }
}

void displayTime(uint8_t displaynum, uint32_t time) {
  //TODO  - have a buffer to compare to and only setDigit if digit changed
  //      - speed up time decomposition with some clever binary math wizardry and make variable declaration more efficient

  int ms = time % 1000;
  int s = time / 1000;
  int min = s / 60;
  int h = min / 60;
  min = min % 60;
  s = s % 60;

  if (h == 0) //ommit hours if zero
    display.setChar(displaynum, 7, ' ', false);
  else
    display.setDigit(displaynum, 7, h == 0 ? ' ' : h, true);

  if (min > 9 || h > 0) //ommit trailing zero
    display.setDigit(displaynum, 6, (min / 10) % 10, false);
  else
    display.setChar(displaynum, 6, ' ', false);

  display.setDigit(displaynum, 5, min % 10, true);
  display.setDigit(displaynum, 4, (s / 10) % 10, false);
  display.setDigit(displaynum, 3, s % 10, true);
  display.setDigit(displaynum, 2, (ms / 100) % 10, false);
  display.setDigit(displaynum, 1, (ms / 10) % 10, false);
  display.setDigit(displaynum, 0, ms % 10, false);
}
