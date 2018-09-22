/*******************************************************************************
    Simulation.hpp
    Riad Shash (Ray)
    ID: n845y337
    Class: CS411
    Program #3

    This class handles the SimAnt simulation using Ants and Doodlebugs. The entire
    world/grid is located in this class. The grid is a 2D array of Critter base
    class pointers. Ants and Doodelbugs live in a 20x20 grid world.

    Movement on a 2D grid where [row#][col#]
    Left - [][-1]
    Up - [-1][]
    Right - [][+1]
    Down - [+1][]

    It operates in this order every time step (by the timeStep function):
    1.) Handles Doodlebug eating/Movement and prints grid with associated title
    2.) Handles Ant movement & Prints grid with associated title
    3.) Handles Doodlebug breeding and starvation
    4.) Handles Ant breeding and then prints the grid 

    Behavior of Ants:
        Move- Every time step, Ants more randomly left, right, up, down. It Ant can
            not move, Ant stays in place
        Breed- If Ant survives 3 time steps, at the end of 3rd time step, Ant breeds
            after moving. It there is no cell available, no breeding occurs.

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
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

class Simulation
{
public:
    // Constructor
    Simulation();

    // Destructor
    ~Simulation();

    // Randomly places ants and doodlebugs in the grid/world
    void setUpSim(int numOfAnts, int numOfDoodlebugs);

    // Does a time step (fundamental/important function)
    void timeStep();

    // Tries to move given a direction from ant or doodlebug
    bool tryMoveDir(char& dir, int& row, int& col);

    // Prints the while world (grid) of ants, doodlebugs and empty spots
    const void printCritterWorld() const;

    // Gets the step number of the simulation
    const int getStepNumber() const;

     /*
     Counts the number of Ants and Doodlebugs in the grid and updates
     the associated static variables
     */
    void countNumberOfCritterTypes();

    // Static variable accessors
    static int getAntsEaten(){return antsEaten;};
    static int getDoodlebugsStarved(){return doodlebugsStarved;};
    static int getTotalNewDoodlebugs(){return totalNewDoodlebugs;};
    static int getTotalNewAnts(){return totalNewAnts;};
    static int getTotalAnts(){return totalAnts;};
    static int getTotalDoodlebugs(){return totalDoodlebugs;};

private:
    int numRows;
    int numCols;
    
    // Used for synchronization with the objects in the grid
    int stepNumber;

    // A 2D array of Critter (base class) pointers
    Critter* critterWorld[20][20];

    // Static variables that store the stats
    static int antsEaten;
    static int totalNewAnts;
    static int totalNewDoodlebugs;
    static int doodlebugsStarved;
    static int totalAnts;
    static int totalDoodlebugs;
};

#endif // SIMULATION_HPP
