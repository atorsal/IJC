#/*
# * 	File:		Makefile
# *		Name:		Project 2 for IJC
# *		Author:		Stanislav Nechutny - xnechu01
# * 	Faculty:	Faculty of Information Technology, Brno University of Technology
# *
# * 	Compiled:	gcc version 4.8.2 20131212 (Red Hat 4.8.2-7) (GCC) 
# *
# *
# * 	Repository:	git@nechutny.net:vut.git
# */


CC=gcc
CPP=g++
CFLAGS=-O2 -std=c99 -g -Wall -pedantic
CXXFLAGS=-O2 -std=c++11 -g -Wall -pedantic

all: fold wordcount

fold: fold.c fold2.cc
	$(CC) $(CFLAGS) fold.c -o fold
	$(CPP) $(CXXFLAGS) fold2.cc -o fold2

htable: htable.h htab_init.c htab_clear.c htab_foreach.c htab_free.c htab_lookup.c htab_lookup.c htab_remove.c htab_statistics.c
	$(CC) $(CFLAGS) -fPIC -c htab_init.c -o htab_init-shared.o
	$(CC) $(CFLAGS) -fPIC -c htab_clear.c -o htab_clear-shared.o
	$(CC) $(CFLAGS) -fPIC -c htab_foreach.c -o htab_foreach-shared.o
	$(CC) $(CFLAGS) -fPIC -c htab_free.c -o htab_free-shared.o
	$(CC) $(CFLAGS) -fPIC -c htab_lookup.c -o htab_lookup-shared.o
	$(CC) $(CFLAGS) -fPIC -c htab_remove.c -o htab_remove-shared.o
	$(CC) $(CFLAGS) -fPIC -c htab_statistics.c -o htab_statistics-shared.o
	$(CC) $(CFLAGS) -shared -o libhtable.so  htab_init-shared.o htab_clear-shared.o htab_foreach-shared.o htab_free-shared.o htab_lookup-shared.o htab_remove-shared.o htab_statistics-shared.o

	$(CC) $(CFLAGS) -c htab_init.c -o htab_init-static.o
	$(CC) $(CFLAGS) -c htab_clear.c -o htab_clear-static.o
	$(CC) $(CFLAGS) -c htab_foreach.c -o htab_foreach-static.o
	$(CC) $(CFLAGS) -c htab_free.c -o htab_free-static.o
	$(CC) $(CFLAGS) -c htab_lookup.c -o htab_lookup-static.o
	$(CC) $(CFLAGS) -c htab_remove.c -o htab_remove-static.o
	$(CC) $(CFLAGS) -c htab_statistics.c -o htab_statistics-static.o
	ar crs libhtable.a  htab_init-static.o htab_clear-static.o htab_foreach-static.o htab_free-static.o htab_lookup-static.o htab_remove-static.o htab_statistics-static.o
	ranlib libhtable.a
	
wordcount: htable wordcount.c io.c
	$(CC) $(CFLAGS) wordcount.c -o wordcount-dynamic -L. -lhtable
	$(CC) $(CFLAGS) wordcount.c libhtable.a -o wordcount
	
clean:
	rm -f fold fold2 wordcount-dynamic wordcount htab_*-shared.o htab_*-static.o xnechu01.zip libhtable.a libhtable.so

zip: *.c *.h Makefile
	zip xnechu01.zip *.c *.cc *.h Makefile
