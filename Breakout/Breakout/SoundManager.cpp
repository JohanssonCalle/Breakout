// SoundManager.cpp

#include "SoundManager.h"
#include <SDL_mixer.h>
#include "SoundClip.h"

SoundManager::SoundManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
	{
		printf("SDL_mixer :: Mix_OpenAudio %s \n", Mix_GetError());
	};
};

SoundManager::~SoundManager() 
{
	{

	for (int i = 0; i<m_axSoundClips.size(); i++) 
	{
		delete m_axSoundClips[i];
		m_axSoundClips[i] = nullptr;
	};

	m_axSoundClips.clear();

	std::map<std::string, Mix_Chunk*>::iterator xIt = m_axSound.begin();
	while (xIt != m_axSound.end()) 
	{
		Mix_FreeChunk(xIt->second);
		xIt->second = nullptr;
		xIt++;
	};

	m_axSound.clear();

	};
};

SoundClip* SoundManager::CreateSound(std::string p_sPath)
{
	SoundClip* xReturn = nullptr;
	std::map<std::string, Mix_Chunk*> ::iterator xIt = m_axSound.find(p_sPath);

	if(xIt == m_axSound.end())
	{
		Mix_Chunk* xSound = Mix_LoadWAV(p_sPath.c_str());		
		std::pair<std::string, Mix_Chunk*> xPair;
		xPair = std::make_pair(p_sPath, xSound);
		m_axSound.insert(xPair);
		xReturn = new SoundClip(xSound);
	}
	else
	{
		xReturn = new SoundClip(xIt->second);
	}
	m_axSoundClips.push_back(xReturn);		
	return xReturn;
}
