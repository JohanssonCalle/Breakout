// Level.h

#pragma once

#include "Vector2.h"
#include <vector>
#include <string>
#include <map>

class GameObject;
class SpriteManager;
class GameObjectManager;
class Engine;

class Level {
	struct Coords {
		int x, y, w, h;
	};
public:
	Level(GameObjectManager* _gameobject_manager);
	~Level();

	bool Load(const std::string &filename, SpriteManager *sprite_manager);

	bool CheckCollision(GameObject *object, Vector2 &offset);

private:
	std::string m_spritemap_filename;
	int m_width;
	int m_height;
	std::map<char,Coords> m_tile_coords;

	GameObjectManager* m_gameobject_manager;
};
