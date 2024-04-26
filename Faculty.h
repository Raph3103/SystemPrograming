//
// Created by 33769 on 07/01/2022.
//

#ifndef VERSION1_FACULTY_H
#define VERSION1_FACULTY_H
//#include "Skill.h"
#include "Employee.h"
namespace mtm {

//    class Condition{
//    public:
//        virtual bool operator()(Employee* employee) = 0;
//
//
//    };
    class Condition {
    public:
        virtual bool operator() (Employee* employee) =0;
    };

   class Faculty_Base {
   public:
       virtual int getAddedPoints () const=0;
       virtual unsigned int getId () const=0;
       virtual Skill getSkill () const=0;
       virtual void teach (Employee* employee)const =0;
       virtual ~Faculty_Base()=default;
      // virtual Condition* getCondition () const=0  ;
    };

    template<class Condition>
    class Faculty : public Faculty_Base {



        unsigned int faculty_id;
        Condition *condition;
        Skill skill;
        int added_points;

    public:

        Faculty(unsigned int id, const Skill& skill1, int new_points,Condition* new_condition) :
                faculty_id(id), condition(new_condition), skill(skill1), added_points(new_points) {
        }

        int getAddedPoints () const override;
        ~Faculty()=default;
        unsigned int getId () const override;
        Skill getSkill () const override;
        void teach(Employee *employee) const override ;


    };


   // template<class Condition>


//        faculty_id = id;
//        condition = new_condition;
//        skill= skill1;
//        added_points = new_points;



    template<class Condition>
  int Faculty<Condition>::getAddedPoints() const  {

      return this->added_points;
  }

    template<class Condition>
    unsigned int Faculty<Condition>::getId() const  {

        return this->faculty_id;
    }

    template<class Condition>
    Skill Faculty<Condition>::getSkill() const  {

        return this->skill;
    }
    template<class Condition>
    void Faculty<Condition>::teach(Employee *employee) const  {


    if ((*condition)(employee)) {   // good parameter to condition ?
    employee->learnSkill(skill);
    employee->setScore(added_points);
}
else {
throw EmployeeNotAccepted();
}
}


}
#endif //VERSION1_FACULTY_H
