#pragma once
#include"HeaderMain.h"
class Plane
{
public:
	Plane()=default;
	~Plane() = default;
	std::string	getNumber() const { return number; }
	std::string	getBrand()const { return brand; }
	std::string	getReleaseDate()const { return releaseDate; }
	double getCarrying()const { return carrying; }
	size_t getPassengersCount()const { return passengersCount; }
	friend std::istream& operator>>(std::istream& in, Plane&);
	friend std::ostream& operator<<(std::ostream& out, Plane&);
private:
	std::string number;
	std::string brand;
	std::string releaseDate;
	double carrying;
	size_t passengersCount;
	
};
std::ostream& operator<<(std::ostream& out, const Plane& plane)
{
	out << " Plane number | " << plane.getNumber() << " brand | " << std::setfill('-') << std::setw(15)<< plane.getBrand() << " releaseDate | " << plane.getReleaseDate() << " carrying | " << std::setfill('-') << std::setw(7) <<plane.getCarrying() << "KG | passengersCount "  << std::setw(5) << plane.getPassengersCount() << std::endl;
	return out;

}

std::istream& operator>>(std::istream& in, Plane& plane)
{
	in >> plane.number  >> plane.brand >> plane.releaseDate>> plane.carrying >> plane.passengersCount ;
	return in;
	
}

