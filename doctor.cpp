#include "doctor.h"

Doctor::Doctor(){
    m_hospital = NULL;
}

Doctor::Doctor(Person person, char* speciality, int year_experience){

    m_person = person;

    m_speciality = new char[strlen(speciality) + 1];
    strcpy(m_speciality, speciality);

    m_year_experience = year_experience;

}

Person Doctor::getDoctorInfo(){
    return m_person;
}
char* Doctor::getSpeciality(){
    return m_speciality;
}
int Doctor::getYearExperience(){
    return m_year_experience;
}
void Doctor::add_hospital(Hospital* hospital){
    m_hospital = hospital;
}
void Doctor::getHospitalInfo(){
    std::cout<<"Name: "<<m_hospital->get_hospital_name()<<", address: "<<m_hospital->get_hospital_address()<<", contact: "<<m_hospital->get_hospital_contact()<<endl;
}
void Doctor::changeHospital(Hospital* hospital){
    // Remove the doctor from the current hospital
    if (m_hospital != NULL) {
        char* id = m_hospital->getDoctorID(this);
        m_hospital->remove_doctor(id);
    }
    // Set the new associated hospital
    m_hospital = hospital;
    // Add the doctor to the new hospital
    if (m_hospital != NULL) {
        m_hospital->add_doctor("newDoctor-ID",this,0.0,Date());
    }
}
ostream& operator<< (ostream& os, const Doctor& doctor){
        //static int count = 0;
        //os<<"Doctor "<<++count<<endl;
        os<<doctor.m_person;
        os<<", speciality: ";
        os<<doctor.m_speciality;
        os<<", year_experience: ";
        os<<doctor.m_year_experience;
        return os;
}
