#pragma once
#include"HeaderMain.h"
#include"Pilot.h"
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
	
	do
	{
		
		for (size_t i = 0; i < flights.size(); i++)
		{
			std::cout<< std::setw(2) <<i<<"."<< this->flights[i];
		}
		std::cout << "\n SELECT FLIGHT " << std::endl << std::endl;
		std::cin >> indexFlight;
		for (size_t i = 0; i < pilots.size(); i++)
		{
			std::cout << std::setw(2) << i << this->pilots[i];
		}
		
		std::cout  << "\n SELECT PILOT " << std::endl << std::endl;

	
		std::cin >> indexPilot;
		for (size_t i = 0; i < planes.size(); i++)
		{
			std::cout << std::setw(2) << i << this->planes[i];
		}

		std::cout << "\n SELECT PLANE " << std::endl << std::endl;
		
		std::cin >> indexPlane;
		flights[indexFlight].setPilotandPlane(pilots[indexPilot], planes[indexPlane]);
		std::cout <<flights[indexFlight] << std::endl;
		std::cout << std::setw(50) <<"successfully\n" << std::endl;
		std::cout << "Again? yes(1)/no(0)" << std::endl;
		std::cin >> flag;
	} while (flag);
	
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
