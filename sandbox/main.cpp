
#include <sq/core/display.hpp>
#include <GL/glew.h>
int main()
{


    sq::Display d(800,600,"hello");

    while (d.is_running())
    {
        glClearColor(0.f,0.145f,0.34f,1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        d.update();
    }
}