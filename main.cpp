#include"HeaderMain.h"

int main()
{
	Airport airport;
	airport.readPilots("Pilots.txt");
	airport.readFlights("Flights.txt");
	airport.readPlanes("Planes.txt");
	airport.menu();
	
	
	/*Airport airport1;
	std::ifstream fin;
	fin.open("Airport.txt", std::ofstream::app);


	if (fin.is_open())
	{
		fin.clear();
		fin.read((char*)&airport1, sizeof(Airport));
	}

	
	
	
	airport1.menu();

	fin.close();
	*/
	return 0;
}