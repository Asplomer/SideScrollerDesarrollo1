#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <math.h>
#include <raylib.h>
#include "gameState.h"

#include "play.h"
using namespace std;
namespace sideScroller {
	
	const int SQUARE = 20;
	//const int BULLETSPEED = 1000;
	//extern Texture2D texture;
	/*
	struct Ship
	{
		Texture2D texture;
		float _x = -100;
		float _y = -100;
		Vector2 origin = { 16, 16 };
		bool shoot;
		float rotation;
	};*/
	void InitShip();
	void DrawShip(float rot);
	void InputShip();
	void UnloadShip();
	Rectangle GetShip();
	void SetCrushed();
	bool GetCrushed();
};
#endif