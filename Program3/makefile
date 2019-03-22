hw03: Critter.o Ant.o Doodlebug.o Simulation.o main.cpp
	g++ -Wall -std=c++11 -o hw03 main.cpp Critter.o Ant.o Doodlebug.o Simulation.o

Critter.o: Critter.hpp Critter.cpp
	g++ -Wall -std=c++11 -c Critter.cpp

Ant.o: Ant.hpp Ant.cpp
	g++ -Wall -std=c++11 -c Ant.cpp

Doodlebug.o: Doodlebug.hpp Doodlebug.cpp
	g++ -Wall -std=c++11 -c Doodlebug.cpp

Simulation.o: Simulation.hpp Simulation.cpp
	g++ -Wall -std=c++11 -c Simulation.cpp

clean:
	rm -f core Critter.o Ant.o Doodlebug.o Simulation.o hw03
