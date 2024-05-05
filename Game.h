//
// Created by Plogoman on 5/3/2024.
//

#ifndef SPROUTLANDS_GAME_H
#define SPROUTLANDS_GAME_H

#include <raylib.h>
#include "types.h"

struct Player {
    Rectangle Position; //Destination Rectangle
    f32 Speed;
    Camera2D PlayerCamera;
};

struct AudioController {
    bool Paused;
    Music Music;
};

class Game {
    private:
        Player Player;
        AudioController Audio;
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
