#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

namespace Core
{
	class FileSystem
	{
		
	public:
		FileSystem() {}
		static std::string ReadFile(std::string path);

		static std::string GetFileExtension(std::string path);
	};
}