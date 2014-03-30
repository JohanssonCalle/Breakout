// LoadingState.h

#pragma once

#include "State.h"

#include "Vector2.h"

class Engine;

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

	Vector2 scale;
};
