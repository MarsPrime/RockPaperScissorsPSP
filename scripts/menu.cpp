#include "../headers/menu.h"
#include <SDL2/SDL_render.h>
#include <vector>


Menu::Menu(const char * title, int x, int y, int width, int height, int type)
{
     menuTitle = title;
     menuPosition[0] = x;
     menuPosition[1] = y;
     menuSize[0] = width;
     menuSize[1] = height;
     menuType = type;

     menuRectangle = {menuPosition[0], menuPosition[1], menuSize[0], menuSize[1]};

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

int * Menu::getMenuPosition()
{
     return this->menuPosition;
}

int * Menu::getMenuSize()
{
     return this->menuSize;
}
void Menu::addMenuButton(const char * title)
{

     int buttonPositionX = 10 + this->getMenuPosition()[0];
     int buttonPositionY = this->getMenuButtonsQuantity() * 30 + this->getMenuPosition()[1] + 10;
     int buttonWidth = this->getMenuSize()[0] / 5;
     int buttonHeight = this->getMenuSize()[1] / 5;

     Button * newButton = new Button(title,
               buttonPositionX,
               buttonPositionY,
               buttonWidth,
               buttonHeight
               );

     this->menuButtons.push_back(newButton);
}

vector<Button *>  Menu::getMenuButtons()
{
     return this->menuButtons;
}

int Menu::getMenuButtonsQuantity()
{
     return this->menuButtons.size();
}

void Menu::setMenuRenderer(SDL_Renderer * renderer)
{
     this->menuRenderer = renderer;
}

SDL_Renderer * Menu::getMenuRenderer()
{
     return this->menuRenderer;
}

void Menu::renderMenu()
{
     // render menu itself
     SDL_SetRenderDrawColor(this->getMenuRenderer(), 
               this->getMenuBackground()[0],
               this->getMenuBackground()[1],
               this->getMenuBackground()[2],
               this->getMenuBackground()[3]);

     SDL_RenderFillRect(this->getMenuRenderer(), this->getMenuRect());

     // render all buttons that in menu
     for (int i = 0; i < this->getMenuButtonsQuantity(); i ++)
     {
          Button * tempButton = this->getMenuButtons()[i];
          SDL_SetRenderDrawColor(this->getMenuRenderer(),
                    tempButton->getButtonColor()[0],
                    tempButton->getButtonColor()[1],
                    tempButton->getButtonColor()[2],
                    tempButton->getButtonColor()[3]
                    );

          SDL_RenderFillRect(this->getMenuRenderer(), tempButton->getButtonRect());
     }

}
