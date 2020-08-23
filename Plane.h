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
	out<<" | Plane number "<<std::setw(7) << plane.getNumber()<<" | Brand "<<std::setw(10) <<plane.getBrand() <<" | Release date "<<  std::setw(14) << plane.getReleaseDate()<<" | Carrying " << std::setw(8) <<  plane.getCarrying() <<" | Passangers count "<< std::setw(6) <<  plane.getPassengersCount() <<  " \n";
	return out;

}

std::istream& operator>>(std::istream& in, Plane& plane)
{
	in >> plane.number  >> plane.brand >> plane.releaseDate>> plane.carrying >> plane.passengersCount ;
	return in;
	
}

