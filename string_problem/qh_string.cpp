#include "qh_string.h"

#include <string.h>

namespace qh
{
	// 

	string::string()
		: data_(NULL), len_(0)
	{
	}

	string::string(const char* s)
	{
		 len_ = strlen(s);
		data_ = new char[len_ + 1];
		strcpy(data_, s);

	}

	string::string(const char* s, size_t len)
	{
		int length = strlen(s);
		char * temp;
		temp = new char[length+1];
		strcpy(temp, s);
		temp[len] = '\0';
		len_ = len ;
		data_ = new char[len_+1];
		strcpy(data_, temp);
		delete [] temp;

	}

	string::string(const string& rhs)
	{
		len_ = rhs.len_;
		data_ = new char[len_ + 1];
		strcpy(data_, rhs.data_);

	}

	string& string::operator=(const string& rhs)
	{
		if(this == &rhs)
			return *this;
		delete  [] data_;
		len_ = rhs.len_;
		data_ = new char[len_ + 1];
		strcpy(data_, rhs.data_);
		return *this;
	}

	string::~string()
	{
		delete[] data_;

	}

	size_t string::size() const
	{
		return len_;
	}

	const char* string::data() const
	{
		return data_;
	}

	const char* string::c_str() const
	{
		return data_;
	}

	char* string::operator[](size_t index)
	{
		return & data_[index];
	}
}