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
	void edit();
	
private:
	
	
	std::vector<Flight>flights;
	std::vector<Plane>planes;
	std::vector<Pilot>pilots;
};
void Airport::edit()
{
	std::cout << "Edit \n1.Flights\n2.Planes\n3.Pilots\n";
	int flag;
	std::cin >> flag;
	switch (flag)
	{
	case 1:
	{
		std::cout << " \n1.Change\n2.Remove\n3.Add\n";
		std::cin >> flag;
		switch (flag)
		{
		case 1:
		{int indexFlight;
			std::cout << "change pilot or plane in flight?yes(1)/no(0)  \n";
			std::cin >> indexFlight;
			if (indexFlight)
			{
				this->initialFlights();
			}
			
			for (size_t i = 0; i < flights.size(); i++)
			{
				std::cout << std::setw(2) << i << "." << this->flights[i];
			}
			std::cout << "\n SELECT FLIGHT " << std::endl << std::endl;
			std::cin >> indexFlight;
			flights[indexFlight].changeItem();

			break;
			
		}
		case 2:
		{
			int indexFlight;
			for (size_t i = 0; i < flights.size(); i++)
			{
				std::cout << std::setw(2) << i << "." << this->flights[i];
			}
			std::cout << "\n SELECT FLIGHT " << std::endl << std::endl;
			std::cin >> indexFlight;
			this->flights.erase(flights.begin()+indexFlight);
			std::cout << "\n DONE  " << std::endl << std::endl;
			break;
		}
		case 3:
		{
			Flight flight;
			std::string str, temp;
			std::cout << " Enter flight number\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter Finish date\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter Start date\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter range in km\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter flight cost\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter start point\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter finish point\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter count of stops\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter count of sold tickets \n";
			std::cin >> temp;
			str +=" "+ temp;
			std::cout << " Enter cargo weight \n";
			std::cin >> temp;
			str += " " + temp;

			std::stringstream ss(str);
			ss >> flight;
			flights.push_back(flight);
			std::cout << " Add pilot and plane? \n";
			std::cin >> flag;
			if (flag)
			{
				this->initialFlights();
				std::cout << "\n DONE  " << std::endl << std::endl;
				break;
			}
			else
			{
				std::cout << "\n DONE  " << std::endl << std::endl;

				break;
			}

		}
		default:
			break;
		}

	}
	case 2:
	{
		std::cout << " \n1.Change\n2.Remove\n3.Add\n";
		std::cin >> flag;
	}
	case 3:
	{

	}
	default:
		break;
	}
}
void Airport::initialFlights()
{
	int indexPlane, indexPilot,indexFlight;
	bool flag = true;
	
	
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
	while (!in.eof())
	{
		Flight temp;
		in >> temp;
		flights.push_back(temp);

	}
}
