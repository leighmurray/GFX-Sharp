/*********************************************************************
This is an Arduino library for our Monochrome SHARP Memory Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1393

These displays use SPI to communicate, 3 pins are required to  
interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include "Adafruit_GFX.h"
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

// LCD Dimensions
#define SHARPMEM_LCDWIDTH       (96)
#define SHARPMEM_LCDHEIGHT      (96)
#define HIGH	1
#define LOW	0

//typedef int boolean;
typedef uint8_t byte;

class Adafruit_SharpMem : public Adafruit_GFX {
 public:
  Adafruit_SharpMem();
  void begin(int argc, char *argv[]);
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  uint8_t getPixel(uint16_t x, uint16_t y);
  void clearDisplay();
  void refresh(void);

 private:
  volatile uint8_t *dataport, *clkport;
  uint8_t _sharpmem_vcom, datapinmask, clkpinmask;

  char *device;
  char *input_tx;
  uint32_t mode;
  uint8_t bits;
  uint32_t speed;
  uint16_t delay;
  int verbose;
  int fd;

  void sendbyte(uint8_t data);
  void sendbyteLSB(uint8_t data);
  void parse_opts(int argc, char *argv[]);
  void print_usage(const char *prog);
  void transfer(byte *input, int len);
};
