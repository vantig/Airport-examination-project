#pragma once
#include"HeaderMain.h"
class Flight :public Pilot, public Plane
{
public:
	Flight() = default;
	~Flight() = default;
	void setPilotandPlane(Pilot& pi, Plane& pl) { pilot = pi, plane = pl; pilotSurname = pi.getSurname(), planeNumber = pl.getNumber(), planeBrand = pl.getBrand(), cargoWeight = pl.getCarrying(); }
	void changeItem();
	std::string getflightNumber()const { return flightNumber; }
	std::string getFinishDate()const { return finishDate; }
	std::string getStartDate() const { return startDate; }
	std::string getPilotSurname()const { return pilotSurname; }
	std::string getPlaneNumber()const { return planeNumber; }
	std::string getPlaneBrand() const { return planeBrand; }
	double getKm()const { return km; }
	double getCost()const { return cost; }
	std::string getStartPoint()const { return startPoint; }
	std::string getFinishPoint() const { return finishPoint; }
	size_t getCountOfStops() const { return countOfStops; }
	size_t getCountOfSoldTickets() const { return countOfSoldTickets; }
	size_t getCargoWeight() const { return cargoWeight; }
	friend std::istream& operator>>(std::istream& in, Flight& flight);
	friend	std::ostream& operator<<(std::ostream& out, const Flight& flight);
protected:
	Pilot pilot;
	Plane plane;
    std::string flightNumber;
	std::string finishDate;
	std::string startDate;
	std::string pilotSurname;
	std::string planeNumber;
	std::string planeBrand;
	double km;
	double cost;
	std::string startPoint;
	std::string finishPoint;
	size_t countOfStops;
	size_t countOfSoldTickets;
	size_t cargoWeight;
};
void Flight:: changeItem()
{
	std::cout << "\n SELECT ITEM " << std::endl << std::endl;
	std::cout << " 1. flight number\n";

	std::cout << " 2.  finish date\n";

	std::cout << " 3.  start date\n";
	std::cout << " 4. range in km\n";
	std::cout << " 5. flight cost\n";

	std::cout << " 6. start point\n";
	std::cout << " 7. finish point\n";
	std::cout << " 8. count of stops\n";

	std::cout << " 9. count of sold tickets \n";

	std::cout << "10.  cargo weight \n";
	int choise;
	std::cin >> choise;
	std::string str;
	
	switch (choise)
	{
	case 1:
	{
		std::cout << "Enter flight number\n";
		std::cin >> str;
		std::stringstream out(str);
		out>>flightNumber;
		break;
	}
	case 2:
	{
		std::cout << "Enter finish date\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> finishDate ;
		break;
	}
	case 3:
	{
		std::cout << "Enter  start date\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> startDate ;
		break;
	}
	case 4:
	{
		std::cout << "Enter range in km\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> km ;
		break;
	}
	case 5:
	{
		std::cout << "Enter flight cost\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> cost ;
		break;
	}
	case 6:
	{
		std::cout << "Enter start point\n";
		std::cin >> str;
		std::stringstream out(str);
		out>>startPoint ;
		break;
	}
	case 7:
	{
		std::cout << "Enter finish point\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> finishPoint ;
		break;
	}
	case 8:
	{
		std::cout << "Enter count of stops\n";
		std::cin >> str;
		std::stringstream out(str);
		out>>countOfStops ;
		break;
	}
	case 9:
	{
		std::cout << "Enter count of sold tickets\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> countOfSoldTickets ;
		break;
	}
	case 10:
	{
		std::cout << "Enter cargo weight\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> cargoWeight ;
		break;
	}
	default:
		break;
	}
}
	std::ostream& operator<<(std::ostream& out, const Flight& flight)
{
		out << " flight number  " << flight.getflightNumber() << " flight start date " << flight.getStartDate() << "  flight finish date " << flight.getFinishDate() << std::endl <<
			" Pilot surname  " << std::setw(10) << flight.getPilotSurname() << " plane Number " << std::setw(10) << flight.getPlaneNumber() << " plane Brand " <<  std::setw(10) << flight.getPlaneBrand() << std::endl <<
			" distance " << std::setw(7) << flight.getKm() << " km " << " cost " << std::setw(4) << flight.getCost() << "$" <<
			" start Point " << std::setw(10) << flight.getStartPoint() << "  finish Point  " << std::setw(10) << flight.getFinishPoint() <<
			" count of stops " << flight.getCountOfStops() << " count of sold tickets " << std::setw(5) << flight.getCountOfSoldTickets() << " cargo weight  " << std::setw(7) << flight.getCargoWeight()<< "KG" <<std::endl;
			out<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
	return out;
	
}

 std::istream& operator>>(std::istream& in, Flight& flight)
{
	in >> flight.flightNumber >> flight.finishDate >> flight.startDate >> 
		 flight.km >> flight.cost >> flight.startPoint >> flight.finishPoint >>
		flight.countOfStops >> flight.countOfSoldTickets>>flight.cargoWeight ;
	return in;
}

