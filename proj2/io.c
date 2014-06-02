/*
* 	File:		io.c
*	Name:		Project 2 for IJC
*	Author:		Stanislav Nechutny - xnechu01
* 	Faculty:	Faculty of Information Technology, Brno University of Technology
*
* 	Compiled:	gcc version 4.8.2 20131212 (Red Hat 4.8.2-7) (GCC) 
*
*
* 	Repository:	git@nechutny.net:vut.git
*/
#include <ctype.h>
#include <stdio.h>

int fgetw(char *s, int max, FILE *f)
{
	if(f == NULL)
	{ // return error if file pointer is null
		return -2;
	}

	int character = 0;
	int i =0;
	while( (character = fgetc(f)) != EOF &&  max > i)
	{ // read characters while is not EOF and we can fit in max
		if(isspace(character))
		{
			if(i != 0)
			{ // space - end of word
				break;
			}
		}
		else
		{ // add character
			s[i] = character;
			i++;
		}
	}

	// finish string
	s[i] = 0;
	
	if(i == 0)
	{ // nothing readed - return EOF
		return EOF;
	}
	

	return i;
}
