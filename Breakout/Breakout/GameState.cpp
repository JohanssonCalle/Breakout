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
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include "Sprite.h"

GameState::GameState(Engine* _engine) {
	m_engine = _engine;

	m_collision_manager = new CollisionManager();

	m_gameobject_manager = new GameObjectManager(m_collision_manager);

	m_level = new Level(m_gameobject_manager);
};

bool GameState::Enter() {
	scale = m_engine->scale;

	if(!m_level->Load("../data/level/level.txt", m_engine->m_sprite_manager))
		return false;



	return true;
};

void GameState::Exit() {
	delete m_level; m_level = nullptr;
	delete m_gameobject_manager;
	m_gameobject_manager = nullptr;
	delete m_engine; m_engine = nullptr;
};

bool GameState::Update(float deltatime) {
	m_gameobject_manager->UpdateAllGameObject(deltatime);
	
	if(m_engine->m_window_height == 2)
		return false;

	return true;
};

void GameState::Draw() {
	m_gameobject_manager->DrawAllGameObjects(m_engine->m_draw_manager);
};

std::string GameState::Next() {
	return "MenuState";
};

bool GameState::IsType(const std::string &type) {
	return type.compare("GameState") == 0;
};