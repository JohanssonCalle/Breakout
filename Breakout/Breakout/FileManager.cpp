//FileManager.cpp

#include "FileManager.h"

#include "GameObject.h"
#include "GameObjectManager.h"

#include "Vector2.h"

#include "Sprite.h"

#include "Collider.h"

#include "PlayerObject.h"
#include "Ball.h"
#include "Brick.h"

#include <sstream>
#include <iostream>

FileManager::FileManager(GameObjectManager* _gameobject_manager)
{
	m_gameobject_manager = _gameobject_manager;
}

void FileManager::Initialize(const std::string &directory)
{
	m_directory = directory;
}

void FileManager::ReadObjects(const std::string &filename, SpriteManager* _sprite_manager)
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
				Sprite* sprite = _sprite_manager->getSprite(spritesource, 0, 0, width, height);
				Box *collider = new Box;
				collider->m_position=Vector2(tpos.m_x,tpos.m_y);
				collider->m_extension=Vector2(width,height);

				Brick* brick = new Brick(sprite, collider);
				m_gameobject_manager->Attach(brick);

				tpos.m_x += width;
			}
			tpos.m_x = pos.m_x;
			tpos.m_y += height;
		}
		while(!inStream.eof())
		{
			inStream >> key >> width >> height >> pos.m_x >> pos.m_y >> spritesource;
			Sprite* sprite = _sprite_manager->getSprite(spritesource, 0, 0, width, height);
			
			if(key == "player")
			{
				Box *collider = new Box;
				collider->m_position=Vector2(pos.m_x,pos.m_y);
				collider->m_extension=Vector2(width,height);
				PlayerObject* m_player = new PlayerObject(sprite, collider);
				m_player->setPosition(Vector2(pos.m_x,pos.m_y));

				m_gameobject_manager->Attach(m_player);
			}
			else if(key == "ball")
			{
				Circle *collider = new Circle;
				collider->m_position=Vector2(pos.m_x,pos.m_y);
				collider->m_extension=Vector2(width,height);
				Ball* m_ball = new Ball(sprite, collider);
				m_ball->setPosition(Vector2(pos.m_x,pos.m_y));

				m_gameobject_manager->Attach(m_ball);
			}
		}
		inStream.close();
	}
	else
	{
		std::cout << "Error, could not read from file" << std::endl;
	}
}

int FileManager::ReadHighscore(const std::string &filename)
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

void FileManager::WriteFile(const std::string &filename, int newhighscore)
{
	outStream.open(m_directory + filename);

	if(outStream.is_open())
	{
		outStream << newhighscore;
	}
	else
	{
		std::cout << "Error, could not write to file" << std::endl;
	}
}