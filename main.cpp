#include "Game.h"

int main()
{
    Game Game;
    Game.InitGame(1000, 600, "Sprout Lands");

    while (Game.Running)
    {
        Game.Input();
        Game.Update();
        Game.Render();
    }

    Game.Close();
    return 0;
}
