/*
* 	File:		htab_init.c
*	Name:		Project 2 for IJC
*	Author:		Stanislav Nechutny - xnechu01
* 	Faculty:	Faculty of Information Technology, Brno University of Technology
*
* 	Compiled:	gcc version 4.8.2 20131212 (Red Hat 4.8.2-7) (GCC) 
*
*
* 	Repository:	git@nechutny.net:vut.git
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

/*
 * Hash function used for table
 *
 * @param	str			string for calculating hash
 * @param	htab_size	size fo hash table
 * @return	calculated hash
 */
unsigned int hash_function(const char *str, unsigned htab_size)
{
	unsigned int h=0;
	const unsigned char *p;
	for(p=(const unsigned char*)str; *p!='\0'; p++)
	{
		h = 65599*h + *p;
	}
	return h % htab_size;
}

/*
 * Inicialize hash table and return pointer
 *
 * @param	size	size of hash table
 * @return	pointer on structure or NULL if error
 */
htab_t* htab_init(unsigned size)
{
	htab_t* result = malloc(sizeof(htab_t)+size*sizeof(htab_listitem));
	if(result == NULL)
	{ // check malloc
		return NULL;
	}

	result->htab_size = size;

	for(unsigned i = 0; i < size; i++)
	{ // inicialize NULL values
		result->list[i] = NULL;
	}

	return result;
}
