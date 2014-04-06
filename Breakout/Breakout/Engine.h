//Engine.h
#pragma once

#include "StateManager.h"
#include "Vector2.h"
#include "Input.h"

class DrawManager;
class SpriteManager;
class Sprite;
class MusicManager;
class MusicClip;

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
	std::string readSettings(const std::string &_filename, const int _line);

	bool m_running;
	float m_prevframetime;
	float m_deltatime;

	float m_volume;

	std::string m_spritepath;
	std::string m_soundpath;

	StateManager m_state_manager;
	struct SDL_Window* m_window;
	struct SDL_Renderer* m_renderer;

	DrawManager* m_draw_manager;
	SpriteManager* m_sprite_manager;
	MusicManager* m_musicmanager;
	MusicClip* m_music;

	Sprite* spr_background;

	Keyboard m_keyboard;
	Mouse m_mouse;
};