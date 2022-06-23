#include "SoundManager.h"

Core::SoundManager G_SoundManager;

namespace Core
{
	SoundManager::SoundManager()
	{
		lastSound = 0;
	}

	SoundManager::~SoundManager()
	{
		for (auto i : sounds)
			delete[] i;
	}

	void SoundManager::LoadSound(std::string soundName)
	{
		std::map<std::string, int>::iterator it = soundNames.find(soundName);

		if (it == soundNames.end())
		{
			soundNames.insert(std::make_pair(soundName, lastSound++));
			sounds.push_back(ReadSound(soundName));
		}
	}

	void SoundManager::PlaySoundEffect(std::string soundName)
	{
		std::map<std::string, int>::iterator it = soundNames.find(soundName);

		if (it != soundNames.end())
		{
			PlaySound((LPCSTR)sounds[it->second], GetModuleHandle(NULL), SND_MEMORY | SND_ASYNC | SND_NOWAIT);
		}
		else
		{
			std::cout << soundName << " wasn't loaded" << std::endl;
		}
	}


	BYTE* SoundManager::ReadSound(std::string soundName)
	{
		DWORD dwFileSize;
		BYTE* pFileBytes;

		std::ifstream File(soundName, std::ios::binary);

		File.seekg(0, std::ios::end);
		int limit = File.tellg();
		dwFileSize = limit;

		pFileBytes = new BYTE[limit];
		File.seekg(0, std::ios::beg);

		File.read((char*)pFileBytes, limit);

		File.close();

		return pFileBytes;
	}
}