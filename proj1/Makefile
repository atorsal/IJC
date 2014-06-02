#/*
# * 	File:		Makefile
# *		Name:		Project 1 for IJC, a)
# *		Author:		Stanislav Nechutny - xnechu01
# * 	Faculty:	Faculty of Information Technology, Brno University of Technology
# *
# * 	Compiled:	gcc version 4.4.7 20120313 (Red Hat 4.4.7-4) (GCC) 
# *
# *		Poetry:		Tenhleten můj projekt, to je mi nádhera!
# *					z okna za monitorem jde jarní atmosféra
# * 
# *					náhle při použití erasetova sítíčka
# *					vyrostla z něj kytička
# *
# * 	Repository:	git@nechutny.net:vut.git
# *		Revision:	8
# * 	Created:	2014-02-26 01:39
# * 	Modified:	2014-03-20 22:48
# */


CC=gcc
CFLAGS=-O2 -std=c99 -lm -Wall -pedantic

all: prvocisla steg-decode

steg-decode: steg-decode.c eratosthenes.c ppm.c ppm.h error.c bit-array.h
	$(CC) $(CFLAGS) steg-decode.c -o steg-decode

prvocisla: prvocisla.c error.c eratosthenes.c bit-array.h
	$(CC) $(CFLAGS) prvocisla.c -o prvocisla
	$(CC) $(CFLAGS) -DUSE_INLINE prvocisla.c -o prvocisla-inline
	
clean:
	rm -f steg-decode prvocisla prvocisla-inline xnechu01.zip

zip: *.c *.h Makefile
	zip xnechu01.zip *.c *.h Makefile
