#include <cstring>
#include <iostream>
#include "GApplication.h"
#include "GWidget.h"
#include <typeinfo>

using namespace std;

GWidget::GWidget(GWidget *newParent)
{
	parent = newParent;
	Display *display = GApplication::getInstance()->getDisplay()->getXDisplay();

	if (parent)
		xWindow = XCreateSimpleWindow(display, *(parent->getXWindow()), 0, 0, 20, 20, 0, 0, 0);

	else	
		xWindow = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, 500, 400, 0, 0, 0);
}

void GWidget::show() const
{
	Display *display = GApplication::getInstance()->getDisplay()->getXDisplay();

	XGCValues gcv;

	XEvent e;
	GC m_gc = XCreateGC(display, xWindow, 0, &gcv);

	//gcv.background = 0x00FF00;
	//gcv.foreground = 0xFF00FF;
	XSetForeground(display, m_gc, 0xFF0000);
	XSetBackground(display, m_gc, 0x00FF00);

	XMapWindow(display, xWindow);
	XSelectInput(display, xWindow, ExposureMask);

	//XSetWindowForeground(display, xWindow, 0xFFFFFF);
	//XSetBackground(display, m_gc, 2556);
	//XSetForeground(display, m_gc, 25656);

//	)))))*****St7Je6Be5La4Si3Ti2Mo1*****(((((
	while (true)
	{
		XNextEvent(display, &e);

		if (e.type == Expose)
		{
			XFillRectangle (display, xWindow, m_gc, 20, 20, 50, 50);

			XDrawString(display, xWindow, m_gc, 100, 100, "Hello world!", strlen("Hello world!"));

			XFlush(display);
		}
	}
}

GWidget::~GWidget()
{
	Display *display = GApplication::getInstance()->getDisplay()->getXDisplay();

	XDestroyWindow(display, xWindow);
	
	display = NULL;
}

