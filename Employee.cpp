#include"Employee.h"
using namespace mtm;


int Employee::getSalary() const {
    return salary;
}

int Employee::getScore() const {
    return points;
}

void Employee::learnSkill(const Skill &skill) {

    if (points < skill.getRequiredPoints()){
        throw CanNotLearnSkill();

    }
    std::set<Skill,compare_skill>::iterator start = Skills.begin(); // use auto ?
    std::set<Skill,compare_skill>::iterator end = Skills.end();

    while (start != end) /// don't forget the last value ?
    {
        if ((*start).getId() == skill.getId()){
            throw mtm::SkillAlreadyLearned();
        }
        ++start;
    }


    // Skill* new_skill = new Skill(skill.getId(),skill.getName(),skill.getRequiredPoints());
    Skills.insert(skill);
}


void Employee::forgetSkill(unsigned int id) {

    std::set<Skill,compare_skill>::iterator start = Skills.begin(); // use auto ?
    std::set<Skill,compare_skill>::iterator end = Skills.end();


    while (start != end) /// don't forget the last value ?
    {
        if ((*start).getId() == id) {

            Skills.erase(*start);

            return;

         //   delete [] *start;



        }
        ++start;
    }

    throw DidNotLearnSkill();

}


bool Employee::hasSkill(unsigned int id) {

    set<Skill,compare_skill>::iterator start = Skills.begin(); // use auto ?
    set<Skill,compare_skill>::iterator end = Skills.end();

    while (start != end) /// don't forget the last value ?
    {
        if ((*start).getId() == id){
            return true;
        }
        ++start;
    }
    return false;
}

void Employee::setSalary(int amount) {

    salary+= amount;
    if (salary < 0) {
        salary = 0;
    }
}

void Employee::setScore(int score_to_add) {
    points+= score_to_add;
    if (points < 0) {
        points = 0;
    }
}
ostream& Employee::printShort(ostream& os){
    os << this->getFirstName() << " " << this->getLastName() << endl;
    os << "Salary:" << " " << salary << " " << "Score: " << points << endl;
    return os;
}

ostream& Employee::printLong(ostream &os) {

    os << this->getFirstName() << " " << this->getLastName() << endl;
    os << "id - " << this->getId() << " " << "birth_year - " << this->getBirthYear() << endl;

    if (Skills.empty()) {
        os << "Salary:" << " " << salary << " " << "Score:" << " " << points << endl;
    }
    else {
        os << "Salary:" << " " << salary << " " << "Score:" << " " << points << " " << "Skills: "<< endl;
    }
    set<Skill,compare_skill>::iterator start = Skills.begin(); // use auto ?
    set<Skill,compare_skill>::iterator end = Skills.end();

    while (start != end) /// don't forget the last value ?
    {
        os << (*start).getName() << endl;
        ++start;
    }
    return os;
}
Employee* Employee::clone () const  {
    return new Employee(*this);
}
/*
Employee::Employee(const Employee& employee) : Citizen(employee),

        salary(employee.getSalary()),
        points(employee.getScore()),
        Skills(employee.Skills),


{

}
*/
