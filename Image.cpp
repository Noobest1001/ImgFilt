#include "headers/Image.hpp"

#include "headers/Window.hpp"


Image::Image(const std::string &name, const bool load, const unsigned int width, const unsigned int height, const FileType fileType)
{
	if (load)
	{
		Window window(imgName, width, height);
	}

	this->imgName = name;
	this->width = width;
	this->height = height;
	this->fileType = fileType;
	this->load = true;
}

Image::~Image() = default;
