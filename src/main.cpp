#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#include <map>

#include <Utf8Char.h>
#include <Utf8Charset.h>
#include <Utf8RussianAlphabetCharset.h>

using namespace std;

int main(int argc, char **argv)
{
/*
	Utf8Charset utf8charset;

	utf8charset.push_back(3, 0x410, 0x411, 0x412);
	utf8charset.push_back(1, 0x510);
	utf8charset.push_back(2, 0x40, 0x60);

	utf8charset.debug();
*/
/*	Utf8Char utf8char2(0x410);
	Utf8Char utf8char = utf8char2;
	utf8char.debug();
	std::cout << utf8char << std::endl;
	
	printf("%lx\n", utf8char.getUnicode());
*/

/*	std::ifstream infile;
	
	infile.open(argv[1], std::ifstream::in | std::ifstream::binary);

	for(int i = 0; i < 5; i++)
	{
		infile >> utf8char;
		std::cout << utf8char << std::endl;		
	}

	infile.close();

//	std::cout << "<>" << std::endl;*/


	std::map<unicode_t, int> unicodemap;

	Utf8Char utf8char;

	std::ifstream infile;
	
	infile.open(argv[1], std::ifstream::in | std::ifstream::binary);

	Utf8RussianAlphabetCharset utf8charset(true);

	while(!infile.eof())
	{
		infile >> utf8char;
		//std::cout << utf8char << std::endl;		
		if (utf8char.notutf8())
		{
			std::cout << "NOT UTF ENCODING. STOP." << std::endl;
//			infile.close();
//			exit(EXIT_FAILURE);
			break;
		}

		if(utf8char.empty())
		{
			break;		
		}

		unicode_t unicode = utf8charset.findgroup(utf8char.getUnicode());

		if (unicode != (unicode_t)-1)
		{
			if(unicodemap.count(unicode) > 0)
			{
				unicodemap[unicode] += 1;
			}
			else
			{
				unicodemap[unicode] = 1;
			}
		}				
	}

	infile.close();


	for(std::map<unicode_t, int>::iterator i = unicodemap.begin(); i != unicodemap.end(); ++i)
	{
		//utf8char.setUnicode(i->first);
		std::cout << utf8charset.tostring(i->first) << ": " << i->second << std::endl;
	}

	return EXIT_SUCCESS;	
}


