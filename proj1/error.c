/*
 *  File:		error.c
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
#include "error.h"


/*
 * Function for variadic printig warnings - used in Warning() and FatalError()
 *
 * @param	fmt		Printf formated string
 * @param	args	variadic list of values for inserting into string
 */
void vWarning(const char *fmt, va_list args)
{
	fprintf(stderr,"CHYBA: ");
	vfprintf(stderr, fmt, args);
}


/*
 * Print warning on stderr
 *
 * @param	fmt		Printf formated string
 * @param	...		variadic list of values for inserting into string
 */
void Warning(const char *fmt, ...)
 {
	va_list args;
	va_start(args, fmt);

	vWarning(fmt,args);
	
	va_end(args);
 }


/*
 * Print error on stderr and exit with code 1
 *
 * @param	fmt		Printf formated string
 * @param	...		variadic list of values for inserting into string
 */
void FatalError(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	vWarning(fmt,args);
	
	va_end(args);
	exit(1);
}

