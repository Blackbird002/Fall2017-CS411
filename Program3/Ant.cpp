/*
	Ant.cpp
	Riad Shash (Ray)
	ID: n845y337
	Class: CS411
	Program #3
 */

#include "Ant.hpp"

Ant::Ant():Critter(0,0,'O')
{}

Ant::Ant(int row, int col):Critter(row,col,'O')
{}

Ant::~Ant()
{}

// Move function that returns randomly selected direction
char const Ant::move() const
{
    char direction = randomDirection();
    return direction;
}

// Returns true when it's time to breed (Ants breed every 3 time steps)
bool Ant::timeToBreed()
{
    if(stepsAlive == 3)
    {
        stepsAlive = 0;
        return true;
    }
    else
        return false;
}

// Returns the direction where it wants to put the new Ant child
// Returns a # character if there is no space to breed
char Ant::breed(int& row, int& col, bool grid[20][20])
{
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
