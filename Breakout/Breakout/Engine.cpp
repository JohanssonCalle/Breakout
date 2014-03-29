//Engine.cpp

#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#include "Engine.h"

/*#include "FileManager.h"
#include "SpriteManager.h"
#include "InputManager.h"*/

#include "MenuState.h"
#include "GameState.h"

Engine::Engine()
{
	m_running = false;
}

void Engine::Update(float _deltatime)
{
	m_state_manager.Update(_deltatime);
}

void Engine::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 180, 255);
	SDL_RenderPresent(m_renderer);
}

bool Engine::Init()
{
	m_window_width = 1280;
	m_window_height = 720;

	scalex = (float)m_window_width/1280.f;
	scaley = (float)m_window_height/720.f;

	m_state_manager.Attach(new GameState);
	m_state_manager.Attach(new MenuState);
	m_state_manager.SetState("MenuState");

	m_window = SDL_CreateWindow("Breakout", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		m_window_width, m_window_height, 
		SDL_WINDOW_OPENGL);

	m_renderer = SDL_CreateRenderer(m_window, -1, 
		SDL_RENDERER_ACCELERATED);

	if (m_window == nullptr || m_renderer == nullptr)
		return false;

	m_running = true;

	return true;
}

void Engine::Run()
{
	while(m_running)
	{
		updateDeltatime();
		updateEvents();

		Update(m_deltatime);
		Draw();
	}
}

void Engine::updateEvents()
{

}

void Engine::updateDeltatime()
{
	float frametime = (float)SDL_GetTicks();

	m_deltatime = frametime - m_prevframetime;

	m_prevframetime = (float)SDL_GetTicks();
}

void Engine::CleanUp()
{


	SDL_DestroyRenderer(m_renderer); m_renderer = nullptr;
	SDL_DestroyWindow(m_window); m_window = nullptr;
}