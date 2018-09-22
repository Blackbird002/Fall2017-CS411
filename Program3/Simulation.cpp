/*
	Simulation.cpp
	Riad Shash (Ray)
	ID: n845y337
	Class: CS411
	Program #3
 */

#include "Simulation.hpp"
#include <iostream>

// This class prints to the terminal...
using std::cout;
using std::endl;

// Static variable initialization section
int Simulation::antsEaten = 0;
int Simulation::totalNewDoodlebugs = 0;
int Simulation::doodlebugsStarved = 0;
int Simulation::totalNewAnts = 0;
int Simulation::totalDoodlebugs = 0;
int Simulation::totalAnts = 0;

// Constructor
Simulation::Simulation()
{
    // Simulation board rows and cols
    numRows = 20;
    numCols = 20;

    // Counts the number of steps
    stepNumber = 0;

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            critterWorld[i][j] = nullptr;
        }
    }
}

// Simple accessor that returns stepNumber
const int Simulation::getStepNumber() const
{
    return stepNumber;
}

// Destructor
Simulation::~Simulation()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if (critterWorld[i][j] != nullptr)
                delete critterWorld[i][j];
        }
    }
}

// Prints the while world (grid) of ants, doodlebugs and empty spots
const void Simulation::printCritterWorld() const
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if (critterWorld[i][j] == nullptr)
                cout<<" . ";
                //The cell is empty so a '.' is printed in that spot
            else
            {
                cout<<" ";
                cout<<critterWorld[i][j]->getType();
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

// Randomly places ants and doodlebugs in the grid/world
void Simulation::setUpSim(int numOfAnts, int numOfDoodlebugs)
{
    //Generates a random number in the spec. range
    static unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 eng(seed1); // seed the generator
    static std::uniform_int_distribution<int> uniDist(0, 19); // define the range

    int randomNum1 = uniDist(eng);
    int randomNum2 = uniDist(eng);

    int antSetUp = 0;
    int doodlebugSetup = 0;

    // Randomly place the ants
    while(antSetUp < numOfAnts)
    {
        randomNum1 = uniDist(eng);
        randomNum2 = uniDist(eng);

        if(critterWorld[randomNum1][randomNum2] == nullptr)
        {
            critterWorld[randomNum1][randomNum2] = new Ant(randomNum1,randomNum2);
            antSetUp++;
        }
    }


    // Randomly place the doodlebugs
    while(doodlebugSetup < numOfDoodlebugs)
    {
        randomNum1 = uniDist(eng);
        randomNum2 = uniDist(eng);

        if(critterWorld[randomNum1][randomNum2] == nullptr)
        {
            critterWorld[randomNum1][randomNum2] = new Doodlebug(randomNum1,randomNum2);
            doodlebugSetup++;
        }
    }
}

/*
Counts the number of Ants and Doodlebugs in the grid and updates
the associated static variables
*/
void Simulation::countNumberOfCritterTypes()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if (critterWorld[i][j] != nullptr)
            {
                //If it's an Ant
                if(critterWorld[i][j]->getType() == 'O')
                    totalAnts++;
                // If it's a Doodlebug
                else if (critterWorld[i][j]->getType() == 'X')
                    totalDoodlebugs++;
            }
        }
    }
}

/*
Movement on a 2D grid where [row#][col#]
Left - [][-1]
Up - [-1][]
Right - [][+1]
Down - [+1][]
Input parameter dir is the desired direction to go to. Input parameters row and
col are the coordinates of the object (Ant or Doodlebug) that wants to move.
Returns a true if the Ant/Doodlebug moved. It uses pointer reassignment to "move"
the objects around. This function does not move the object if the move is out
of bounds or if the space is already occupied by another object.

*/
bool Simulation::tryMoveDir(char& dir, int& row, int& col)
{
        // If requested to go left...
        if (dir == 'L')
        {
            // Check if out of bounds
            if((col - 1) != -1)
            {
                if(critterWorld[row][col-1] == nullptr)
                {
                    critterWorld[row][col-1] = critterWorld[row][col];
                    // Updates position in object
                    critterWorld[row][col]->colPosition = col-1;
                    critterWorld[row][col]->rowPosition = row;
                    critterWorld[row][col] = nullptr;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        // If requested to go up...
        else if (dir == 'U')
        {
            // Check if out of bounds
            if((row - 1) != -1)
            {
                if(critterWorld[row-1][col] == nullptr)
                {
                    critterWorld[row-1][col] = critterWorld[row][col];
                    // Updates position in object
                    critterWorld[row][col]->rowPosition = row-1;
                    critterWorld[row][col]->colPosition = col;
                    critterWorld[row][col] = nullptr;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        // If requested to go right...
        else if (dir == 'R')
        {
            // Check if out of bounds
            if((col + 1) != numCols)
            {
                if(critterWorld[row][col+1] == nullptr)
                {
                    critterWorld[row][col+1] = critterWorld[row][col];
                    // Updates position in object
                    critterWorld[row][col]->colPosition = col+1;
                    critterWorld[row][col]->rowPosition = row;
                    critterWorld[row][col] = nullptr;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                    return false;
            }
        }
        // If requested to go down...
        else if (dir == 'D')
        {
            // Check if out of bounds
            if((row + 1) != numCols)
            {
                if(critterWorld[row+1][col] == nullptr)
                {
                    critterWorld[row+1][col] = critterWorld[row][col];
                    // Updates position in object
                    critterWorld[row][col]->rowPosition = row+1;
                    critterWorld[row][col]->colPosition = col;
                    critterWorld[row][col] = nullptr;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
            return false;

}

/*
Left - [][-1]
Up - [-1][]
Right - [][+1]
Down - [+1][]

This is the most important/fundamental function in this Simulation class. Each
time it is called, it does a time step. It operates in this order:
    1.) Handles Doodlebug eating/Movement and prints grid with associated title
    2.) Handles Ant movement & Prints grid with associated title
    3.) Handles Doodlebug breeding and starvation
    4.) Handles Ant breeding and then prints the grid 

The way I wrote this simulation involves the concept of "asking" each object 
and invoking the object to make decisions. Then this simulation class (mainly this
function) carries out the decision. In order for the objects to make their own
decisions, parameters get passed in like the objects coordinates in the gird and
a char/bool 2D array that cotains information.

*/
void Simulation::timeStep()
{
    // Resets the static variables
    antsEaten = 0;
    doodlebugsStarved = 0;
    totalNewDoodlebugs = 0;
    totalNewAnts = 0;
    totalAnts = 0;
    totalDoodlebugs = 0;

    /*
     Updates the simulator class stepNumber by two. This is done to properly synchronize the
     Ants and Doodlebugs with this simulator class. This is done to prevent an Ant or doodlebug
     from doing more than one step at a time which could occur if an Ant moved somewhere forward
     where the grid scan will visit again in the future. 
     This function scans the grid from [0][0] to [19][19]. 
    */
    stepNumber+=2;

//--------------------------------------------------------------------------------------------
    //Phase #1 (Doodlebugs movement/eating)
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if (critterWorld[i][j] != nullptr)
            {
                if (critterWorld[i][j]->getStepNumber() < stepNumber-1)
                {
                        // If it's a Doodlebug
                        if (critterWorld[i][j]->getType() == 'X')
                        {
                            critterWorld[i][j]->incrementStepsAlive();
                            critterWorld[i][j]->incrementStepNumber();


                            int prevRow = i;
                            int prevCol = j;

                            // Generates a 2D array of bools where ants are located
                            bool antGrid[20][20];
                            for (int x = 0; x < 20; x++)
                            {
                                for(int y = 0; y < 20; y++)
                                {
                                    if (critterWorld[x][y] != nullptr)
                                    {
                                        // If there is an Ant
                                        if (critterWorld[x][y]->getType() == 'O')
                                            antGrid[x][y] = true;
                                        else
                                            antGrid[x][y] = false;
                                    }
                                    else
                                        antGrid[x][y] = false;
                                }
                            }

                            // Doodlebug will returnturn direction of Ant it 
                            // wants to eat in an adjacent cell
                            char eatDir = critterWorld[i][j]->eatAnt(i,j,antGrid);

                            // Generates the coordinates of the traget Ant to be "eaten"
                            if(eatDir == 'L')
                                prevCol--;
                            else if(eatDir == 'U')
                                prevRow--;
                            else if(eatDir == 'R')
                                prevCol++;
                            else if(eatDir == 'D')
                                prevRow++;

                            // If an Ant is detected in adjacent cell...
                            if (eatDir != '#')
                            {
                                //Delete the Ant in future Doodlebug spot
                                Critter *temp;
                                temp = critterWorld[prevRow][prevCol];
                                
                                delete temp;
                                critterWorld[prevRow][prevCol] = nullptr;
                                antsEaten++;


                                //Move Doodlebug to future spot (assign pointer)
                                if(critterWorld[prevRow][prevCol] == nullptr)
                                    critterWorld[prevRow][prevCol] = critterWorld[i][j];

                                // Set prev position to nullptr
                                critterWorld[i][j] = nullptr;
                            }
                            // If the Doodlebug could not eat, it will just move
                            else
                            {
                                // Asks Doodlebug for directions
                                char movedir = critterWorld[i][j]->move();

                                // Tries to move the Doodlebug
                                bool moved = tryMoveDir(movedir,i,j);

                                // If Doodlebug moved, update the coordinates
                                // Not needed, but it case I want to add more
                                // functionality later
                                if(moved == true)
                                {
                                    if(movedir == 'L')
                                        prevCol--;
                                    else if(movedir == 'U')
                                        prevRow--;
                                    else if(movedir == 'R')
                                        prevCol++;
                                    else if(movedir == 'D')
                                        prevRow++;
                                }
                            }
                        }
                    }
                }
            }
        }
        // Prints the grid after Doodlebug eating/movement
        cout<<"-Doodlebug eating & movement-\n";
        printCritterWorld();
        cout<<endl;
//--------------------------------------------------------------------------------------------
//Phase #2 (Ant movement)
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                if (critterWorld[i][j] != nullptr)
                {
                    if (critterWorld[i][j]->getStepNumber() < stepNumber-1)
                    {
                        // If it's an Ant
                        if(critterWorld[i][j]->getType() == 'O')
                        {

                            critterWorld[i][j]->incrementStepsAlive();
                            critterWorld[i][j]->incrementStepNumber();

                            int prevRow = i;
                            int prevCol = j;

                            // Asks the Ant what direction it wants to go
                            char movedir = critterWorld[i][j]->move();

                            // Tries to move the Ant
                            bool moved = tryMoveDir(movedir,i,j);

                            // Not needed, but it case I want to add more
                            // functionality later
                            if(moved == true)
                            {
                                if(movedir == 'L')
                                    prevCol--;
                                else if(movedir == 'U')
                                    prevRow--;
                                else if(movedir == 'R')
                                    prevCol++;
                                else if(movedir == 'D')
                                    prevRow++;
                            }
                        }
                    }
                }
            }
        }
        //Prints the grid after the Ants moved
        cout<<"-Ant movement-\n";
        printCritterWorld();
        cout<<endl;
//--------------------------------------------------------------------------------------------
//Phase #3 (Doodlebug breeding and starvation)

        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                if (critterWorld[i][j] != nullptr)
                {
                    if (critterWorld[i][j]->getStepNumber() < stepNumber)
                    {
                        // If it's a Doodlebug
                        if (critterWorld[i][j]->getType() == 'X')
                        {
                            critterWorld[i][j]->incrementStepNumber();

                            // ----------------------------STARVATION-----------------------
                            // Check if the Doodlebug starved!
                            bool checkStarvation = critterWorld[i][j]->starve();
                            if(checkStarvation == true)
                            {
                                // Deletes the Doodlebug (it died)
                                Critter *temp;
                                temp = critterWorld[i][j];
                                delete temp;

                                // Sets the positio back to nullptr
                                critterWorld[i][j] = nullptr;

                                // Increment the static death counter
                                doodlebugsStarved++;
                            }
                            else
                            {
                                // ----------------------------BREEDING-----------------------
                                bool breedTime = critterWorld[i][j]->timeToBreed();

                                if(breedTime == true)
                                {
                                    // Generates a 2D array of bools
                                    bool grid[20][20];
                                    for (int x = 0; x < 20; x++)
                                    {
                                        for(int y = 0; y < 20; y++)
                                        {
                                            if (critterWorld[x][y] != nullptr)
                                            {
                                                grid[x][y] = false;
                                            }
                                            else
                                                grid[x][y] = true;
                                        }
                                    }

                                    char breedDir = critterWorld[i][j]->
                                                breed(i,j,grid);
                                    /*
                                    Left - [][-1]
                                    Up - [-1][]
                                    Right - [][+1]
                                    Down - [+1][]
                                    */

                                    // Sets newRow and newCol to current obj coordinates
                                    int newRow = i;
                                    int newCol = j;

                                    // Generates the coordinates of the new bred Doodlebug
                                    if(breedDir == 'L')
                                        newCol--;
                                    else if(breedDir == 'U')
                                        newRow--;
                                    else if(breedDir == 'R')
                                        newCol++;
                                    else if(breedDir == 'D')
                                        newRow++;

                                    // Creates the new Doodlebug object... if space is available
                                    if (breedDir != '#')
                                    {
                                        // Creates a new dynamic Doodlebug
                                        critterWorld[newRow][newCol] = new Doodlebug(newRow,newCol);

                                        // Increments the static new doodlebug counter
                                        totalNewDoodlebugs++;

                                        //Syncs the stepNumber with the parent Doodlebug
                                        int newStep = critterWorld[i][j]->getStepNumber();
                                        critterWorld[newRow][newCol]->changeStepNumber(newStep);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    //--------------------------------------------------------------------------------------------
    //Phase #3 Ant breeding

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if (critterWorld[i][j] != nullptr)
            {
                if (critterWorld[i][j]->getStepNumber() < stepNumber)
                {
                        // If it's a Doodlebug
                        if (critterWorld[i][j]->getType() == 'O')
                        {
                            critterWorld[i][j]->incrementStepNumber();


                        // ----------------------------Ant BREEDING-----------------------
                        bool breedTime = critterWorld[i][j]->timeToBreed();

                        if(breedTime == true)
                        {
                            // Generates a 2D array of bools
                            bool grid[20][20];
                            for (int x = 0; x < 20; x++)
                            {
                                for(int y = 0; y < 20; y++)
                                {
                                    if (critterWorld[x][y] != nullptr)
                                    {
                                        grid[x][y] = false;
                                    }
                                    else
                                        grid[x][y] = true;
                                }
                            }

                            char breedDir = critterWorld[i][j]->
                                        breed(i,j,grid);
                            /*
                            Left - [][-1]
                            Up - [-1][]
                            Right - [][+1]
                            Down - [+1][]
                            */

                            int newRow = i;
                            int newCol = j;

                            // Generates the coordinates of the new bred Ant
                            if(breedDir == 'L')
                                newCol--;
                            else if(breedDir == 'U')
                                newRow--;
                            else if(breedDir == 'R')
                                newCol++;
                            else if(breedDir == 'D')
                                newRow++;

                            // Creates the new Ant object... if space is available
                            if (breedDir != '#')
                            {
                                // Creates a new dynamic ant
                                critterWorld[newRow][newCol] = new Ant(newRow,newCol);

                                // Increments the static new ants counter
                                totalNewAnts++;

                                //Syncs the stepNumber with the parent Ant
                                int newStep = critterWorld[i][j]->getStepNumber();
                                critterWorld[newRow][newCol]->changeStepNumber(newStep);
                            }
                        }
                    }
                }
            }
        }
    }
    //Prints the grid after Doodlebug & Ant breeding and then Doodlebug starvation
    cout<<"-Doodlebug & Ant breeding. Doodlebug starvation-\n";
    printCritterWorld();
    cout<<endl;
}
