
#include <ECSManager.hpp>

#include <DebugUtils.hpp>

ECSManager::ECSManager(/* args */)
{

  sparse_transforms.resize(SPARSE_TANSFORMS_SIZE, 0xFFFFFFFF);
  sparse_circles.resize(SPARSE_CIRCLES_SIZE, 0xFFFFFFFF);
}

ECSManager::~ECSManager()
{
}

Entity ECSManager::createEntity()
{
  current_id++;
  return current_id;
}

void ECSManager::addTransformComponent(Entity& id, Component::Transform _transform)
{
  p(id);
  p(sparse_circles.size());
  transforms.emplace_back(Dense<Component::Transform>{id, _transform});
  sparse_transforms.at(id) = transforms.size() - 1;
}

void ECSManager::addCircleComponent(Entity id, Component::Circle _circle)
{
  p(id);
  p(sparse_circles.size());
  circles.emplace_back(Dense<Component::Circle>{id, _circle});
  sparse_circles.at(id) = circles.size() - 1;
}

const std::vector<Dense<Component::Transform>> &ECSManager::getTransforms() const
{
  return transforms;
}

const std::vector<unsigned int> &ECSManager::getSparseTransforms() const
{
  return sparse_transforms;
}

const std::vector<Dense<Component::Circle>> &ECSManager::getCircles() const
{
  return circles;
}

const std::vector<unsigned int> &ECSManager::getSparseCircles() const
{
  return sparse_circles;
}
