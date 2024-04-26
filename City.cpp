#include "City.h"
using namespace mtm;


City::City(string name) {

    city_name = name;

    faculties = {};
    citizens = {};
    employees = {};
    managers = {};

}

City& City::addEmployee(unsigned int id, string first_name, string last_name, int birth_year) {

   //
    set<Citizen*,compare>::iterator start = citizens.begin();
    set<Citizen*,compare>::iterator end = citizens.end();

    while (start != end ){

        if ((*start)->getId() == id ){

            throw CitizenAlreadyExists();
        }
        ++start;

    }
    Employee* employee = new Employee(id,first_name,last_name,birth_year);
    this->citizens.insert(employee);
    this->employees.insert(employee);

    return *this;
}

City& City::addManager(int id, string first_name, string last_name, int birth_year) {

    if (findCitizen(id) != nullptr) {
        throw CitizenAlreadyExists();
    }
    Manager* manager = new Manager(id,first_name,last_name,birth_year);


    this->citizens.insert(manager);
    this->managers.insert(manager);
    return *this;
}






City& City::createWorkplace(unsigned int id, string name, int salary_for_employee, int salary_for_manager) {

     //ask if this is correct

    std::set<Workplace*>::iterator start = workplaces.begin();
    std::set<Workplace*>::iterator end = workplaces.end();

    while (start != end ) {

        if ((*start)->getID() == id){

            throw WorkplaceAlreadyExists();
        }
        ++start;

    }
    Workplace* workplace = new Workplace(id,name,salary_for_employee,salary_for_manager);
    workplaces.insert(workplace);
    return *this;
}




Citizen* City::findCitizen(unsigned int id) const {

    set<Citizen*,compare>::iterator start = citizens.begin();
    set<Citizen*,compare>::iterator end = citizens.end();

    while (start != end ){

        if ((*start)->getId() == id ){
            return *start;
        }
        ++start;

    }
    return nullptr;

}

Employee* City::findEmployee(unsigned int id) const {

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
Manager* City::findManager(unsigned int id) const {

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

Workplace* City::findWorkplace(unsigned int id) const {

    set<Workplace*>::iterator start = workplaces.begin();
    set<Workplace*>::iterator end = workplaces.end();

    while (start != end ){

        if ((*start)->getID() == id ){
            return *start;
        }
        ++start;

    }
    return nullptr;

}





City& City::hireManagerAtWorkplace(unsigned int manager_id, unsigned int workplace_id) {

    Manager* manager = this->findManager(manager_id);
    Workplace* workplace = this->findWorkplace(workplace_id);

    if (manager == nullptr){
        throw ManagerDoesNotExist();
    }
    if(workplace == nullptr){
        throw WorkplaceDoesNotExist();
    }

    workplace->hireManager(manager);
    managers.insert(manager);
    return *this;
}

City& City::fireEmployeeAtWorkplace(unsigned int employee_id, unsigned int manager_id, unsigned int workplace_id) {

    Manager* manager = this->findManager(manager_id);
    Workplace* workplace = this->findWorkplace(workplace_id);
    Employee* employee = this->findEmployee(employee_id);

    if (manager == nullptr){
        throw ManagerDoesNotExist();
    }
    if(workplace == nullptr){
        throw WorkplaceDoesNotExist();
    }
    if (employee == nullptr){
        throw EmployeeDoesNotExist();
    }

    workplace->fireEmployee(employee_id,manager_id);
    return *this;
}


City& City::fireManagerAtWorkplace(unsigned int manager_id, unsigned int workplace_id) {

    Manager* manager = findManager(manager_id);
    if (manager == nullptr){
        throw ManagerDoesNotExist();
    }
    Workplace* workplace = findWorkplace(workplace_id);
    if (workplace == nullptr){
        throw WorkplaceDoesNotExist();
    }
// manager->getEmployeesGroup().clear();
   for (Employee* e1 : manager->getEmployeesGroup()) {
       e1->setSalary(-(workplace->getWorkersSalary()));
       manager->removeEmployee(e1->getId());
   }
//manager->removeAllEmployees();

    workplace->fireManager(manager_id);
    return *this;
}


int City::getAllAboveSalary(ostream &os, int above_salary) {

    std::set<Citizen*,compare> citizens_above = {};
    int number_of_citizens_above = 0;
    for (Employee* e1 : employees) {                                    // maybe change all the while to for.
        if( (e1)->getSalary() >= above_salary) {
            citizens_above.insert(e1);
            number_of_citizens_above++;
        }

    }


    for (Manager* m1 : managers) {                                    // maybe change all the while to for.
       if( (m1)->getSalary() >= above_salary) {
           citizens_above.insert(m1);
           number_of_citizens_above++;
       }

    }
    for (Citizen* c1 : citizens_above) {                                    // maybe change all the while to for.

        c1->printShort(os);

    }
    return number_of_citizens_above;
}

bool City::isWorkingInTheSameWorkplace(unsigned int employee1_id, unsigned int employee2_id) const {

    Employee* employee1 = findEmployee(employee1_id);
    Employee* employee2 = findEmployee(employee2_id);
    if (employee1 == nullptr || employee2 == nullptr) {
        throw EmployeeDoesNotExist();
    }
    std::set<Workplace*>::iterator start = workplaces.begin();
    std::set<Workplace*>::iterator end = workplaces.end();

    while (start != end) {
        if((*start)->EmployeesAreInWorkplace(employee1_id,employee2_id) == true) {
            return true;
        }
        ++start;
    }
    return false;
}

void City::printAllEmployeesWithSkill(ostream &os,unsigned int skill_id) { // maybe skill not skill id

    std::set<Employee*,compare>::iterator start = employees.begin();
    std::set<Employee*,compare>::iterator end  = employees.end();

    while (start != end) {
        if( (*start)->hasSkill(skill_id) == true) {
            (*start)->printShort(os);
        }
        ++start;
    }
    // return os.
}


//template<class Condition>
City& City::teachAtFaculty(unsigned int employee_id, unsigned int faculty_id) {


    // try with find employee.
    Employee* employee = findEmployee(employee_id);
    if (employee == nullptr) {
        throw EmployeeDoesNotExist();
    }


    std::set<Faculty_Base*>::iterator start_faculty = faculties.begin();
    std::set<Faculty_Base*>::iterator end_faculty = faculties.end();

    while (start_faculty != end_faculty) {

        if ((*start_faculty)->getId() == faculty_id){

            (*start_faculty)->teach (employee);
            return *this;

        }
        ++start_faculty;
    }

    throw FacultyDoesNotExist ();



}