#ifndef Menu_h
#define Menu_h

#include "globals.h"
#include "button.h"


class Menu
{
     private:
          // variables
          const char * menuTitle = "";

          int menuType = 0;

          // menu postion on screen
          int  menuPosition [2] = {0, 0};

          // menu size
          int menuSize [2] = {0, 0};

          SDL_Rect menuRectangle = {};

          int menuBackground [4];

          vector<Button * > menuButtons;

          SDL_Renderer * menuRenderer;

          // methods
          void selectMenuColorFromType();
     
     public:
          // methods

          Menu(const char * title, 
                    int x, 
                    int y, 
                    int width, 
                    int height, 
                    int type, 
                    SDL_Renderer * renderer); // constructor

          int * getMenuSize();
          int * getMenuPosition();

          SDL_Rect * getMenuRect();
          int * getMenuBackground();
          SDL_Renderer * getMenuRenderer();

          // functions for menu buttons
          void addMenuButton(const char * title);
          vector<Button * > getMenuButtons();
          int getMenuButtonsQuantity();

          // render menu
          void renderMenu();
};


#endif 
