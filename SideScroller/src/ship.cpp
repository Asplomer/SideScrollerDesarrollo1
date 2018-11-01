#include "ship.h"

namespace sideScroller {
	static Rectangle _ship = { 400,225, SQUARE, SQUARE };
	static Texture2D texture;
	static float _x = -100;
	static float _y = -100;
	static Vector2 originVec = { 64,64};
	static float Speed = 80.0f;
	static Vector2 vecSpeed = { 0.0f,0.0f };
	static Rectangle origin = { 0.0f, 0.0f,64.0f, 64.0f};
	static bool crushed= false;
	static float shipAngle;
	static float frameCounter;
	void InitShip() {
		texture = LoadTexture("res/Ship.png");
		shipAngle = 0.0f;
		frameCounter = 0.0f;
		crushed = false;
	}

	void DrawShip(float rot) {
		Rectangle aux= {0.0f,0.0f ,originVec.x, originVec.y};
		if (shipAngle > 1 && shipAngle < 2 || (shipAngle < -1 && shipAngle >-2))
			aux.x += texture.width / 2;
		if (shipAngle <= 0.3f && shipAngle >= -0.3f) {
			aux.x += texture.width / 2;
			aux.y += texture.height / 3;

		}
		if (shipAngle > 2 || shipAngle <-2) {
			aux.x += texture.width / 2;
			aux.y += 2 * texture.height / 3;
		}
	
		Vector2 aux2 = { _ship.x, _ship.y};
		if(!crushed)
		DrawTextureRec(texture, aux, aux2, WHITE);
	}

	void InputShip() {
		frameCounter += GetFrameTime();
		if (frameCounter > 3) {
			frameCounter = 0.0f;
		}

		if (shipAngle < 0)
			shipAngle += 10*GetFrameTime();
		else
			shipAngle -= 10*GetFrameTime();

		if(IsKeyDown(KEY_W)){
			_ship.y -= Speed *GetFrameTime();
			if(shipAngle<3)
			shipAngle += 50.0f*GetFrameTime();
		}
		if (IsKeyDown(KEY_A)) {
			_ship.x -= Speed *GetFrameTime();
			
		}
		if (IsKeyDown(KEY_D)) {
			_ship.x += Speed*GetFrameTime();

		}
		if (IsKeyDown(KEY_S)) {
			_ship.y += Speed *GetFrameTime();
			if (shipAngle>-3)
			shipAngle -= 50.0f*GetFrameTime();
		}
		if (IsKeyDown(KEY_SPACE)) {
			SetShot(true);
		}
	}
	void UnloadShip() {
		UnloadTexture(texture);
	}
	Rectangle GetShip() {
		return _ship;
	}
	void SetCrushed() {
		crushed = true;
	}
	bool GetCrushed() {
		return crushed;
	}
}