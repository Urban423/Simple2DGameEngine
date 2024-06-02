#pragma once
#include <Window.h>

#define do_nothing	0
#define do_repair	1
#define do_break	2

class Location
{
public:
	Location();
	Location(float, float);
	~Location();

	float getX();
	float getY();

	void setX(float);
	void setY(float);
protected:
	float x;
	float y;
};

class Point : public Location
{
protected:
	int color;
	bool visible = true;
public:
	Point();
	~Point();

	void hide();
	void show();
	void moveTo(float, float);
};

class Object: public Point
{
public:
	int index = 0;
	bool drawCountor = 1;
	unsigned char up    = KeyCode_UpArrrow;
	unsigned char down  = KeyCode_DownArrow;
	unsigned char left  = KeyCode_LeftArrow;
	unsigned char right = KeyCode_RightArrow;

	int* colors;
	float speed    = 0.5;
	float rotation = 0;
public:
	Object();
	~Object();

	virtual void doSomething(int action, Object& obj) = 0;
	void show();
	void hide();
	int* getColors();
	bool getVisibility();
	void Update();
};

class ConcreateObjectInterface
{
public:
	virtual void doSomething(int action, Object& obj) = 0;
	virtual void show() = 0;
	virtual void hide() = 0;
};

class MapleLeaf: public Object, public ConcreateObjectInterface
{
public:
	MapleLeaf();
	~MapleLeaf();

	void doSomething(int action, Object& obj);
	void show();
	void hide();
};

class MapleLeafBroken : public MapleLeaf
{
public:
	MapleLeafBroken();
	~MapleLeafBroken();

	void doSomething(int action, Object& obj);
	void show();
	void hide();
};

class Stone : public Object, public ConcreateObjectInterface
{
public:
	Stone();
	~Stone(); 
	
	void doSomething(int action, Object& obj);
	void show();
	void hide();
};

class DuctTape : public Object, public ConcreateObjectInterface
{
public:
	DuctTape();
	~DuctTape();

	void show();
	void hide();
	void doSomething(int action, Object& obj);
};

class Knife: public Object, public ConcreateObjectInterface
{
protected:
	float sharp = 1.3;
public:
	Knife();
	~Knife();
	void doSomething(int action, Object& obj);

	void show();
	void hide();
};


class Scissors: public Knife
{
public:
	Scissors();
	~Scissors();
	void doSomething(int action, Object& obj);

	void show();
	void hide();
};
