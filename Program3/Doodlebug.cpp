/*
	Doodlebug.cpp
	Riad Shash (Ray)
	ID: n845y337
	Class: CS411
	Program #3
 */

#include "Doodlebug.hpp"

Doodlebug::Doodlebug():Critter(0,0,'X')
{
    noEatingSteps = 0;
}

Doodlebug::Doodlebug(int row, int col):Critter(row,col,'X')
{
    noEatingSteps = 0;
}

Doodlebug::~Doodlebug()
{}

const char Doodlebug::move() const
{
    char direction = randomDirection();
    return direction;
}

bool Doodlebug::timeToBreed()
{
    if(stepsAlive == 8)
    {
        stepsAlive = 0;
        return true;
    }
    else
        return false;

}

// Returns the direction where it wants to put the new child 
char Doodlebug::breed(int& row, int& col, bool grid[20][20])
{
    /*
    Left - [][-1]
    Up - [-1][]
    Right - [][+1]
    Down - [+1][]
    */

    if((col -1) != -1)
    {
        if(grid[row][col-1] == true)
            return 'L';
        else
            return '#';
    }
    else if((row -1) != -1)
    {
        if(grid[row-1][col] == true)
            return 'U';
        else
            return '#';
    }
    else if((col+1) != 20)
    {
        if(grid[row][col+1] == true)
            return 'R';
        else
            return '#';
    }
    else if((row+1) != 20)
    {
        if(grid[row+1][col] == true)
            return 'D';
        else
            return '#';
    }
    else
        // No space is available!
        return '#';
}

// Returns the direction of the ant to eat
char Doodlebug::eatAnt(int row, int col, bool grid[20][20])
{
    /*
    Left - [][-1]
    Up - [-1][]
    Right - [][+1]
    Down - [+1][]
    */

    // Check left direction
    if((col -1) != -1)
    {
        if(grid[row][col-1] == true)
        {
            noEatingSteps = 0;
            return 'L';
        }
    }

    // Check up direction
    if((row -1) != -1)
    {
        if(grid[row-1][col] == true)
        {
            noEatingSteps = 0;
            return 'U';
        }
    }

    // Check right direction
    if((col+1) != 20)
    {
        if(grid[row][col+1] == true)
        {
            noEatingSteps = 0;
            return 'R';
        }
    }

    // Check down direction
    if((row+1) != 20)
    {
        if(grid[row+1][col] == true)
        {
            noEatingSteps = 0;
            return 'D';
        }
    }

    // No Ant to eat!
    noEatingSteps++;
    return '#';
}

/*
Returns true if doodlebug did not eat for three steps. This means that then
doodlebug starved and simulation will destroy the doodlebug
*/
const bool Doodlebug::starve()
{
    if(noEatingSteps == 3)
    {
        return true;
    }
    else
        return false;
}
