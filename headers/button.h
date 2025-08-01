#ifndef Button_h
#define Button_h

#include "globals.h"

class Button
{
     private:
          const char * buttonTitle = "";
          int buttonWidth = 0;
          int buttonHeight = 0;

          int buttonPositionX = 0;
          int buttonPositionY = 0;

          int buttonColor [4] = {0, 150, 255, 255};

          SDL_Rect buttonShape = {};

     public:
          Button(const char * title, int x, int y, int width, int height);
          int * getButtonColor();
          const char * getButtonTitle();
          SDL_Rect * getButtonRect();
};

#endif

