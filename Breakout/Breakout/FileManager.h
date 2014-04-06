//FileManager.h

#pragma once

#include <map>
#include <vector>
#include <string>
#include <fstream> 

class GameObject;
class GameObjectManager;

class SpriteManager;
class PlayerObject;
class Ball;
class Brick;

class FileManager
{
public:
	FileManager(GameObjectManager* _gameobject_manager);

	void Initialize(const std::string &directory);
	void ReadObjects(const std::string &filename, SpriteManager* _sprite_manager);
	int ReadHighscore(const std::string &filename);
	void WriteFile(const std::string &filename, int newhighscore);

protected:
	std::ifstream inStream;
	std::ofstream outStream;

	std::string m_directory;

private:
	GameObjectManager* m_gameobject_manager;
};