#include <iostream>
#include <fstream>
#include <cstdlib>

#include <Utf8Char.h>

using namespace std;

int main(int argc, char **argv)
{

	Utf8Char utf8char;
	std::ifstream infile;
	
	infile.open(argv[1], std::ifstream::in | std::ifstream::binary);

	for(int i = 0; i < 5; i++)
	{
		infile >> utf8char;
		std::cout << utf8char << std::endl;		
	}

	infile.close();

//	std::cout << "<>" << std::endl;

	return EXIT_SUCCESS;	
}


