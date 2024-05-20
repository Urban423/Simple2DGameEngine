#pragma once
#include <Window.h>
#include "Location.h"

class App: Window
{
public:
	App();
	~App();
	
	void onCreate();
	void onUpdate();

	bool isRunning();
private:
	int moveable_index = 0;
	int size = 5;
	Object* objects[256];
	bool _running = false;
};