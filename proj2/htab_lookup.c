/*
* 	File:		htab_lookup.c
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
 * Helpfull function for creating item in hash table
 *
 * @param	key		string used for key
 * @return	pointer on structure or NULL if error
 */
inline htab_listitem* htab_create(const char *key)
{
	htab_listitem* item;
	// allocate memory for structure size + size of key (length + 1 byte for null-terminating)
	item = malloc(sizeof(htab_listitem) + sizeof(char)*(strlen(key)+1));
	if(item == NULL)
	{ // Check malloc
		return NULL;
	}

	// Set values
	memcpy(item->key,key,strlen(key)+1);
	item->data = 0;
	item->next = NULL;

	return item;
}

/*
 * Find or create new item in hash table
 *
 * @param	t		reference on hash table
 * @param	key		string used as index for item
 * @return	pointer on structure or NULL if error
 */
htab_listitem* htab_lookup(htab_t *t, const char *key)
{
	// Get index and pointer
	unsigned index = hash_function(key, t->htab_size);
	htab_listitem* item_ptr = NULL;
	htab_listitem* item = t->list[index];

	if(item == NULL)
	{ // Pointer is null (item not found), so create new item
		item = t->list[index] = htab_create(key);
		if(item == NULL)
		{
			return NULL;
		}
	}
	else
	{ // Possible result
		while(item != NULL)
		{ // Loop on table and find if item exists
			if(strcmp(item->key,key) == 0)
			{ // Found
				item_ptr = item;
				break;
			}
			else
			{ // Next 
				item_ptr = item;
				item = item->next;
			}
			
		}

		if(item_ptr != NULL && item != item_ptr)
		{ // Not found, so create
			item = htab_create(key); // create
			if(item == NULL)
			{
				return NULL;
			}
			item_ptr->next = item; // link in list
		}
	}

	return item;
}
