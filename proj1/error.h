/*
 *  File:		error.h
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
 *	Revision:	2
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-02-27 14:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void Warning(const char *fmt, ...);
void vWarning(const char *fmt, va_list args);
void FatalError(const char *fmt, ...);
