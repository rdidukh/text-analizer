#ifndef __UTF8CHARSET_H_
#define __UTF8CHARSET_H_

#include <Utf8Char.h>
#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdio>

using namespace std;

//typedef std::vector<unicode_t> UnicodeVector;

typedef struct _UnicodeGroup
{
	std::vector<unicode_t> array;
	int index;
	unicode_t group_code;
	std::string output_string;
	unsigned int flags;
} UnicodeGroup;

class Utf8Charset
{

  std::vector<UnicodeGroup> charset;

 public:
  Utf8Charset();
  
  //void push_back(const Utf8Charset& utf8charset);
//  void push_back(Utf8CharList utf8charlist);
  void push_back(unicode_t grouping_char, std::string output, unsigned int flags, int amount, unicode_t unicode, ...);
  void push_back(int amount, unicode_t unicode, ...);
  void push_back(unicode_t unicode);
//  int find(unicode_t unicode);
  unicode_t findgroup(unicode_t unicode);
  std::string tostring(unicode_t unicode);
  	
	
  void debug();
};

#else
#endif // __UTF8CHARSET_H_

