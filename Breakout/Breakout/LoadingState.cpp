// LoadingState.cpp

#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include "LoadingState.h"
#include "Engine.h"
#include "SpriteManager.h"
#include "FileManager.h"
#include "DrawManager.h"

LoadingState::LoadingState(Engine* _engine) {

	m_engine = _engine;

	pos = Vector2(0,0);
};

bool LoadingState::Enter() {

	scale = m_engine->scale;

	m_engine->m_sprite_manager->Load("spr_loading.png",0,0,1280,720);
	spr_loading = m_engine->m_sprite_manager->getSprite("spr_loading.png",0,0,1280,720);

	m_engine->m_sprite_manager->Load("spr_map.png",0,0,160,160);
	m_engine->m_sprite_manager->Load("spr_ball.png",0,0,40,40);
	m_engine->m_sprite_manager->Load("spr_player.png",0,0,160,20);
	m_engine->m_sprite_manager->Load("spr_brick.png",0,0,80,20);
	

	return true;
};

void LoadingState::Exit() {

	delete spr_loading; spr_loading = nullptr;

	delete m_engine; m_engine = nullptr;
};

bool LoadingState::Update(float deltatime) {
	return false;
};

void LoadingState::Draw() {

	m_engine->m_draw_manager->Draw(spr_loading,0,0);

	SDL_Delay(200);

	Next();
};

std::string LoadingState::Next() {
	return "MenuState";
};

bool LoadingState::IsType(const std::string &type) {
	return type.compare("LoadingState") == 0;
};
