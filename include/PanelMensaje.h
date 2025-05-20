#pragma once
#include "raylib.h"
#include <string>
enum PanelState {
	hidden,
	moving,
	showing,
};
class PanelMensaje
{
public:
	Vector2 position;
	Vector2 size;

	int timeOnScreen;

	std::string message;

	PanelMensaje(float posX, float width, float height, int _timeonScreen) {
		position = { posX,-height };
		size = { width,height };
		timer = 0;
		timeOnScreen = _timeonScreen;
		desiredPositionY = -height;
		state = hidden;
	}
	void Update() {
		if (state == hidden) {
			return;
		}
		else if (state == moving) {
			if (position.y != desiredPositionY) {
				//lerp
				position.y += (desiredPositionY - position.y) * 0.5f * GetFrameTime();
			}
			if (desiredPositionY -position.y < 0.1f) {
				position.y = desiredPositionY;
				state = showing;
				timer = 0;
			}
		}
		else if (state == showing) {
			timer += GetFrameTime();
			if (timer > timeOnScreen) {
				desiredPositionY = -size.y - 10;
				state = moving;
			}
		}
		
	}
	void Draw() {
		DrawRectangle(position.x, position.y, size.x, size.y, BEIGE);
		DrawRectangleLines(position.x, position.y, size.x, size.y,DARKBLUE);
		DrawText(message.c_str(), position.x+10, position.y + 10, 20, DARKGRAY);

	}
	void Show(std::string msg) {
		state = moving;
		timer = 0;
		message = msg;
		desiredPositionY = 10;
		position.y = -size.y;
	}
private:
	PanelState state = hidden;
	float timer;
	float desiredPositionY;
};

