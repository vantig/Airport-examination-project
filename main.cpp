#include"HeaderMain.h"

int main()
{
	Airport airoport;
	
	
	airoport.readPilots("Pilots.txt");
	airoport.readFlights("Flights.txt");
	airoport.readPlanes("Planes.txt");
	airoport.initialFlights();
	airoport.printPilots(std::cout);
	airoport.printFlights(std::cout);
	airoport.printPlanes(std::cout);
		
	
	return 0;
}