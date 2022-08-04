#include "game.hpp"
#include "TextureManager.hpp"

SDL_Texture* background;
SDL_Texture* player;
SDL_Rect srcR, destR;
SDL_Rect playerR;

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
            std::cout << "Rendere Created" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    
    background = TextureManager::LoadTexture("assets/nightbg.gif", renderer);
    player = TextureManager::LoadTexture("assets/player.png", renderer);

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
    destR.h = 550;
    destR.w = 960;
    playerR.w = 80;
    playerR.h = 80;
    playerR.y = count;
    if(playerR.y == 510){
        count = 0;
    }
    std::cout << count << std::endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, &destR);
    SDL_RenderCopy(renderer, player, NULL, &playerR);
    SDL_RenderPresent(renderer);
}

void Game::clean(){}