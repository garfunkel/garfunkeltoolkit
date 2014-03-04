#include <X11/Xlib.h>

#include "GDisplay.h"
#include "GException.h"

GDisplay::GDisplay()
{
	xDisplay = XOpenDisplay(NULL);
	
	if (!xDisplay)
		throw GDisplayException("Could not open display.");
}

GDisplay::~GDisplay()
{
	XCloseDisplay(xDisplay);
	
	xDisplay = NULL;
}

