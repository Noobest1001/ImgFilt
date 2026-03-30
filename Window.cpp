#include <windows.h>
#include <tchar.h>
#include <shlobj.h>
#include <filesystem>
#include <iostream>
#include <vector>
// #include <shobjidl.h>

#include "headers/Window.hpp"
#include "headers/library.h"

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "Gdiplus.lib")

LRESULT CALLBACK WindowProc(HWND const *hWnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CLOSE:
			DestroyWindow(*hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		// case WM_PAINT:
		// 	Window::Imageinit();
		// 	break;
	}
	return DefWindowProc(*hWnd, uMsg, wParam, lParam);
}

Window::Window(const std::string &title, const int width, const int height) : m_hInstance(GetModuleHandleA(nullptr))
{
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = "Window Class";
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);

	constexpr DWORD style = WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX;

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, true);

	m_hWnd = CreateWindowEx(
		0,
		"Window Class",
		title.c_str(),
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		nullptr,
		nullptr,
		m_hInstance,
		nullptr
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

Window::~Window()
{
	const auto CLASS_NAME = "Window Class";

	UnregisterClass(CLASS_NAME, m_hInstance);
}

void Window::Imageinit()
{
	
}

bool Window::ProcessMessages()
{
	MSG msg = {};

	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);

		return true;
	}
	return true;

}

// std::string Window::GetFolderPath(const KNOWNFOLDERID folderId)
// {
// 	PWSTR path = nullptr;
//
// 	if (const HRESULT hr = SHGetKnownFolderPath(folderId, 0, nullptr, &path); SUCCEEDED(hr))
// 	{
// 		const std::wstring pathStr(path);
// 		CoTaskMemFree(path);
// 		const int size_needed = WideCharToMultiByte(CP_UTF8, 0, &pathStr[0], static_cast<int>(pathStr.size()), nullptr, 0, nullptr, nullptr);
// 		std::string str_to(size_needed, 0);
// 		WideCharToMultiByte(CP_UTF8, 0, &pathStr[0], static_cast<int>(pathStr.size()), &str_to[0], size_needed, nullptr, nullptr);
// 		return str_to;
// 	}
// 	std::cerr << "Couldn't get the path for the application." << std::endl;
// 	return R"(C:\Users\DefaultUser\Downloads)";
// }

// 🖕Fuck "Clean Code"
void Window::OpenFileDilg()
{
	if (HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE); SUCCEEDED(hr))
	{
		IFileOpenDialog *FileOpenDialog;

		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&FileOpenDialog));

		if (SUCCEEDED(hr))
		{
			hr = FileOpenDialog->Show(nullptr);

			if (SUCCEEDED(hr))
			{
				IShellItem *Item;
				hr = FileOpenDialog->GetResult(&Item);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = Item->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					if (SUCCEEDED(hr))
					{
						MessageBoxW(nullptr, pszFilePath, L"FileOpenDialog", MB_OKCANCEL);
					}
					Item->Release();
				}
				FileOpenDialog->Release();
			}
			CoUninitialize();
		}
	}
}
