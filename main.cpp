#include"HeaderMain.h"

int main()
{
	Airport airoport;
	std::ifstream in("Planes.txt");
	airoport.readPlanes(in);
	/*airoport.readPilots("Pilots.txt");
	airoport.readFlights("Flights.txt");
	airoport.initialFlights();*/
	return 0;
}