/*
 *  File:		eratosthenes.c
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
 *	Revision:	7
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-03-22 16:12
 */
#include <stdio.h>
#include <math.h>
#include "eratosthenes.h"


/*
 * Set 0 on primary bits in given BitArray via Eatosthenes algorithm
 *
 * @param	pole	BitArray on which 
 */
void Eratosthenes(BitArray_t pole)
{
	unsigned long N = BitArraySize(pole);
	double limit = sqrt(N);
	
	for(unsigned long i = 2; i < limit; i++)
	{
		if(GetBit(pole,i) == 0)
		{
			for(unsigned long n = 2; n*i < N; n++)
			{
				SetBit(pole,n*i,1);
			}
		}	
	}
}

