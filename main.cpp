#include "Game.h"

int main()
{
    Game Game;
    Game.InitGame(920, 540, "Sprout Lands");

    while (Game.Running)
    {
        Game.Input();
        Game.Update();
        Game.Render();
    }

    Game.Close();
    return 0;
}
