#include <exception>
#include <string>

using namespace std;

class GException : public exception
{
	public:
		GException(const string newMsg = string()) : msg(newMsg) {};
		~GException() throw() {};
		
		const char *what() const throw() { return msg.c_str(); }
		
	private:
		string msg;
};

class GDisplayException : public GException
{
	public:
		GDisplayException(const string newMsg = string()) : GException(newMsg) {};
		~GDisplayException() throw() {};
};

