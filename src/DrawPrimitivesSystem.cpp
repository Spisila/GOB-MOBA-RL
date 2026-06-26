#include <DrawPrimitivesSystem.hpp>
#include <raylib.h>

#include <DebugUtils.hpp>

DrawPrimitivesSystem::DrawPrimitivesSystem(ECSManager &_ecs) : ecs(_ecs)
{
}

DrawPrimitivesSystem::~DrawPrimitivesSystem()
{
}

// TODO: Change to draw primitive system
void DrawPrimitivesSystem::drawCircles()
{

  auto& dense_circles = ecs.getCircles();
  auto& dense_transforms = ecs.getTransforms();
  auto& sparce_transforms = ecs.getSparseTransforms();

  for (int i = 0; i < dense_circles.size(); i++)
  {

    unsigned int entity_id = dense_circles.at(i).entity_ID;
    Component::Circle circle = dense_circles.at(i).component;

    unsigned int transform_id = sparce_transforms.at(entity_id);
    Component::Transform transform = dense_transforms.at(transform_id).component;
    DrawCircle(transform.position.x, transform.position.y, circle.radius, circle.color);
  }

  // for (int i = 0; i < dense_circles.size(); i++)
  // {

  //   unsigned int circle_ent_id = dense_circles.at(i).entity_ID;
  //   Component::Circle circle = dense_circles.at(i).component;
  //   Component::Transform transform;

  //   for (int j = 0; j < dense_transforms.size(); j++)
  //   {

  //     unsigned int trans_ent_id = dense_transforms.at(j).entity_ID;

  //     if (trans_ent_id == circle_ent_id)
  //     {
  //       transform = dense_transforms.at(j).component;
  //       break;
  //     }
  //   }
}