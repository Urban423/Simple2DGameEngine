#include "App.h"

#include <stdio.h>
#include <GraphicEngine.h>
#include "Vector.h"
#include <Matrix4x4.h>
#include <MapleLeaf.h>

App::App()
{	
	fulscreen 	= false;
	focus 		= true;
	_running 	= true;
}

App::~App(){}

void App::calculateCamera()
{
	mat.setIdentity();
	mat.setTranslation(0, 0, 0);

	cam = mat.getTranslation();
	camView = mat;
	camView.inverse();

}

void App::onCreate()
{
	//system
	_running = true;


	//graphicEngine
	Window::init("Window", 12, 12, false);
	r = Window::getInnerSize();
	image = new int[r.width * r.height];
	setKeyBoard((char*)Window::keyBoarState, (char*)Window::oldkeyBoarState);

	//MapleLeaf
	Mesh.vertexs = mapleLeafPoints;
	Mesh.vertexs_size = 27;
	Mesh.vertexs_copy = new Vector[Mesh.vertexs_size];
	Mesh.indicies = mapleLeaf_indexes;
	Mesh.indicies_size = 75;





	//object1
	objects[1].up = KeyCode_W;
	objects[1].down = KeyCode_S;
	objects[1].left = KeyCode_A;
	objects[1].right = KeyCode_D;
} 

void App::onUpdate()
{
	t += 0.01f;
	
	//clear buffer
	memset(image,    0, r.height * r.width * 4);

	//caluclate camera
	calculateCamera();
	Matrix4x4 proj;
	proj.setIdentity();
	proj.setOrthoLH(r.width, r.height, 0.01f, 4);


	//draw  mesh
	for (int i = 0; i < size; i++)
	{
		objects[i].Update();
		GraphicEngine::drawMesh(Mesh, image, r.width, r.height, camView, proj, objects[i].rotation, objects[i].x, objects[i].y);
	}


	//update iosystem
	Window::setBuffer(image);
	Window::broadcast();
}



bool App::isRunning()
{
	return _running;
}



void App::setSize(unsigned int width, unsigned int height)
{

}

void App::onDestroy()
{
	_running = false;
}

void App::onFocus()
{

}

void App::onKillFocus()
{

}