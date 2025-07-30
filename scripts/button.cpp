#include "../headers/button.h"

Button::Button(const char * title, int x, int y, int width, int height)
{
     this->buttonTitle = title;
     this->buttonWidth = width;
     this->buttonHeight = height;

     this->buttonPositionX = x;
     this->buttonPositionY = y;

     this->buttonShape = {buttonPositionX,
                          buttonPositionY,
                          buttonWidth,
                          buttonHeight};
}

int * Button::getButtonColor()
{
     return this->buttonColor;
}

const char * Button::getButtonTitle()
{
     return this->buttonTitle;
}

