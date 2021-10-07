#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace Core
{
	class FileSystem
	{
		
	public:
		FileSystem() {}
		static std::string ReadFile(std::string path);

		static std::vector<std::string> ReadLines(std::string path);

		static std::string GetFileExtension(std::string path);
	};
}