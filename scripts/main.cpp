#include "../headers/globals.h"
#include "../headers/window.h"
#include "../headers/menu.h"

#include <SDL2/SDL_render.h>
// global variables

// screen resolution
int screenWidth = 480;
int screenHeight = 272;


// main function
int main(int argc, char  *argv[])
{

     SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

     Window * mainWindow = new Window("main", screenWidth, screenHeight);

     bool running = true; // refactor name of this variable

     SDL_Event event;

     Menu * mainMenu = new Menu("menu", 100, 100, 200, 100, 2, mainWindow->getRenderer());

     mainMenu->addMenuButton("test");
     mainMenu->addMenuButton("test2");
     mainMenu->addMenuButton("test3");

     while (running)
     {
          if (SDL_PollEvent(&event))
          {

               switch (event.type)
               {

                    case SDL_QUIT:
                         running = false;
                         break;

                    case SDL_CONTROLLERDEVICEADDED:
                         SDL_GameControllerOpen(event.cdevice.which);
                         break;

                    case SDL_CONTROLLERBUTTONDOWN: 
                         
                    if (event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
                    {
                    }

                    else if (event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
                    {
                    }

                    else if (event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
                    {
                    }

                    else if (event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
                    {
                    }

                    break;
               }

          }


          SDL_RenderClear(mainWindow->getRenderer());
          mainMenu->renderMenu();
          SDL_SetRenderDrawColor(mainWindow->getRenderer(), 0, 0, 0, 0);
          SDL_RenderPresent(mainWindow->getRenderer());
     }


     SDL_DestroyRenderer(mainWindow->getRenderer());
     SDL_DestroyWindow(mainWindow->getWindow());
     SDL_Quit();

     return 0;

}
