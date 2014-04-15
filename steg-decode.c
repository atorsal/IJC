/*
 *  File:		steg-decode.c
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
 *	Revision:	8
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-03-20 22:48
 */
#include <stdio.h>
#include <ctype.h>
#include "eratosthenes.c"
#include "ppm.c"
#include "error.c"


/*
 * Print on stdout decoded message from ppm image hiden in prime bits
 *
 * @param	data[]	PPM image data
 */
void decode(char data[])
{
	int character, offset = 0;

	BitArray(ero,10100L);
	Eratosthenes(ero);

	int bit = 0;
	for(long i = 2; i < 101000000L-1; i++  )
	{
		if (GetBit(ero, i) == 0)
		{
			bit = DU1__GET_BIT((&data[i]), 0);
			DU1__SET_BIT((&character), offset, bit);

			offset++;
			if(offset == CHAR_BIT)
			{
				if(character == 0)
				{
					break;
				}
				if(!isprint(character))
				{
					FatalError("Nevalidni obsah - netisknutelny znak.");
				}
				printf("%c",character);
				offset = 0;
			}
		}
	}
}


/*
 * Parse ppm image from 1 argument and decode it
 *
 * @param	argc	number of given arguments
 * @param	argv[]	run arguments
 * @return	succes code = 0, or 1 if is wrong number of arguments or invalid file
 */
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		FatalError("Spatne argumenty programu");
	}
	else
	{
		struct ppm* img = ppm_read(argv[1]);

		if(img == NULL)
		{
			FatalError("Nevalidni soubor.");
		}
		
		decode(img->data);

		free(img);
	}

	return 0;
}

