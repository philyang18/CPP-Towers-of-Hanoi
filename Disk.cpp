// ITP 365 Fall 2018
// HW3 Towers of Hannoi
// Name: Phillip Yang
// Email: yangphil@usc.edu
// Platform: Mac

#include "Disk.h"
#include <iostream>
#include "gwindow.h"
#include <cstdlib>
#include <ctime>


//Function: Disk constructor
//Purpose: initialize a Disk type class
//Parameters: nothing
//Output: nothing
Disk::Disk()
{
}

//Function: Disk constructor
//Purpose: initialize a Disk type class with parameters
//Parameters: four ints- for x and y coords and width and height
//Output: nothing
Disk::Disk(int x, int y, int w, int h)
{
    setDiskX(x);
    setDiskY(y);
    setDiskW(w);
    setDiskH(h);
    setColor();
}

//Function: setters
//Purpose: gets the member class variables
//Parameters: ints
//Output: nothing
void Disk::setDiskX(int x)
{
    mDiskX = x;
}
void Disk::setDiskY(int y)
{
    mDiskY = y;
}
void Disk::setDiskW(int w)
{
    mPixelWidth = w;
}
void Disk::setDiskH(int h)
{
    mPixelHeight = h;
}

//Function: setColor
//Purpose: calls the create vector function and sets a random color to the disk
//Parameters: nothing
//Output: nothing
void Disk::setColor()
{
    createColorVec();
    int random_integer = rand() % 18;
    //std::cout << random_integer << std::endl;
    mColor = getColorVec()[random_integer];
}

int Disk::getDiskX()
{
    return mDiskX;
}
int Disk::getDiskY()
{
    return mDiskY;
}
int Disk::getDiskW()
{
    return mPixelWidth;
}
int Disk::getDiskH()
{
    return mPixelHeight;
}

Vector<std::string> Disk::getColorVec()
{
    return mColorVec;
}

//Function: createColorVec
//Purpose: adds colors to the member vector variable
//Parameters: nothing
//Output: nothing
void Disk::createColorVec()
{
    mColorVec.add("blue");
    mColorVec.add("red");
    mColorVec.add("green");
    mColorVec.add("yellow");
    mColorVec.add("blue");
    mColorVec.add("red");
    mColorVec.add("blue");
    mColorVec.add("red");
    mColorVec.add("yellow");
    mColorVec.add("magenta");
    mColorVec.add("orange");
    mColorVec.add("pink");;
    mColorVec.add("yellow");
    mColorVec.add("magenta");
    mColorVec.add("pink");
    mColorVec.add("magenta");
    mColorVec.add("orange");
    mColorVec.add("pink");
}

//Function: getColor
//Purpose: returns the color of the disk
//Parameters: nothing
//Output: string
std::string Disk::getColor()
{
    return mColor;
}

//Function: draw
//Purpose: draws the disk
//Parameters: GWindow
//Output: nothing
void Disk::draw(GWindow& gw)
{
    gw.setColor(getColor());
    gw.fillRect(getDiskX(), getDiskY(), getDiskW(), getDiskH());
    gw.setColor("black");
    gw.drawRect(getDiskX(), getDiskY(), getDiskW(), getDiskH());
}

