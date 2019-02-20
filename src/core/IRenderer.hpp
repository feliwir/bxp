#pragma once
#include <glm/glm.hpp>

namespace bxp
{
    class IRenderer
    {
        public:
        virtual ~IRenderer();

        virtual void Begin() = 0;
        virtual void End() = 0;

        virtual void DrawTriangle(const glm::vec2& v1, const glm::vec2& v2, const glm::vec2& v3) = 0;
    };
}