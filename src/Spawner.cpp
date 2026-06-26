#include <Spawner.hpp>

Spawner::Spawner(ECSManager& _ecs) : ecs(_ecs)
{
}

Spawner::~Spawner()
{
}

void Spawner::spawnCircle(Component::Transform _transform, Component::Circle _circle)
{

  unsigned int new_circle = ecs.createEntity();

  ecs.addTransformComponent(new_circle, _transform);
  ecs.addCircleComponent(new_circle, _circle);
}