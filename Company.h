#pragma once
#include <iostream>
#include <string.h>
#include "Employee.h"
#include "Equipment.h"

using std::ostream;

class Company
{
private:
	char* name;
	Employee* employees;
	int countEmployees;
	Equipment* equipments;
	int countEquipments;
	int employeesCapacity;
	int equipmentCapacity;

	void resizeEmployees();
	void resizeEquipment();

	void copy(const Company& other)
	{
		this->setname(other.getname());
		this->countEmployees=other.getcountEmployees();
		this->countEquipments=other.getcountEquipments();
		this->employeesCapacity=other.getemployeesCapacity();
		this->equipmentCapacity=other.getequipmentCapacity();
	}

public:
	Company();
	~Company();
	Company (const Company& other);
	Company (const char* newName, Employee* newEmployee, Equipment* newEquipment);
	Company& operator=(const Company& other);

	char* getname() const;
	int getcountEmployees() const;
	int getcountEquipments() const;
	int getemployeesCapacity() const;
	int getequipmentCapacity() const;
	Employee* getEmployees() const;
	Equipment* getEquipments() const;

	void setname(char*);

	void addEmployee(Employee& newEmployee);
	void removeEmployee(char*);

	void addEquipment(Equipment& newEquipment);
	void removeEquipment(char*);

	double annualSalaryEmployes();
	double annualExpensesEquipment();

	double increase (char*,int);
	void increaseall (int);

	double decrease (char*,int);
	void decreaseall (int);

	friend ostream& operator<<(ostream& os, const Company& company)
	{
		os << "Welcome to company "<<company.getname()<<". \nAt the moment the company has "<< company.getcountEmployees()<<" employees with capacity of total "<<company.getemployeesCapacity()<<" employees.\n Right now there are "<<company.getcountEquipments()<<" equipments with capacity of "<<	company.getequipmentCapacity()<<"\n";
		os << "The currently employed people are:\n";
		for (int i=0; i< company.getcountEmployees(); i++)
		{
			os<<company.getEmployees()[i].getname()<<"\n"; 
		}
		os << "Currently the equipment in the company is:\n";
		for (int i=0; i< company.getcountEquipments(); i++)
		{
			os<<company.getEquipments()[i].getname()<<"\n";
		}
		return os;
	}

};