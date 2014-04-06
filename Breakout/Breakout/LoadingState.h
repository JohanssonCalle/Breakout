// LoadingState.h

#pragma once

#include "State.h"

#include "Vector2.h"

class Engine;
class FileManager;
class Sprite;

class LoadingState : public State {
public:
	LoadingState(Engine* _engine);

	bool Enter();
	void Exit();
	bool Update(float deltatime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &type);

private:
	Engine* m_engine;
	Sprite* spr_loading;

	Vector2 pos;

	Vector2 scale;
};
