#ifndef DOCTOR
#define DOCTOR

#include <iostream>
#include <string.h>
#include "date.h"
#include "person.h"
#include "patient.h"
#include "hospital.h"

using namespace std;

class Doctor{
     private:
        /** Data members*/
        Person m_person;
        char* m_speciality;
        int m_year_experience;
        Hospital* m_hospital;

    public:
        Doctor();
        Doctor(Person person, char* speciality, int m_year_experience);

        /**Getters*/
        Person getDoctorInfo();
        char* getSpeciality();
        int getYearExperience();
        void add_hospital(Hospital* hospital);
        void getHospitalInfo();
        void changeHospital(Hospital* hospital);

        /**Friend function to overload the << operator for output*/
        friend ostream& operator<< (ostream&, const Doctor&);


};
#endif //DOCTOR
