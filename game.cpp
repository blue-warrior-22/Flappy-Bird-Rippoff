#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;
GameObject* background;

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
    
    player = new GameObject("assets/player.png", renderer, 0,0,64,64);
    background = new GameObject("assets/nightbg.gif", renderer,0,0,900,540);

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
    player->Update();
    background->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    background->Render();
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){}