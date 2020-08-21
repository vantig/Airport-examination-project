#pragma once
#include"HeaderMain.h"
class Flight
{
public:
	Flight()=default;
	~Flight() = default;
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
private:
	
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

