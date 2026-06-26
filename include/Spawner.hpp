#pragma once

#include <ECSManager.hpp>

class Spawner
{
private:

  ECSManager& ecs;

public:
  Spawner(ECSManager& _ecs);
  ~Spawner();

  void spawnCircle(Component::Transform _transform, Component::Circle _circle);
};


