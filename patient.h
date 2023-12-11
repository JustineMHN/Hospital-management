#ifndef PATIENT
#define PATIENT

#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "hospital.h"

using namespace std;

class Patient{
        Person m_person;
        vector<char*> m_symptoms;
        vector<char*> m_allergies;
        Hospital* m_hospital;

    public:
        Patient();
        Patient(Person person, vector<char*>& symptoms, vector<char*>& m_allergies);

        /**Getters*/
        Person getPatientInfo();
        vector <char*> getSymptoms();
        vector <char*> getAllergies();
        void add_hospital(Hospital* hospital);
        void getHospitalInfo();
        void changeHospital(Hospital* hospital);


        friend ostream& operator<< (ostream&, const Patient&);

};
#endif //PATIENT
