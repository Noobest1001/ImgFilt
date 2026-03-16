#include "headers/library.h"
#include "Pixel.cpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void hello()
{
	std::cout << "Hello, World!" << std::endl;
	new Pixel(255, 255, 255);
}

std::stringstream getMagicNumber(const std::string &filetype)
{
	std::stringstream ss;
	if (filetype == "png")
	{
		ss << 0x89504E470D0A1A0A;
	}
	else if (filetype == "jpg" || filetype == "jpeg" || filetype == "jpe" || filetype == "jfi" || filetype == "jfif" || filetype == "jif")
	{
		ss << 0xFFD8FF;
	}
	return ss;
}

std::stringstream getFileType(const std::filesystem::path &filePath)
{
	std::stringstream ss;
	std::ifstream file(filePath, std::ios::binary);
	if (!file)
	{
		ss << "Error: Unable to open file.";
		exit(EXIT_FAILURE);
	}

	unsigned char buffer[8];
	file.read(reinterpret_cast<char *>(buffer), sizeof(buffer));

	// Im 99% sure this is redundant but just in case
	// if (!file)
	// {
	// 	ss << "Error: Unable to read file.";
	// 	return ss;
	// }

	// Check for PNG magic number
	if (buffer[0] == 0x89)
	{
		ss << "png";
		return ss;
	}

	// Check for JPEG magic number
	if (buffer[0] == 0xFF)
	{
		ss << "jpg";
		return ss;
	}

	ss << "unknown";
	return ss;
}

