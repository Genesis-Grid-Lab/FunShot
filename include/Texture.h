#pragma once
#include "Core.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	bool Load(const std::string& fileName);
	void Unload();

	void SetActive();

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }
private:
	unsigned int mTextureID;
	int mWidth;
	int mHeight;
};
