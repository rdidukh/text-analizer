#ifndef __UTF8CHARSET_H_
#define __UTF8CHARSET_H_

#include <Utf8Char.h>
#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdio>

using namespace std;

typedef std::vector<unicode_t> UnicodeVector;

class Utf8Charset
{

  std::vector<UnicodeVector> charset;

 public:
  Utf8Charset();
  
  //void push_back(const Utf8Charset& utf8charset);
//  void push_back(Utf8CharList utf8charlist);
  void push_back(int amount, unicode_t unicode, ...);
  void debug();
};

#else
#endif // __UTF8CHARSET_H_

