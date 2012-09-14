#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#include <Utf8Char.h>
#include <Utf8Charset.h>

using namespace std;

int main(int argc, char **argv)
{

	Utf8Char utf8char2(0x410);
	Utf8Char utf8char = utf8char2;
	utf8char.debug();
	std::cout << utf8char << std::endl;
	
	printf("%lx\n", utf8char.getUnicode());

/*	std::ifstream infile;
	
	infile.open(argv[1], std::ifstream::in | std::ifstream::binary);

	for(int i = 0; i < 5; i++)
	{
		infile >> utf8char;
		std::cout << utf8char << std::endl;		
	}

	infile.close();

//	std::cout << "<>" << std::endl;*/


	return EXIT_SUCCESS;	
}


