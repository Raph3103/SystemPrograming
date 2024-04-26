//
// Created by 33769 on 30/12/2021.
//

#ifndef VERSION1_CITIZEN_H
#define VERSION1_CITIZEN_H

#include <string>
//using std::string;
using namespace std;
#include <iostream>
#include <ostream>
#include "Exceptions.h"

namespace mtm {
    namespace {
        using std::string;

    }



    class Citizen  {



        unsigned int citizen_id;
        string first_name;
        string last_name;
        unsigned int birth_year;

    public:
        Citizen(unsigned int id, string first_name, string last_name, unsigned int birth_year) {
            this->citizen_id = id;
            this->first_name = first_name;
            this->last_name = last_name;
            this->birth_year = birth_year;

        }

        Citizen() = default;

        virtual ~Citizen() = default;

      //  unsigned int getId() const;

       // string getFirstName() const;

     //   string getLastName() const;

      //  unsigned int getBirthYear() const;

        virtual ostream &printShort(ostream &os) { // protected ?
            os << endl;
            return os;
        }

        virtual ostream &printLong(ostream &os) {  // protected ?
            os << endl;
            return os;
        }

        virtual Citizen *clone() const = 0;


        bool operator<(const Citizen &citizen) const;

        bool operator>(const Citizen &citizen) const;

        bool operator>=(const Citizen &citizen) const;

      bool operator<=(const Citizen &citizen) const;

        bool operator!=(const Citizen &citizen) const;
        bool operator==(const Citizen &citizen) const;

        unsigned int getId() const ;

        string getFirstName() const ;

        string getLastName() const ;

        unsigned int getBirthYear() const ;





    };
 //   bool operator==(const Citizen &citizen, const Citizen &citizen1);
 /*bool operator==(const Citizen &citizen, const Citizen &citizen1) {

     if (citizen.getId() == citizen1.getId()) {
         return true;
     }
     return false;
 }
*/

    class compare {

    public:

        bool operator() ( Citizen* c1 , Citizen* c2) const
        {
            return c2->getId() > c1->getId();
        }
    };

}




#endif //VERSION1_CITIZEN_H
