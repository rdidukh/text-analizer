#ifndef __UTF8_H_
#define __UTF8_H_

#include <bitset>

using namespace std;

class Utf8
{
  std::bitset<32> bs;

 public:
  Utf8();
  Utf8(const Utf8&);
  Utf8(unsigned long int uli);
 
};

#else
#endif // __UTF8_H_

