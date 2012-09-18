#include <Utf8RussianAlphabetCharset.h>

Utf8RussianAlphabetCharset::Utf8RussianAlphabetCharset(bool ignoreCase)
{

// void push_back(int amount, unicode_t unicode, ...);
	if(ignoreCase)
	{
		//this->push_back(0x20, "_", 0x0, 1, 0x20);
		for (unicode_t i = 0x410; i <= 0x415; i++) {this->push_back(2, i, i+0x20);}
		this->push_back(2, 0x401, 0x451);
		for (unicode_t i = 0x416; i <= 0x42f; i++) {this->push_back(2, i, i+0x20);}
		
	}
	else
	{
		//this->push_back(0x20, "_", 0x0, 1, 0x20);
		for (unicode_t i = 0x410; i <= 0x415; i++) this->push_back(i);
		this->push_back(0x0401);
		for (unicode_t i = 0x416; i <= 0x435; i++) this->push_back(i);
		this->push_back(0x0451);
		for (unicode_t i = 0x436; i <= 0x44f; i++) this->push_back(i);
	}





}
