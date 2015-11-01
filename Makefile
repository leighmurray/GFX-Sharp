all:
	g++ Adafruit_GFX.cpp Adafruit_SharpMem.cpp sharpmemtest.cpp -o sharpmemtest

gfx:
	g++ -c Adafruit_GFX.cpp

install:
	cp Adafruit_GFX.o /usr/local/lib/
	cp Adafruit_GFX.h /usr/local/include/

clean:
	rm -f *.o *.a *.gch
