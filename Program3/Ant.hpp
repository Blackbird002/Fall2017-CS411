/*******************************************************************************
    Ant.hpp
    Riad Shash (Ray)
    ID: n845y337
    Class: CS411
    Program #3

  This is a derived class from the base class Critter.
  Behavior of Ants:
    Move- Every time step, Ants more randomly left, right, up, down. If Ant can
        not move, Ant stays in place
    Breed- If Ant survives 3 time steps, at the end of 3rd time step, Ant breeds
        after moving. It there is no cell available, no breeding occurs.

 ******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include <iostream>

class Ant: public Critter
{
public:
    // Constructors
    Ant();
    Ant(int row, int col);

    // Destructor (does nothing)
    ~Ant();

    // Move function that returns randomly selected direction
    virtual const char move() const override;

    // Returns true when it's time to breed
    virtual bool timeToBreed() override;

    // Returns the direction where it wants to put the new child
    virtual char breed(int& row, int& col, bool grid[20][20]) override;
};

#endif // ANT_HPP
