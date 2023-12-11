#include "nurse.h"

Nurse::Nurse(){
    //m_hospital = NULL;
}
Nurse::Nurse(Person person, int year_experience){
    m_person = person;

   m_year_experience =  year_experience;
}
Person Nurse::getNurseInfo(){
    return m_person;
}
int Nurse::getYearExperience(){
    return m_year_experience;
}
ostream& operator<< (ostream& os, const Nurse& nurse){
        os<<nurse.m_person;
        os<<", year_experience: ";
        os<<nurse.m_year_experience;
        os<<endl;
    return os;
}
