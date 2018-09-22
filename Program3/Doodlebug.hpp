/*******************************************************************************
    Doodlebug.hpp
    Riad Shash (Ray)
    ID: n845y337
    Class: CS411
    Program #3

  This is a derived class from the base class Critter. 

  Behavior of Doodlebugs:
    Move- Every time step, Doodlebugs will move to an adjacent cell containing 
        and ant and "eat" the ant. If there are no ants in any adjacent cells,
        the doodlebug moves according to the same rules as ant.
    Breed- If Doodlebug survives 8 time steps, at the end of 8th time step, 
        Doodlebug breeds after moving. It there is no cell available, 
        no breeding occurs.
    Starve- If the Doodlebug has not eaten an Ant within 3 time steps, at the 
        end of the 3rd time step, it will "starve" and "die". 

 ******************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"
#include <iostream>

class Doodlebug: public Critter
{
public:
    Doodlebug();
    Doodlebug(int row, int col);
    ~Doodlebug();

    virtual const char move() const override;
    virtual bool timeToBreed() override;

    // Returns the direction where it wants to put the new child
    virtual char breed(int& row, int& col, bool grid[20][20]) override;

    // Retruns the direction of the ant to eat
    virtual char eatAnt(int row, int col, bool grid[20][20]) override;

    // Deletes the doodlebug object if it starved
    virtual const bool starve() override;

protected:
    int noEatingSteps;
};

#endif // DOODLEBUG_HPP
