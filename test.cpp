#include <iostream>

#include "GApplication.h"
#include "GWidget.h"
#include "GButton.h"

using namespace std;

int main()
{
	GApplication *app = GApplication::getInstance();
	
	cout << app->getDisplay()->getWidth() << endl << app->getDisplay()->getHeight() << endl;
	
	GWidget *widget = new GWidget();
	
	GButton *button = new GButton(widget);
	
	widget->show();
	
	sleep(10);
	
	app->run();
	
	delete app;
	app = NULL;

	return 0;
}

