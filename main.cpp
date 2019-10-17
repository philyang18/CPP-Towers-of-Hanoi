// ITP 365 Fall 2018
// HW3 Towers of Hannoi
// Name: Phillip Yang
// Email: yangphil@usc.edu
// Platform: Mac

#include <iostream>
#include "strlib.h"
#include "gwindow.h"
#include "Disk.h"
#include "Peg.h"
#include <cmath>

//Function: promptForDisks
//Purpose: ask the user for the desired number of disks
//Parameters: nothing
//Output: int representing the number of disks
int promptForDisks()
{
    int userNum = 0;
    while(userNum < 2 || userNum > 10)
    {
        std::cout << "Towers of Hanoi\nHow many disks would you like? (2-10): ";
        std::cin >> userNum;
    }
    return userNum;
}

//Function: promptForPegs
//Purpose: ask the user for the number of pegs and store them into the parameters by reference
//Parameters: two integers by reference
//Output: nothing
void promptForPegs(int& input1, int& input2)
{
    //make sure user enters a correct peg number
    while(input1 < 1 || input1 > 3)
    {
        std::cout << "Choose your starting peg (1,2,3): ";
        std::cin >> input1;
    }
    if(input1 == 1)
    {
        while(input2 < 2 || input2 > 3)
        {
            std::cout << "Choose your ending peg (2,3): ";
            std::cin >> input2;
        }
    }
    else if(input1 == 2)
    {
        while(input2 != 1 && input2 != 3)
        {
            std::cout << "Choose your ending peg (1,3): ";
            std::cin >> input2;
        }
    }
    else if(input1 == 3)
    {
        while(input2 < 1 || input2 > 2)
        {
            std::cout << "Choose your ending peg (1,2): ";
            std::cin >> input2;
        }
    }
    //subtract one to match index
    input1 -= 1;
    input2 -= 1;
}

//Function: draw
//Purpose: draw the pegs and their corresponding disks on a java window
//Parameters: GWindow by ref and vector of pegs
//Output: nothing
void draw(GWindow& gw, Vector<Peg>& pegVec)
{
    gw.clear();
    gw.drawLabel("1", 140, 40);
    gw.drawLabel("2", 400, 40);
    gw.drawLabel("3", 660, 40);
    
    for(int i = 0; i < pegVec.size(); i++)
    {
        pegVec[i].draw(gw);
    }
    pause(250);
}

//Function: initializeStack
//Purpose: creates the disks on the starting peg in the java window
//Parameters: GWindow and vector of Pegs by ref, and two ints
//Output: nothing
void initializeStack(GWindow& gw, Vector<Peg>& pegVec, int numOfDisks, int startPeg)
{
    //variables aka my limits
    int maxDiskHeight = 500;
    int maxDiskWidth = 255;
    const int changeOfWidth = 15;
    const int stackHeight = 400;
    const int heightOfDisk = stackHeight/numOfDisks;
    
    for(int i = 0; i < numOfDisks; i++)
    {
        //make the width shrink by my constant change of width and height
        maxDiskWidth -= changeOfWidth;
        //stack the disks up
        maxDiskHeight -= heightOfDisk;
        int x = pegVec[startPeg].getPegX() + pegVec[startPeg].getPegW()/2 - maxDiskWidth/2;
        Disk topDisk(x, maxDiskHeight, maxDiskWidth, heightOfDisk);
        pegVec[startPeg].addDisk(topDisk);
    }
    draw(gw, pegVec);
}
//Function: moveDisk
//Purpose: moves a single disk from one peg to another
//Parameters: GWindow, vector of pegs, two ints for start and end peg
//Output: nothing
void moveDisk(GWindow& gw, Vector<Peg>& pegCollection, int startPeg, int destPeg)
{
    //initialize the first disk, then have the rest build on it
    Disk removedDisk = pegCollection[startPeg].removeDisk();
    pegCollection[destPeg].addDisk(removedDisk);
    draw(gw, pegCollection);
    pause(1500);
}

//Function: towerSolver
//Purpose: uses recursion to solve the towers
//Parameters: GWindow, vector of pegs, two ints for start and end peg, and one int for the number of disk
//Output: nothing
void towerSolver(GWindow& gw, Vector<Peg>& pegCollection, int startPeg, int destPeg, int numDisks)
{
    //find the temp peg
    int tempPeg = 3 - startPeg - destPeg;

    if (numDisks == 0)
    {
        return;
    }
    else
    {
        //Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start” (recursion)
        towerSolver(gw, pegCollection, startPeg, tempPeg, numDisks - 1);
        //Move Disk 0 from “start” to “end”
        moveDisk(gw, pegCollection, startPeg, destPeg);
        //ransfer N−1 Disks from “temp” to “end” so they sit on Disk 0 (recursion)
        towerSolver(gw, pegCollection, tempPeg, destPeg, numDisks - 1);
    }
}

int main(int argc, char** argv)
{
    int startPeg = 0;
    int endPeg = 0;
    
    //Create a window
    GWindow gw(800, 500);
    
    //initialize the peg and disk vectors
    Vector<Peg> pegVec;
    
    //create the peg coordinates
    Peg peg1(135, 50, 10, 450);
    Peg peg2(395, 50, 10, 450);
    Peg peg3(655, 50, 10, 450);
    //create the vector of pegs
    pegVec.add(peg1);
    pegVec.add(peg2);
    pegVec.add(peg3);
    
    //display the pegs and their numbers
    draw(gw, pegVec);
    
    //call the prompt functions
    int numOfDisks = promptForDisks();
    promptForPegs(startPeg, endPeg);
   
    //calls functions from main
    initializeStack(gw, pegVec, numOfDisks, startPeg);
    pause(1000);
    towerSolver(gw, pegVec, startPeg, endPeg, numOfDisks);

    return 0;
}

