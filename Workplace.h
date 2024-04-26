//
// Created by 33769 on 05/01/2022.
//

#ifndef VERSION1_WORKPLACE_H
#define VERSION1_WORKPLACE_H

#include "Manager.h"

#include <set>
 namespace mtm {


         namespace {
             using std::string;
             using std::ostream;
         }


         class Workplace {



             unsigned int workplace_id;
             string workplace_name;
             int salary_employee;
             int salary_manager;
             std::set<Manager *,compare> managers;   // what better with pointer or without. Only class with.

         public:

             Workplace(int id, string name, int salary_for_employee, int salary_for_manager);

             ~Workplace()  {
                 managers.clear();
             }

             int getManagerSalary() const;

             int getWorkersSalary() const;

             unsigned int getID() const;

             string getName() const;

             void hireManager(Manager *manager);

             void fireEmployee(unsigned int employee_id, unsigned int manager_id);

             void fireManager(unsigned int manager_id);

             friend ostream& operator<<(ostream& os, const Workplace& workplace);

             set<Manager*,compare> getManagerGroup () const;

             set<Manager *,compare>::iterator getFirst () const;

             set<Manager *,compare>::iterator getLast () const;

             bool EmployeesAreInWorkplace (unsigned int employee1_id, unsigned int employee2_id);


             Manager* findManager (unsigned int id) const;

             template<class Condition>

             void hireEmployee(Condition condition, Employee *employee, unsigned int id); // maybe Condition&



         };

     template<class Condition>
     void Workplace::hireEmployee(Condition condition,  Employee *employee, unsigned int manager_id) {

         if (condition(employee) == false){
             throw EmployeeNotSelected();
         }
         Manager* manager = this->findManager(manager_id);

         if (manager == nullptr) {
             throw ManagerIsNotHired();
         }
         if (manager->findEmployee(employee->getId()) != nullptr) {
             throw EmployeeAlreadyHired();
         }


         employee->setSalary(salary_employee);
         manager->addEmployee(employee);

     }




 }

#endif //VERSION1_WORKPLACE_H
