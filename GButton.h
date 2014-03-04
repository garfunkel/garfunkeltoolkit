#ifndef GBUTTON_H
#define GBUTTON_H

#include <X11/Xlib.h>
#include "GWidget.h"

class GButton : public GWidget
{
	public:
		GButton(GWidget *newParent);
		~GButton();
};

#endif // GBUTTON_H

