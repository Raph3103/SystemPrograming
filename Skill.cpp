#include "Skill.h"
using namespace mtm;


Skill:: Skill(unsigned int id, string name, int mastery){
    this->name = name;
    skill_id = id;
    this->mastery = mastery;

}



// functions down here in cpp file
string Skill::getName() const {
    return this->name;
}
unsigned int Skill::getId() const {
    return this->skill_id;
}
int Skill::getRequiredPoints() const {
    return this->mastery;
}




bool Skill::operator < (const Skill& skill) const {
    if (skill_id < skill.skill_id ){
        return true;
    }
    return false;
}

bool Skill::operator > (const Skill& skill) const {
    if (skill_id > skill.skill_id ){
        return true;
    }
    return false;
}

bool Skill::operator >= (const Skill& skill) const {
    if (*this > skill || this->getId() == skill.getId()  ){
        return true;
    }
    return false;
}
bool Skill::operator <= (const Skill& skill) const {
    if (*this < skill || this->getId() == skill.getId()  ){
        return true;
    }
    return false;
}


bool Skill::operator!=(const Skill& skill) const {

    if (this->getId() == skill.getId()){
        return false;
    }
    return true;
}

 Skill  Skill::operator++ (int ) {

    Skill temp(*this);
    mastery+=1;
    return temp;

}
Skill& Skill::operator+=( const int points){

    if (points < 0) {
        throw NegativePoints();
    }

    mastery+= points;
    return *this;
}
Skill mtm::operator+(const Skill& skill ,const int points){

    if (points<0){
        throw NegativePoints();
    }

    return Skill(skill)+= points;
    // remind to  check if we have to give new id, name and strength to the copy we create.
}
Skill mtm::operator+(const int points ,const Skill& skill){

    if (points<0){
        throw mtm::NegativePoints();
    }

    return Skill(skill)+= points;
    // remind to  check if we have to give new id, name and strength to the copy we create.
}

Skill& Skill::operator=(const Skill &skill1) {

    skill_id = skill1.getId();
    mastery = skill1.getRequiredPoints();
    name = skill1.getName();
    return *this;
}

