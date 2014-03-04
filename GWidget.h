#ifndef GWIDGET_H
#define GWIDGET_H

#include <X11/Xlib.h>

#include "GObject.h"

class GWidget : public GObject
{
	public:
		GWidget(GWidget *newParent = NULL);
		~GWidget();

		void show() const;
		Window *getXWindow() { return &xWindow; }
		GWidget *getParent() const { return parent; }

	protected:
		GWidget *parent;
		Window xWindow;
};

#endif // GWIDGET_H

