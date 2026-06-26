#pragma once

#include <raylib.h>
#include <GlobalSettings.hpp>

#include <MoveDirections.hpp>


class MainCamera
{
  
  private:
  Camera2D camera = {0};
  
  Vector2 camera_pivot_position = {0.0f, 0.0f};
  const float move_screen_sensitivity = 5;

public:
  MainCamera(/* args */);
  ~MainCamera();

  void updateGameCamera();
  void moveGameCameraDirection(MovementDirection direction);
  void MoveGameCameraKeyboard();

  Vector2 getMouseWorldPosition();

  // TODO: void moveGameCameraAbsolute(Vector2 position);

  Camera2D getGameCamera();
};


