#pragma once
#include"HeaderMain.h"
class Airport
{
public:
	Airport()=default;
	~Airport() = default;
	void readPlanes(std::istream&);
	void readPilots(std::istream&);
	void readFlights(std::istream&);
	
	void printPlanes(std::ostream&);
	void printPilots(std::ostream&);
	void printFlights(std::ostream&);
private:
	std::vector<Plane>planes;
	std::vector<Pilot>pilots;
	std::vector<Flight>flights;

};

