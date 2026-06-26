#pragma once

#include <vector>

#include <Components.hpp>

using Entity = unsigned int;

class ECSManager
{
private:
  Entity current_id = 0;

  size_t SPARSE_TANSFORMS_SIZE = 100'000;
  size_t SPARSE_CIRCLES_SIZE = 10'000;

  std::vector<Dense<Component::Transform>> transforms;
  std::vector<unsigned int> sparse_transforms;
  std::vector<Dense<Component::Circle>> circles;
  std::vector<unsigned int> sparse_circles;

public:
  ECSManager(/* args */);
  ~ECSManager();

  Entity createEntity();

  void addTransformComponent(Entity& id, Component::Transform);
  void addCircleComponent(Entity id, Component::Circle);

  const std::vector<Dense<Component::Transform>> &getTransforms() const;
  const std::vector<unsigned int> &getSparseTransforms() const;
  const std::vector<Dense<Component::Circle>> &getCircles() const;
  const std::vector<unsigned int> &getSparseCircles() const;
};
