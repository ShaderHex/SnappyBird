// Standard Library
#include <iostream>

// External Library
#include "raylib.h"

int main() {
    int ScreenWidth = 800, ScreenHeight = 800;
    InitWindow(ScreenWidth, ScreenHeight, "SnappyBird");

    Rectangle player = {50, 50, 100, 100};
    float velocityY = 0.0f;
    float gravity = 800.0f;
    float jumpStrength = -350.0f;

    Camera2D camera = {0};
    camera.target = { player.x, player.y };
    camera.offset = { ScreenWidth / 2.0f, ScreenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    float groundY = 300;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        velocityY += gravity * deltaTime;
        player.y += velocityY * deltaTime;
        if(IsKeyDown(KEY_SPACE)) {
            velocityY = jumpStrength * deltaTime;
        }

        if (player.y >= groundY) {
            player.y = groundY;
            velocityY = 0;
            break;
        }

        camera.target = { player.x, 50 };

        BeginDrawing();
        ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawRectangleRec(player, RED);
                DrawRectangle(0, 400, 150, 50, BLUE);
            EndMode2D();
        EndDrawing();
    }
    EndDrawing();
}