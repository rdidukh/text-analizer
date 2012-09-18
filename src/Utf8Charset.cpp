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
	

	for(std::vector<UnicodeGroup>::iterator i = charset.begin(); i != charset.end(); ++i)
	{
		for(vector<unicode_t>::iterator j = i->array.begin(); j != i->array.end(); ++j)
		{
			printf("%lx  ", *j);
		}
		printf("\n");
	}
	std::cout << std::endl;
	std::cout << "--- DEBUG ---" << std::endl << std::endl;
}


unicode_t Utf8Charset::findgroup(unicode_t unicode)
{
	
	for(std::vector<UnicodeGroup>::iterator i = charset.begin(); i != charset.end(); ++i)
		for(vector<unicode_t>::iterator j = i->array.begin(); j != i->array.end(); ++j)
			if ((*j) == unicode) return i->group_code;			
	
	return -1;
}

std::string Utf8Charset::tostring(unicode_t unicode)
{
	for(std::vector<UnicodeGroup>::iterator i = charset.begin(); i != charset.end(); ++i)
		for(vector<unicode_t>::iterator j = i->array.begin(); j != i->array.end(); ++j)
			if ((*j) == unicode)
			{
				return i->output_string;
			}
	
	return string("");

}

/*
int Utf8Charset::find(unicode_t unicode)
{
	// std::vector<UnicodeVector> charset;
	
	for(unsigned int i = 0; i < this->charset.size(); i++)
		for(UnicodeVector::iterator j = charset.at(i).begin(); j != charset.at(i).begin(); ++j)		
			if(*j == unicode) return i;
		
	return -1;

}
*/


void Utf8Charset::push_back(unicode_t group_code, std::string output_string, unsigned int flags, int amount, unicode_t unicode, ...)
{
	unicode_t val;
	UnicodeGroup unicodegroup;

	if(amount <= 0) return;

	unicodegroup.array.push_back(unicode);

	va_list vl;
	va_start(vl, unicode);
	for (int i = 1; i < amount; i++)
  	{
    		val = va_arg(vl, unicode_t);
		unicodegroup.array.push_back(val);
  	}
  	va_end(vl);

	if (group_code != 0)
		unicodegroup.group_code = group_code;
	else
		unicodegroup.group_code = unicode;
	
	if (!output_string.empty())
		unicodegroup.output_string = output_string;
	else
	{
		Utf8Char utf8char(unicode);
		unicodegroup.output_string = utf8char.tostring();
	}
	
	unicodegroup.flags = flags;

	this->charset.push_back(unicodegroup);

}

void Utf8Charset::push_back(int amount, unicode_t unicode, ...)
{
	unicode_t val;
	UnicodeGroup unicodegroup;

	if(amount <= 0) return;

	unicodegroup.array.push_back(unicode);

	va_list vl;
	va_start(vl, unicode);
	for (int i = 1; i < amount; i++)
  	{
    		val = va_arg(vl, unicode_t);
		unicodegroup.array.push_back(val);
  	}
  	va_end(vl);

	unicodegroup.group_code = unicode;
	
	Utf8Char utf8char(unicode);
	unicodegroup.output_string = utf8char.tostring();
	unicodegroup.flags = 0x0;
	unicodegroup.index = this->charset.size();

	this->charset.push_back(unicodegroup);

}

void Utf8Charset::push_back(unicode_t unicode)
{
	this->push_back(1, unicode);
}

#else
#endif // __UTF8CHARSET_CPP_

