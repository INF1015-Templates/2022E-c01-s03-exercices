///
/// Une compagnie avec des employés.
///


#include <cstddef>
#include <cstdint>

#include <string>
#include <iostream>

#include <cppitertools/range.hpp>

#include "Employee.hpp"

#include "Company.hpp"

using namespace std;
using namespace iter;


// TODO: Les définitions.

Company::Company() {
	cout << "Company()" << "\n";
}

Company::Company(const string& name, const string& presidentName, double presidentSalary)
: name_(name),
  president_(presidentName, presidentSalary) {
	cout << "Company(const string&, const string&, double)" << "\n";
}

Company::Company(const string& name, const string& presidentName, double presidentSalary, span<Employee*> employees)
: Company(name, presidentName, presidentSalary) {
	for (int i : range(employees.size())) {
		employees_[i] = employees[i];
	}
	numEmployees_ = employees.size();
	cout << "Company(const string&, const string&, double, span<Employee*>)" << "\n";
}

Company::~Company() {
	for (int i : range(numEmployees_)) {
		delete employees_[i];
		employees_[i] = nullptr;
	}
	cout << "~Company() : " << name_ << "\n";
}

const string& Company::getName() const {
	return name_;
}

const Employee& Company::getPresident() const {
	return president_;
}

Employee& Company::getPresident() {
	return president_;
}

int Company::getNumEmployees() const {
	return numEmployees_;
}

void Company::addEmployee(const string& name, double salary) {
	// numEmployees_ = 3;
	// [E, E, E, 0, 0, 0, ...]
	//  0  1  2  3  4  5
	employees_[numEmployees_] = new Employee(name, salary);
	numEmployees_++;
}

void Company::print() const {
	cout << "Name: " << name_ << "\n"
	     << "President: " << president_.getName() << "\n"
	     << "Employees (" << numEmployees_ << "):" << "\n";
	for (int i : range(numEmployees_))
		cout << "  " << employees_[i]->getName() << " (" << employees_[i]->getSalary() << ")" << "\n";
}
