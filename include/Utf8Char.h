#ifndef __UTF8CHAR_H_
#define __UTF8CHAR_H_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Utf8Char
{

  bool notutf8_flag;

  friend std::istream& operator>> (istream& is, Utf8Char& utf8char);
  friend std::ostream& operator<< (ostream& os, Utf8Char& utf8char);

  std::vector<char> bytes;
  unsigned long int unicode;

 public:
  Utf8Char();
//  Utf8Char(Utf8Char&);
  Utf8Char(unsigned long int);
  void debug();
  bool empty();
  bool notutf8();
  void setUnicode(unsigned long int); 
  unsigned long int getUnicode();

};

typedef std::list<Utf8Char> Utf8CharList;

#else
#endif // __UTF8CHAR_H_

