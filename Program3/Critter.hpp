/*******************************************************************************
    Critter.hpp
    Riad Shash (Ray)
    ID: n845y337
    Class: CS411
    Program #3

    This is the base Critter class where both the Ant and Doodlebug classes where
    derived from. This base class contains data and functions that are common
    to ants and doodlebugs. This class cannot be declared as an object due to the
    existance of pure virtual functions and due to protected constructors.

 ******************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <random>
#include <chrono>

class Critter
{
public:
    // virtual Destructor (does nothing but present)
    virtual ~Critter();

    // Move function that returns randomly selected direction
    virtual const char move() const;

    // Gets the type of Critter
    const char getType() const;

    // Generates a random direction (L,U,R,D)
    const char randomDirection() const;

    // Pure virtual breeding function
    virtual char breed(int& row, int& col, bool grid[20][20]) = 0;

    // Pure virtual function that returns true when it's breeding time
    virtual bool timeToBreed() = 0;

    // Function that returns direction of the ant to be eaten (does nothing here)
    virtual char eatAnt(int row, int col, bool grid[20][20]);

    // Returns true the doodlebug did not eat for within three time steps.
    virtual const bool starve();

    // The position of the object (NOT USED, just for future expansion)
    int rowPosition;
    int colPosition;

    // Accessor for stepsAlive
    const int getStepsAlive() const;

    // Accessor for stepNumber
    const int getStepNumber() const;

    // Mutator for stepNumber
    void changeStepNumber(int newStepNumber);

    // Increment stepNumber by 1
    void incrementStepNumber();

    // Increment stepsAlive by 1
    void incrementStepsAlive();

    

protected:

    int stepsAlive;
    int stepNumber;
    
    //Constructors (protected)
    Critter();
    Critter(int row, int col);
    Critter(int row, int col, char type);

    /*
    Type of Critter (will be either C,O,X):
    C - Critter (not used and never will be)
    O - Ant
    X - Doodlebug
    */
    char typeOfCritter;

};

#endif // CRITTER_HPP
