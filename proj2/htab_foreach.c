/*
* 	File:		htab_foreach.c
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
 * Call function on each memeber of given hash table
 *
 * @param	t			reference on hash table
 * @param	function	pointer on function
 */
void htab_foreach(htab_t *t, void (*function)(char key[], unsigned value))
{
	htab_listitem* item = NULL;

	for(unsigned i = 0; i < t->htab_size; i++)
	{ // Loop on list with indexes
		item = t->list[i]; 
		while(item != NULL)
		{ // loop on items
			function(item->key,item->data);
			item = item->next;
		}
	}
}
