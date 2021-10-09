#pragma once
#include <sstream>
#include <vector>

typedef unsigned int uint;

namespace Core
{
	std::vector<std::string> Split(std::string str, char splitter = ' ');

	std::string GetValueFromExpression(std::string str);


	uint ParseUInt(std::string str);
	int ParseInt(std::string str);
}