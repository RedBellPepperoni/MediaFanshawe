#include <fmod.hpp>
#include <iostream>
#include <conio.h>

static FMOD::System* g_soundsystem = nullptr;
FMOD::Sound* g_sound = nullptr;
FMOD::Channel* g_channel = nullptr;

void PlaySound(FMOD::Sound* sound, FMOD::Channel* channel)
{
	g_soundsystem->playSound(sound, 0, false, &channel);
}


void InitSoundSystem()
{
	
	


	FMOD_RESULT result = FMOD::System_Create(&g_soundsystem);
	if (result != FMOD_OK)
	{
		printf("Failed to Create FMod System");
		return;
	}

	result = g_soundsystem->init(1, FMOD_INIT_NORMAL, nullptr);

	if (result != FMOD_OK)
	{
		printf("Failed to initialize the Sound System");
		return;
	}


	result = g_soundsystem->createSound("audio/singing.wav", FMOD_DEFAULT, 0 , &g_sound);

	if (result != FMOD_OK)
	{
		printf("Failed to load the sound file");
		return;
	}

	
}




int main(int argc, char** argv)
{
	bool isRunning = true;

	InitSoundSystem();

	PlaySound(g_sound, g_channel);

	

	while (isRunning)	
	{
		g_soundsystem->update();

		if (_kbhit())
		{
			int key = _getch();

			// Escape key is pressed
			if (key == 27) { isRunning = false; }
		}

	}

	return 0;
}