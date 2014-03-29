// GameState.cpp

#include <iostream>
#include "GameState.h"

GameState::GameState() {
	std::cout << "GameState::GameState" << std::endl;
};

bool GameState::Enter() {
	std::cout << "GameState::Enter" << std::endl;
	return true;
};

void GameState::Exit() {
	std::cout << "GameState::Exit" << std::endl;
};

bool GameState::Update(float deltatime) {
	std::cout << "GameState::Update" << std::endl;
	return false;
};

void GameState::Draw() {
	std::cout << "GameState::Draw" << std::endl;
};

std::string GameState::Next() {
	std::cout << "GameState::Next" << std::endl;
	return "MenuState";
};

bool GameState::IsType(const std::string &type) {
	return type.compare("GameState") == 0;
};