#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED

#include <iostream>
#include <ostream>
#include "address.h"
#include "date.h"
#include "person.h"
#include "patient.h"
#include "nurse.h"
#include "diagnosis.h"
#include "treatmentPlan.h"

using namespace std;


class Doctor; // Forward declaration of the Doctor class To establish a bidirectional relationship between the Doctor and Hospital classes;
class Patient; // Forward declaration of the Patient class 
class Nurse; // Forward declaration of the Nurse class

class Hospital
{
private:
    // Private data members
    char* m_name;
    Address m_address;    // hospital's contact
    char* m_contact;
    struct Hospital_patient{
        char* m_id;
        Patient* m_patient;
        Diagnosis* m_diagnosis;
        TreatmentPlan* m_tPlan;
        char* m_doctorName;
        Hospital_patient* next;
    };

    struct Hospital_doctor{
            char* m_id;
            Doctor* m_doctor;
            double m_salary;
            Date m_hireDate;
            Hospital_doctor* next;
            Hospital_patient* dpHead;
    };

    struct Hospital_nurse{
        char* m_id;
        Nurse* m_nurse;
        double m_salary;
        Date m_hireDate;
        Hospital_nurse* next;
    };

    Hospital_patient* hpHead;
    Hospital_doctor* hdHead;
    Hospital_nurse* hnHead;


public:
    // Constructor
    Hospital(char* name, Address& address, char* contact);


    bool add_doctor(char* doc_id, Doctor* doctor, double salary, Date hireDate);
    void setDoctor_info(char* doc_id, double salary, Date hireDate, Doctor *doctor); // modify information about the new doctor's move to another hospital
    bool remove_doctor(char* doc_id);
    bool search_doctor(char* doc_id);
    void printDoctor();
    char* getDoctorID(Doctor* doctor);
    void print_doctor_patients_list(char* doc_id);
    bool search_doctor(char* did, Hospital_doctor*& where);
    void set_patient_examination(char* pid, char* examinatorID, int bp, int hr, int rr, int tmp);
    void add_patient_diagnostic(char* pid, char* examinatorID, vector<char*> test, vector<char*> result);
    void add_patient_treatmentPlan(char* pID, char* examinatorID, char* type, vector<char*> description, Date date);

    bool add_patient(char* id, Patient* patient, char* careGiverName);
    void setPatient_info(char* id, char* careGiverName,Patient* patient);
    bool search_patient(char* pid);
    bool search_patient(char* pid, Hospital_doctor*& where);
    bool remove_DeadPatient(char* pid);
    void printPatient();
    char* getPatientID(Patient* patient);
    void getExamination(char* pid);
    void getPrescription(char* pid);

    bool add_nurse(char* id, Nurse* nurse, double salary, Date hireDate);
    bool remove_nurse(char* id);
    bool search_nurse(char* id) const;
    void printNurse();


    /**Getters*/
    Address get_hospital_address();
    char* get_hospital_contact();
    char* get_hospital_name();


    // Friend function to overload the << operator for output
    friend ostream& operator<< (ostream&, const Hospital&);
    //friend class Doctor;


};


#endif // HOSPITAL_H_INCLUDED
