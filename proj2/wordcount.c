/*
* 	File:		wordcount.c
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
#include "io.c"
#include "htable.h"

/*
 * Print "key\tvalue\n"
 * 
 * @param	key
 * @param	value
 */
void print_word(char key[], unsigned value)
{
	printf("%s\t%d\n",key,value);
}
/*
 * Read words from stdin and print number of occurrences
 * @param	argc	number of arguments
 * @param	argv	arguments
 * @return	success code
 *
 */
int main(int argc, char* argv[])
{
	// This size is used, because it is enought for entire book (tested on Alice's Adventures in Wonderland and Pride and Prejudice)
	// and average number is between 0.5-2 - is used more than half and is average not more than 2 items
	htab_t* htab = htab_init(7000);
	htab_listitem* item;
	
	char word[128];
	while(fgetw(word, 127,stdin) != EOF)
	{
		item = htab_lookup(htab,word);
		item->data++;
	}

	htab_foreach(htab, &print_word);
	
	//htab_statistics(htab);

	htab_free(htab);

	return 0;
}




