#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#include <map>

#include <Utf8Char.h>
#include <Utf8Charset.h>
#include <Utf8RussianAlphabetCharset.h>

using namespace std;

struct DoubleCharStruct
{
	unicode_t first;
	unicode_t second;
	int count;	
};

struct OneCharStruct
{
	public:
	unicode_t first;
	int count;	
};

int main(int argc, char **argv)
{

	std::ifstream infile;
	
	infile.open(argv[1], std::ifstream::in | std::ifstream::binary);

	if(infile.fail())
	{
		std::cout << "Can not open file " << argv[1] << std::endl;
		exit(EXIT_FAILURE);
	}

	infile.clear();

	Utf8RussianAlphabetCharset utf8charset(true);
	
	std::map<unicode_t, int> unicodemap;

	Utf8Char utf8char;

	
	while(!infile.eof())
	{
		infile >> utf8char;
		//std::cout << utf8char << std::endl;		
		if (utf8char.notutf8())
		{
			std::cout << "NOT UTF ENCODING. STOP." << std::endl;
			infile.close();
			exit(EXIT_FAILURE);
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

	std::vector<OneCharStruct> onecharVector;

	for(std::map<unicode_t, int>::iterator i = unicodemap.begin(); i != unicodemap.end(); ++i)
	{
		OneCharStruct ocs;

		ocs.first = i->first;
		ocs.count = i->second;

		std::vector<OneCharStruct>::iterator j;
		for(j = onecharVector.begin(); j != onecharVector.end(); ++j)
			if(ocs.count > j->count) break;

		if(j != onecharVector.end())
			onecharVector.insert(j, ocs);
		else
			onecharVector.push_back(ocs);
	
	}

	/*for(std::map<unicode_t, int>::iterator i = unicodemap.begin(); i != unicodemap.end(); ++i)
	{
		//utf8char.setUnicode(i->first);
		std::cout << utf8charset.tostring(i->first) << ": " << i->second << std::endl;
	}*/

	int all_ones = 0;
	for(std::vector<OneCharStruct>::iterator i = onecharVector.begin(); i != onecharVector.end(); ++i)
		all_ones += i->count;
	

	int output_limit = 50;
	for(std::vector<OneCharStruct>::iterator i = onecharVector.begin(); i != onecharVector.end(); ++i)
	{
	//	if(output_limit < 1) break;
		output_limit--;
		std::cout << utf8charset.tostring(i->first) << " : " << i->count << " = " << (100*(double)i->count)/all_ones << "%" << std::endl;
	}
	
/*
	std::ifstream infile;
	
	infile.open(argv[1], std::ifstream::in | std::ifstream::binary);

	if(infile.fail())
	{
		std::cout << "Can not open file " << argv[1] << std::endl;
		exit(EXIT_FAILURE);
	}

	infile.clear();

	Utf8RussianAlphabetCharset utf8charset(true);

	std::map<std::pair<unicode_t, unicode_t>, int> unicodemap;
	
	Utf8Char utf8char1, utf8char2;

	
	infile >> utf8char2;

	while(!infile.eof())
	{		
		utf8char1 = utf8char2;
		infile >> utf8char2;	
	
		if (utf8char1.notutf8() || utf8char2.notutf8())
		{
			std::cout << "NOT UTF ENCODING. STOP." << std::endl;
			infile.close();
			exit(EXIT_FAILURE);
			//break;
		}

		if(utf8char1.empty() || utf8char2.empty()) break;		

		unicode_t unicode1 = utf8charset.findgroup(utf8char1.getUnicode());
		unicode_t unicode2 = utf8charset.findgroup(utf8char2.getUnicode());

		if (unicode1 != (unicode_t)-1 && unicode2 != (unicode_t)-1)
		{
			std::pair<unicode_t, unicode_t> doublechar = std::make_pair(unicode1, unicode2);
			
			if(unicodemap.count(doublechar) > 0)
			{
				unicodemap[doublechar] += 1;
			}
			else
			{
				unicodemap[doublechar] = 1;
			}
		}				
	}

	infile.close();

	std::vector<DoubleCharStruct> doublecharVector;

	for(std::map<std::pair<unicode_t, unicode_t>, int>::iterator i = unicodemap.begin(); i != unicodemap.end(); ++i)
	{
		DoubleCharStruct dcs;

		dcs.first = i->first.first;
		dcs.second = i->first.second;
		dcs.count = i->second;

		std::vector<DoubleCharStruct>::iterator j;
		for(j = doublecharVector.begin(); j != doublecharVector.end(); ++j)
			if(dcs.count > j->count) break;

		if(j != doublecharVector.end())
			doublecharVector.insert(j, dcs);
		else
			doublecharVector.push_back(dcs);
	
	}

	int all_doubles = 0;
	for(std::vector<DoubleCharStruct>::iterator i = doublecharVector.begin(); i != doublecharVector.end(); ++i)
		all_doubles += i->count;
	

	int output_limit = 50;
	for(std::vector<DoubleCharStruct>::iterator i = doublecharVector.begin(); i != doublecharVector.end(); ++i)
	{
	//	if(output_limit < 1) break;
		output_limit--;
		std::cout << "( " << utf8charset.tostring(i->first) << ", " << utf8charset.tostring(i->second) << " ) = " << i->count << " = " << (100*(double)i->count)/all_doubles << "%" << std::endl;
	}
*/

	return EXIT_SUCCESS;	
}


