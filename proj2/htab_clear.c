/*
* 	File:		htab_clear.c
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
 * Remove all items from hash table
 *
 * @param	t		reference on hash table
 */
void htab_clear(htab_t *t)
{
	htab_listitem* item = NULL;

	for(unsigned i = 0; i < t->htab_size; i++)
	{ // Loop on list with indexes
		while((item = t->list[i]) != NULL)
		{ // loop on items
			htab_remove(t,item->key);
		}
	}
}
