#ifndef GAPPLICATION_H
#define GAPPLICATION_H

#include <X11/Xlib.h>

#include "GObject.h"
#include "GDisplay.h"

class GApplication : public GObject
{
	public:
		static GApplication *getInstance()
		{
			if (!instance)
				instance = new GApplication;
				
			return instance;
		}
	
		~GApplication();
	
		void run();
		GDisplay *getDisplay() const { return display; }

	private:
		GApplication();
		
		static GApplication *instance;
		GDisplay *display;
};

#endif // GAPPLICATION_H

