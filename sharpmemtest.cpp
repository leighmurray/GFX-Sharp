/*********************************************************************
This is an example sketch for our Monochrome SHARP Memory Displays

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
#include "Adafruit_SharpMem.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

Adafruit_SharpMem display;

#define BLACK 0
#define WHITE 1

void delay(int usec)
{
  usleep(usec);
}

void setup(int argc, char *argv[])
{
  printf("Hello!");

  // start & clear the display
  display.begin(argc, argv);
  display.clearDisplay();
}

void loop(void)
{
  // Screen must be refreshed at least once per second
  display.refresh();
  delay(1000000);
}

int main (int argc, char *argv[])
{
	printf("so far so good\n");
	setup(argc, argv);
	printf("we are setup\n");
	display.fillScreen(BLACK);
	display.drawPixel(10, 10, WHITE);
	display.refresh();
	printf("REEEFRESSSH!\n");
	while (true) {
		loop();
	}
}
