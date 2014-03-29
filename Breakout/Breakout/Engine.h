//Engine.h
#pragma once

#include "StateManager.h"
#include <vector>

class Engine
{
public:
	Engine();

	bool Init();
	void Run();

	void Update(float _deltatime);
	void Draw();

	void updateDeltatime();
	void updateEvents();

	void CleanUp();

	float scalex, scaley;
	int m_window_width, m_window_height;

private:
	bool m_running;
	float m_prevframetime;
	float m_deltatime;

	StateManager m_state_manager;
	struct SDL_Window* m_window;
	struct SDL_Renderer* m_renderer;
};