//
// Created by Plogoman on 5/3/2024.
//

#include "Game.h"

void Game::InitGame(i32 ScreenWidth, i32 ScreenHeight, const char* Title)
{
    InitWindow(ScreenWidth, ScreenHeight, Title);
    SetExitKey(0);
    SetTargetFPS(60);

    GrassSprite = LoadTexture("..\\res\\Tilesets\\Grass.png");
    PlayerSprite = LoadTexture("..\\res\\Characters\\Basic Charakter Spritesheet.png");

    PlayerSourceRect = {
            0,
            0,
            48,
            48
    };

    PlayerDestinationRect = {
            200,
            200,
            100,
            100
    };

    Player.Speed = 3;
}

void Game::Input()
{
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        PlayerDestinationRect.y -= Player.Speed;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        PlayerDestinationRect.y += Player.Speed;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        PlayerDestinationRect.x -= Player.Speed;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        PlayerDestinationRect.x += Player.Speed;
    }
}

void Game::Update()
{
    Running = !WindowShouldClose();
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(TiffanyBlue);
    DrawScene();
    EndDrawing();
}

void Game::DrawScene()
{
    DrawTextureV(GrassSprite, {100, 50}, WHITE);
    DrawTexturePro(PlayerSprite, PlayerSourceRect, PlayerDestinationRect, {PlayerDestinationRect.width, PlayerDestinationRect.height}, 0, WHITE);
}

void Game::Close()
{
    UnloadTexture(GrassSprite);
    UnloadTexture(PlayerSprite);
    CloseWindow();
}