#ifndef Window_h
#define Window_h

#include "globals.h"

class Window
{
     private:
          int windowWidth;
          int windowHeight;
          const char * windowTitle;
          SDL_Window * window;
          SDL_Renderer * renderer;

     public: 
          Window(const char* title, int width, int height); // constructor

          void setWidth(int width);
          void setHeight(int width);

          int getWidth();
          int getHeight();

          SDL_Window * getWindow();

          SDL_Renderer * getRenderer();

};

#endif
