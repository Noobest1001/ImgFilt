#pragma once

#ifdef _WIN32

#include <filesystem>
#include <string>
#include <Windows.h>
#include <shtypes.h>

#include "../src/Pixel.cpp"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#include <X11/Xlib.h>

class Prog_Window
{
	public:
		Prog_Window(const std::string &title, int width, int height);
		Prog_Window(const Prog_Window&) = delete;
		Prog_Window& operator =(const Prog_Window&) = delete;
		~Prog_Window();

		static bool ProcessMessages();
		static void Imageinit();

	private:
		HWND m_hWnd;
		HINSTANCE m_hInstance;
	protected:

		int width, height;
		// void OpenFileDilg() const;
		static std::string GetFolderPath(KNOWNFOLDERID folderId);
		static std::string GetFolderPath(std::string FolderName);

		static void OpenFileDilg() ;
};


#endif