#pragma once

#include "sq/core/core.hpp"
#include <string>
#include <memory>
#include <SDL.h>

namespace sq
{

class SQUEAKY_PUBLIC Display
{
  private:
    SDL_Window* m_window;
    SDL_GLContext m_gl_context;
    bool closed = false;
  public:
    Display(int width, int height, const std::string &name);
    void update();
    ~Display();
    bool is_running();
};

} // namespace sq
