#pragma once
#include "Window.h"
#include <GraphicEngine.h>
#include <Matrix4x4.h>
#include <Object.h>

class App: Window
{
public:
	App();
	~App();
	
	void onCreate();
	void onUpdate();
	void calculateCamera();

	bool isRunning();


	void setSize(unsigned int width, unsigned int height);
	void onDestroy();
	void onFocus();
	void onKillFocus();
private:
	float t;
	Vector cam = Vector(100, -100, -100);
	int* image;
	Rect r;
	mesh Mesh;
	Matrix4x4 camView;
	Matrix4x4 mat;

	int size = 2;
	Object objects[256];

	//system paramerts
	bool focus = true;
	bool fulscreen = false;
	bool _running = false;
};