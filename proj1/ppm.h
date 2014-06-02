/*
 *  File:		ppm.h
 *	Name:		Project 1 for IJC, b)
 *	Author:		Stanislav Nechutny - xnechu01
 *  Faculty:	Faculty of Information Technology, Brno University of Technology
 *
 *  Compiled:	gcc version 4.4.7 20120313 (Red Hat 4.4.7-4) (GCC) 
 *
 *	Poetry:		Tenhleten můj projekt, to je mi nádhera!
 *				z okna za monitorem jde jarní atmosféra
 * 
 *				náhle při použití erasetova sítíčka
 *				vyrostla z něj kytička
 *
 * 	Repository:	git@nechutny.net:vut.git
 *	Revision:	4
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-03-17 14:15
 */

 struct ppm {
	unsigned xsize;
	unsigned ysize;
	char data[]; // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
int ppm_write(struct ppm *p, const char * filename);
