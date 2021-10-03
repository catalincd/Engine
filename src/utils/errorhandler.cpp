#include "ErrorHandler.h"

namespace Core
{
	void ErrorHandler::Log(std::string errorText)
	{
		std::cout << errorText << std::endl;
	}

	void ErrorHandler::Log(std::vector<GLchar> errorText)
	{
		for(int i=0;i<errorText.size();i++)
			std::cout << errorText[i];
		std::cout << std::endl;
	}
}