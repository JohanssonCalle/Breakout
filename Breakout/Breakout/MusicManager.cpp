// MusicManager.cpp

#include "MusicManager.h"
#include <SDL_mixer.h>
#include "MusicClip.h"

MusicManager::MusicManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
	{
		printf("SDL_mixer :: Mix_OpenAudio %s \n", Mix_GetError());
	};
};

MusicManager::~MusicManager() 
{
	{

	for (int i = 0; i < m_apxMusicClip.size(); i++) 
	{
		delete m_apxMusicClip[i];
		m_apxMusicClip[i] = nullptr;
	};

	m_apxMusicClip.clear();

		std::map<std::string, Mix_Music*>::iterator xIt = m_mpxMusic.begin();
		while(xIt != m_mpxMusic.end() )
		{
			Mix_FreeMusic(xIt->second);
			xIt->second = nullptr;
			xIt++;
		};

		m_mpxMusic.clear();
	};
};

MusicClip* MusicManager::CreateMusic(std::string p_sPath) 
{
	MusicClip* m_pxReturn = nullptr;
	std::map<std::string, Mix_Music*>::iterator xIt = m_mpxMusic.find(p_sPath);

	if (xIt == m_mpxMusic.end())
	{
		Mix_Music* xMusic = Mix_LoadMUS(p_sPath.c_str());
		std::pair<std::string, Mix_Music*> xPair;
		xPair = std::make_pair(p_sPath, xMusic);
		m_mpxMusic.insert(xPair);
		m_pxReturn = new MusicClip(xMusic);
	}
	else 
	{
		m_pxReturn = new MusicClip(xIt->second); // xIt == m_axMusic[0]
	};

	m_apxMusicClip.push_back(m_pxReturn);

	return m_pxReturn;
};