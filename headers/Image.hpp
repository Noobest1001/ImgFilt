#pragma once

#include <string>

#include "Pixel.hpp"

enum FileType
{
	PNG,
	JPG,
	UNKNOWN
};

class Image
{
	std::string imgName;
	FileType fileType;
	bool load = false;
	unsigned int width = 0, height = 0;
	Pixel pixel = Pixel(0,0,0);

	public:
		Image(const std::string &name, bool load, unsigned int width, unsigned int height, FileType fileType);
		~Image();

		[[nodiscard]] std::string getName() const;
		[[nodiscard]] FileType getFileType() const;
		[[nodiscard]] bool isLoaded() const;
		[[nodiscard]] unsigned int getWidth() const;
		[[nodiscard]] unsigned int getHeight() const;
		[[nodiscard]] Pixel getPixel(size_t x, size_t y) const;
		void setPixel(size_t x, size_t y, const Pixel &pixel);

		Image operator==(Image &other);
};
