#include <iostream>

#include <raylib.h>
#include <raymath.h>

#include <GlobalSettings.hpp>
#include <MainCamera.hpp>

// Camera2D camera = { 0 };

int main(int, char **)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GOB MOBA");

    MainCamera main_cam;

    Vector2 circle_position = {0.0f, 0.0f};

    bool is_moving = false;

    float move_speed = 5.0f;

    Vector2 target_position;
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        main_cam.MoveGameCameraKeyboard();
        main_cam.updateGameCamera();
        Camera2D camera = main_cam.getGameCamera();

        if (IsMouseButtonPressed(0))
        {
            target_position = main_cam.getMouseWorldPosition();
            is_moving = true;
        }

        if (is_moving == true)
        {
            Vector2 move_dir = Vector2Subtract(target_position, circle_position);
            Vector2 normalized_move_dir = Vector2Normalize(move_dir);

            Vector2 new_circle_pos = Vector2Add(circle_position, Vector2Scale(normalized_move_dir, move_speed));
            circle_position = new_circle_pos;

            if (Vector2Distance(circle_position, target_position) < 2)
            {
                is_moving = false;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);

        DrawCircle(0, 0, 5, WHITE);
        DrawCircle(circle_position.x, circle_position.y, 30, RED);

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
