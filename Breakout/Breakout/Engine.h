//Engine.h
#pragma once

#include "StateManager.h"
#include "Vector2.h"

class DrawManager;
class SpriteManager;

class Engine
{
	friend class GameState;
	friend class LoadingState;
	friend class MenuState;

public:
	Engine();

	bool Init();
	void Run();

	void Update(float _deltatime);
	void Draw();

	void updateDeltatime();
	void updateEvents();

	void CleanUp();

	Vector2 scale;
	int m_window_width, m_window_height;

private:
	bool m_running;
	float m_prevframetime;
	float m_deltatime;

	StateManager m_state_manager;
	struct SDL_Window* m_window;
	struct SDL_Renderer* m_renderer;

	DrawManager* m_draw_manager;
	SpriteManager* m_sprite_manager;
};