#ifndef __UTF8CHARSET_CPP_
#define __UTF8CHARSET_CPP_

#include <Utf8Charset.h>


Utf8Charset::Utf8Charset()
{
	
}
  
//  void push_back(Utf8Charset utf8charset);
//  void push_back(Utf8CharList utf8charlist);
void Utf8Charset::push_back(int amount, Utf8Char& utf8char, ...)
{
	Utf8Char& val;
	Utf8CharList utf8charlist;

	if(amount <= 0) return;

	utf8charlist.push_back(utf8char);

	//this->charset;

	va_list vl;
	va_start(vl,utf8char);
	for (i=1;i<amount;i++)
  	{
    		val = va_arg(vl, Utf8Char&);
		utf8charlist.push_back(val);
    		//printf ("\t%.2f",val);
  	}
  	va_end(vl);

	this->charset.push_back(utf8charlist);

}



#else
#endif // __UTF8CHARSET_CPP_

