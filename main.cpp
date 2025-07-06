#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

// global variables

// screen resolution
int screenWidth = 480;
int screenHeight = 272;

// functions

SDL_Window * createWindow(const char * title, int windowWidth, int windowHeight);

SDL_Renderer * createRenderer(SDL_Window * targetWindow);


// main function
int main(int argc, char  *argv[])
{

     SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

     SDL_Window  * mainWindow = createWindow("main", screenWidth, screenHeight);

     SDL_Renderer * mainRenderer = createRenderer(mainWindow);

     bool running = true; // refactor name of this variable

     int red = 0, green = 0, blue = 0, alpha = 0;

     int inputCode;

     SDL_Event event;

     while (running)
     {

          SDL_RenderClear(mainRenderer);

          SDL_SetRenderDrawColor(mainRenderer, red, green, blue, alpha);
          SDL_RenderPresent(mainRenderer);

     }


     SDL_DestroyRenderer(mainRenderer);
     SDL_DestroyWindow(mainWindow);
     SDL_Quit();

     return 0;

}

SDL_Window * createWindow(const char * title, int windowWidth, int windowHeight)
{
     SDL_Window * window = SDL_CreateWindow(
               title, 
               SDL_WINDOWPOS_UNDEFINED,
               SDL_WINDOWPOS_UNDEFINED,
               windowWidth,
               windowHeight,
               0
               );

     return window;

}

SDL_Renderer * createRenderer(SDL_Window * targetWindow)
{
     SDL_Renderer * renderer = SDL_CreateRenderer(
               targetWindow,
               -1,
               SDL_RENDERER_ACCELERATED
               );

     return renderer;

}

