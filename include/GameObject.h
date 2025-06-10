#pragma once
#include <string>
#include "raylib.h"

extern "C" {
	#include "md5.h"
#include <string>
}
class GameObject
{
protected:
	std::string name;
	uint8_t uid[16];
	std::string uidString="";
	
public:
	Vector2 position;
	Texture2D texture;
	bool isEnabled;
	
	//constructor recibe un nombre y computa el md5
	GameObject(char* _name,bool _isEnabled,Vector2 _position) {
		name = _name;
		isEnabled = _isEnabled;
		md5String(_name, uid);
		position = _position;
		texture = { 0 };
	}
	virtual void Start()=0;
	virtual void Update()=0;
	virtual void Draw()=0;

	//void Mov
	void printUID();
	void DrawUID();
	void UIDtoString();
	void Enable() {
		isEnabled = true;;
	}
	void Disable() {
		isEnabled = false;
	}
	std::string getUID()
	{
		std::string uidString;
		for (int i = 0; i < 16; i++)
		{
			char buffer[3];
			sprintf(buffer, "%02X", uid[i]);
			uidString += buffer;
		}
		return uidString;
	}
	std::string GetName() {
		return name;
	}
};

