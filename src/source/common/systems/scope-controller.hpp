#pragma once

#include "../ecs/world.hpp"
#include "../components/scope.hpp"
#include "../components/camera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <vector>
namespace our
{

    // The movement system is responsible for moving every entity which contains a MovementComponent.
    // This system is added as a simple example for how use the ECS framework to implement logic.
    // For more information, see "common/components/movement.hpp"
    class ScopeController
    {
    public:
        // This should be called every frame to update all entities containing a MovementComponent.
        void update(World *world, float deltaTime)
        {
            std::vector<Entity *> ducks;
            Entity *camera, *scope;

            // For each entity in the world
            for (auto entity : world->getEntities())
            {
                // Get the movement component if it exists
                CameraComponent *c = entity->getComponent<CameraComponent>();
                // If the movement component exists
                if (c)
                {
                    camera = entity;
                    //  std::cout << "Camera found" << std::endl;
                }
                Scope *s = entity->getComponent<Scope>();
                if (s)
                {
                    scope = entity;
                    //  std::cout << "scope found" << std::endl;
                }
            }
            Entity *entity = camera;
            glm::mat4 matrix = entity->localTransform.toMat4();

            glm::vec3 front = glm::vec3(matrix * glm::vec4(0, 0, -1, 0)),
                      up = glm::vec3(matrix * glm::vec4(0, 1, 0, 0)),
                      right = glm::vec3(matrix * glm::vec4(1, 0, 0, 0));

            auto cameraPos = camera->localTransform.position;
            // scope->localTransform.position = front;
            /*for(auto duck :ducks){
                auto duckPos=duck->localTransform.position;
                auto dir=glm::normalize(cameraPos-duckPos);

                duck->localTransform.position+=deltaTime*dir;
                duck->localTransform.rotation= glm::vec3(glm::rotate(glm::mat4(1.0f),glm::atan(dir.z,dir.x),glm::vec3(0,-1,0))*glm::vec4(0,0,-1,0));
            }*/
        }
    };

}
