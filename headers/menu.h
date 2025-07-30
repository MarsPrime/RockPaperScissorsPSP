#ifndef Menu_h
#define Menu_h

#include "globals.h"

class Menu
{
     private:
          const char * menuTitle = "";
          int menuType = 0;

          int menuPositionX = 0;
          int menuPositionY = 0;

          int menuWidth = 0;
          int menuHeight= 0;

          SDL_Rect menuRectangle;

          int menuBackground [4];

          void selectMenuColorFromType();
     
     public:
          Menu(const char * title, int x, int y, int width, int height, int type); // constructor
          SDL_Rect * getMenuRect();

          int* getMenuBackground();
};



#endif 
