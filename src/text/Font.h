#pragma once
#include "../basic.h"
#include "../texture/texture.h"

#define FONTS_PATH "res/fonts/"

namespace Core
{
	class Font
	{
		std::string m_name;
		std::string m_path;
		Texture* m_texture;
		uint m_maxHeight;

		vector2 m_size = vector2(512.0f, 512.0f);

		float x[256];
		float y[256];
		float xS[256];
		float yS[256];
		float xO[256];
		float yO[256];
		float width[256];
		float height[256];
		float advance[256];

	public:

		Font(std::string name);

		void Load();
		std::string GetName() const;
		vector2 ComputeTextSize(std::string text);
		vector2 GetPosition(char c); 
		vector2 GetSize(char c);
		vector2 GetBottom(char c); 
		vector2 GetOffset(char c);
		float GetAdvance(char c);
		Texture* GetTexture();
	};
}