#pragma once
#include "../basic.h"
#include <Windows.h>

namespace Core
{
	class SoundManager
	{
		std::vector<BYTE*> sounds;
		std::map<std::string, int> soundNames;
		int lastSound;

	public:
		SoundManager();
		~SoundManager();

		void LoadSound(std::string soundName);

		void PlaySoundEffect(std::string soundName);

	private:

		BYTE* ReadSound(std::string soundName);
		//PlaySound(buffer, GetModuleHandle(NULL), SND_MEMORY | SND_ASYNC);


	};
}

