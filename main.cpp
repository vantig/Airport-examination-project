#include"HeaderMain.h"

int main()
{
	Airport airport;
	
	
	airport.readPilots("Pilots.txt");
	airport.readFlights("Flights.txt");
	airport.readPlanes("Planes.txt");
//	airport.edit();
//	airport.printPilots(std::cout);
	
	airport.searchFlightByNumber();
	
	return 0;
}