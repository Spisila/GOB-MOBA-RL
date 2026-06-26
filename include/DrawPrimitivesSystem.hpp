#pragma once

#include <ECSManager.hpp>

class DrawPrimitivesSystem
{
private:
  ECSManager &ecs;

public:
  DrawPrimitivesSystem(ECSManager &ecs);
  ~DrawPrimitivesSystem();

  void drawCircles();
};
