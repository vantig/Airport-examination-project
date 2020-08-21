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
	friend std::ostream& operator<<(std::ostream& out, Pilot&);
private:
	std::string surname;
	size_t workExperienceYears;
	std::string address;
	std::string DateOfBirth;
	double salary;
};
std::ostream& operator<<(std::ostream& out, const Pilot& pilot)
{
	out << " Pilot surname | " <<  std::setw(12) << pilot.getSurname() << " | work Experience  " << std::setw(2) << pilot.getworkExperienceYears() << " years | address " <<std::setw(23) << pilot.getAddress() << " | Date Of Birth " << pilot.getDateOfBirth() << " | salary " << pilot.getSalary() << "$"<<std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Pilot& pilot)
{
	in >> pilot.surname >> pilot.workExperienceYears >> pilot.address >> pilot.DateOfBirth >> pilot.salary;
	return in;

}
