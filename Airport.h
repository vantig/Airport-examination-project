#pragma once
#include"HeaderMain.h"
class Airport
{
public:
	Airport()=default;
	~Airport() = default;
	void readPlanes(std::string);
	void readPilots(std::string);
	void readFlights(std::string);
	 void initialFlights();
	void printPlanes(std::ostream&);
	void printPilots(std::ostream&);
	void printFlights(std::ostream&);
	
private:
	
	
	std::vector<Flight>flights;
	std::vector<Plane>planes;
	std::vector<Pilot>pilots;
};

void Airport::initialFlights()
{
	int indexPlane, indexPilot,indexFlight;
	bool flag = true;
	
	while (flag)
	{
		
		for (size_t i = 0; i < flights.size(); i++)
		{
			std::cout<<i<< this->flights[i];
		}
		std::cout << " SELECT FLIGHT " << std::endl << std::endl;
		std::cin >> indexFlight;
		for (size_t i = 0; i < pilots.size(); i++)
		{
			std::cout << this->pilots[i];
		}
		std::copy(pilots.begin(), pilots.end(), std::ostream_iterator<Pilot>(std::cout, "\n"));
		std::cout  << " SELECT PILOT " << std::endl << std::endl;

	
		std::cin >> indexPilot;
		std::cout << " SELECT PLANE " << std::endl << std::endl;
		
		std::cin >> indexPlane;
		//flights[indexFlight].setPilotandPlane(pilots[indexPilot], planes[indexPlane]);
		std::cout << "-----------successfully-------------" << std::endl;
		std::cout << "Again? yes(1)/no(0)" << std::endl;
		std::cin >> flag;
	}
	
}
void  Airport::printPlanes(std::ostream& out)
{
	std::copy(planes.begin(), planes.end(), std::ostream_iterator<Plane>(out, "\n"));
}
void  Airport::printPilots(std::ostream& out)
{
	std::copy(pilots.begin(), pilots.end(), std::ostream_iterator<Pilot>(out, "\n"));
}
void  Airport::printFlights(std::ostream& out)
{
	std::copy(flights.begin(), flights.end(), std::ostream_iterator<Flight>(out, "\n"));
}
void Airport::readPlanes(std::string file)
{
	std::ifstream in(file);
	while (!in.eof())
	{
		Plane temp;
		in >> temp;
		planes.push_back(temp);

	}
}
void Airport::readPilots(std::string file)
{
	std::ifstream in(file);
	while (! in.eof() )
	{
		Pilot temp;
		in >> temp;
		pilots.push_back(temp);

	}
}
void Airport::readFlights(std::string file)
{
	std::ifstream in(file);
	while (in)
	{
		Flight temp;
		in >> temp;
		flights.push_back(temp);

	}
}
