#include "game.hpp"

SDL_Texture* playerText;
SDL_Rect srcR, destR;

Game::Game(){}
Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initialised!" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window) {
            std::cout << "Window Created" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Rendere Created" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
    playerText = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update(){
    count++;
    destR.h = 32;
    destR.w = 32;

    std::cout << count << std::endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerText, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean(){}