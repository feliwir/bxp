#include "GLRenderer.hpp"
#include <GL/gl.h>

void bxp::GLRenderer::DrawTriangle(const glm::vec2& v1, const glm::vec2& v2, const glm::vec2& v3)
{

}

void bxp::GLRenderer::Begin() 
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void bxp::GLRenderer::End() 
{

}