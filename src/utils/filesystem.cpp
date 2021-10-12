#include "filesystem.h"
#include <vector>
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

		return text;
	}

	std::vector<std::string> FileSystem::ReadLines(std::string path)
	{
		std::vector<std::string> container;
		std::ifstream readStream(path);
		std::string temp;
		while (getline(readStream, temp))
			container.push_back(temp);

		return container;
	}


	std::string FileSystem::GetFileExtension(std::string path)
	{
		std::size_t found = path.find_last_of(".");
		return (path.substr(found + 1));
	}

	bool FileSystem::Exists(std::string path)
	{
		struct stat buffer;
		return (stat(path.c_str(), &buffer) == 0);
	}
}