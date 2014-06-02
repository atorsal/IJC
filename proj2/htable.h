/*
* 	File:		htable.h
*	Name:		Project 2 for IJC
*	Author:		Stanislav Nechutny - xnechu01
* 	Faculty:	Faculty of Information Technology, Brno University of Technology
*
* 	Compiled:	gcc version 4.8.2 20131212 (Red Hat 4.8.2-7) (GCC) 
*
*
* 	Repository:	git@nechutny.net:vut.git
*/

// List item
typedef struct  htab_listitem_s {
  struct htab_listitem_s *next;
  unsigned data;
  char key[];
} htab_listitem;

// Hash table
typedef struct  htab {
  unsigned htab_size;
  struct htab_listitem_s *list[];
} htab_t;


// Hashing function
unsigned hash_function(const char *str, unsigned htab_size);

// pro vytvoření a inicializaci tabulky
htab_t *htab_init(unsigned size);

//  vyhledávání - viz dále
htab_listitem *htab_lookup(htab_t *t, const char *key);

// volání funkce pro každý prvek
void htab_foreach(htab_t *t,  void (*function)(char key[], unsigned value));

// vyhledání a zrušení zadané položky
void htab_remove(htab_t *t, const char *key);

// zrušení všech položek v tabulce
void htab_clear(htab_t *t);

// zrušení celé tabulky (volá clear)
void htab_free(htab_t *t);

//  tisk průměrné a min/max. délky seznamů v tabulce - vhodné pro ladění a testování
void htab_statistics(htab_t *t);
