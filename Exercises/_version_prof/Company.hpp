///
/// Une compagnie avec des employés.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <string>
#include <span>

#include "Employee.hpp"

using namespace std;


const int numEmployeesMax = 256;

class Company {
public:
	Company();
	Company(const string& name, const string& presidentName, double presidentSalary = 0.0);
	Company(const string& name, const string& presidentName, double presidentSalary, span<Employee*> employees);
	~Company();

	const string& getName() const;
	const Employee& getPresident() const;
	Employee& getPresident();
	int getNumEmployees() const;

	void addEmployee(const string& name, double salary);
	void print() const;

private:
	string name_ = "Unnamed";
	Employee president_;
	Employee* employees_[numEmployeesMax] = {};
	int numEmployees_ = 0;
};