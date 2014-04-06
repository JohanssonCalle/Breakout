//Engine.cpp

#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#include "Engine.h"

#include "DrawManager.h"
#include "SpriteManager.h"

#include "Sprite.h"

#include "MenuState.h"
#include "GameState.h"
#include "LoadingState.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

Engine::Engine()
{
	m_prevframetime = 0.f;

	m_running = false;

	m_window = nullptr;
	m_renderer = nullptr;

	m_window_width = 1280;
	m_window_height = 720;
	m_volume = 0.2f;
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

	SDL_Rect src = { 0, 0, 1280, 720 };
	SDL_Rect dst = { 0, 0, 1280, 720 };
	SDL_RenderCopy(m_renderer, spr_background->m_texture, &src, &dst);

	m_state_manager.Draw();
}

bool Engine::Init()
{
	#pragma region Load Settings
	std::string temp;
	temp = readSettings("../data/settings/settings.txt", 0);
	if(temp == "")
		m_window_width = 1280;
	else
		std::istringstream (temp) >> m_window_width;

	temp = readSettings("../data/settings/settings.txt", 1);
	if(temp == "")
		m_window_height = 720;
	else
		std::istringstream (temp) >> m_window_height;

	temp = readSettings("../data/settings/settings.txt", 2);
	if(temp == "")
		m_volume = 0.2f;
	else
		std::istringstream (temp) >> m_volume;

	temp = readSettings("../data/settings/settings.txt", 3);
	if(temp == "")
		m_spritepath = "../data/sprites/";
	else
		std::istringstream (temp) >> m_spritepath;

	temp = readSettings("../data/settings/settings.txt", 4);
	if(temp == "")
		m_soundpath = "../data/sounds/";
	else
		std::istringstream (temp) >> m_soundpath;
	#pragma endregion

	scale.m_x = (float)m_window_width/1280.f;
	scale.m_y = (float)m_window_height/720.f;

	m_window = SDL_CreateWindow("Breakout", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		m_window_width, m_window_height, 
		SDL_WINDOW_OPENGL);

	m_renderer = SDL_CreateRenderer(m_window, -1, 
		SDL_RENDERER_ACCELERATED);

	m_state_manager.Attach(new GameState(this));
	m_state_manager.Attach(new MenuState(this));
	m_state_manager.Attach(new LoadingState(this));
	//m_state_manager.SetState("LoadingState");

	if(m_window == nullptr || m_renderer == nullptr)
	{
		return false;
	}

	m_draw_manager = new DrawManager;
	if(!m_draw_manager->Initialize(m_renderer)) {
		return false;
	};

	m_sprite_manager = new SpriteManager(m_draw_manager);
	if(!m_sprite_manager->Initialize(m_spritepath)) {
		return false;
	};

	m_sprite_manager->Load("spr_map.png",0,0,160,160);

	m_sprite_manager->Load("spr_background.png",0,0,1280,720);
	spr_background = m_sprite_manager->getSprite("spr_background.png",0,0,1280,720);

	m_running = true;

	m_state_manager.SetState("GameState");

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
	SDL_Event event;
	while(SDL_PollEvent(&event)) 
	{
		if(event.type == SDL_QUIT) 
		{
			m_running = false;
		}else if(event.type == SDL_KEYDOWN)
		{
			int index = event.key.keysym.sym & 0xFF;
			m_keyboard.m_current[index] = true;
		}else if(event.type == SDL_KEYUP)
		{
			int index = event.key.keysym.sym & 0xFF;
			m_keyboard.m_current[index] = false;
		}else if(event.type == SDL_MOUSEMOTION)
		{
			m_mouse.m_x = event.motion.x;
			m_mouse.m_y = event.motion.y;
		}else if(event.type == SDL_MOUSEBUTTONDOWN) 
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouse.m_current[0] = true;
			}else if(event.button.button == SDL_BUTTON_RIGHT) 
			{
				m_mouse.m_current[1] = true;
			}
		}else if(event.type == SDL_MOUSEBUTTONUP) 
		{
			if(event.button.button == SDL_BUTTON_LEFT) 
			{
				m_mouse.m_current[0] = false;
			}else if(event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouse.m_current[1] = false;
			}
		}
	}
}

void Engine::updateDeltatime()
{
	float frametime = (float)SDL_GetTicks();

	m_deltatime = frametime - m_prevframetime;

	m_prevframetime = (float)SDL_GetTicks();
}

void Engine::CleanUp()
{
	m_sprite_manager->Cleanup();
	m_draw_manager->Cleanup();

	delete m_sprite_manager; m_sprite_manager = nullptr;
	delete m_draw_manager; m_draw_manager = nullptr;

	SDL_DestroyRenderer(m_renderer); m_renderer = nullptr;
	SDL_DestroyWindow(m_window); m_window = nullptr;
}

std::string Engine::readSettings(const std::string &_filename, const int _line)
{
	std::ifstream stream;

	stream.open(_filename);
	if (stream.is_open())
	{
		unsigned int i = 0;
		std::string temp;
		while( !stream.eof() )
		{
			std::getline(stream, temp,'\n');

			if ( i == _line)
			{
				stream.close();
				return temp;
			}
			i++;
		}
	}

	stream.close();
	return "";
}