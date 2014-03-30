// MenuState.h

#pragma once

#include "State.h"

#include "Vector2.h"

class Engine;

class MenuState : public State {
public:
	MenuState(Engine* _engine);

	bool Enter();
	void Exit();
	bool Update(float deltatime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &type);

private:
	Engine* m_engine;
	bool m_done;
	std::string m_next_state;

	Vector2 scale;
};
