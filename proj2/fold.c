/*
* 	File:		fold.c
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
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

#define SOURCE_FILE		0
#define SOURCE_STDIN	1
#define CUT_TRUE		1
#define CUT_FALSE		0

void formate(int maxlen, int cut, int source, char *file);

int main(int argc, char *argv[])
{
	int length = 80, cut = CUT_FALSE, option, source = SOURCE_STDIN;
	char *filename = "";

	// Parse arguments
	while ((option = getopt (argc, argv, "cw:")) != -1)
	switch (option)
	{
		case 'w':
			length = atoi(optarg);
			break;
		case 'c':
			cut = CUT_TRUE;
			break;
		default:
			abort();
    }

    // Read from file, or stdin?
    if(optind < argc)
    {
       source = SOURCE_FILE;
       filename = argv[optind];
    }

	// Call formating function
	formate(length,cut,source,filename);

	return 0;
}


void formate(int maxlen, int cut, int source, char *file)
{
	FILE *fp;
	if(source == SOURCE_FILE)
	{ // try open file
		fp = fopen(file, "r");
		if(fp == NULL)
		{
			fprintf(stderr,"Can't open file [%s])",file);
			return;
		}
	}
	else if(source == SOURCE_STDIN)
	{ // set source to stdin
		fp = stdin;
	}
	else
	{
		fprintf(stderr,"Wrong source type [%d] in formate()",source);
		return;
	}

	// Limits are only for n00bs, this thing allow work with unlimited length word and without realloc
	char *word = malloc((maxlen+2)*sizeof(char));
	if(word == NULL)
	{
		fprintf(stderr,"Malloc error in formate() while trying allocate %li bytes",(maxlen+2)*sizeof(char));
		return;
	}
	
	int readed = 0, length = 0, column = 0, warned = 0, empty_line = 0, print_nl = 0;

	do
	{ // main reading cycle
		readed = fgetc(fp);
		
		if(isspace(readed) || readed == EOF)
		{ // word end

			// print empty lines
			if(empty_line && readed == '\n')
			{
				if(column != 0)
				{
					printf("\n");
				}
				printf("\n");
				column = 0;
				length = 0;
			}
			if(readed == '\n')
			{
				empty_line = 1;
			}

			// word can't fit on current line so print newline
			if(column+length+1 > maxlen && !(column == 0 && length == maxlen) )
			{
				column = 0;
				printf("\n");
				print_nl = 0;
			}

			// word fit on current line
			if(length <= maxlen && length != 0)
			{
				word[length] = 0;
				if(column > 0)
				{
					printf(" ");
					column++;
				}
				printf("%s",word);
				column += length;
				print_nl = 1;
				
			}

			length = 0;
		}
		else
		{	
			if(length <= maxlen)
			{ // save char to buffer - we don't know now if print newline or just space
				word[length] = readed;
				
				if(length == maxlen)
				{ // show warning if is word longer than line and print it
					word[length+1] = 0;

					if(cut)
					{ // cut if is -c option
						word[length] = 0;
					}
					
					if(!warned)
					{ // print warning only once
						fprintf(stderr,"\nWord (%s...) is longer than max line length (%i).\n",word,maxlen);
						warned = 1;
					}

					if(column != 0)
					{
						printf("\n");
						column = 0;
					}
					printf("%s",word);
					print_nl = 0;
				}
			}
			else if(!cut)
			{ // word is longer than line, so print next chars after limit, but only if is not set -c
				printf("%c",readed);
				
			}
				
			length++;
			empty_line = 0;
		}

	}
	while(readed != EOF);

	if(print_nl)
	{
		printf("\n");
	}

	// Mommy and PePe always says, that i must tidy my toys, so...
	fclose(fp);
	free(word);

	
}
