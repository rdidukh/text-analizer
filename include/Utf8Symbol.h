#ifndef __UTF8SYMBOL_H_
#define __UTF8SYMBOL_H_

#include <bitset>

using namespace std;

class Utf8Symbol
{

  static const int MAX_UTF8_BIT_LEN = 32;

  std::bitset<MAX_UTF8_BIT_LEN> bs;

 public:
  Utf8Symbol();
  Utf8Symbol(const Utf8Symbol&);
  Utf8Symbol(unsigned long int uli);
 
};

#else
#endif // __UTF8SYMBOL_H_

