#include "sq/core/display.hpp"
#include <spdlog/fmt/fmt.h>
#include <GL/glew.h>
namespace sq
{

Display::Display(int width, int height, const std::string &name)
{
    fmt::print("Hello world");
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_gl_context = SDL_GL_CreateContext(m_window);

    auto status = glewInit();

    if (status != GLEW_OK)
    {
        fmt::print("Glew failed to initialize\n");
    }
}

Display::~Display()
{
    SDL_GL_DeleteContext(m_gl_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
void Display::update()
{
    SDL_GL_SwapWindow(m_window);

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            closed = true;
        }
    }
}
bool Display::is_running()
{
    return !closed;
}
} // namespace sq