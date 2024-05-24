#include "Game.h" 

Game* game = nullptr; 

int main(int argc, char* argv[]) {

    const int FPS = 10; 

    Uint32 elapsed = 0; 
    int frameTime = 0; 

    game = new Game(); 
    game->init("Snake-Game by 09Jayy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false); 

    while (game->running()) {
        elapsed = SDL_GetTicks(); 

        game->handleEvents(); 
        game->update(); 
        game->render(); 

        frameTime = SDL_GetTicks() - elapsed; 
        if (1000 / FPS > frameTime) {
            SDL_Delay((1000 / FPS) - frameTime);
        }; 
    }
    game->clean(); 

    return 0; 
}
