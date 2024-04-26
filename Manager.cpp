

#include "Manager.h"

using namespace mtm;


/*Manager ::Manager(int id, string& first_name, string& last_name, int birth_year) :
        Citizen(id,first_name,last_name,birth_year){

    manager_salary = 0;
    employees = {}; // the right way to initalise the set ?

}*/

int Manager::getSalary()const {
    return manager_salary;
}

void Manager::addEmployee( Employee *employee) {

    std::set<Employee*,compare>::iterator start = employees.begin(); // use auto ?
    std::set<Employee*,compare>::iterator end = employees.end();

    while (start!=end){                                        // maybe we don't check end

        if ((*start)->getId() == employee->getId())
        {
            throw EmployeeAlreadyHired();
        }
        ++start;
    }

    employees.insert(employee);



}
void Manager::removeEmployee(unsigned int id) {

    std::set<Employee*,compare>::iterator start = employees.begin(); // use auto ?
    std::set<Employee*,compare>::iterator end = employees.end();

    while (start!=end){                                        // maybe we don't check end

        if ((*start)->getId() == id)
        {

            employees.erase(start);
            return;

        }
        ++start;
    }
        throw mtm::EmployeeIsNotHired();

}

ostream& Manager::printShort(ostream& os){
    os << this->getFirstName() << " " << this->getLastName()<< endl;
    os << "Salary:" << " " << manager_salary << endl;
    return os;
}

ostream& Manager::printLong(ostream &os) {

    os << this->getFirstName() << " " << this->getLastName() << endl;
    os << "id - " << this->getId() << " " << "birth_year - " << this->getBirthYear() << endl;
    os << "Salary:" << " " << manager_salary << endl;
    if ( !employees.empty()) {
        os << "Employees: " << endl;
    }
    std::set<Employee*,compare>::iterator start = employees.begin();
    std::set<Employee*,compare>::iterator end = employees.end();

    while (start != end) /// don't forget the last value ?
    {
        os << (*start)->getFirstName() << " " << (*start)->getLastName() << endl;
        os << "Salary:" << " " << (*start)->getSalary() << " " << "Score:" << " " << (*start)->getScore()<< endl;
        ++start;
    }
    return os;
}

/*
Manager::Manager(const Manager &manager) :

        manager_salary(manager.getSalary()),
        employees(manager.employees)
{

}
*/
Manager* Manager::clone () const {
    return new Manager(*this);

}

void Manager::setSalary(int salary_to_set) {

    manager_salary+= salary_to_set;

    if (manager_salary < 0) {
        manager_salary = 0;
    }
}

Employee* Manager::findEmployee(unsigned int id) const {

    set<Employee*,compare>::iterator start = employees.begin();
    set<Employee*,compare>::iterator end = employees.end();

    while (start != end ){

        if ((*start)->getId() == id ){
            return *start;
        }
        ++start;

    }
    return nullptr;

}
Manager Manager::SetEmployeesSalary(int salary_to_add) {

//    set<Employee *,compare>::iterator start = employees.begin(); // use auto ?
//    set<Employee *,compare>::iterator end = employees.end();
    for (Employee* e1 : employees) {
        e1->setSalary(salary_to_add);
    }

//    while (start != end) {
//        (*start)->setSalary(salary_to_add);
//
//        ++start;
//    }

    return *this;
}
std::set<Employee*,compare> Manager::getEmployeesGroup()  const
{
    return this->employees;
}

void Manager::removeAllEmployees() {

  std::set<Employee*,compare>::iterator start = employees.begin();
  std::set<Employee*,compare>::iterator end  = employees.end();

  while (start != end ) {

      delete *start;
  }
}