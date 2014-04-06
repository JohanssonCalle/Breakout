//FileManager.h

#pragma once

#include <map>
#include <vector>
#include <string>
#include <fstream> 

class GameObject;
class SpriteManager;
class PlayerObject;
class Ball;
class Brick;

class FileManager
{
public:
	FileManager();

	void Initialize(std::string directory);
	std::map<std::string, float> ReadSettings(std::string filename);
	void ReadObjects(std::string filename, SpriteManager* sprite_manager);
	int ReadHighscore(std::string filename);
	void WriteFile(std::string filename, int newhighscore);
	PlayerObject* returnPlayer();
	Ball* returnBall();
	std::vector<Brick*> returnBricks();

protected:
	std::ifstream inStream;
	std::ofstream outStream;

	PlayerObject *m_player;
	Ball* m_ball;
	std::vector<Brick*> m_bricks;
	std::map<std::string, float> m_settings;
	std::string m_directory;
};