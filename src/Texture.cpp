#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D()
:mTextureID(0)
,mWidth(0)
,mHeight(0)
{

}

Texture2D::~Texture2D()
{

}

bool Texture2D::Load(const std::string& fileName)
{
	int channels = 0;

	unsigned char* image = stbi_load(fileName.c_str(),
										   &mWidth, &mHeight, &channels, STBI_rgb_alpha);

	if (image == nullptr)
	{
		FN_ERROR("SOIL failed to load image {}: {}", fileName.c_str());
		return false;
	}

	int format = GL_RGB;
	if (channels == 4)
	{
		format = GL_RGBA; FN_INFO("rgba");
	}
	else{
	   FN_INFO("rgb");
	}

	glGenTextures(1, &mTextureID);
	glBindTexture(GL_TEXTURE_2D, mTextureID);

	glTexImage2D(GL_TEXTURE_2D, 0, format, mWidth, mHeight, 0, format,
				 GL_UNSIGNED_BYTE, image);

	stbi_image_free(image);

	// Enable linear filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

void Texture2D::Unload()
{
	glDeleteTextures(1, &mTextureID);
}

void Texture2D::SetActive()
{
	glBindTexture(GL_TEXTURE_2D, mTextureID);
}
