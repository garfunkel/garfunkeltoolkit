#ifndef GDISPLAY_H
#define GDISPLAY_H

#include <X11/Xlib.h>
#include "GObject.h"

class GDisplay : public GObject
{
	public:
		GDisplay();
		~GDisplay();

		unsigned int getWidth() const { return XDisplayWidth(xDisplay, 0); }
		unsigned int getHeight() const { return XDisplayHeight(xDisplay, 0); }

		Display *getXDisplay() const { return xDisplay; }

	private:
		Display *xDisplay;
};

#endif // GDISPLAY_H

