// MenuState.cpp

#include <iostream>
#include "MenuState.h"

MenuState::MenuState() {
	std::cout << "MenuState::MenuState" << std::endl;
	m_done = false;
};

bool MenuState::Enter() {
	std::cout << "MenuState::Enter" << std::endl;
	return true;
};

void MenuState::Exit() {
	std::cout << "MenuState::Exit" << std::endl;
};

bool MenuState::Update(float deltatime) {
	std::cout << "MenuState::Update" << std::endl;
	std::cout << "[new]  New game" << std::endl;
	std::cout << "[opt]  Options" << std::endl;
	std::cout << "[quit] Quit" << std::endl;
	std::string choice;
	std::cin >> choice;
	if(choice.compare("new") == 0) {
		m_next_state = "GameState";
		m_done = true;
	}
	else if(choice.compare("opt") == 0) {
		m_next_state = "OptionsState";
		m_done = true;
	}
	else if(choice.compare("quit") == 0){
		m_next_state = "";
		m_done = true;
	};

	return !m_done;
};

void MenuState::Draw() {
	std::cout << "MenuState::Draw" << std::endl;
};

std::string MenuState::Next() {
	std::cout << "MenuState::Next" << std::endl;
	return m_next_state;
};

bool MenuState::IsType(const std::string &type) {
	return type.compare("MenuState") == 0;
};
