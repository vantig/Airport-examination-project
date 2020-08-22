#pragma once
#include"HeaderMain.h"
class Flight :public Pilot, public Plane
{
public:
	Flight() = default;
	void setPilotandPlane(Pilot& pi, Plane& pl) { pilot = pi, plane = pl; pilotSurname = pi.getSurname(), planeNumber = pl.getNumber(), planeBrand = pl.getBrand(), cargoWeight = pl.getCarrying(); }
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
	std::ostream& operator<<(std::ostream& out, const Flight& flight)
{
		out << " flight number  " << flight.getflightNumber() << " flight start date " << flight.getStartDate() << "  flight finish date " << flight.getFinishDate() << std::endl <<
			" Pilot surname  " << std::setw(15) << flight.getPilotSurname() << " plane Number " << std::setw(10) << flight.getPlaneNumber() << " plane Brand " <<  std::setw(10) << flight.getPlaneBrand() << std::endl <<
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

