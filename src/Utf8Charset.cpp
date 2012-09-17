#ifndef __UTF8CHARSET_CPP_
#define __UTF8CHARSET_CPP_

#include <Utf8Charset.h>


Utf8Charset::Utf8Charset()
{
	
}
  
void Utf8Charset::debug()
{
	
	std::cout << std::endl;
	std::cout << "*** DEBUG ***" << std::endl;
	

	for(std::vector<UnicodeVector>::iterator i = charset.begin(); i != charset.end(); ++i)
	{
		for(UnicodeVector::iterator j = i->begin(); j != i->end(); ++j)
		{
			printf("%lx  ", *j);
		}
		printf("\n");
	}
	std::cout << std::endl;
	std::cout << "--- DEBUG ---" << std::endl << std::endl;
}


int Utf8Charset::find(unicode_t unicode)
{
	// std::vector<UnicodeVector> charset;
	
	for(unsigned int i = 0; i < this->charset.size(); i++)
		for(UnicodeVector::iterator j = charset.at(i).begin(); j != charset.at(i).begin(); ++j)		
			if(*j == unicode) return i;
		
	return -1;

}

//  void push_back(Utf8Charset utf8charset);
//  void push_back(Utf8CharList utf8charlist);
void Utf8Charset::push_back(int amount, unicode_t unicode, ...)
{
	unicode_t val;
	UnicodeVector unicodevector;

	if(amount <= 0) return;

	unicodevector.push_back(unicode);

	va_list vl;
	va_start(vl, unicode);
	for (int i=1; i<amount; i++)
  	{
    		val = va_arg(vl, unicode_t);
		unicodevector.push_back(val);
  	}
  	va_end(vl);

	this->charset.push_back(unicodevector);

}



#else
#endif // __UTF8CHARSET_CPP_

