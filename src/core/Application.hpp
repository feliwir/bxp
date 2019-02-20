#pragma once
#include "IRenderer.hpp"

namespace bxp
{
class Application final
{
  public:
    Application(IRenderer* renderer);
    ~Application();

    virtual void OnInitialize();
    virtual void OnUpdate();

    inline IRenderer& GetRenderer() 
    {
      return *m_renderer;
    }

    protected:
    IRenderer* m_renderer;
};
} // namespace bxp