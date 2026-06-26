#pragma once

#include <raylib.h>

struct Transform
{

  Vector2 position;
  Vector2 scale;
  float rotation;
  
};


struct Health
{
  int health_amount;
  int health_regen;
};

