#pragma once

#include "../ecs/entity.hpp"
#include "camera.hpp"
#include "mesh-renderer.hpp"
#include "free-camera-controller.hpp"
#include "movement.hpp"
#include "duck.hpp"
#include "scope.hpp"
#include "light.hpp"
#include "skyLight.hpp"
#include "player.hpp"
#include "collision.hpp"
#include "fog.hpp"
namespace our {

    // Given a json object, this function picks and creates a component in the given entity
    // based on the "type" specified in the json object which is later deserialized from the rest of the json object
    inline void deserializeComponent(const nlohmann::json& data, Entity* entity){
        std::string type = data.value("type", "");
        Component* component = nullptr;
        if(type == CameraComponent::getID()){
            component = entity->addComponent<CameraComponent>();
        } else if (type == MeshRendererComponent::getID()) {
            component = entity->addComponent<MeshRendererComponent>();
        } else if (type == FreeCameraControllerComponent::getID()) {
            component = entity->addComponent<FreeCameraControllerComponent>();
        } else if (type == MovementComponent::getID()) {
            component = entity->addComponent<MovementComponent>();
        }else if (type == Duck::getID()) {
            component = entity->addComponent<Duck>();
        }else if (type == Scope::getID()) {
            component = entity->addComponent<Scope>();
        }else if (type == Light::getID()) {
            component = entity->addComponent<Light>();
        }else if (type == skyLight::getID()) {
            component = entity->addComponent<skyLight>();
        }else if (type == Player::getID()) {
            component = entity->addComponent<Player>();
        }else if (type == Collision::getID()) {
            component = entity->addComponent<Collision>();
        }else if (type == Fog::getID()) {
            component = entity->addComponent<Fog>();
        }

        if(component) component->deserialize(data);
    }

}