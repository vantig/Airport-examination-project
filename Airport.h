#pragma once
#include"HeaderMain.h"
class Airport
{
public:
	Airport()=default;
	~Airport() = default;
	void readPlanes(std::istream&);
	/*void readPilots(std::string);
	void readFlights(std::string);*/
	void initialFlights();
	void printPlanes(std::ostream&);
	void printPilots(std::ostream&);
	void printFlights(std::ostream&);
private:
	std::vector<Plane>planes;
	std::vector<Pilot>pilots;
	std::vector<Flight>flights;

};
void Airport::initialFlights()
{
	int indexPlane, indexPilot,indexFlight;
	bool flag = true;
	
	while (flag)
	{
		std::cout << std::setfill('-') << " SELECT FLIGHT " << std::endl;
		for (size_t i = 0; i < flights.size(); ++i)
		{
			std::cout << i << ". " << flights[i];
		}
		std::cin >> indexFlight;
		std::cout << std::setfill('-') << " SELECT PILOT " << std::endl;
		for (size_t i = 0; i < pilots.size(); ++i)
		{
			std::cout << i << ". " << pilots[i];
		}
		std::cin >> indexPilot;
		std::cout << std::setfill('-') << " SELECT PLANE " << std::endl;
		for (size_t i = 0; i < planes.size(); ++i)
		{
			std::cout << i << ". " << planes[i];
		}
		std::cin >> indexPlane;
		flights[indexFlight].setPilotandPlane(pilots[indexPilot], planes[indexPlane]);
		std::cout << "✈-----------successfully-------------✈" << std::endl;
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
void Airport::readPlanes(std::istream& in)
{
	
	while (!in.eof())
	{
		Plane temp;
		in >> temp;
		planes.push_back(temp);

	}
}
//void Airport::readPilots(std::string file)
//{
//	std::ifstream in(file);
//	while (!in.eof())
//	{
//		Pilot temp;
//		in >> temp;
//		pilots.push_back(temp);
//
//	}
//}
//void Airport::readFlights(std::string file)
//{
//	std::ifstream in(file);
//	while (!in.eof())
//	{
//		Flight temp;
//		in >> temp;
//		flights.push_back(temp);
//
//	}
//}
