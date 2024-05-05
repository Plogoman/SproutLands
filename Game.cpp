//
// Created by Plogoman on 5/3/2024.
//

#include "Game.h"

void Game::InitGame(i32 ScreenWidth, i32 ScreenHeight, const char* Title)
{
    InitWindow(ScreenWidth, ScreenHeight, Title);
    SetExitKey(0);
    SetTargetFPS(60);

    GrassSprite = LoadTexture(R"(..\\res\\Tilesets\\Grass.png)");
    PlayerSprite = LoadTexture(R"(..\res\Characters\Basic Charakter Spritesheet.png)");

    // Player Source Rectangle.
    Player.Animation = {
            0,
            0,
            48,
            48
    };
    // Player Destination Rectangle.
    Player.Position = {
            200,
            200,
            100,
            100
    };
    Player.Speed = 3;
    Player.PlayerCamera = {
            {
                    (f32)ScreenWidth / 2.0f,
                    (f32)ScreenHeight / 2.0f
                    },
            {
                    (f32)(Player.Position.x - (Player.Position.width / 2.0f)),
                    (f32)(Player.Position.y - (Player.Position.height / 2.0f))
                    },
            0.0f,
            1.0f
    };

    InitAudioDevice();
    Audio.Music = LoadMusicStream(R"(..\\res\\Audio\\Avery's Farm.mp3)");
    Audio.Paused = false;
    PlayMusicStream(Audio.Music);
}
void Game::Input()
{
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        Player.Moving = true;
        Player.Direction = 1;
        Player.UP = true;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        Player.Moving = true;
        Player.Direction = 0;
        Player.DOWN = true;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        Player.Moving = true;
        Player.Direction = 2;
        Player.LEFT = true;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        Player.Moving = true;
        Player.Direction = 3;
        Player.RIGHT = true;
    }

    if (IsKeyPressed(KEY_Q))
    {
        Audio.Paused = !Audio.Paused;
    }
}
void Game::Update()
{
    Running = !WindowShouldClose();

    if (Player.Moving)
    {
        if (Player.UP)
        {
            Player.Position.y -= Player.Speed;
        }
        if (Player.DOWN)
        {
            Player.Position.y += Player.Speed;
        }
        if (Player.LEFT)
        {
            Player.Position.x -= Player.Speed;
        }
        if (Player.RIGHT)
        {
            Player.Position.x += Player.Speed;
        }
        if (FrameCount % 8 == 0)
        {
            Player.Frame++;
        }
    }

    if (!Player.Moving)
    {
        Player.Frame = 0;
    }

    FrameCount++;
    if (Player.Frame > 3)
    {
        Player.Frame = 0;
    }

    Player.Animation.x = Player.Animation.width * (f32)Player.Frame;
    Player.Animation.y = Player.Animation.height * (f32)Player.Direction;

    UpdateMusicStream(Audio.Music);
    if (Audio.Paused)
    {
        PauseMusicStream(Audio.Music);
    }
    else
    {
        ResumeMusicStream(Audio.Music);
    }

    Player.PlayerCamera.target = {
            (f32)(Player.Position.x - (Player.Position.width / 2.0f)),
            (f32)(Player.Position.y - (Player.Position.height / 2.0f))
    };
    Player.Moving = false;
    Player.UP = false;
    Player.DOWN = false;
    Player.LEFT = false;
    Player.RIGHT = false;
}
void Game::Render()
{
    BeginDrawing();
    ClearBackground(TiffanyBlue);
    BeginMode2D(Player.PlayerCamera);
    DrawScene();
    EndMode2D();
    EndDrawing();
}
void Game::DrawScene()
{
    DrawTextureV(GrassSprite, {100, 50}, WHITE);
    DrawTexturePro(PlayerSprite, Player.Animation, Player.Position, { Player.Position.width, Player.Position.height }, 0, WHITE);
}
void Game::Close()
{
    UnloadTexture(GrassSprite);
    UnloadTexture(PlayerSprite);
    UnloadMusicStream(Audio.Music);
    CloseAudioDevice();
    CloseWindow();
}