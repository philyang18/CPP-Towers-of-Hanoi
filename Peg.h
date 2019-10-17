// ITP 365 Fall 2018
// HW3 Towers of Hannoi
// Name: Phillip Yang
// Email: yangphil@usc.edu
// Platform: Mac

#pragma once
#include "gwindow.h"
#include "Disk.h"


class Peg
{
private:
    int mPegX = 0;
    int mPegY = 0;
    int mPegWidth = 0;
    int mPegHeight = 0;
    Vector<Disk> mDiskVec;
    
public:
    
    //Function: Default Peg constructor
    //Purpose: initialize a peg type class
    //Parameters: nothing
    //Output: nothing
    Peg();
    
    //Function: Peg constructor
    //Purpose: initializes a peg type class with values for member variables
    //Parameters: four ints representing x and y coord. and width and height of the peg
    //Output: nothing
    Peg(int x, int y, int w, int h);
    
    //Functions: setters
    //Purpose: set the input value as the value for the respective member variable
    //Parameters: int representing the new desired value of the variable
    //Output: nothing
    void setPegX(int& x);
    void setPegY(int y);
    void setPegW(int w);
    void setPegH(int h);
    
    //Function: getters
    //Purpose: return the current value of the respective member variable
    //Parameters: nothing
    //Output: current int value
    int getPegX();
    int getPegY();
    int getPegW();
    int getPegH();
    
    //Function: getDiskVec
    //Purpose: return the current vector of disks
    //Parameters: nothing
    //Output: current vector
    Vector<Disk> getDiskVec();
    
    //Function: draw
    //Purpose: draw the peg and the disks associated with its Disk vector
    //Parameters: GWindow
    //Output: nothing
    void draw(GWindow& gw);
    
    //Function: addDisk
    //Purpose: uses the .add() function to add a Disk to mDiskVec
    //Parameters: Disk type
    //Output: nothing
    void addDisk(Disk& topDisk);
    
    //Function: removeDisk
    //Purpose: uses .remove() funct to remove a Disk from mDiskVec
    //Parameters: nothing
    //Output: the disk that was removed
    Disk removeDisk();
};
