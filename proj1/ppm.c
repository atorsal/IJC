/*
 *  File:		ppm.c
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
 *	Revision:	4
 * 	Created:	2014-02-26 01:39
 * 	Modified:	2014-03-17 14:15
 */
#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"


/*
 * Parse PPM P6 255bit file into structure.
 * If is invalid file print error on stderr.
 *
 * @param	filename	Path to file 
 * @return	pointer on parsed structure, or NULL if error
 */
struct ppm * ppm_read(const char * filename)
{
	FILE *fp;
	struct ppm* image = NULL;
	int readed;
	unsigned xsize, ysize;
    
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
		Warning("Soubor %s se nepodarilo otevrit.",filename);
        return NULL;
    }


    readed = fscanf(fp, "P6 %u %u 255 ", &xsize, &ysize);
    if(readed != 2)
    {
		fclose(fp);
		Warning("Soubor %s neni validni ppm.",filename);
        return NULL;
	}

	unsigned long size = xsize*ysize*3*sizeof(char);

	image = malloc(size+sizeof(struct ppm));
	if(image == NULL)
	{
		fclose(fp);
		Warning("Nepodarila se alokace.");
        return NULL;
	}

	readed = fread(&image->data, sizeof(char), size, fp);

	if(readed != size || ferror(fp) != 0 || fgetc(fp) != EOF)
	{
		fclose(fp);
		free(image);
		Warning("Obrazek neni validni.");
        return NULL;
	}

	fclose(fp);

	image->xsize = xsize;
	image->ysize = ysize;

	return image;
}


/*
 * Save PPM P6 255bit image into file
 * If is error while writing print error on stderr.
 *
 * @param	p	Structure with image to write
 * @param	filename	Name for creating file with PPM P6 255bit image
 * @return	0 if everything ok, -1 if can't create file and -2 if failed writing
 */
int ppm_write(struct ppm *p, const char * filename)
{
	FILE *fp;
	int writen;
	
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
		Warning("Soubor %s se nepodarilo otevrit.",filename);
        return -1;
    }

    writen = fprintf(fp, "P6\n%u %u\n255\n", p->xsize, p->ysize);
    if(writen < 1)
    {
		Warning("Soubor %s se nepodarilo zapsat.",filename);
		fclose(fp);
        return -2;
	}

	long size = p->xsize*p->ysize*sizeof(char)*3;
	
	writen = fwrite(p->data, sizeof(char), size, fp);
	if(writen != size)
	{
		Warning("Soubor %s se nepodarilo zapsat.",filename);
		fclose(fp);
        return -2;
	}

	fclose(fp);

    return 0;
}
