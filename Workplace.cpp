
#include "Workplace.h"

using namespace mtm;



Workplace::Workplace(int id, string name, int salary_for_employee, int salary_for_manager) {

    workplace_name = name;
    workplace_id = id;
    salary_employee = salary_for_employee;
    salary_manager = salary_for_manager;
    managers = {};
}

int Workplace::getManagerSalary() const {

    return this->salary_manager;
}


int Workplace::getWorkersSalary() const {

    return this->salary_employee;
}

unsigned int Workplace::getID() const {

    return this->workplace_id;
}

string Workplace::getName() const {

    return this->workplace_name;
}


void Workplace::hireManager(Manager *manager) {

    Manager* manager1 = findManager(manager->getId());

    if (manager1 != nullptr){
        throw ManagerAlreadyHired();
    }

    if (manager->getSalary() != 0) {

        throw CanNotHireManager();

    }
    manager->setSalary(this->getManagerSalary()); /// set also the employees salary
    manager->SetEmployeesSalary(getWorkersSalary());
    managers.insert(manager);
}


void Workplace::fireEmployee(unsigned int employee_id, unsigned int manager_id) {

    Manager* manager = findManager(manager_id);
    if (manager == nullptr) {

        throw ManagerIsNotHired();
    }

    Employee* employee = manager->findEmployee(employee_id); // maybe have to be check first.
    if (employee == nullptr){
        throw EmployeeIsNotHired();
    }
    employee->setSalary(-salary_employee);
    manager->removeEmployee(employee_id);









}



void Workplace::fireManager(unsigned int manager_id) {


    //std::set<Manager *,compare>::iterator start = managers.begin(); // use auto ?
   // std::set<Manager *,compare>::iterator end = managers.end();
    for (Manager* m : managers) {
        if (m->getId() == manager_id) {
            m->setSalary(-getManagerSalary());
            m->SetEmployeesSalary(- getWorkersSalary());
            managers.erase(m);
            return;
        }
    }
/*
    while (start != end) {
        if ((*start)->getId() == manager_id) {
          (*start)->setSalary(-salary_manager);        //     Want to keep salary of the employees like they were
                                                          // after we erase them and add them again, according piazza
            (*start)->SetEmployeesSalary(-salary_employee);
            managers.erase(*start);
            return;
            // employees stay in the manager's group
        }
        ++start;
    }*/
    throw ManagerIsNotHired();
}
std::set<Manager *,compare>::iterator Workplace::getFirst() const {
    set<Manager *,compare>::iterator start = this->managers.begin();
    return start;
}
std::set<Manager *>::iterator Workplace::getLast() const {
    std::set<Manager *,compare>::iterator end = this->managers.end();
    return end;
}
std::set<Manager*,compare> Workplace::getManagerGroup()  const{
    return this->managers;
}






Manager* Workplace::findManager(unsigned int id) const {

    set<Manager*,compare>::iterator start = managers.begin();
    set<Manager*,compare>::iterator end = managers.end();

    while (start != end ){

        if ((*start)->getId() == id ){
            return *start;
        }
        ++start;

    }
    return nullptr;

}

bool Workplace::EmployeesAreInWorkplace(unsigned int employee1_id, unsigned int employee2_id) {

    std::set<Manager*,compare>::iterator start = managers.begin();
    std::set<Manager*,compare>::iterator end  = managers.end();
    bool employee1_in_workplace = false;
    bool employee2_in_workplace = false;
    while (start != end) {
        if ((*start)->findEmployee(employee1_id) != nullptr) {
            employee1_in_workplace =true;
        }
        if((*start)->findEmployee(employee2_id) != nullptr) {
            employee2_in_workplace = true;
        }
        ++start;
    }
    if (employee1_in_workplace == true && employee2_in_workplace == true) {
        return true;
    }
    else {
        return false;
    }

}
    ostream& mtm::operator<< (ostream& os, const Workplace& workplace) {

    string temp = workplace.getName();
    if (workplace.getManagerGroup().empty()) {
        os << "Workplace name - " << temp << endl;
    }
    else {
        os << "Workplace name - " << temp << " Groups:" << endl;
    }

    for (Manager* m1 : workplace.getManagerGroup()) {
        os << "Manager ";
        (m1)->printLong(os);
    }

    return os;

}



