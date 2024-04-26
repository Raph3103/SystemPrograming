
#ifndef VERSION1_SKILL_H
#define VERSION1_SKILL_H
#include <string>
//using std::string;
using namespace std;
#include <iostream>
#include <ostream>
#include "Exceptions.h"
namespace mtm {
    namespace {
        using std::string;
        using std::ostream;
    }

    class Skill {
    protected:
        unsigned int skill_id;
        string name;
        int mastery;


    public:
        Skill(unsigned int id, string name, int mastery);

        Skill() = default;

        ~Skill() = default;

        string getName() const;

        unsigned int getId() const ;

        int getRequiredPoints() const;

        Skill &operator=(const Skill &skill);

        friend bool operator==(const Skill & skill ,const Skill & skill2)  {          // without mtm::

            if (skill2.getId() == skill.getId()){
                return true;
            }
            return false;
        }


        bool operator<(const Skill &skill) const;

        bool operator>(const Skill &skill) const;

        bool operator>=(const Skill &skill) const;

        bool operator<=(const Skill &skill) const;

        bool operator!=(const Skill &skill) const;

         Skill operator++(int ); // has to be skill& ?
        Skill &operator+=(int points);

        friend ostream &operator<<(ostream &os, const Skill &skill)  {          // without mtm::


            string temp = skill.getName();

            return os << temp <<endl ;

        }






    };







    Skill operator+(const Skill &skill, int points);

    Skill operator+(int points, const Skill &skill);

    class compare_skill {

    public:

        bool operator()(Skill s1, Skill s2) const {
            return s2.getId() > s1.getId();
        }
    };
}
#endif //VERSION1_SKILL_H
