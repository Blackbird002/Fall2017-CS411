/*
	main.cpp
	Riad Shash (Ray)
	ID: n845y337
	Class: CS411
	Program #3
 */

#include <iostream>
#include "Simulation.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
    Simulation sim;
    int step = 0;

    //Sets up the simulation with 100 ants and 5 doodlebugs
    sim.setUpSim(100,5);

    cout<<"---------------------------------------------------------------------\n";
    cout<<"Starting World: \n";
    cout<<"---------------------------------------------------------------------\n";
    cout<<endl;
    sim.printCritterWorld();
    cout<<endl;

    bool simulation = true;
    string userinput;

    // The simulation keeps going until a edge case occurs
    while(simulation == true)
    {
        // step is the time step counter
        step++;
        cout<<"---------------------------------------------------------------------\n";
        cout<<"Simulation step: ";
        cout<<step;
        cout<<endl;
        cout<<"---------------------------------------------------------------------\n";
        cout<<endl;

        // Does a time step
        sim.timeStep();


        cout<<"Total number of Ants eaten: " <<sim.getAntsEaten() <<endl;
        cout<<"Total new Ants from breeding: " <<sim.getTotalNewAnts() <<endl;
        cout<<"Total new doodlebugs from breeding: " <<sim.getTotalNewDoodlebugs() <<endl;
        cout<<"Total doodlebugs that starved: " <<sim.getDoodlebugsStarved() <<endl;

        // Counts the number of Ants and Doodlebugs in the world
        sim.countNumberOfCritterTypes();

        cout<<"Total number of Ants: " <<sim.getTotalAnts() <<endl;
        cout<<"Total number of Doodlebugs: " <<sim.getTotalDoodlebugs() <<endl;
        cout<<endl;

        // If the ants populate the whole grid...
        if(sim.getTotalAnts() == 400)
        {
            simulation = false;
            break;
        }

        // The loop continues with the press of enter
        cout<<"Press ENTER to proceed to next time step...\n";
        getline(cin,userinput);
    }


    return 0;
}
