﻿#pragma once
#include"HeaderMain.h"
class Airport
{
public:
	Airport() = default;
	~Airport() = default;
	void menu();
	void readPlanes(std::string);
	void readPilots(std::string);
	void readFlights(std::string);
	void initialFlights();
	void printPlanes (std::ostream&);
	void printPilots(std::ostream&);
	void printFlights(std::ostream&);
	void edit();
	void searchFlightByNumber();
private:
	
	
	std::vector<Flight>flights;
	std::vector<Plane>planes;
	std::vector<Pilot>pilots;
};
void Airport:: menu()
{
	int flag;
	do {
		std::cout << "MENU:\n1 .Print\n2 .Edit\n3 .Find\n4 .Save\n0 .Exit\n";
		std::cin >> flag;
		switch (flag)
		{
		case 1:
		{
			std::cout << "PRINT:\n1 .Pilots\n2 .Planes\n3 .Flights\n4 .Back\n";
			std::cin >> flag;
			switch (flag)
			{
			case 1:
			{
				printPilots(std::cout);
				break;
			}
			case 2:
			{
				printPlanes(std::cout);
				break;
			}
			case 3:
			{
				printFlights(std::cout);
				break;
			}
			case 4:
			{
				break;
			}
			default:
				break;
			}
			break;
		}
			
		case 2:
		{
			edit();
			break;
		}
		case 3:
		{
			this->searchFlightByNumber();
			break;
		}
        case 4:
		{
			
			/*std::ofstream file;
			file.open("Airport.txt", std::ofstream::app);
			file.clear();
			std::string number;
			std::string brand;
			std::string releaseDate;
			int carrying;
			int passengersCount;
			size_t str_size = number.size() + 1;
			file.write(reinterpret_cast<char*>(&str_size), sizeof(size_t));
			file.write(reinterpret_cast<char*>(number.c_str()), str_size);

			str_size = brand.size() + 1;
			file.write(reinterpret_cast<char*>(&str_size), sizeof(size_t));
			file.write(reinterpret_cast<char*>(brand.c_str()), str_size);

			str_size = releaseDate.size() + 1;
			file.write(reinterpret_cast<char*>(&str_size), sizeof(size_t));
			file.write(reinterpret_cast<char*>(releaseDate.c_str()), str_size);

			file.write(reinterpret_cast<char*>(&carrying), sizeof(int));
			file.write(reinterpret_cast<char*>(&passengersCount), sizeof(int));
			file.close();
			std::cout << "DONE\n";
				break;*/
		}
		case 0:
		{
			exit;
			break;

		}
		default:
			std::cout<<"\n\nwrong number\n\n";
		}

		
			//HANDLE                     hStdOut;
			//CONSOLE_SCREEN_BUFFER_INFO csbi;
			//DWORD                      count;
			//DWORD                      cellCount;
			//COORD                      homeCoords = { 0, 0 };

			//hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			//if (hStdOut == INVALID_HANDLE_VALUE) return;

			///* Get the number of cells in the current buffer */
			//if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
			//cellCount = csbi.dwSize.X * csbi.dwSize.Y;

			///* Fill the entire buffer with spaces */
			//if (!FillConsoleOutputCharacter(
			//	hStdOut,
			//	(TCHAR)' ',
			//	cellCount,
			//	homeCoords,
			//	&count
			//)) return;

			///* Fill the entire buffer with the current colors and attributes */
			//if (!FillConsoleOutputAttribute(
			//	hStdOut,
			//	csbi.wAttributes,
			//	cellCount,
			//	homeCoords,
			//	&count
			//)) return;

			///* Move the cursor home */
			//SetConsoleCursorPosition(hStdOut, homeCoords);
		 
	} while (flag);



}

void Airport::searchFlightByNumber()
{
 std::cout << "Enter flight number\n"; 
 std::string str;
	std::cin >> str;
	std::for_each(flights.begin(), flights.end(), [this,&str](Flight &obj) {
		if (obj.getflightNumber() == str)
		{
			
			if (obj.getPlane().getBrand().size()==0)
			{
				int temp;
				std::cout << " pilot and plane not assigned, assign?yes(1)/no(0)" << std::endl;
				std::cin >> temp;
				if (temp)
				{
					this->initialFlights();

					std::cout << std::endl << "INFORMATION " << std::endl;
					std::cout << std::endl << "FLIHGT" << std::endl;

					std::cout << std::endl << obj << std::endl;
					std::cout << std::endl << "PILOT" << std::endl;

					std::cout << std::endl << obj.getPilot() << std::endl;
					std::cout << std::endl << " PLANE " << std::endl;

					std::cout << std::endl << obj.getPlane() << std::endl;
				}
			
			}
			else
			{
				std::cout << std::endl << "INFORMATION " << std::endl;
				std::cout << std::endl << "FLIHGT" << std::endl;

				std::cout << std::endl << obj << std::endl;
				std::cout << std::endl << "PILOT" << std::endl;

				std::cout << std::endl << obj.getPilot() << std::endl;
				std::cout << std::endl << " PLANE " << std::endl;

				std::cout << std::endl << obj.getPlane() << std::endl;
			}
			str.clear();
			return;
		}
		
		});
	if (!str.size() < 1) {
		std::cout << std::endl << "NOT FOUND\n" << std::endl;
	}
}

void Airport::edit()
{
	std::cout << "EDIT \n1.Flights\n2.Planes\n3.Pilots\n4.Back\n";
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
			std::cout << "\n DONE " << std::endl << std::endl;

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
		break;
	}
	case 2:
	{
		//Plane
		std::cout << " \n1.Change\n2.Remove\n3.Add\n";
		std::cin >> flag;
		switch (flag)
		{
		case 1:
		{
			for (size_t i = 0; i < planes.size(); i++)
			{
				std::cout << std::setw(2) << i << "." << this->planes[i];
			}
			std::cout << "\n SELECT PLANE " << std::endl << std::endl;
			std::cin >> flag;
			planes[flag].changeItem();


			std::cout << "\n DONE  " << std::endl << std::endl;

			break;
		}
		case 2:
		{
			int indexPlane;
			for (size_t i = 0; i < planes.size(); i++)
			{
				std::cout << std::setw(2) << i << "." << this->planes [i] ;
			}
			std::cout << "\n SELECT PLANE " << std::endl << std::endl;
			std::cin >> indexPlane;
			this->planes.erase(planes.begin() + indexPlane);
			std::cout << "\n DONE  " << std::endl << std::endl;
			break;

		}
		case 3:
		{
			Plane plane;
			std::string str, temp;
			std::cout << " Enter plane number\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter plane brand\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter release date\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter plane carrying in kg\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter plane passengers count\n";
			std::cin >> temp;
			str += " " + temp;
		

			std::stringstream ss(str);
			ss >> plane;
			planes.push_back(plane);
			
			
			std::cout << "\n DONE  " << std::endl << std::endl;


			break;
		}
		default:
			break;
		}
		break;
	}
	case 3:
	{
		//Pilot
		std::cout << " \n1.Change\n2.Remove\n3.Add\n";
		std::cin >> flag;
		switch (flag)
		{
		case 1:
		{
			for (size_t i = 0; i < pilots.size(); i++)
			{
				std::cout << std::setw(2) << i << "." << this->pilots[i];
			}
			std::cout << "\n SELECT PILOT " << std::endl << std::endl;
			std::cin >> flag;
			pilots[flag].changeItem();


			std::cout << "\n DONE  " << std::endl << std::endl;

			break;
		}
		case 2:
		{
			int indexPilot;
			for (size_t i = 0; i < pilots.size(); i++)
			{
				std::cout << std::setw(2) << i << "." << this->pilots [i] ;
			}
			std::cout << "\n SELECT PILOT " << std::endl << std::endl;
			std::cin >> indexPilot;
			this->pilots.erase(pilots .begin() + indexPilot);
			std::cout << "\n DONE  " << std::endl << std::endl;
			break;


			break;
		}
		case 3:
		{

			Pilot pilot;
			std::string str, temp;
			std::cout << " Enter pilot surname\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter work Experience\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " address\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Date Of Birth\n";
			std::cin >> temp;
			str += " " + temp;
			std::cout << " Enter salary \n";
			std::cin >> temp;
			str += " " + temp;


			std::stringstream ss(str);
			ss >> pilot;
			pilots.push_back(pilot);
			std::cout << "\n DONE  " << std::endl << std::endl;

			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
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
		 again:
		std::cout << "\n SELECT PLANE " << std::endl << std::endl;
		
		std::cin >> indexPlane;
		if (planes[indexPlane].getCarrying()<flights[indexFlight].getCargoWeight()|| planes[indexPlane].getPassengersCount()< flights[indexFlight].getCountOfSoldTickets())
		{
			std::cout << "\nTHIS PLANE DOES NOT FIT BY PARAMETERS, CHOOSE ANOTHER\n";
			goto  again;
		}
		flights[indexFlight].setPilotandPlane(pilots[indexPilot], planes[indexPlane]);
		std::cout <<flights[indexFlight] << std::endl;
		std::cout << std::setw(50) <<"successfully\n" << std::endl;
		std::cout << "Again? yes(1)/no(0)" << std::endl;
		std::cin >> flag;
	} 
	while (flag);
	
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
