#pragma once
#include <iostream>
#include <string.h>
#include "PositionEnum.h"

using std::ostream;

class Employee
{
private:
	char* name;
	int age;
	//double salary;
	Position position;

	void copy(const Employee& other)
	{
		this->setname(other.getname());
		this->setage(other.getage());
		this->setsalary(other.getsalary());
		this->setposition(other.getposition());
	}

public:
	double salary;
	Employee();
	~Employee();
	Employee(const Employee& other);
	Employee& operator= (const Employee& other);

	char* getname() const;
	int getage() const;
	double getsalary() const;
	Position getposition() const;

	void setname(char*);
	void setage(int);
	void setsalary(double);
	void setposition(Position);

	double annualsalary(double);
	double raisesalary(double, int);
	double decreasesalary(double, int);



	friend ostream& operator<<(ostream& os, const Employee& employee)
	{
		os<<"This employee name is "<<employee.getname()<<". Age "<<employee.getage()<<". Salary "<<employee.getsalary()<<". Position in the company is "<<(Position)employee.getposition()<<"\n";
		return os;
	}
};