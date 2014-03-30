// GameState.cpp

#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include "GameState.h"

#include "Engine.h"
#include "Level.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Sprite.h"

GameState::GameState(Engine* _engine) {
	std::cout << "GameState::GameState" << std::endl;

	m_engine = _engine;


};

bool GameState::Enter() {
	std::cout << "GameState::Enter" << std::endl;

	scale = m_engine->scale;

	m_level->Load("levels/level.txt", m_engine->m_sprite_manager);
	Sprite* spr_player = m_engine->m_sprite_manager->getSprite("sprites/pad_player.png",0,0,200,30);
	Sprite* spr_ball = m_engine->m_sprite_manager->getSprite("sprites/ball.png",0,0,40,40);
	Sprite* spr_bricks = m_engine->m_sprite_manager->getSprite("sprites/brick.png",0,0,140, 50);

	return true;
};

void GameState::Exit() {
	std::cout << "GameState::Exit" << std::endl;


	delete m_level; m_level = nullptr;
	delete m_engine; m_engine = nullptr;
};

bool GameState::Update(float deltatime) {
	std::cout << "GameState::Update" << std::endl;
	return false;
};

void GameState::Draw() {
	std::cout << "GameState::Draw" << std::endl;

	//m_engine->m_draw_manager->Draw();
};

std::string GameState::Next() {
	std::cout << "GameState::Next" << std::endl;
	return "MenuState";
};

bool GameState::IsType(const std::string &type) {
	return type.compare("GameState") == 0;
};