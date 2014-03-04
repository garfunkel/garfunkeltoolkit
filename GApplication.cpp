#include "GApplication.h"
#include "GDisplay.h"

GApplication *GApplication::instance = NULL;

GApplication::GApplication()
{
	display = new GDisplay();
}

GApplication::~GApplication()
{
	delete display;
	
	display = NULL;
}

void GApplication::run()
{
	
}

