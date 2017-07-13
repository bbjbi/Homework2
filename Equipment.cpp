#include <iostream>
#include "Equipment.h"

using std::cout;

#define DEFAULT_PRICE 0
#define DEFAULT_FEE 0

Equipment::Equipment(): name(nullptr), price(DEFAULT_PRICE), maintenancefee(DEFAULT_FEE)
{}

Equipment::~Equipment()
{
	delete[] name;
}

Equipment::Equipment(const Equipment& other)
{
	copy(other);
}

Equipment& Equipment::operator=(const Equipment& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}

char* Equipment::getname() const
{
	return this->name;
}

double Equipment::getprice() const
{
	return this->price;
}

double Equipment::getmaintenancefee() const
{
	return this->maintenancefee;
}

void Equipment::setname(char* newName)
{
	if(this->name!=nullptr)
	{
		delete[] this->name;
		this->name=nullptr;
	}
	size_t newNameLength=strlen(newName) +1;
	this->name=new char[newNameLength];
	strcpy(this->name, newName);
}

void Equipment::setprice(double newPrice)
{
	if (price<DEFAULT_PRICE)
	{
		cout<<"Please, input valid price.\n";
		return;
	}
	else
	{
		this->price=newPrice;
	}
}

void Equipment::setmaintenancefee(double newMaintenancefee)
{
	if (maintenancefee<DEFAULT_FEE)
	{
		cout<<"Please, input valid fee.\n";
		return;
	}
	else
	{
		this->maintenancefee=newMaintenancefee;
	}
}

double Equipment::annualexpenses(double maintenancefee)
{
	return 12*maintenancefee;
}