#pragma once
#include <gdiplus.h>

#include "Window.hpp"

class GdiplusHelper
{
public:

	GdiplusHelper()
	{
		Gdiplus::GdiplusStartupInput input;
		ULONG_PTR token;
		if (Gdiplus::Ok != Gdiplus::GdiplusStartup(&token, &input, nullptr))
		{
			throw std::runtime_error("Failed to initialize GDI+.");
		}
		this->m_token = token;
	}
	~GdiplusHelper()
	{
		Gdiplus::GdiplusShutdown(m_token);
	}

private:
	ULONG_PTR m_token;
};
