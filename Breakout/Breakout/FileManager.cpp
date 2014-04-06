//FileManager.cpp

#include "FileManager.h"
#include "GameObject.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "Collider.h"
#include "PlayerObject.h"
#include "Ball.h"
#include "Brick.h"
#include <sstream>
#include <iostream>

FileManager::FileManager()
{

}

void FileManager::Initialize(std::string directory)
{
	m_directory = directory;
}

std::map<std::string, float> FileManager::ReadSettings(std::string filename)
{
	inStream.open(m_directory + filename);

	std::string key;
	float value = 0;

	if(inStream.is_open())
	{
		while(!inStream.eof())
		{
			inStream >> key >> value;
			
			m_settings.insert( std::pair <std::string, float>(key, value) );
		}
		inStream.close();
		return m_settings;
	}
	else
	{
		std::cout << "Error, could not read from file" << std::endl;
	}
}

void FileManager::ReadObjects(std::string filename, SpriteManager* sprite_manager)
{
	inStream.open(m_directory + filename);

	if(inStream.is_open())
	{
		std::string key;
		int columns;
		int rows;
		int width;
		int height;
		Vector2 pos;
		std::string spritesource;

		inStream >> key >> columns >> rows >> width >> height >> pos.m_x >> pos.m_y >> spritesource;
		Vector2 tpos = pos;
		for(int r = 0;r < rows;r++)
		{
			for(int c = 0;c < columns; c++)
			{
				sprite_manager->Load(spritesource, 0, 0, width, height);
				Sprite* sprite = sprite_manager->getSprite(spritesource, 0, 0, width, height);
				Box *collider = new Box;
				collider->m_position=Vector2(tpos.m_x,tpos.m_y);
				collider->m_extension=Vector2(width,height);

				Brick* brick = new Brick(sprite, collider);
				m_bricks.push_back(brick);
				tpos.m_x += width;
			}
			tpos.m_x = pos.m_x;
			tpos.m_y += height;
		}
		while(!inStream.eof())
		{
			inStream >> key >> width >> height >> pos.m_x >> pos.m_y >> spritesource;
			sprite_manager->Load(spritesource, 0, 0, width, height);
			Sprite* sprite = sprite_manager->getSprite(spritesource, 0, 0, width, height);
			
			if(key == "player")
			{
				Box *collider = new Box;
				collider->m_position=Vector2(pos.m_x,pos.m_y);
				collider->m_extension=Vector2(width,height);
				m_player = new PlayerObject(sprite, collider);
				m_player->setPosition(Vector2(pos.m_x,pos.m_y));
			}
			else if(key == "ball")
			{
				Circle *collider = new Circle;
				collider->m_position=Vector2(pos.m_x,pos.m_y);
				collider->m_extension=Vector2(width,height);
				m_ball = new Ball(sprite, collider);
				m_ball->setPosition(Vector2(pos.m_x,pos.m_y));
			}
		}
		inStream.close();
	}
	else
	{
		std::cout << "Error, could not read from file" << std::endl;
	}
}

int FileManager::ReadHighscore(std::string filename)
{
	inStream.open(m_directory + filename);
	
	if(inStream.is_open())
	{
		int hs;
		inStream >> hs;

		return hs;
	}
	else
	{
		std::cout << "Error, could not read highscore" << std::endl;
	}
}

void FileManager::WriteFile(std::string filename, int newhighscore)
{
	outStream.open(m_directory + filename);

	if(outStream.is_open())
	{
		outStream << newhighscore;
	}
	else
	{
		std::cout << "Error, could not write from file" << std::endl;
	}
}

PlayerObject* FileManager::returnPlayer()
{
	return m_player;
}

Ball* FileManager::returnBall()
{
	return m_ball;
}

std::vector<Brick*> FileManager::returnBricks()
{
	return m_bricks;
}