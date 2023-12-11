#include "patient.h"

Patient::Patient(){
    m_hospital = NULL;
}
Patient::Patient(Person person, vector<char*>& symptoms, vector<char*>& allergies){

    m_person = person;
    m_symptoms = symptoms;
    m_allergies = allergies;

}

Person Patient::getPatientInfo(){
    return m_person;
}
void Patient::add_hospital(Hospital* hospital){
    m_hospital = hospital;
}
void Patient::getHospitalInfo(){
    std::cout<<"Name: "<<m_hospital->get_hospital_name()<<", address: "<<m_hospital->get_hospital_address()<<", contact: "<<m_hospital->get_hospital_contact()<<endl;
}
void Patient::changeHospital(Hospital* hospital){
    // Remove the doctor from the current hospital
    if (m_hospital != NULL) {
        char* id = m_hospital->getPatientID(this);
        m_hospital->remove_DeadPatient(id);
    }
    // Set the new associated hospital
    m_hospital = hospital;
    // Add the doctor to the new hospital
    if (m_hospital != NULL) {
        m_hospital->add_patient("newPatient-ID",this,"drST-rec");
    }
}
ostream& operator<< (ostream& os, const Patient& patient){
    os << patient.m_person <<endl;
    os << "Symptoms: " << endl;
    for (int i = 0; i < patient.m_symptoms.size(); i++) {
        //os << "    -" << i + 1 << ": " << *(patient.m_symptoms->at(i)) << endl;
        os << "    -" << patient.m_symptoms[i] << endl;
    }
    os << "Allergies: " << endl;
    for (int i = 0; i < patient.m_allergies.size(); i++) {
        os << "    -" << patient.m_allergies[i] << endl;
    }
    os << endl;
    return os;
}

