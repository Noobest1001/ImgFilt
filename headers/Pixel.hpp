#pragma once

#include <tuple>

class Window;
typedef unsigned char byte;
typedef std::tuple<byte, byte, byte> Pixel_tuple;

class Pixel
{
	protected:
		byte r, g, b;

	public:
		explicit Pixel(const std::tuple<byte, byte, byte>& rgb);
		explicit Pixel(byte red, byte green, byte blue);
		Pixel(int gray);
		~Pixel();

		// Setters
		void setPixel(byte red, byte green, byte blue);
		[[nodiscard]] Pixel_tuple getPixel() const;
		[[nodiscard]] byte getRed() const;
		[[nodiscard]] byte getGreen() const;
		[[nodiscard]] byte getBlue() const;
		void setRed(byte red);
		void setGreen(byte green);
		void setBlue(byte blue);
		static void print(const Pixel &pixel);
		void draw(Window &window, unsigned int x, unsigned int y, Pixel pixel) const;
};

// Logical Operators
bool operator==(Pixel const & lhs, const Pixel &rhs);
bool operator==(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
bool operator==(Pixel const & lhs, byte rhs);
bool operator==(Pixel const & lhs, int rhs);
bool operator!=(Pixel const & lhs, const Pixel &rhs);
bool operator!=(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
bool operator!=(Pixel const & lhs, byte rhs);
bool operator!=(Pixel const & lhs, int rhs);
bool operator<(Pixel const & lhs, const Pixel &rhs);
bool operator<(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
bool operator<(Pixel const & lhs, byte rhs);
bool operator<(Pixel const & lhs, int rhs);
bool operator>(Pixel const & lhs, const Pixel &rhs);
bool operator>(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
bool operator>(Pixel const & lhs, byte rhs);
bool operator>(Pixel const & lhs, int rhs);
bool operator<=(Pixel const & lhs, const Pixel &rhs);
bool operator<=(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
bool operator<=(Pixel const & lhs, byte rhs);
bool operator<=(Pixel const & lhs, int rhs);
bool operator>=(Pixel const & lhs, const Pixel &rhs);
bool operator>=(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
bool operator>=(Pixel const & lhs, byte rhs);
bool operator>=(Pixel const & lhs, int rhs);
// bool operator&&(Pixel const & lhs, const Pixel &rhs);
// bool operator||(Pixel const & lhs, const Pixel &rhs);
bool operator!(Pixel const & lhs);

// Arithmetic Operators
Pixel operator+(Pixel const & lhs, const Pixel &rhs);
Pixel operator+(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
Pixel operator+(Pixel const & lhs, byte rhs);
Pixel operator+(Pixel const & lhs, int rhs);
Pixel operator-(Pixel const & lhs, const Pixel &rhs);
Pixel operator-(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
Pixel operator-(Pixel const & lhs, byte rhs);
Pixel operator-(Pixel const & lhs, int rhs);
Pixel operator*(Pixel const & lhs, const Pixel &rhs);
Pixel operator*(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
Pixel operator*(Pixel const & lhs, byte rhs);
Pixel operator*(Pixel const & lhs, int rhs);
Pixel operator/(Pixel const & lhs, const Pixel &rhs);
Pixel operator/(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
Pixel operator/(Pixel const & lhs, byte rhs);
Pixel operator/(Pixel const & lhs, int rhs);
Pixel operator%(Pixel const & lhs, const Pixel &rhs);
Pixel operator%(Pixel const & lhs, const std::tuple<byte, byte, byte> & rhs);
Pixel operator%(Pixel const & lhs, byte rhs);
Pixel operator%(Pixel const & lhs, int rhs);

// Increment and Decrement Operators
Pixel &operator++(Pixel &lhs); // Prefix increment
Pixel operator++(Pixel &lhs, int); // Postfix increment

// Bitwise Operators
Pixel operator&(Pixel const & lhs, const Pixel &rhs);
Pixel operator|(Pixel const & lhs, const Pixel &rhs);
Pixel operator^(Pixel const & lhs, const Pixel &rhs);
Pixel operator~(Pixel const & lhs);
Pixel operator-(Pixel const & lhs);
