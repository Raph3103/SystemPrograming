//
// Created by 33769 on 04/01/2022.
//

#ifndef VERSION1_MANAGER_H
#define VERSION1_MANAGER_H

//#include "Citizen.h"
#include "Employee.h"
#include <set>

namespace mtm {
    class Manager : public Citizen {


        int manager_salary;
        std::set<Employee *,compare> employees;


    public:
        Manager(unsigned int id, string first_name, string last_name, int birth_year):
        Citizen(id, first_name, last_name, birth_year),
                                                                                manager_salary(0), employees()     //the right way to initalise the set ?
        {
        }

        ~Manager() =default;

        Manager(const Manager &manager) = default;

        int getSalary() const;

        Employee* findEmployee (unsigned int id) const;

        void addEmployee(Employee *employee);

        void removeEmployee(unsigned int id);

        void setSalary(int salary_to_set);

        set<Employee*,compare> getEmployeesGroup () const;

        void removeAllEmployees () ;

        ostream &printShort(ostream &os) override; // protected ?

        ostream &printLong(ostream &os) override; // protected ?
        Manager *clone() const override;

        Manager SetEmployeesSalary(int salary_to_add);


    };



}

#endif //
