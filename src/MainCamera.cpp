
#include <iostream>

#include <DebugUtils.hpp>
#include <MainCamera.hpp>

MainCamera::MainCamera(/* args */)
{
  camera.offset = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
  camera.target = {camera_pivot_position.x, camera_pivot_position.y};
  camera.rotation = 0.0f;
  camera.zoom = 0.7f;
}

MainCamera::~MainCamera()
{
}

void MainCamera::updateGameCamera()
{
  camera.target = {camera_pivot_position.x, camera_pivot_position.y};
}

void MainCamera::moveGameCameraDirection(MovementDirection direction)
{

  switch (direction)
  {
  case MovementDirection::Up:
    camera_pivot_position.y -= move_screen_sensitivity;
    break;
  case MovementDirection::Down:
    camera_pivot_position.y += move_screen_sensitivity;
    break;
  case MovementDirection::Left:
    camera_pivot_position.x -= move_screen_sensitivity;
    break;
  case MovementDirection::Right:
    camera_pivot_position.x += move_screen_sensitivity;
    break;
  default:
    break;
  }
}

void MainCamera::MoveGameCameraKeyboard()
{

  if (IsKeyDown(KEY_A))
    camera_pivot_position.x -= move_screen_sensitivity;
  if (IsKeyDown(KEY_D))
    camera_pivot_position.x += move_screen_sensitivity;
  if (IsKeyDown(KEY_W))
    camera_pivot_position.y -= move_screen_sensitivity;
  if (IsKeyDown(KEY_S))
    camera_pivot_position.y += move_screen_sensitivity;
}

Camera2D MainCamera::getGameCamera()
{
  return camera;
}

Vector2 MainCamera::getMouseWorldPosition()
{
  Vector2 mouse_position = GetMousePosition();
  Vector2 mouse_world_position = GetScreenToWorld2D(mouse_position, camera);

  return mouse_world_position;
}