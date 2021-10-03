#include "filesystem.h"

namespace Core
{
	std::string FileSystem::ReadFile(std::string path)
	{
		std::string text = "";
		std::ifstream readStream(path);
		std::string temp;
		while (getline(readStream, temp))
			text += temp + "\n";

#if 0
		std::cout << text << std::endl;
#endif

		return text;
	}
}