#include <iostream>
#include "Employee.h"
#include "Company.h"
#include "Equipment.h"

using namespace std;

void printEmployee(Employee& employee) {
	cout << employee;
	//cout << employee.getposition() << "\n";
}

int main()
{
	Employee employee;
	employee.setname("Gosho");
	employee.setsalary(100);
	
	employee.setposition(Position(3));
	employee.setage(18);
	//printEmployee (employee);

	//Employee employee2;
	//printEmployee(employee2);
	//cout << employee2.getage();

	//employee2=employee;
	//cout << employee2.getname()<<"\n";
	//cout << employee.getname()<<"\n";
	
	//cout << employee.annualsalary(employee.getsalary())<<"\n";
	//cout << employee.decreasesalary(employee.getsalary(),5)<<"\n";
	//cout << employee.getsalary()<<"\n";

	//cout << employee.raisesalary(employee.getsalary(),5)<<"\n";
	//cout << employee.getsalary()<<"\n";
	Employee employee3;
	employee3.setname("Alex");
	employee3.setposition(Position(3));
	employee3.setage(18);
	employee3.setsalary(20);
	employee3.raisesalary(10);

	Company company;
	//employee.setsalary(10);
	//employee2.setsalary(5);
	company.addEmployee(employee);
	//company.addEmployee(employee2);
	company.addEmployee(employee3);
	

	//cout << employee3.getname() << "\n";
	//cout << company.getcountEmployees() << "\n";
	//cout << company.annualSalaryEmployes() << "\n";
	//cout << company.increase("Alex",10) << "\n";

	//cout << employee3.getsalary()<<"\n";

	//company.increaseall(10);

	system("pause");
	return 0;
}

