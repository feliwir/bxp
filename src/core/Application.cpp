#include "Application.hpp"

bxp::Application::Application(IRenderer* renderer)
    : m_renderer(renderer)
{
}

bxp::Application::~Application()
{
    delete m_renderer;
}

void bxp::Application::OnInitialize()
{
}

void bxp::Application::OnUpdate()
{
}