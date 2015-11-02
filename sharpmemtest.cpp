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

// any pins can be used
#define SCK 10
#define MOSI 11
#define SS 13

Adafruit_SharpMem display(SCK, MOSI, SS);

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

/*
  // draw the first ~12 characters in the font
  testdrawchar();
  display.refresh();
  delay(2000);
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.refresh();
  delay(2000);
*/
}

void loop(void)
{
  // Screen must be refreshed at least once per second
  display.refresh();
  delay(500);
}

///

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    //display.write(i);
    //if ((i > 0) && (i % 14 == 0))
      //display.println();
  }
  display.refresh();
}

void testdrawcircle(void) {
  for (uint8_t i=0; i<display.height(); i+=2) {
    display.drawCircle(display.width()/2-5, display.height()/2-5, i, BLACK);
    display.refresh();
  }
}

void testfillrect(void) {
  uint8_t color = 1;
  for (uint8_t i=0; i<display.height()/2; i+=3) {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.refresh();
    color++;
  }
}

void testdrawtriangle(void) {
  for (uint16_t i=0; i<fmin(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, BLACK);
    display.refresh();
  }
}

void testfilltriangle(void) {
  uint8_t color = BLACK;
  for (int16_t i=fmin(display.width(),display.height())/2; i>0; i-=5) {
    display.fillTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.refresh();
  }
}

void testdrawroundrect(void) {
  for (uint8_t i=0; i<display.height()/4; i+=2) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, BLACK);
    display.refresh();
  }
}

void testfillroundrect(void) {
  uint8_t color = BLACK;
  for (uint8_t i=0; i<display.height()/4; i+=2) {
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.refresh();
  }
}
   
void testdrawrect(void) {
  for (uint8_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, BLACK);
    display.refresh();
  }
}

void testdrawline() {  
  for (uint8_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, BLACK);
    display.refresh();
  }
  for (uint8_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, BLACK);
    display.refresh();
  }
  delay(250);
  
  display.clearDisplay();
  for (uint8_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, BLACK);
    display.refresh();
  }
  for (int8_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, BLACK);
    display.refresh();
  }
  delay(250);
  
  display.clearDisplay();
  for (int8_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, BLACK);
    display.refresh();
  }
  for (int8_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, BLACK);
    display.refresh();
  }
  delay(250);

  display.clearDisplay();
  for (uint8_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, BLACK);
    display.refresh();
  }
  for (uint8_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, BLACK); 
    display.refresh();
  }
  delay(250);
}

int main (int argc, char *argv[])
{
  printf("so far so good\n");
  setup(argc, argv);
  printf("we are setup\n");

// draw a single pixel
  display.drawPixel(10, 10, BLACK);
  display.refresh();
  sleep(1);
  display.clearDisplay();

  // draw many lines
  testdrawline();
  sleep(1);
  display.clearDisplay();

  // draw rectangles
  testdrawrect();
  sleep(1);
  display.clearDisplay();

  // draw multiple rectangles
  testfillrect();
  display.refresh();
  sleep(1);
  display.clearDisplay();

  // draw a circle, 10 pixel radius
  display.fillCircle(display.width()/2, display.height()/2, 10, BLACK);
  display.refresh();
  sleep(1);
  display.clearDisplay();

  testdrawroundrect();
  display.refresh();
  sleep(1);
  display.clearDisplay();

  testfillroundrect();
  display.refresh();
  sleep(1);
  display.clearDisplay();

  testdrawtriangle();
  display.refresh();
  sleep(1);
  display.clearDisplay();

  testfilltriangle();
  display.refresh();
  sleep(1);
  display.clearDisplay();
}
