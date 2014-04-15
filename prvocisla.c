/*
 *  File:		prvocisla.c
 *	Name:		Project 1 for IJC, a)
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
 *	Revision:	1
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-03-18 15:21
 */

#include <stdio.h>
#include "error.c"
#include "eratosthenes.c"


/*
 * Print last 10 prime numbers from range 0 to 101 000 000
 * @return	success code = 0
 */
int main()
{
	BitArray(foo,101000000L);
	Eratosthenes(foo);

	int printed = 0;

	for(unsigned long i = 101000000L-1; i > 1; i--)
	{
		if(GetBit(foo,i) == 0)
		{
			printf("%ld\n",i);
			printed++;
			if(printed == 10)
			{
				i = 1;
			}
		}
	}
	
	return 0;
}
