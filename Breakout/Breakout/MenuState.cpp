// MenuState.cpp

#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include "MenuState.h"

#include "Engine.h"

#include "Sprite.h"
#include "SpriteManager.h"

#include "DrawManager.h"

#include "Input.h"

MenuState::MenuState(Engine* _engine) {
	std::cout << "MenuState::MenuState" << std::endl;

	m_engine = _engine;

	m_done = false;
};

bool MenuState::Enter() {
	std::cout << "MenuState::Enter" << std::endl;

	scale = m_engine->scale;

	m_engine->m_sprite_manager->Load("spr_menu.png",0,0,1280,720);
	spr_menu = m_engine->m_sprite_manager->getSprite("spr_menu.png",0,0,1280,720);

	return true;
};

void MenuState::Exit() {
	std::cout << "MenuState::Exit" << std::endl;

	delete m_engine; m_engine = nullptr;
};

bool MenuState::Update(float deltatime) {
	
	if(m_engine->m_keyboard.IsDownOnce(27))
	{
		m_next_state = "";
		Next();
	}
	if(m_engine->m_keyboard.IsDownOnce(32))
	{
		m_next_state = "GameState";
		Next();
	}

	return !m_done;
};

void MenuState::Draw() {
	std::cout << "MenuState::Draw" << std::endl;

	m_engine->m_draw_manager->Draw(spr_menu,0,0);
};

std::string MenuState::Next() {
	std::cout << "MenuState::Next" << std::endl;
	return m_next_state;
};

bool MenuState::IsType(const std::string &type) {
	return type.compare("MenuState") == 0;
};
