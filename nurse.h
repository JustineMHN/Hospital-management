#ifndef NURSE_H_INCLUDED
#define NURSE_H_INCLUDED

#include <ostream>
#include <string>
#include "person.h"
#include "hospital.h"

using namespace std;

class Nurse{
    private:
        Person m_person;
        int m_year_experience;
        //Hospital* m_hospital;

    public:
        /**Constructor*/
        Nurse();
        Nurse(Person person, int year_experience);

        /**Getters*/
        Person getNurseInfo();
        int getYearExperience();

        /** Friend function to overload the << operator for output*/
        friend ostream& operator<< (ostream&, const Nurse&);

};

#endif // NURSE_H_INCLUDED
