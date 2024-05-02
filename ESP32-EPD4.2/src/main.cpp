#include <Arduino.h>
#include <SPI.h>
#include "EPD_Driver.h"

#define SCREEN 420

#include "demoImageData.h"

// #define EPD_SCK_PIN  13
// #define EPD_MOSI_PIN 14
// #define EPD_CS_PIN   15
// #define EPD_RST_PIN  26
// #define EPD_DC_PIN   27
// #define EPD_BUSY_PIN 25

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
  EPD_Driver epdtest(eScreen_EPD_417, eps);
  epdtest.COG_initial();
  epdtest.globalUpdate(BW_monoBuffer, BW_0x00Buffer);
  delay(1000);
  epdtest.globalUpdate(BWR_blackBuffer, BWR_redBuffer);
  epdtest.COG_powerOff();
}

void loop() {
  sleep(1000);
}
