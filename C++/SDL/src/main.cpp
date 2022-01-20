#include <SDL2/SDL.h>
#include <iostream>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool init();
bool loadMedia(std::string path);
void close();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* helloSurface = NULL;


int main(int argc, char* args[]) {
    
    //Start up SDL and create window
    if(!init()) {
        printf("Failed to initialize!\n");
    }
    else {
        //Load media
        if(!loadMedia("res/test.bmp")) {
            printf("[Error] Failed to load media!\n");
        }
        else {
            //Apply the image
            SDL_BlitSurface(helloSurface, NULL, screenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(window);
        }
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    //Free app resources and close SDL
    close();

    return 0;
}


bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("[Error] SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            printf("[Error] Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}


bool loadMedia(std::string path) {
    //Loading success flag
    bool success = true;

    if (path.length() <= 0) {
        printf("[Error] Cannot load resource at path of length 0\n");
        success = false;
    } else {
        //Load splash image
        helloSurface = SDL_LoadBMP(path.c_str());
        if(helloSurface == NULL)
        {
            printf("[Error] Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
            success = false;
        }
    }
    
    return success;
}


void close() {
    //Deallocate surface
    SDL_FreeSurface(helloSurface);
    helloSurface = NULL;

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}