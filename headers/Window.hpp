#pragma once

#include <filesystem>
#include <string>
#include <Windows.h>
#include <shtypes.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
class Window
{
	public:
		Window(const std::string &title, int width, int height);
		Window(const Window&) = delete;
		Window& operator =(const Window&) = delete;
		~Window();

		static bool ProcessMessages();
		static void Imageinit();

	private:
		HWND m_hWnd;
		HINSTANCE m_hInstance;

	protected:
		// void OpenFileDilg() const;
		static std::string GetFolderPath(KNOWNFOLDERID folderId);

		static void OpenFileDilg() ;
};
