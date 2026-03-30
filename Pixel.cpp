#include "headers/Pixel.hpp"

#include <cmath>
#include <iostream>
#include <gdiplus.h>

unsigned char r;
	unsigned char g;
	unsigned char b;


	/// <summary>
	/// sets the Pixel from a tuple of 3 bytes (0->255)
	/// </summary>
	Pixel::Pixel(const std::tuple<byte, byte, byte> &rgb)
	{
		this->r = std::get<0>(rgb);
		this->g = std::get<1>(rgb);
		this->b = std::get<2>(rgb);
	}

	/// <summary>
	/// sets the Pixel from a tuple of 3 bytes (0->255)
	/// This one will most likely be used more often
	/// </summary>
	Pixel::Pixel(const byte red, const byte green, const byte blue)
	{
		this->r = red;
		this->g = green;
		this->b = blue;
	}

	Pixel::Pixel(const int gray)
	{
		this->r = gray;
		this->g = gray;
		this->b = gray;
	}

	Pixel::~Pixel() = default;

	void Pixel::setPixel(const byte red, const byte green, const byte blue)
	{
		this->r = red;
		this->g = green;
		this->b = blue;
	}

	[[nodiscard]] Pixel_tuple Pixel::getPixel() const
	{
		return std::make_tuple(r, g, b);
	}

	// Getters

	[[nodiscard]] byte Pixel::getRed() const
	{
		return this->r;
	}

	[[nodiscard]] byte Pixel::getGreen() const
	{
		return this->g;
	}

	[[nodiscard]] byte Pixel::getBlue() const
	{
		return this->b;
	}

	// Setters

	void Pixel::setRed(const byte red)
	{
		this->r = red;
	}

	void Pixel::setGreen(const byte green)
	{
		this->g = green;
	}

	void Pixel::setBlue(const byte blue)
	{
		this->b = blue;
	}

	void Pixel::print(const Pixel &pixel)
	{
		std::cout << pixel.r << ", " << pixel.g << ", " << pixel.b << std::endl;
	}

	void Pixel::draw(Window &window, unsigned int x, unsigned int y, Pixel pixel) const
	{

	}

	bool operator==(Pixel const & lhs, const Pixel &rhs)
	{
		return lhs.getRed() == rhs.getRed() && lhs.getGreen() == rhs.getGreen() && lhs.getBlue() == rhs.getBlue();
	}
	bool operator==(Pixel const & lhs, const byte rhs)
	{
		return lhs.getRed() == rhs && lhs.getGreen() == rhs && lhs.getBlue() == rhs;
	}
	bool operator==(Pixel const & lhs, const int rhs)
	{
		return lhs.getRed() == rhs && lhs.getGreen() == rhs && lhs.getBlue() == rhs;
	}
	bool operator!=(Pixel const & lhs, const Pixel &rhs)
	{
		return !(lhs == rhs);
	}
	bool operator!=(Pixel const & lhs, const byte rhs)
	{
		return lhs.getRed() != rhs && lhs.getGreen() != rhs && lhs.getBlue() != rhs;
	}
	bool operator!=(Pixel const & lhs, const int rhs)
	{
		return lhs.getRed() != rhs && lhs.getGreen() != rhs && lhs.getBlue() != rhs;
	}
	bool operator<(Pixel const & lhs, const Pixel &rhs)
	{
		return lhs.getRed()*0.2126 + lhs.getGreen()*0.7152 + lhs.getBlue()*0.0722 < rhs.getRed()*0.2126 + rhs.getGreen()*0.7152 + rhs.getBlue()*0.0722;
	}
	bool operator>(Pixel const & lhs, const Pixel &rhs)
	{
		return lhs.getRed()*0.2126 + lhs.getGreen()*0.7152 + lhs.getBlue()*0.0722 > rhs.getRed()*0.2126 + rhs.getGreen()*0.7152 + rhs.getBlue()*0.0722;
	}
	bool operator<=(Pixel const & lhs, const Pixel &rhs)
	{
		return !(lhs > rhs);
	}
	bool operator>=(Pixel const & lhs, const Pixel &rhs)
	{
		return !(lhs < rhs);
	}

	// Arithmetic Operators
	Pixel operator+(Pixel const & lhs, const Pixel &rhs)
	{
		return Pixel(lhs.getRed() + rhs.getRed() > 255 ? 255 : lhs.getRed() + rhs.getRed(),
				   lhs.getGreen() + rhs.getGreen() > 255 ? 255 : lhs.getGreen() + rhs.getGreen(),
					lhs.getBlue() + rhs.getBlue() > 255 ? 255 : lhs.getBlue() + rhs.getBlue());
	}
	Pixel operator-(Pixel const & lhs, const Pixel &rhs)
	{
		return Pixel(lhs.getRed() - rhs.getRed() < 0 ? 0 : lhs.getRed() - rhs.getRed(),
				   lhs.getGreen() - rhs.getGreen() < 0 ? 0 : lhs.getGreen() - rhs.getGreen(),
					lhs.getBlue() - rhs.getBlue() < 0 ? 0 : lhs.getBlue() - rhs.getBlue());
	}
	Pixel operator*(Pixel const & lhs, const Pixel &rhs)
	{
		return Pixel(std::round(lhs.getRed() * rhs.getRed() / 255), lhs.getGreen() * rhs.getGreen() / 255,
		             lhs.getBlue() * rhs.getBlue() / 255);
	}
	Pixel operator/(Pixel const & lhs, const Pixel &rhs);

	// Grayscale a pixel
	// Pixel operator%(Pixel const & lhs, const Pixel &rhs);

	// Increment and Decrement Operators
	Pixel &operator++(Pixel &lhs); // Prefix increment
	Pixel operator++(Pixel &lhs, int); // Postfix increment

	// Bitwise Operators
	Pixel operator&(Pixel const & lhs, const Pixel &rhs);
	Pixel operator|(Pixel const & lhs, const Pixel &rhs);
	Pixel operator^(Pixel const & lhs, const Pixel &rhs);
	Pixel operator~(Pixel const & lhs);
	Pixel operator-(Pixel const & lhs);
