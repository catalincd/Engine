#include "utilString.h"

namespace Core
{
	std::vector<std::string> Split(std::string str, char splitter)
	{
		std::vector<std::string> container;

		
		size_t cursor;
		while ((cursor = str.find(splitter)) != std::string::npos)
		{
			std::string current = str.substr(0, cursor);
			if(current != "")
				container.push_back(current);
			str = str.substr(cursor + 1);
		}

		if (str != "")
			container.push_back(str);

		return container;
	}

	std::string GetValueFromExpression(std::string str)
	{
		return str.substr(str.find('=') + 1);
	}

	uint ParseUInt(std::string str)
	{
		uint n = 0;
		for (int i = 0; i < str.length(); i++)
			n = n * 10 + (str[i] - '0');

		return n;
	}

	int ParseInt(std::string str)
	{
		int n = 0;
		int i = 0;
		int sign = 1;

		if (str[0] == '-')
		{
			sign = -1;
			i++;
		}

		for (; i < str.length(); i++)
			n = n * 10 + (str[i] - '0');

		return n * sign;
	}
}