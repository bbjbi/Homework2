#include <iostream>
#include <string.h>
#include "Company.h"

using namespace std;

#define CAPACITY_MULTIPLIER 2
#define DEFAULT_CAPACITY 10
#define MINIMUM_EMPLOYEES 0
#define MINIMUM_EQUIPMENT 0

Company::Company(): name(nullptr), employees(nullptr), equipments(nullptr), countEmployees(MINIMUM_EMPLOYEES), countEquipments(MINIMUM_EQUIPMENT), employeesCapacity(DEFAULT_CAPACITY), equipmentCapacity(DEFAULT_CAPACITY)
{}

Company::~Company()
{
	delete[] this->name;
	delete[] this->employees;
	delete[] this->equipments;
}

Company::Company(const Company& other)
{
	copy(other);
}

Company& Company::operator=(const Company& other)
{
	if(this!=&other)
	{
		copy(other);
	}
	return *this;
}

char* Company::getname() const
{
	return this->name;
}

Employee* Company::getEmployees() const
{
	return this->employees;
}

Equipment* Company::getEquipments() const
{
	return this->equipments;
}

int Company::getcountEmployees() const
{
	return this->countEmployees;
}

int Company::getcountEquipments() const
{
	return this->countEquipments;
}

int Company::getemployeesCapacity() const
{
	return this->employeesCapacity;
}

int Company::getequipmentCapacity() const
{
	return this->countEquipments;
}

void Company::setname(char* newName)
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

void Company::resizeEmployees() 
{
	this->employeesCapacity *= CAPACITY_MULTIPLIER;

	Employee* newEmployees = new Employee[this->employeesCapacity];
	
	for (int i = 0; i < this->countEmployees; i++) 
	{
		newEmployees[i] = this->employees[i];
	}

	delete[] this->employees;

	this->employees = newEmployees;
}

void Company::resizeEquipment() 
{
	this->equipmentCapacity *= CAPACITY_MULTIPLIER;

	Equipment* newEquipment = new Equipment[this->equipmentCapacity];
	
	for (int i = 0; i < this->countEquipments; i++) 
	{
		newEquipment[i] = this->equipments[i];
	}

	delete[] this->equipments;

	this->equipments = newEquipment;
}

void Company::addEmployee(Employee& newEmployee)
{
	if (this->employees == nullptr) 
	{
		this->employees = new Employee[DEFAULT_CAPACITY];
	}

	if (this->getcountEmployees() == this->getemployeesCapacity()) 
	{
		resizeEmployees();
	}

	this->employees[countEmployees] = newEmployee;
	countEmployees++;
}

void Company::removeEmployee(char* employeeToBeRemoved)
{
	for (int i = 0; i < countEmployees; i++) 
	{
		if(strcpy(this->employees[i].getname(), employeeToBeRemoved) == 0)
		{
			for (int j=i; j < this->getcountEmployees() - 1; j++)
			{
				this->employees[j] = this->employees[j+1];
			}
			countEmployees--;
			return;
		}
	}
}

void Company::addEquipment(Equipment& newEquipment)
{
	if (this->equipments == nullptr) 
	{
		this->equipments = new Equipment[DEFAULT_CAPACITY];
	}

	if (this->getcountEquipments() == this->getequipmentCapacity()) 
	{
		resizeEquipment();
	}

	this->equipments[countEmployees] = newEquipment;
	countEquipments++;
}

void Company::removeEquipment(char* equipmentToBeRemoved)
{
	for (int i = 0; i < countEquipments; i++) 
	{
		if(strcpy(this->equipments[i].getname(), equipmentToBeRemoved) == 0)
		{
			for (int j=i; j < this->getcountEquipments() - 1; j++)
			{
				this->equipments[j] = this->equipments[j+1];
			}
			countEquipments--;
			return;
		}
	}
}

double Company::annualSalaryEmployes() 
{
	Employee* employees = this->getEmployees();
	int sum = 0;
	for (int i = 0; i < countEmployees; i++) 
	{
		sum += employees[i].annualsalary(employees[i].getsalary());
	}
	return sum;
}

double Company::annualExpensesEquipment() 
{
	Equipment* equipments = this->getEquipments();
	int sum = 0;
	for (int i = 0; i < countEquipments; i++) 
	{
		sum += equipments[i].annualexpenses(equipments[i].getmaintenancefee());
	}

	return sum;
}

double Company::increase (char* searchName, int percent)
{
	Employee* employees = this->getEmployees();
	for (int i = 0; i < this->countEmployees; i++)
	{	
		if (strcmp(employees[i].getname(), searchName) == 0)
		{
			employees[i].setsalary(employees[i].salary + employees[i].salary*percent/100);
			return  employees[i].getsalary();
		}
	}

}

void Company::increaseall (int percent)
{
	Employee* employees = this->getEmployees();
	for (int i = 0; i < this->countEmployees; i++)
	{	
		{
			employees[i].salary+=employees[i].salary*percent/100;
			cout << employees[i].salary << "\n";
		}
	}

}

double Company::decrease (char* searchName, int percent)
{
	Employee* employees = this->getEmployees();
	for (int i = 0; i < this->countEmployees; i++)
	{	
		if (strcmp(employees[i].getname(), searchName) == 0)
		{
			employees[i].setsalary(employees[i].salary - employees[i].salary*percent/100);
			return  employees[i].getsalary();
		}
	}

}

void Company::decreaseall (int percent)
{
	Employee* employees = this->getEmployees();
	for (int i = 0; i < this->countEmployees; i++)
	{	
		{
			employees[i].salary-=employees[i].salary*percent/100;
			cout << employees[i].salary << "\n";
		}
	}

}