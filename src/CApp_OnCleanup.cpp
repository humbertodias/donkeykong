/*
 * DonkeyKong
 * CApp_OnCleanup.cpp
 * This file contains the member function OnCleanup() for the class CApp.
 * OnCleanup() takes care of freeing all SDL surfaces and sound chunks from
 * memory.
 */

#include "CApp.h"

void CApp::OnCleanup() {
    for (int i = 0; i < entityList.size(); i++) {  // free all entities
        if (!entityList[i]) continue;
        entityList[i]->OnCleanup();
    }
    entityList.clear();
    mario.OnCleanup();
    peach.OnCleanup();

    SDL_FreeSurface(Surf_bgObjs);  // free all static background objects
    bgObjs.clear();

    SDL_FreeSurface(Surf_Menu);
    SDL_FreeSurface(Surf_Gameover);
    SDL_FreeSurface(Surf_Highscore);
    SDL_FreeSurface(Surf_Score);
    SDL_FreeSurface(Surf_Points);
    SDL_FreeSurface(Surf_LevelText);

    SDL_FreeSurface(Surf_Display);

    Mix_FreeChunk(burns);  // Free the sound effects
    Mix_FreeChunk(hurts);
    Mix_FreeChunk(jumps);
    Mix_FreeChunk(gameover);
    Mix_FreeChunk(levelclear);
    Mix_FreeMusic(theme);  // Free the music
    Mix_CloseAudio();      // Quit SDL_mixer

    SDL_Quit();
}
