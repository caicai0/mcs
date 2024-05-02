#include <Arduino.h>

#include "EPD_Driver.h"

#define SCREEN 1200
#include "demoImageData.h"

void reverse(unsigned char * x) {
  *x = (((*x & 0XAA) >> 1) | ((*x & 0X55) << 1));
  *x = (((*x & 0XCC) >> 2) | ((*x & 0X33) << 2));
  *x = ((*x >> 4) | (*x << 4));
}

void setup() {
  pins_t eps =
{
    .panelBusy = 25, /// EPD_BUSY_PIN
    .panelDC = 27, /// EPD_DC_PIN
    .panelReset = 26, /// EPD_RST_PIN
    .panelCS = 15, // EPD_CS_PIN
    .panelON_EXT2 = NOT_CONNECTED,
    .panelSPI43_EXT2 = NOT_CONNECTED,
    .flashCS = NOT_CONNECTED
};
  EPD_Driver epdtest(eScreen_EPD_B98, eps);
  // Initialize CoG
  epdtest.COG_initial();
  // Global Update Call
  epdtest.globalUpdate(Masterfm1, Masterfm2, Slavefm1, Slavefm2);
  // Turn off CoG
  // epdtest.COG_powerOff();

  delayMicroseconds(10000);

  epdtest.COG_initial();

  epdtest.globalUpdate(Masterfm1, Masterfm2, Slavefm1, Slavefm2);

  // epdtest.COG_powerOff();
}

void loop() {

}