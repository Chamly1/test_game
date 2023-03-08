#include "iostream"
#include "Game.h"

int main()
{

    Game game;

    // Game loop
    while (game.isWindowOpen()) {
        // Event polling

        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}
