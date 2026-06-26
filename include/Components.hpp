#pragma once

#include <raylib.h>

template <typename T>
struct Dense
{
  unsigned int entity_ID;
  T component;
};

namespace Component
{

  struct Transform
  {
    Vector2 position = {0, 0};
    Vector2 scale = {0, 0};
    float rotation = 0;
  };

  struct Circle
  {
    float radius = 10;
    Color color = RAYWHITE;
  };

  struct Health
  {
    int health_amount = 100;
    int health_regen = 0;
  };

}
