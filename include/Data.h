#pragma once
#include "Shader.h"
#include "Texture.h"
#include "glm/fwd.hpp"

struct Transform2D{
    inline Transform2D(const Transform2D &) = default;
    inline Transform2D() = default;
    glm::vec2 Translate = glm::vec2(0);
    glm::vec2 Scale = glm::vec2(1);
    float Rotation = 0;
};

struct Transform3D{
    inline Transform3D(const Transform3D &) = default;
    inline Transform3D() = default;
    glm::vec3 Translate = glm::vec3(1);
    glm::vec3 Scale = glm::vec3(1);
    float Rotation = 0;
    glm::quat test = glm::quat();
};

struct Camera3D{
    inline Camera3D(const Camera3D&) = default;
    inline Camera3D() = default;
    glm::vec3 Position;
    glm::vec3 Up = glm::vec3(0,0,1);
};
