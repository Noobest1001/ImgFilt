#pragma once

#include <string>
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
class Window
{
	public:
		Window(const std::string &title, int width, int height);
		Window(const Window&) = delete;
		Window& operator =(const Window&) = delete;
		~Window();

		static bool ProcessMessages();

	private:
		HWND m_hWnd;
		HINSTANCE m_hInstance;
};
