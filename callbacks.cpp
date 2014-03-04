#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef void (*fptr)(void);

vector<fptr> triggeredCallbacks;
vector<fptr> clickedCallbacks;

void connect(const string signal, fptr to, ...)
{
	if (signal == "triggered")
		triggeredCallbacks.push_back(to);

	else if (signal == "clicked")
		clickedCallbacks.push_back(to);
}

void emit(const string signal)
{
	cout << "Emitting " + signal + " ";

	if (signal == "triggered")
	{
		for (vector<fptr>::iterator iter = triggeredCallbacks.begin(); iter != triggeredCallbacks.end(); iter++)
		{
			(*iter)();
		}
	}

	else if (signal == "clicked")
	{
		for (vector<fptr>::iterator iter = clickedCallbacks.begin(); iter != clickedCallbacks.end(); iter++)
		{
			(*iter)();
		//	(*iter)(rand());
		}
	}
}

void eventLoop()
{
	while (true)
	{
		if ((rand() % 100000000) == 54225458)
		{
			if ((rand() % 2) == 0)
				emit("triggered");

			else
				emit("clicked");
		}
	}
}

void callback1()
{
	cout << "in callback" << endl;
}

void callback2()
{
	cout << "in callback2" << endl;
}

void callback2(const int arg)
{
	cout << "In overrided callback2 with arg = " << arg << endl;
}

int main()
{
	srand(time(NULL));

	connect("triggered", callback1);
	connect("clicked", callback2);
	connect("clicked", callback2, "int");

	eventLoop();
}

