#ifndef __UTF8CHAR_H_
#define __UTF8CHAR_H_

#include <bitset>

using namespace std;

class Utf8Char
{

  static const int MAX_UTF8_BIT_LEN = 32;

  std::bitset<MAX_UTF8_BIT_LEN> bs;

 public:
  Utf8Char();
  Utf8Char(const Utf8Char&);
  Utf8Char(unsigned long int uli);
 
};

#else
#endif // __UTF8CHAR_H_

