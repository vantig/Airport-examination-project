#include"HeaderMain.h"

int main()
{
	Airport airoport;
	
	airoport.readPlanes("Planes.txt");
	/*airoport.readPilots("Pilots.txt");
	airoport.readFlights("Flights.txt");*/
	airoport.printPlanes(std::cout);
	/*airoport.initialFlights();*/
	return 0;
}