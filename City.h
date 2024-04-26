
#ifndef VERSION1_CITY_H
#define VERSION1_CITY_H
#include "Workplace.h"
//#include "Employee.h"
//#include "Skill.h"
#include "Faculty.h"
//#include "Citizen.h"
namespace mtm {


    class City {


        std::set<Workplace*> workplaces;
        std::set<Citizen*,compare> citizens;

        std::set<Faculty_Base*> faculties;
        std::set<Employee*,compare> employees;
        std::set<Manager*,compare> managers;


        string city_name;

    public:

        explicit City (string name);

        ~City() {
            for (Employee* e1 : employees) {

                delete e1;
            }
            for (Manager* m1 : managers) {
                delete m1;
            }
            //workplaces.clear();
              for (Workplace* w1 : workplaces) {
               //w1->getManagerGroup().clear();
              delete w1;
            }
            for (Faculty_Base* f1 : faculties) {
                delete f1;
            }

        }

        City& addEmployee (unsigned int id, string first_name, string last_name, int birth_year);

       Citizen* findCitizen (unsigned int id) const;

        Employee* findEmployee (unsigned int id) const;

        Manager* findManager (unsigned int id) const;

       Workplace* findWorkplace (unsigned int id) const;

       City& addManager (int id, string first_name, string last_name, int birth_year);
        template<typename Condition>
       City& addFaculty (unsigned int id ,Skill& skill , int new_points,Condition* new_condition);

        City& createWorkplace (unsigned int id, string name, int salary_for_employee, int salary_for_manager);

       // template<class Condition>
       City& teachAtFaculty (unsigned int employee_id, unsigned int faculty_id);
        template<class Condition>
        City& hireEmployeeAtWorkplace (Condition condition, unsigned int employee_id,
                                      unsigned int manager_id,unsigned int workplace_id);

        City& hireManagerAtWorkplace (unsigned int manager_id, unsigned int workplace_id);

       City& fireEmployeeAtWorkplace (unsigned int employee_id,unsigned int manager_id,unsigned int workplace_id);

        City& fireManagerAtWorkplace (unsigned int manager_id, unsigned int workplace_id);

       int getAllAboveSalary (ostream& os, int above_salary);

       bool isWorkingInTheSameWorkplace (unsigned int employee1_id, unsigned int employee2_id) const;

       void printAllEmployeesWithSkill (ostream& os, unsigned int skill_id);



    };


    template <typename Condition>

    City& City::addFaculty(unsigned int id, Skill &skill, int new_points, Condition *new_condition) {

        // Faculty<Condition>* faculty = new Faculty<Condition>(id,skill,new_points,new_condition);

       // std::set<FB*>::iterator start = faculties.begin();
       // FB* == shared_ptr<FB>
        std::set<Faculty_Base*>::iterator start = faculties.begin();
        std::set<Faculty_Base*>::iterator end = faculties.end();


        while (start != end ){

            if ((*start)->getId() == id ){

                throw FacultyAlreadyExists();
            }
            ++start;

        }
        Faculty<Condition>* faculty = new Faculty<Condition>(id,skill,new_points,new_condition);


        this->faculties.insert(faculty);
        return *this;
    }
    template<class Condition>
    City& City::hireEmployeeAtWorkplace(Condition condition, unsigned int employee_id, unsigned int manager_id,
                                       unsigned int workplace_id) {

        Employee* employee = this->findEmployee(employee_id);
        Manager* manager = this->findManager(manager_id);
        Workplace* workplace = this->findWorkplace(workplace_id);

        if( employee == nullptr) {
            throw EmployeeDoesNotExist();
        }
        if (manager == nullptr) {
            throw ManagerDoesNotExist();
        }
        if (workplace == nullptr){
            throw WorkplaceDoesNotExist();
        }
        workplace-> hireEmployee(condition,employee,manager_id);
        return *this;

    }


}
#endif //VERSION1_CITY_H
