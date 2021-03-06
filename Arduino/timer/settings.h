/**
Copyright (c) 2021 by NXEZ.com
See more at https://www.nxez.com
*/

//#define spiOLED
#define i2cOLED

#ifdef spiOLED
#include "SSD1306Spi.h"
#endif
#ifdef i2cOLED
#include "SSD1306Wire.h"
#include "SH1106.h"
#endif
#include "OLEDDisplayUi.h"

// Setup
const int UPDATE_INTERVAL_SECS = 3 * 60;
const int UPDATE_INTERVAL_SECS_DHT = 10;
int UTC_OFFSET = 8;

#ifdef spiOLED
// Pin definitions for SPI OLED
#define OLED_CS D8    // Chip select
#define OLED_DC D2    // Data/Command
#define OLED_RESET D0 // RESET  - If you get an error on this line, either change Tools->Board to the board you are using or change "D0" to the appropriate pin number for your board.
#endif

#ifdef i2cOLED
// Pin definitions for I2C OLED
//const int I2C_DISPLAY_ADDRESS = 0x3C;
const int I2C_DISPLAY_ADDRESS = 0x3C;
const int SDA_PIN = 4;
const int SDC_PIN = 5;
#endif

// -----------------------------------
// Example Locales (uncomment only 1)
#define HoChiMinh
//------------------------------------

#ifdef HoChiMinh
//DST rules for Central European Time Zone
//#define UTC_OFFSET +8
// Uncomment for 24 Hour style clock
#define STYLE_24HR

#define NTP_SERVERS "ntp.aliyun.com"

#endif

#ifdef spiOLED
SSD1306Spi display(OLED_RESET, OLED_DC, OLED_CS); // SPI OLED
#endif
#ifdef i2cOLED
//SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SDC_PIN); // I2C OLED
SH1106 display(I2C_DISPLAY_ADDRESS, SDA_PIN, SDC_PIN); // I2C OLED
#endif

OLEDDisplayUi ui(&display);


// WIFI
const char* WIFI_SSID = "Underground";
const char* WIFI_PWD = "001129gao";

const boolean IS_METRIC = true;

//DHT10/DHT22
const String TEMPERATURE_SENSOR_TYPE = "DHT10";
/***************************
 * End Settings
 **************************/
