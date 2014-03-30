// GameState.h

#pragma once

#include "State.h"

#include "Vector2.h"

class Engine;
class Level;

class GameState : public State {
public:
	GameState(Engine* _engine);

	bool Enter();
	void Exit();
	bool Update(float deltatime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &type);

private:
	Engine* m_engine;
	Level* m_level;

	Vector2 scale;
};
