// SpriteManager.cpp

#include <SDL_image.h>
#pragma comment(lib,"sdl2_image.lib")

#include <iostream>
#include <map>

#include "DrawManager.h"
#include "Sprite.h"
#include "SpriteManager.h"

SpriteManager::SpriteManager(DrawManager *draw_manager) {
	m_draw_manager = draw_manager;
};

SpriteManager::~SpriteManager() {
};

bool SpriteManager::Initialize(const std::string &directory) {
	IMG_Init(IMG_INIT_PNG);

	m_directory = directory;

	return true;
};

void SpriteManager::Cleanup() {
	std::map<std::string,Pair>::iterator it = m_sprites.begin();
	while(it != m_sprites.end()) {
		SDL_FreeSurface(it->second.surface);
		SDL_DestroyTexture(it->second.texture);
		++it;
	};
	m_sprites.clear();

	IMG_Quit();
};

void SpriteManager::Load(const std::string &filename, int x, int y, int width, int height) {
	std::map<std::string,Pair>::iterator it = m_sprites.find(filename);
	if(it == m_sprites.end()) {
		std::string path = m_directory + filename;
		SDL_Surface* surface = IMG_Load(path.c_str());
		if(surface == nullptr) {
			std::cout << "File not found" << std::endl;
		};
		SDL_Texture* texture = SDL_CreateTextureFromSurface(
			m_draw_manager->m_renderer,
			surface);

		Pair pair = { surface, texture };

		m_sprites.insert( std::pair<std::string,Pair>( filename, pair ) );
	};
};

Sprite* SpriteManager::getSprite(const std::string &_filename, int _x, int _y, int _width, int _height)
{
	std::map<std::string,Pair>::iterator it;// = m_sprites.find(_filename);
	it = m_sprites.find(_filename);

	if(it == m_sprites.end())
	{
		std::cout << "Sprite not found" << std::endl;
	}

	return new Sprite(it->second.surface, it->second.texture, _x, _y, _width, _height);
}