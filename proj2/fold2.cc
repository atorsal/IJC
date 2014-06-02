/*
* 	File:		fold2.cc
*	Name:		Project 2 for IJC
*	Author:		Stanislav Nechutny - xnechu01
* 	Faculty:	Faculty of Information Technology, Brno University of Technology
*
* 	Compiled:	gcc version 4.8.2 20131212 (Red Hat 4.8.2-7) (GCC) 
*
*
* 	Repository:	git@nechutny.net:vut.git
*/
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>



void formate(std::istream& file, unsigned length, bool cut)
{
	std::ios::sync_with_stdio(false);

	std::string line;
	std::string word;

	unsigned position = 0;
	bool warned = false;

	while(std::getline(file, line))
	{
		if(line.find_first_not_of(' ') != std::string::npos)
		{
			std::cout << "\n";
			position = 0;
		}
		std::istringstream linestream(line);

		//std::cout << line << "\n\n\n";
		
		while (linestream >> word)
		{
			if( (position+word.length()+1) > length)
			{
				std::cout << "\n";
				position = 0;
			}
			
			if(position > 0)
			{
				std::cout << " ";
				position++;
			}

			if(word.length() > length)
			{
				if(!warned)
				{
					std::cerr << "Word is longer";
					warned = true;
				}
				if(cut)
				{
					word.erase(length);
				}
			}
				
			std::cout  << word;
				
			position = position + word.length();
		}
	}
}



int main(int argc, char *argv[])
{
	bool cut = false;
	
	bool length_set = false;
	unsigned length = 80;

	for(int i = 1; i < argc; i++)
	{
		if(strcmp(argv[i],"-c") == 0)
		{
			cut = true;
		}
		if(strcmp(argv[i],"-w") == 0 && argc >= i)
		{
			length = atoi(argv[i+1]);
			length_set = true;
		}
	}


	int pos = 1;
	if(cut)
	{
		pos++;
	}
	if(length_set)
	{
		pos += 2;
	}

	
	if(argc > pos)
	{
		std::ifstream file (argv[pos]);
		if(!file.is_open())
		{
			std::cerr << "Can't open file";
		}
		else
		{
			formate(file, length, cut);
		}
	}
	else
	{
		 formate(std::cin, length, cut);
	}
	

	return 0;
}


