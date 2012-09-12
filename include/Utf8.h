#ifndef __UTF8_H_
#define __UTF8_H_

#include <bitset>

using namespace std;

class Utf8
{

  static const int MAX_UTF8_BIT_LEN = 32;

  std::bitset<MAX_UTF8_BIT_LEN> bs;

 public:
  Utf8();
  Utf8(const Utf8&);
  Utf8(unsigned long int uli);
 
};

#else
#endif // __UTF8_H_

