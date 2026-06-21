#pragma once

#ifdef linux
#include <iostream>
#include <ostream>
#include <string>
#include <future>
#include <chrono>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "Image.hpp"
#include "../src/Pixel.cpp"



class Prog_Window
{
    protected:
        XEvent event;

        void WindowManager(Prog_Window *window)
        {
            if (mainThread == std::this_thread::get_id())
            {

            }
            while (running)
            {
                XNextEvent(display, &event);

                switch (event.type)
                {
                    case ClientMessage:
                        if (event.xclient.message_type == XInternAtom(display, "WM_PROTOCOLS", false) && event.xclient.data.l[0] == XInternAtom(display, "WM_DELETE_WINDOW", false))
                        {
                            running = false;
                        }

                }
            }
        }

    private:
        static bool running;
        std::string windowName = "Main Window";
        Display *display = nullptr;
        int screenID = NULL;
        Window rootWin = NULL;
        unsigned int width = 0, height = 0;
        GC gc = None;
        std::thread::id mainThread;


    public:
        void WindowManager(int _cpp_par_);

        Prog_Window()
        {
            mainThread = std::this_thread::get_id();
            display = XOpenDisplay(nullptr);

            if (!display)
            {
                std::cerr << "Error opening display" << std::endl;
                exit(EXIT_FAILURE);
            }

            screenID = DefaultScreen(display);
            rootWin = RootWindow(display, screenID);

            int x = 10, y = 10;
            constexpr unsigned int borderWidth = 5;

            Window MainWin = XCreateSimpleWindow(
                display, rootWin,
                x, y, width, height, borderWidth,
                BlackPixel(display, screenID), WhitePixel(display, screenID));

            gc = XCreateGC(display, RootWindow(display, screenID), 0, nullptr);

            Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", false);

            XStoreName(display, MainWin, windowName.c_str());

            XSelectInput(display, MainWin, StructureNotifyMask | KeyPressMask | ExposureMask | ButtonPressMask);

            XMapWindow(display, MainWin);

            WindowManager(this);

        }



        Prog_Window(std::string WindowName);
        Prog_Window(Image image)
        {
            windowName = image.getName();
            Prog_Window();
        }

        ~Prog_Window()
        {
            if (running)
            {
                XFreeGC(display, gc);

            }
        }
};


#endif