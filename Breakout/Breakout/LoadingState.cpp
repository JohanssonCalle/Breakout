// LoadingState.cpp

#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include "LoadingState.h"
#include "Engine.h"
#include "SpriteManager.h"

LoadingState::LoadingState(Engine* _engine) {
	std::cout << "LoadingState::LoadingState" << std::endl;

	m_engine = _engine;
};

bool LoadingState::Enter() {
	std::cout << "LoadingState::Enter" << std::endl;

	scale = m_engine->scale;

	m_engine->m_sprite_manager->Load("sprites/spr_map.png",0,0,160,160);

	return true;
};

void LoadingState::Exit() {
	std::cout << "LoadingState::Exit" << std::endl;

	delete m_engine; m_engine = nullptr;
};

bool LoadingState::Update(float deltatime) {
	std::cout << "LoadingState::Update" << std::endl;
	return false;
};

void LoadingState::Draw() {
	std::cout << "LoadingState::Draw" << std::endl;

	//m_engine->m_draw_manager->Draw();
};

std::string LoadingState::Next() {
	std::cout << "LoadingState::Next" << std::endl;
	return "MenuState";
};

bool LoadingState::IsType(const std::string &type) {
	return type.compare("LoadingState") == 0;
};
