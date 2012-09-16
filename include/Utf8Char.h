#ifndef __UTF8CHAR_H_
#define __UTF8CHAR_H_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef unsigned long int unicode_t;

class Utf8Char
{

  bool notutf8_flag;

  friend std::istream& operator>> (istream& is, Utf8Char& utf8char);
  friend std::ostream& operator<< (ostream& os, Utf8Char& utf8char);

  std::vector<char> bytes;
  unsigned long int unicode;

  unicode_t toUnicode();

 public:
  Utf8Char();
//  Utf8Char(Utf8Char&);
  Utf8Char(unsigned long int);
  void debug();
  bool empty();
  bool notutf8();
  void setUnicode(unicode_t); 
  unicode_t getUnicode();
  

};



#else
#endif // __UTF8CHAR_H_

