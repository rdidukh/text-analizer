#ifndef __UTF8CHARSET_H_
#define __UTF8CHARSET_H_

#include <Utf8Char.h>
#include <iostream>
#include <list>
#include <cstdarg>

using namespace std;

class Utf8Charset
{

  std::list<Utf8CharList> charset;

 public:
  Utf8Charset();
  
  void push_back(Utf8Charset utf8charset);
//  void push_back(Utf8CharList utf8charlist);
  void push_back(int amount, Utf8Char& utf8char, ...);

};

#else
#endif // __UTF8CHARSET_H_

