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
	void changeItem();
private:
	std::string number;
	std::string brand;
	std::string releaseDate;
	int carrying;
	int passengersCount;
	
};
void Plane::changeItem()
{
	std::cout << "\n SELECT ITEM " << std::endl << std::endl;
	std::cout << " 1. plane number\n";

	std::cout << " 2.  plane brand\n";

	std::cout << " 3.  plane release date\n";
	std::cout << " 4. plane carrying\n";
	std::cout << " 5. plane passangers count\n";

	
	int choise;
	std::cin >> choise;
	std::string str;

	switch (choise)
	{
	case 1:
	{
		std::cout << "Enter plane number\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> number;
		break;
	}
	case 2:
	{
		std::cout << "Enter plane brand\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> brand;
		break;
	}
	case 3:
	{
		std::cout << "Enter  realese date\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> releaseDate;
		break;
	}
	case 4:
	{
		std::cout << "Enter plane carrying in kg\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> carrying;
		break;
	}
	case 5:
	{
		std::cout << "Enter passengers count\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> passengersCount;
		break;
	}
	
	default:
		break;
	}
}

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

