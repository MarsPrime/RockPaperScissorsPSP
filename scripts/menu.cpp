#include "../headers/menu.h"
#include <vector>


Menu::Menu(const char * title, int x, int y, int width, int height, int type)
{
     menuTitle = title;
     menuPositionX = x;
     menuPositionY = y;
     menuWidth = width;
     menuHeight = height;
     menuType = type;

     menuRectangle = {menuPositionX, menuPositionY, menuWidth, menuHeight};

     selectMenuColorFromType();

}

SDL_Rect * Menu::getMenuRect()
{
     return &this->menuRectangle;

}

void Menu::selectMenuColorFromType()
{
     switch (this->menuType)
     {
          case 1:
          {
               this->menuBackground[0] = 255;
               this->menuBackground[1] = 0;
               this->menuBackground[2] = 0;
               this->menuBackground[3] = 255;
               break;
          }
          case 2:
          {
               this->menuBackground[0] = 0;
               this->menuBackground[1] = 0;
               this->menuBackground[2] = 255;
               this->menuBackground[3] = 255;
               break;
          }
     }

}

int * Menu::getMenuBackground()
{
     return this->menuBackground;
}

void Menu::addMenuButton(Button * newButton)
{
     this->menuButtons.push_back(newButton);
}

vector<Button *>  Menu::getMenuButtons()
{
     return this->menuButtons;
}
