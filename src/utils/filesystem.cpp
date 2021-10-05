#include "filesystem.h"
#include <cstddef>

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

	std::string FileSystem::GetFileExtension(std::string path)
	{
		std::size_t found = path.find_last_of(".");
		return (path.substr(found + 1));
	}
}