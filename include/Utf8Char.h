#ifndef __UTF8CHAR_H_
#define __UTF8CHAR_H_

#include <iostream>
#include <vector>

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
  void debug();
  bool empty();
  bool notutf8();
 
};

// istream& operator>> (istream& is, Utf8Char& utf8char);
// ostream& operator<< (ostream& os, Utf8Char& utf8char);

#else
#endif // __UTF8CHAR_H_

