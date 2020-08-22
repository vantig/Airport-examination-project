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
	friend std::ostream& operator<<(std::ostream& out, const Plane&);
private:
	std::string number;
	std::string brand;
	std::string releaseDate;
	int carrying;
	int passengersCount;
	
};
std::ostream& operator<<(std::ostream& out, const Plane& plane)
{
	out<<std::setw(7) << plane.getNumber()<<std::setw(10) <<plane.getBrand() <<  std::setw(14) << plane.getReleaseDate() << std::setw(8) <<  plane.getCarrying() << std::setw(6) <<  plane.getPassengersCount() <<  " \n";
	return out;

}

std::istream& operator>>(std::istream& in, Plane& plane)
{
	in >> plane.number  >> plane.brand >> plane.releaseDate>> plane.carrying >> plane.passengersCount ;
	return in;
	
}

