//MusicManager.h

#pragma once
#ifndef MUSICMANAGER_H_INCLUDED
#define MUSICMANAGER_H_INCLUDED

#include <SDL_mixer.h>
#include <vector>
#include <map>
#include <string>

class MusicClip;

class MusicManager 
{
public:
	MusicManager();
	~MusicManager();
	MusicClip* CreateMusic(std::string p_sPath);

private:
	std::map<std::string, Mix_Music*> m_mpxMusic;
	std::vector<MusicClip*> m_apxMusicClip;
};

#endif