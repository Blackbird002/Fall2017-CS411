/*
	Critter.cpp
	Riad Shash (Ray)
	ID: n845y337
	Class: CS411
	Program #3
 */

#include "Critter.hpp"

// Defualt constructor
Critter::Critter()
{
    stepsAlive = 0;
    typeOfCritter = 'C';
    rowPosition = 0;
    colPosition = 0;
    stepNumber = 0;
}

// Constructor
Critter::Critter(int row, int col)
{
    stepsAlive = 0;
    typeOfCritter = 'C';
    rowPosition = row;
    colPosition = col;
    stepNumber = 0;
}

// Constructor (most used)
Critter::Critter(int row, int col, char type)
{
    stepsAlive = 0;
    typeOfCritter = type;
    rowPosition = row;
    colPosition = col;
    stepNumber = 0;
}

// virtual Destructor (does nothing but present)
Critter::~Critter()
{
}

/*
 Used by Doodlebug (does nothing here). This could not 
 be a pure virtual function because Ant is also derrived
 from Critter. Ants do not strave.
*/
const bool Critter::starve()
{
    return false;
}

// Accessor for stepsAlive
const int Critter::getStepsAlive() const
{
    return stepsAlive;
}

// Accessor for stepNumber
const int Critter::getStepNumber() const
{
    return stepNumber;
}

// Mutator for stepNumber
void Critter::changeStepNumber(int newStepNumber)
{
    stepNumber = newStepNumber;
}

// Increment stepNumber by 1
void Critter::incrementStepNumber()
{
    stepNumber++;
}

// Increment stepsAlive by 1
void Critter::incrementStepsAlive()
{
    stepsAlive++;
}


/*
 Used by Doodlebug (does nothing here). This could not 
 be a pure virtual function because Ant is also derrived
 from Critter. Ants do not eat other ants.
*/
char Critter::eatAnt(int row, int col, bool grid[20][20])
{
    return '#';
}

/*
 Generates a random direction (L,U,R,D):
 Left, Up, Right, Down 
*/
const char Critter::randomDirection() const
{
    // Generates a random number in the range 1 - 4 
    static unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 eng(seed1); // seed the generator
    static std::uniform_int_distribution<int> uniDist(1, 4); // define the range

    int randomNum = uniDist(eng);
    char direction;

    switch(randomNum)
    {
    case 1:
        direction = 'L';
        // Left
        break;
    case 2:
        direction = 'U';
        // Up
        break;
    case 3:
        direction = 'R';
        // Right
        break;
    case 4:
        direction = 'D';
        // Down
        break;
    }
    return direction;
}

 // Gets the type of Critter (O,X)
const char Critter::getType() const
{
    return typeOfCritter;
}

// Move function that returns randomly selected direction
char const Critter::move() const
{
    return randomDirection();
}
