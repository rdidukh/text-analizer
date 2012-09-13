#ifndef __UTF8CHAR_CPP_
#define __UTF8CHAR_CPP_

#include <Utf8Char.h>
#include <cstdio>

Utf8Char::Utf8Char()
{
	notutf8_flag = false;
}

bool Utf8Char::notutf8()
{
	return notutf8_flag;
}

void Utf8Char::debug()
{
	
unsigned char c;

	for(std::vector<char>::iterator i = bytes.begin(); i != bytes.end(); ++i)
	{
		c = *i;
		printf("%x ", c);
	}
	std::cout << std::endl;

}

bool Utf8Char::empty()
{
	return bytes.empty();
}

std::istream& operator>> (std::istream& is, Utf8Char& utf8char)
{
	char byte;
	int bytes_count = 1;
	
	utf8char.bytes.clear();
	utf8char.notutf8_flag = false;
	streampos save_pos = is.tellg();

	if(save_pos == -1) { std::cout << "Position failure!" << std::endl; return is;}

//	std::cout << "save_pos = " << save_pos << std::endl;

//	if(is.eof()) { std::cout << "EOF!!!" << std::endl; return is;}

//	std::cout << "is.eof() == false" << std::endl;

	is.get(byte); 
	if(is.eof()) { std::cout << "EOF!!!" << std::endl; return is;}	

//	printf("Got first byte = %x\n", (unsigned char)byte);
	//std::cout << "got first byte = " << std::hex << byte << std::endl;

	if(!(byte & 0x80)) 
	{
//		std::cout << "The highest bit is 0: ASCII char." << std::endl;
		utf8char.bytes.push_back(byte);
//		std::cout << "Pushed it to utf8char" << std::endl;
		return is;
	}

	if(!(byte & 0x40))
	{
		std::cout << "NOT UTF!" << std::endl;
		utf8char.notutf8_flag = true;
		// error: not a utf8 encoding!
		is.clear();
		is.seekg(save_pos, ios::beg);
		return is;		
	}
	
//	std::cout << "Continue. First byte is correct 0xc0" << std::endl;
	utf8char.bytes.push_back(byte);
	bytes_count = 2;
//	std::cout << "bytes_count = 2" << std::endl;

	for(char i = 0x20; i > 0; i >>= 1)
	{
//		std::cout << "i = " << std::hex << i << std::endl;
		if((byte & i)) 
		{	
			bytes_count++; 
//			std::cout << "bytes_count = " << std::dec << bytes_count << std::endl;
		}
		else 
		{
//			std::cout << "break;" << std::endl;
			break;
		}
	}

//	std::cout << "bytes_count = " << std::dec << bytes_count << std::endl;

//	std::cout << "Reading rest of bytes:" << std::endl;
	for(int i = 1; i < bytes_count; i++)
	{
//		std::cout << "i = " << std::dec << i << std::endl;
//		std::cout << "is.get(&byte)" << std::endl;
		is.get(byte);
//		printf("Read byte = %x\n", (unsigned char)byte);
		if(is.eof()) 
		{	
			std::cout << "EOF!" << std::endl;
			utf8char.bytes.clear();
			is.clear();
			is.seekg(save_pos, ios::beg);
			return is;
		}
		//std::cout <<  << std::hex << byte << std::endl;
		if((byte & 0xc0) != 0x80)
		{
			// error: not a utf8 encoding!
			std::cout << "NOT UTF!" << std::endl;
			utf8char.notutf8_flag = true;
			utf8char.bytes.clear();
			is.clear();
			is.seekg(save_pos, ios::beg);
			return is;
		}	
//		std::cout << "Push back byte" << std::endl;
		utf8char.bytes.push_back(byte);
	}
//	std::cout << "Return is" << std::endl;
	return is;
}

std::ostream& operator<< (ostream& os, Utf8Char& utf8char)
{
	for(std::vector<char>::iterator i = utf8char.bytes.begin(); i != utf8char.bytes.end(); ++i)
		os.put(*i);
	//std::cout << std::endl;
	return os;
}

#else
#endif // __UTF8Char_CPP_

