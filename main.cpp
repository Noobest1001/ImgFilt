#include<iostream>

#include "headers/Window.hpp"

int main()
{
	std::cout << "Hello World!" << std::endl;

	const auto* pWindow = new Window("Hello World!", 800, 600);
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
	delete pWindow;
	return 0;

}