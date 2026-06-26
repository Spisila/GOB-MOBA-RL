#include <iostream>

#include <raylib.h>
#include <raymath.h>

const float move_screen_sensitivity = 5;

Vector2 map_size = {800.0f,800.0f};

Camera2D camera = { 0 };


int main(int, char**){

    const int screenWidth = 1500;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "MOBINIS");

    Vector2 camera_pivot_position = {0.0f,0.0f};

    camera.offset = {screenWidth / 2, screenHeight / 2};
    camera.target = {camera_pivot_position.x, camera_pivot_position.y};
    camera.rotation = 0.0f;
    camera.zoom = 0.7f;

    Vector2 circle_position = {0,0};

    bool is_moving = false;
    
    float move_speed = 5.0f;

    Vector2 target_position;
    SetTargetFPS(60); 
    while (!WindowShouldClose()) 
    { 
        camera.target = {camera_pivot_position.x, camera_pivot_position.y};

        Vector2 mouse_position = GetMousePosition();
        Vector2 mouse_world_position = GetScreenToWorld2D(mouse_position, camera);

        if (IsMouseButtonPressed(0)) 
        {
            target_position = mouse_world_position;
            is_moving = true;
        }

        if (is_moving == true) 
        {
            Vector2 move_dir = Vector2Subtract(target_position, circle_position);
            Vector2 normalized_move_dir = Vector2Normalize(move_dir);
            std::cout << normalized_move_dir.x << " " << normalized_move_dir.y << std::endl;

            Vector2 new_circle_pos = Vector2Add(circle_position, Vector2Scale(normalized_move_dir, move_speed));
            circle_position = new_circle_pos;

            if (Vector2Distance(circle_position, target_position) < 2) 
            {
                is_moving = false;
            }
        }

        if (IsKeyDown(KEY_A)) camera_pivot_position.x -= move_screen_sensitivity;
        if (IsKeyDown(KEY_D)) camera_pivot_position.x += move_screen_sensitivity;
        if (IsKeyDown(KEY_W)) camera_pivot_position.y -= move_screen_sensitivity;
        if (IsKeyDown(KEY_S)) camera_pivot_position.y += move_screen_sensitivity;

        BeginDrawing();

            ClearBackground(BLACK);

            BeginMode2D(camera);

            DrawRectangle(-map_size.x / 2, -map_size.y / 2, map_size.x, map_size.y, Color{75,25,75,255});

            DrawCircle(0,0,5,WHITE);
            DrawCircle(circle_position.x, circle_position.y, 30, RED);
            
            EndMode2D();
            
        EndDrawing();
        
    }

    CloseWindow(); 

    return 0;
}
    

