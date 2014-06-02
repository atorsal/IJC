/*
* 	File:		htab_free.c
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
 * Destrohy hash table and free memory
 *
 * @param	t		reference on hash table
 */
void htab_free(htab_t *t)
{
	if(t != NULL)
	{
		htab_clear(t);
		free(t);
	}
}
