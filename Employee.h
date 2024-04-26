

#ifndef VERSION1_EMPLOYEE_H
#define VERSION1_EMPLOYEE_H

#include "Citizen.h"
#include "Skill.h"
#include <set>
#include <algorithm>

namespace mtm {
    class Employee : public Citizen {

        int salary;
        int points;
        std::set<Skill,compare_skill> Skills;

    public:
        Employee(unsigned int id, string first_name, string last_name, int birth_year) :
                Citizen(id, first_name, last_name, birth_year),
                salary(0), points(0), Skills()     //the right way to initalise the set ?
        {
        }

        ~Employee () override {

//                for (Skill *s1 : Skills) {
//
//                        delete s1;
//                }
                Skills.clear();
        }

        int getSalary() const;

        int getScore() const;

        void learnSkill(const Skill &skill);

        void forgetSkill(unsigned int id);

        bool hasSkill(unsigned int id);

        void setSalary(int amount);

        void setScore(int score_to_add);

        ostream &printShort(ostream &os) override; // protected ?

        ostream &printLong(ostream &os) override; // protected ?

        Employee *clone() const override;

        Employee(const Employee &employee) = default;
    };

}


#endif //VERSION1_EMPLOYEE_H
