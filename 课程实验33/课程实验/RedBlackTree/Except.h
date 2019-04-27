#ifndef EXCEPT_H_
#define EXCEPT_H_

#include <string>

using namespace std;

class DSException
{
public:
	DSException(const string & msg = "") : message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException : public DSException
{
public:
	DuplicateItemException(const string & msg = "") : DSException(msg) {}
};

class NullPointerException : public DSException
{
public:
	NullPointerException(const string & msg = "") : DSException(msg)
	{}
};
#endif