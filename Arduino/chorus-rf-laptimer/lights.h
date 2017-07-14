/**
 * DIY RF Laptimer by Andrey Voroshkov (bshep)
 * SPI driver based on fs_skyrf_58g-main.c by Simon Chambers
 * fast ADC reading code is by "jmknapp" from Arduino forum
 * fast port I/O code from http://masteringarduino.blogspot.com.by/2013/10/fastest-and-smallest-digitalread-and.html

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

// We have common anode LEDs (swap values below for common cathode LEDs)
#define LED_ON LOW
#define LED_OFF HIGH


#define LIGHT_OFF 0
#define LIGHT_RED 1
#define LIGHT_YELLOW 2
#define LIGHT_GREEN 3


void initLights() {

  pinAsOutput(PIN_LED1_RED);
  pinAsOutput(PIN_LED1_GREEN);
  pinAsOutput(PIN_LED2_RED);
  pinAsOutput(PIN_LED2_GREEN);
  pinAsOutput(PIN_LED3_RED);
  pinAsOutput(PIN_LED3_GREEN);
}

void setLight(uint8_t pin, uint8_t ledstate) {

  if (ledstate == LOW)
    digitalLow(pin);
  else if (ledstate == HIGH)
    digitalHigh(pin);
}

void setLightColor(uint8_t lightnum, uint8_t color) {

  uint8_t ledredpin = 0;
  uint8_t ledgreenpin = 0;

  switch (lightnum) {
    case 1:
      ledredpin = PIN_LED1_RED;
      ledgreenpin = PIN_LED1_GREEN;
      break;
    case 2:
      ledredpin = PIN_LED2_RED;
      ledgreenpin = PIN_LED2_GREEN;
      break;
    case 3:
      ledredpin = PIN_LED3_RED;
      ledgreenpin = PIN_LED3_GREEN;
  }

  switch (color) {
    case LIGHT_OFF:
      setLight(ledredpin, LED_OFF);
      setLight(ledgreenpin, LED_OFF);
      break;
    case LIGHT_RED:
      setLight(ledredpin, LED_ON);
      setLight(ledgreenpin, LED_OFF);
      break;
    case LIGHT_YELLOW:
      setLight(ledredpin, LED_ON);
      setLight(ledgreenpin, LED_ON);
      break;
    case LIGHT_GREEN:
      setLight(ledredpin, LED_OFF);
      setLight(ledgreenpin, LED_ON);
      break;
  }
}

void setLightColorAll(uint8_t color){

  setLightColor(1, color);
  setLightColor(2, color);
  setLightColor(3, color);
}
