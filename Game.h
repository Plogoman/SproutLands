//
// Created by Plogoman on 5/3/2024.
//

#ifndef SPROUTLANDS_GAME_H
#define SPROUTLANDS_GAME_H

#include <raylib.h>
#include "types.h"

struct Player {
    Rectangle PositionRectangle; //Destination Rect
    f32 Speed;
};

class Game {
    private:
        Player Player;
        Color TiffanyBlue = { 147, 211, 196, 255 };
    public:
        bool Running = true;
        Texture2D GrassSprite;
        Texture2D PlayerSprite;
        Rectangle PlayerSourceRectangle;

        void InitGame(i32 ScreenWidth, i32 ScreenHeight, const char* Title);
        void Input();
        void Update();
        void Render();
        void DrawScene();
        void Close();
};


#endif //SPROUTLANDS_GAME_H
