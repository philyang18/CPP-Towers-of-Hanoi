// ITP 365 Fall 2018
// HW3 Towers of Hannoi
// Name: Phillip Yang
// Email: yangphil@usc.edu
// Platform: Mac

#pragma once
#include <iostream>
#include "gwindow.h"


class Disk
{
private:
    int mDiskX = 0;
    int mDiskY = 0;
    int mPixelWidth = 0;
    int mPixelHeight = 0;
    std::string mColor;
    Vector<std::string> mColorVec;
  
public:
    //Function: Disk constructor
    //Purpose: initialize a Disk type class
    //Parameters: nothing
    //Output: nothing
    Disk();
    
    //Function: Disk constructor
    //Purpose: initialize a Disk type class with parameters
    //Parameters: four ints- for x and y coords and width and height
    //Output: nothing
    Disk(int x, int y, int w, int h);
    
    //Function: setters
    //Purpose: gets the member class variables
    //Parameters: ints
    //Output: nothing
    void setDiskX(int x);
    void setDiskY(int y);
    void setDiskW(int w);
    void setDiskH(int h);
    
    //Function: setColor
    //Purpose: calls the create vector function and sets a random color to the disk
    //Parameters: nothing
    //Output: nothing
    void setColor();
    
    //Function: getters
    //Purpose: returns the value of the respective member variable
    //Parameters: nothing
    //Output: int
    int getDiskX();
    int getDiskY();
    int getDiskW();
    int getDiskH();
    
    //Function: getColorVec
    //Purpose: returns the class member vector
    //Parameters: nothing
    //Output: string vector
    Vector<std::string> getColorVec();
    
    //Function: createColorVec
    //Purpose: adds colors to the member vector variable
    //Parameters: nothing
    //Output: nothing
    void createColorVec();
    
    //Function: getColor
    //Purpose: returns the color of the disk
    //Parameters: nothing
    //Output: string
    std::string getColor();
    
    //Function: draw
    //Purpose: draws the disk
    //Parameters: GWindow
    //Output: nothing
    void draw(GWindow& gw);
};

