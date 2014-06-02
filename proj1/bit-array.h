/*
 *  File:		bit-array.h
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
 *	Revision:	4
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-03-14 14:15
 */
#include <limits.h>
#include "error.h"


typedef unsigned long BitArray_t[];

/*
 * Initialize BitArray
 *
 * @param	jmeno_pole	Name of created variable
 * @param	velikost	Number of requested bits for storage
 */
#define BitArray(jmeno_pole,velikost)  unsigned long jmeno_pole[((velikost/(sizeof(unsigned long)))+(velikost % (sizeof(unsigned long)) > 0 ? 1 : 0)+1)] = { velikost, 0}


/*
 * Get requested bit size of array
 *
 * @param	jmeno_pole	Name of BiArray_t variable
 * @return  Number of requeted bits for storage when created
 */
#ifdef USE_INLINE
	static inline unsigned long BitArraySize(BitArray_t jmeno_pole)
	{
		return jmeno_pole[0];
	}
#else
	#define BitArraySize(jmeno_pole) jmeno_pole[0]
#endif


/*
 * Set bit in BittArray_t
 *
 * @param	jmeno_pole	Name of BitArray
 * @param	index	Index for setting bit
 * @param	vyraz	Bit for set - 0 for 0, or any other number for 1
 */
#ifdef USE_INLINE
	static inline void SetBit(BitArray_t jmeno_pole, long index, int vyraz)
	{	
		if(index > BitArraySize(jmeno_pole)-1 || index < 0)
		{
			FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)BitArraySize(jmeno_pole)-1);
		} 
		if(vyraz)
		{
			jmeno_pole[index/(sizeof(*jmeno_pole)*CHAR_BIT) + 1] |= ((unsigned long)1 << (index%(sizeof(*jmeno_pole)*CHAR_BIT)) );
		}
		else
		{
			jmeno_pole[index/(sizeof(*jmeno_pole)*CHAR_BIT) + 1] &= ~((unsigned long)1 << (index%(sizeof(*jmeno_pole)*CHAR_BIT)) );
		} 
	}
#else
	#define SetBit(jmeno_pole,index,vyraz) \
		do \
		{ \
			if(index > BitArraySize(jmeno_pole)-1  || index < 0) \
			{ \
				FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)BitArraySize(jmeno_pole)-1); \
			} \
			if(vyraz) \
			{ \
				jmeno_pole[index/(sizeof(*jmeno_pole)*CHAR_BIT) + 1] |= ((unsigned long)1 << (index%(sizeof(*jmeno_pole)*CHAR_BIT)) ); \
			} \
			else \
			{ \
				jmeno_pole[index/(sizeof(*jmeno_pole)*CHAR_BIT) + 1] &= ~((unsigned long)1 << (index%(sizeof(*jmeno_pole)*CHAR_BIT)) ); \
			} \
		} \
		while(0)
#endif
#define DU1__SET_BIT(p,i,b) \
		do \
		{ \
			if(b) \
			{ \
				p[i/(sizeof(*p)*CHAR_BIT)] |= (1 << (i%(sizeof(*p)*CHAR_BIT)) ); \
			} \
			else \
			{ \
				p[i/(sizeof(*p)*CHAR_BIT)] &= ~(1 << (i%(sizeof(*p)*CHAR_BIT)) ); \
			} \
		} \
		while(0)


/*
 * Get bit from BittArray_t
 *
 * @param	jmeno_pole	Name of BitArray
 * @param	index	Index of requested bit
 * @return	Bit in position - 0 or 1
 */
#ifdef USE_INLINE
	static inline int GetBit(BitArray_t jmeno_pole, long index)
	{
		if(index > BitArraySize(jmeno_pole)-1 || index < 0)
		{
			FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)BitArraySize(jmeno_pole)-1);
			return 0;
		}
		return ( jmeno_pole[index/(sizeof(*jmeno_pole)*CHAR_BIT) + 1] & ((unsigned long)1 << (index%(sizeof(*jmeno_pole)*CHAR_BIT)) )) > 0;
	}
#else
	#define GetBit(jmeno_pole,index) \
		(index > BitArraySize(jmeno_pole)-1  || index < 0) ? \
			FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)BitArraySize(jmeno_pole)-1), 0 \
		: \
			(unsigned long)((jmeno_pole[index/(sizeof(*jmeno_pole)*CHAR_BIT) + 1] & ((unsigned long)1 << (index%(sizeof(*jmeno_pole)*CHAR_BIT))) ) > 0)
#endif
#define DU1__GET_BIT(p,i) (unsigned long)((p[i/(sizeof(*p)*CHAR_BIT)] & (1 << (i%(sizeof(*p)*CHAR_BIT))) ) > 0)
