#include "Window.h"
#include <stdio.h>
#include "resource.h"

Window::Window()
{
	Window::init("Window", 12, 12, false);
	r = Window::getInnerSize();
	image = new int[r.width * r.height];
	Matrix4x4 proj;
	proj.setIdentity();
	proj.setOrthoLH(r.width, r.height, 0.01f, 8);
	setKeyBoard((char*)Window::keyBoarState, (char*)Window::oldkeyBoarState);
	initGraphic(image, r.width, r.height, proj);
}

Window::~Window()
{
	DestroyWindow(_hwnd);
}

void Window::init(const char* windowName, int width, int height, bool fullscreen)
{

	RECT rc = { 0, 0, width, height };
	_hwnd = GetConsoleWindow();
	
	GetClientRect(_hwnd, &rc);
	width = rc.right - rc.left;
	height = rc.bottom - rc.top;
	left = rc.left;
	top = rc.top;
	centerX = left + width / 2;
	centerY = top + height / 2;

	hDC = GetDC(_hwnd);
	memBitmap = CreateBitmap(
		width, height,
		1, 8 * 4, nullptr);
}

void Window::broadcast()
{
	unsigned char* ptrA = keyBoarState;
	unsigned char* ptrB = oldkeyBoarState;
	for (unsigned int i = 0; i < 256; i++)
	{
		*(ptrB++) = *(ptrA++);
	}
	GetKeyState(0);
	if (GetKeyboardState(keyBoarState) == 0) {}

	oldPos = pos;
	GetCursorPos(&pos);
	Sleep(1);
}

Rect  Window::deltaCursorPos()
{
	return Rect(pos.x - oldPos.x, pos.y - oldPos.y);
}

void Window::setBuffer(int* image)
{
	HDC hdc = GetDC(_hwnd);
	SetBitmapBits(memBitmap, height * 4 * width, image);
	HDC src = CreateCompatibleDC(hdc);
	SelectObject(src, memBitmap);
	BitBlt(hdc, 0, 0, width, height, src, 0, -0, SRCCOPY);
	DeleteDC(src);
	ReleaseDC(_hwnd, hdc);
}

unsigned char* Window::getInputState()
{
	return keyBoarState;
}

//windows size block
void Window::setPos(int x, int y)
{
	left = x;
	top = y;
	centerX = left + width / 2;
	centerY = top + height / 2;
}
Rect Window::getCenter()
{
	return Rect(centerX, centerY);
}

Rect Window::getInnerSize()
{
	RECT rc;
	GetClientRect(_hwnd, &rc);
	width = rc.right - rc.left;
	height = rc.bottom - rc.top;
	left = rc.left;
	top = rc.top;
	centerX = left + width / 2;
	centerY = top + height / 2;
	return Rect(left, top, width, height);
}

void Window::setFullscreen(const bool state)
{
	if (state)
	{
		LONG l_WinStyle = GetWindowLong(_hwnd, GWL_STYLE);
		SetWindowLong(_hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~(WS_CAPTION | WS_THICKFRAME));
		SetWindowLong(_hwnd, GWL_EXSTYLE, WS_EX_TOPMOST);

		SetWindowPos(_hwnd, HWND_TOP, 0, 0, screen_width, screen_height, 0);
	}
	else
	{
		LONG l_WinStyle = GetWindowLong(_hwnd, GWL_STYLE);
		SetWindowLong(_hwnd, GWL_STYLE, (l_WinStyle | WS_CAPTION | WS_THICKFRAME | WS_BORDER) & ~WS_POPUP & ~WS_MAXIMIZE);
		//SetWindowPos(_hwnd, HWND_TOP, left, top, width, height, 0);
	}
}


//windows virtuals
void Window::onDestroy()
{

}

void Window::setSize(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;

	RECT rc;
	GetClientRect(_hwnd, &rc);
	ClientToScreen(_hwnd, (POINT*)&rc);
	left = rc.left;
	top = rc.top;

	centerX = left + width / 2;
	centerY = top + height / 2;
}

void Window::onFocus()
{

}

void Window::onKillFocus()
{

}



//system metrics
Rect Window::screenSize()
{
	return Rect(screen_width, screen_height);
}


//cursor
void Window::showCursor(const bool show)
{
	if (show)
	{
		SetCursor(arrowCursor);
	}
	else
	{
		SetCursor(noneCursor);
	}
}