// SoundManager.h

#pragma once
#ifndef SOUNDMANAGER_H_INCLUDED
#define SOUNDMANAGER_H_INCLUDED

#include <SDL_mixer.h> //#pragma comment(lib,"SDL2_mixer.lib");
#include <vector>
#include <map>
#include <string>

class SoundClip;

class SoundManager 
{
public:
	SoundManager();
	~SoundManager();
	SoundClip* CreateSound(std::string p_sPath);

private:
	std::map<std::string, Mix_Chunk*> m_axSound;
	std::vector<SoundClip*> m_axSoundClips;
};

#endif