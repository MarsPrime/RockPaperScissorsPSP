#include "../headers/window.h"
#include <SDL2/SDL_render.h>

Window::Window(const char* title, int width, int height)
{
     windowWidth = width;
     windowHeight= height;
     windowTitle = title;
     window = SDL_CreateWindow(title, 
               SDL_WINDOWPOS_UNDEFINED,
               SDL_WINDOWPOS_UNDEFINED,
               windowWidth,
               windowHeight,
               0
               );
     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void Window::setWidth(int width)
{
    this->windowWidth = width;
}

void Window::setHeight(int height)
{
    this->windowHeight = height;
}
int Window::getWidth()
{
     return this->windowWidth;
}

int Window::getHeight()
{
     return this->windowHeight;
}


SDL_Window * Window::getWindow()
{
     return this->window;
}

SDL_Renderer * Window::getRenderer()
{
     return this->renderer;
}
