#include <iostream>
#include "Employee.h"
using std::cout;

#define DEFAULT_EMPLOYEE_AGE 0
#define DEFAULT_EMPLOYEE_SALARY 0

Employee::Employee(): name(nullptr), age(DEFAULT_EMPLOYEE_AGE), salary(DEFAULT_EMPLOYEE_SALARY), position(Position::NONE)
{}

Employee::~Employee()
{
	delete[] name;
}

Employee::Employee(const Employee& other)
{
	copy(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}

char* Employee::getname() const
{
	return this->name;
}

int Employee::getage() const
{
	return this->age;
}

double Employee::getsalary() const
{
	return this->salary;
}

Position Employee::getposition() const
{
	return this->position;
}

void Employee::setname(char* newName)
{
	if(this->name!=nullptr)
	{
		delete[] this->name;
		this->name=nullptr;
	}
	size_t newNameLenght=strlen(newName)+1;
	this->name=new char[newNameLenght];
	strcpy(this->name, newName);
}

void Employee::setage(int newAge)
{
	if (age<DEFAULT_EMPLOYEE_AGE)
	{
		cout<<"Please, input a valid age.\n";
		return;
	}
	else
	{
		this->age = newAge;
	}
}

void Employee::setsalary(double newSalary)
{
	if (salary<DEFAULT_EMPLOYEE_SALARY)
	{
		cout<<"Please, input a valid salary.\n";
		return;
	}
	else
	{
		this->salary=newSalary;
	}
}

void Employee::setposition(Position newPosition)
{
	this->position=newPosition;
}

double Employee::annualsalary(double salary)
{
	return 12*salary;
}

double Employee::raisesalary(double salary, int percent)
{
	return this->salary+=salary*percent/100;
}

double Employee::decreasesalary(double salary, int percent)
{
	return this->salary-=salary*percent/100;
}
