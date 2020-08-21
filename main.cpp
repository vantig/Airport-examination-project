#include"HeaderMain.h"

int main()
{
	Airport airoport;
	
	
	airoport.readPilots("Pilots.txt");
	airoport.readFlights("Flights.txt");
	airoport.initialFlights(5);
	airoport.printFlights(std::cout);
	airoport.printPilots(std::cout);
		
	
	return 0;
}