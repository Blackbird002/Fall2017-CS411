hw02: PFAString.o main.cpp
	g++ -Wall -std=c++11 -o hw02 main.cpp PFAString.o

PFAString.o: PFAString.hpp PFAString.cpp
	g++ -Wall -std=c++11 -c PFAString.cpp

clean:
	rm -f core PFAString.o hw02
