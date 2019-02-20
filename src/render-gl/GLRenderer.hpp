#pragma once
#include "IRenderer.hpp"

namespace bxp
{
    class GLRenderer final : public IRenderer
    {
        void Begin() override;
        void End() override;

        void DrawTriangle(const glm::vec2& v1, const glm::vec2& v2, const glm::vec2& v3) override;
    };
} 