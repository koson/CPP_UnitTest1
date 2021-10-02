#pragma once
using namespace std;
#include <string>
 

class MyClass
{
private:
	string _name;

public:
	MyClass()
	{
	}

	MyClass(std::string name)
	{
		_name = name;
	}

	string  GetName()
	{
		return _name;
	}

	bool isDouble(char* s)
	{
		if (s == NULL)
			return false;

		while (*s == ' ')
		{
			s++;
		}
		if (*s == '\0')
			return false;

		char* start = s;
		char* t = s + strlen(s) - 1;
		while (*t == ' ')
		{
			t--;
		}

		bool dot = false;
		bool exp = true;
		bool num = false;

		while (*s != '\0' && s != t + 1)
		{
			if (*s >= '0' && *s <= '9')
			{
				num = true;
			}
			else if (*s == '.')
			{
				if (exp || dot)
					return false;
				dot = true;
			}
			else if (*s == 'e')
			{
				if (!num || exp)
					return false;
				exp = true;
				num = false;
			}
			else if (*s == '-' || *s == '+')
			{
				if (s != start && *(s - 1) != 'e')
					return false;
			}
			else
				return false;

			s++;
		}

		return num;
	}

};

