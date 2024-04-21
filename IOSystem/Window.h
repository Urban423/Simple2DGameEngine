#pragma once
#include <Windows.h>
#include "Rect.h"

typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC)(int);

class Window
{
public:
	Window();
	~Window();

	//system metrics
	Rect screenSize();
	
	//size
	Rect getCenter();
	Rect getInnerSize();
	void setPos(int x, int y);
	void setFullscreen(const bool state);
	
	//cursor
	void showCursor(const bool show);
	
	//main
	Rect deltaCursorPos();
	void init(const char* windowName, int width, int height, bool fullscreen);
	void broadcast();
	void setBuffer(int* image);
	unsigned char* getInputState();
	
	//virtuals
	virtual void setSize(unsigned int width, unsigned int height);
	virtual void onDestroy();
	virtual void onFocus();
	virtual void onKillFocus();
protected:

	unsigned char keyBoarState[256];
	unsigned char oldkeyBoarState[256];
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;

	POINT oldPos;
	POINT pos;

	HWND _hwnd; 
	HDC hDC;
	HBITMAP memBitmap;
	HCURSOR arrowCursor;
	HCURSOR  noneCursor;
	
	int screen_width;
	int screen_height;
	int width;
	int height;
	int left;
	int top;
	int centerX;
	int centerY;
};

