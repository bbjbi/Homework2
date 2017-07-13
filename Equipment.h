#pragma once
#include <iostream>
#include <string.h>

using std::ostream;

class Equipment
{
	private:
		char* name;
		double price;
		double maintenancefee;
		
		void copy(const Equipment& other)
		{
			this->setname(other.getname());
			this->setprice(other.getprice());
			this->setmaintenancefee(other.getmaintenancefee());
		}

public:
	Equipment();
	~Equipment();
	Equipment(const Equipment& other);
	Equipment& operator=(const Equipment& otger);

	char* getname() const;
	double getprice() const;
	double getmaintenancefee() const;

	void setname(char*);
	void setprice(double);
	void setmaintenancefee(double);

	double annualexpenses(double);

	friend ostream& operator<<(ostream& os, const Equipment& equipment)
	{
		os<<"This is the equipment: "<<equipment.getname()<<" with price "<<equipment.getprice()<<" and montly maintenance fee "<<equipment.getmaintenancefee();
		return os;
	}
};
