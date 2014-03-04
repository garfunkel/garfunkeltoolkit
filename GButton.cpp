#include <X11/Xlib.h>
#include "GApplication.h"
#include "GButton.h"

#include <iostream>

using namespace std;

GButton::GButton(GWidget *parent = NULL) : GWidget(parent)
{
	Display *display = GApplication::getInstance()->getDisplay()->getXDisplay();

	XResizeWindow(display, xWindow, 100, 30);
	XMapWindow(display, xWindow);
	XSetWindowBackground(display, xWindow, 0xFFFFFF);

	XEvent report;
	XSelectInput(display, xWindow, ExposureMask | KeyPressMask | ButtonPressMask);

	while (true)
	{
		XNextEvent(display, &report);
	
		switch  (report.type)
		{
			case Expose:
				cerr << "I have been exposed.\n";
				break;
		
			case KeyPress:
				//if (XLookupKeysym(&report.xkey, 0) == XK_space)
					cerr << "The space bar was pressed.\n";

				break;
		}
	}
}

GButton::~GButton()
{

}

