#include<iostream>

#include "headers/L_Window.hpp"
#include "headers/M_Window.hpp"

int main()
{
	std::cout << "Hello World!" << std::endl;

	auto pWindow = Prog_Window("Hello World!");
	bool running = true;

	while (running)
	{
		if (!Window::ProcessMessages())
		{
			std::cout << "Window closed, exiting..." << std::endl;
			running = false;
		}

		Sleep(10);
		// Process Windows messages
	}
#ifdef _WIN32
	delete pWindow;
#endif
	return 0;

}