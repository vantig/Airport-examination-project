#pragma once
#include"HeaderMain.h"
class Pilot
{
public:
	Pilot() = default;
	~Pilot() = default;
	std::string getSurname()const { return surname; }
	size_t getworkExperienceYears() const { return workExperienceYears; }
	std::string getAddress()const { return address; }
	std::string getDateOfBirth()const { return DateOfBirth; }
	double getSalary()const { return salary; }
	friend std::istream& operator>>(std::istream& in, Pilot&);
	friend std::ostream& operator<<(std::ostream& out, const Pilot&);
	 void changeItem();
public:
	std::string surname;
	size_t workExperienceYears;
	std::string address;
	std::string DateOfBirth;
	double salary;
};
void Pilot:: changeItem()
{
	std::cout << "\n SELECT ITEM " << std::endl << std::endl;
	std::cout << " 1. pilot surname\n";

	std::cout << " 2. pilot work Experience \n";

	std::cout << " 3. pilot address\n";
	std::cout << " 4. pilot Date Of Birth\n";
	std::cout << " 5. pilot salary\n";


	int choise;
	std::cin >> choise;
	std::string str;

	switch (choise)
	{
	case 1:
	{
		std::cout << "Enter pilot surname\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> surname;
		break;
	}
	case 2:
	{
		std::cout << "Enter pilot work Experience in Years\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> workExperienceYears;
		break;
	}
	case 3:
	{
		std::cout << "Enter  pilot address\n";
		std::cin >> str;
		std::stringstream out(str);
		out >> address;
		break;
	}
	case 4:
	{
		std::cout << "Enter pilot Date Of Birth \n";
		std::cin >> str;
		std::stringstream out(str);
		out >> DateOfBirth;
		break;
	}
	case 5:
	{
		std::cout << "Enter pilot salary\n";
		std::cin >> str;
		str += "$";
		std::stringstream out(str);
		out >> salary;
		break;
	}

	default:
		break;
	}
}
std::ostream& operator<<(std::ostream& out, const Pilot& pilot)
{
	out << " | Pilot surname  " << std::setw(12) << pilot.getSurname() << " | work Experience  " << std::setw(2) << pilot.getworkExperienceYears() << " years | address " << std::setw(23) << pilot.getAddress() << " | Date Of Birth " << pilot.getDateOfBirth() << " | salary " << pilot.getSalary() << "$" << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Pilot& pilot)
{
	in >> pilot.surname >> pilot.workExperienceYears >> pilot.address >> pilot.DateOfBirth >> pilot.salary;
	return in;

}
