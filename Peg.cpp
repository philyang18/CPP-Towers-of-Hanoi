// ITP 365 Fall 2018
// HW3 Towers of Hannoi
// Name: Phillip Yang
// Email: yangphil@usc.edu
// Platform: Mac

#include "Peg.h"
#include "Disk.h"
#include <cstdlib>
#include <ctime>

//Function: Default Peg constructor
//Purpose: initialize a peg type class
//Parameters: nothing
//Output: nothing
Peg::Peg()
{
}

//Function: Peg constructor
//Purpose: initializes a peg type class with values for member variables
//Parameters: four ints representing x and y coord. and width and height of the peg
//Output: nothing
Peg::Peg(int x, int y, int w, int h)
{
    setPegX(x);
    setPegY(y);
    setPegW(w);
    setPegH(h);
}

//Functions: setters
//Purpose: set the input value as the value for the respective member variable
//Parameters: int representing the new desired value of the variable
//Output: nothing
void Peg::setPegX(int& x)
{
    mPegX = x;
}
void Peg::setPegY(int y)
{
    mPegY = y;
}
void Peg::setPegW(int w)
{
    mPegWidth = w;
}
void Peg::setPegH(int h)
{
    mPegHeight = h;
}

//Function: getters
//Purpose: return the current value of the respective member variable
//Parameters: nothing
//Output: current int value
int Peg::getPegX()
{
    return mPegX;
}
int Peg::getPegY()
{
    return mPegY;
}
int Peg::getPegW()
{
    return mPegWidth;
}
int Peg::getPegH()
{
    return mPegHeight;
}

//Function: getDiskVec
//Purpose: return the current vector of disks
//Parameters: nothing
//Output: current vector
Vector<Disk> Peg::getDiskVec()
{
    return mDiskVec;
}

//Function: draw
//Purpose: draw the peg and the disks associated with its Disk vector
//Parameters: GWindow
//Output: nothing
void Peg::draw(GWindow& gw)
{
    //draws the pegs
    gw.setColor("black");
    gw.fillRect(getPegX(), getPegY(), getPegW(), getPegH());

    for(int i = 0; i < getDiskVec().size(); i++)
    {
        getDiskVec()[i].draw(gw);
    }
}

//Function: addDisk
//Purpose: uses the .add() function to add a Disk to mDiskVec
//Parameters: Disk type
//Output: nothing
void Peg::addDisk(Disk& topDisk)
{
    //set x and y for incoming disk
    if(getDiskVec().size() == 0)
    {
        int newX = getPegX() + 5 - topDisk.getDiskW()/2;
        topDisk.setDiskX(newX);
        int newY = 500 - topDisk.getDiskH();
        topDisk.setDiskY(newY);
    }
    else
    {
        int disksInDest = getDiskVec().size();
        int newX = getPegX() + 5 - topDisk.getDiskW()/2;
        topDisk.setDiskX(newX);
        int newY = getDiskVec()[disksInDest - 1].getDiskY() - topDisk.getDiskH();
        topDisk.setDiskY(newY);
    }
    mDiskVec.add(topDisk);
    
}

//Function: removeDisk
//Purpose: uses .remove() funct to remove a Disk from mDiskVec
//Parameters: nothing
//Output: the disk that was removed
Disk Peg::removeDisk()
{
    Disk movingDisk = mDiskVec[mDiskVec.size() - 1];
    mDiskVec.remove(mDiskVec.size() - 1);
    return movingDisk;
}
