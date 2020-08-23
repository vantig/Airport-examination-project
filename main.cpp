#include"HeaderMain.h"

int main()
{
	Airport airport;
	
	
	airport.readPilots("Pilots.txt");
	airport.readFlights("Flights.txt");
	airport.readPlanes("Planes.txt");
	//airport.initialFlights();
	airport.edit();
	airport.printFlights(std::cout);
	
	
	return 0;
}