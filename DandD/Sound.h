#if !defined (SOUND_H)
#define SOUND_H
#include "sdl_initialize.h"

class Sound
{
protected:
	std::string _path;

public:
	Sound(){};
	virtual void play() = 0;
};

class OneTimeEffect : public Sound
{
private:
	Mix_Chunk* _effect;

public:
	OneTimeEffect(std::string path);
	void play();
	~OneTimeEffect();
};

class ContinousEffect : public Sound
{
private:
	Mix_Music* _music;

public:
	ContinousEffect(std::string path);
	void play();
	void fadeInPlay(int milliseconds);
	void stopPlay();
	void fadeOutStopPlay(int milliseconds);
	~ContinousEffect();
};

#endif