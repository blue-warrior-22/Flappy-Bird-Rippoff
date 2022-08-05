#include"game.hpp"


class GameObject{

    public:
        GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int width, int height);
        ~GameObject();

        void Update();
        void Render();
    private:

        int xpos;
        int ypos;
        int heighty;
        int widthx;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;

};
