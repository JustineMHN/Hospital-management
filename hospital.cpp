#include "hospital.h"

Hospital::Hospital(char *name, Address &address, char *contact)
{
    hdHead = NULL;
    hpHead = NULL;
    hnHead = NULL;

    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);

    m_address = address;

    m_contact = new char[strlen(contact) + 1];
    strcpy(m_contact, contact);
}

char *Hospital::get_hospital_name()
{
    return m_name;
}

Address Hospital::get_hospital_address()
{
    return m_address;
}

char *Hospital::get_hospital_contact()
{
    return m_contact;
}

char *Hospital::getDoctorID(Doctor *doctor)
{
    Hospital_doctor *current = hdHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_doctor->getDoctorInfo().getFullname(), doctor->getDoctorInfo().getFullname()) == 0)
        {
            return current->m_id;
        }
        current = current->next;
    }
    return NULL; // Doctor not found
}

bool Hospital::search_doctor(char *did, Hospital_doctor *&where)
{
    Hospital_doctor *currentDoc = hdHead;
    while (currentDoc != NULL)
    {
        Hospital_patient *currentDoctor = currentDoc->dpHead;
        while (currentDoctor != NULL)
        {
            if (strcasecmp(currentDoctor->m_id, did) == 0)
            {
                where = currentDoc; // Assign the matching doctor to 'where' parameter
                return true;        // Patient found
            }
            currentDoctor = currentDoctor->next;
        }
        currentDoc = currentDoc->next;
    }
    return false; // Patient not found
}

bool Hospital::add_doctor(char *doc_id, Doctor *doctor, double salary, Date hireDate)
{
    Hospital_doctor *newdoctor = new Hospital_doctor;

    newdoctor->m_id = new char[strlen(doc_id) + 1];
    strcpy(newdoctor->m_id, doc_id);

    newdoctor->m_doctor = doctor;

    newdoctor->m_salary = salary;
    newdoctor->m_hireDate = hireDate;

    newdoctor->next = NULL;
    newdoctor->dpHead = NULL;
    doctor->add_hospital(this);

    if (hdHead == NULL)
    {
        hdHead = newdoctor;
        return true;
    }
    else
    {
        if (strcasecmp(hdHead->m_doctor->getDoctorInfo().getFullname(), doctor->getDoctorInfo().getFullname()) > 0)
        {
            newdoctor->next = hdHead;
            hdHead = newdoctor;
            return true;
        }
        else if (strcasecmp(hdHead->m_doctor->getDoctorInfo().getFullname(), doctor->getDoctorInfo().getFullname()) == 0)
        {
            std::cout << "*******************************************************************************************" << endl;
            std::cerr << "Doctor " << doctor->getDoctorInfo().getFullname() << " duplicated, insertion failed." << endl;
            delete newdoctor; // Clean up the allocated memory
        }
        else
        {
            Hospital_doctor *current = hdHead;
            while (current->next != NULL && strcasecmp(current->next->m_doctor->getDoctorInfo().getFullname(), doctor->getDoctorInfo().getFullname()) < 0)
            {
                current = current->next;
            }
            if (current->next != NULL && strcasecmp(current->next->m_doctor->getDoctorInfo().getFullname(), doctor->getDoctorInfo().getFullname()) == 0)
            {
                std::cout << "*******************************************************************************************" << endl;
                std::cerr << "Doctor " << doctor->getDoctorInfo().getFullname() << " duplicated, insertion failed." << endl;
                delete newdoctor; // Clean up the allocated memory
            }
            else
            {
                newdoctor->next = current->next;
                current->next = newdoctor;
                return true;
            }
        }
    }
}

bool Hospital::add_patient(char *id, Patient *patient, char *careGiverID)
{

    Hospital_patient *newpatient = new Hospital_patient;

    newpatient->m_id = new char[strlen(id) + 1];
    strcpy(newpatient->m_id, id);

    newpatient->m_patient = patient;

    newpatient->m_doctorName = new char[strlen(careGiverID) + 1];
    strcpy(newpatient->m_doctorName, careGiverID);
    newpatient->next = NULL;

    Hospital_doctor *currentDoc = hdHead;

    while (currentDoc != NULL)
    {
        if (strcasecmp(currentDoc->m_id, careGiverID) == 0)
        {
            if (hpHead == NULL)
            {
                hpHead = newpatient;
            }
            else
            {
                if (strcasecmp(hpHead->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) > 0)
                {
                    newpatient->next = hpHead;
                    hpHead = newpatient;
                }
                else if (strcasecmp(hpHead->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) == 0)
                {
                    std::cout << "*******************************************************************************************" << endl;
                    std::cerr << "Patient " << patient->getPatientInfo().getFullname() << " duplicated, insertion failed." << endl;
                    delete newpatient; // Clean up the allocated memory
                    return false;
                }
                else
                {
                    Hospital_patient *current = hpHead;
                    while (current->next != NULL && strcasecmp(current->next->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) < 0)
                    {
                        current = current->next;
                    }
                    if (current->next != NULL && strcasecmp(current->next->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) == 0)
                    {
                        std::cout << "*******************************************************************************************" << endl;
                        std::cerr << "Patient " << patient->getPatientInfo().getFullname() << " duplicated, insertion failed." << endl;
                        delete newpatient; // Clean up the allocated memory
                        return false;
                    }
                    else
                    {
                        current->next = newpatient;
                    }
                }
            }

            // Insert the current patient in the doctor's patient list
            if (currentDoc->dpHead == NULL)
            {
                currentDoc->dpHead = newpatient;
            }
            else
            {
                if (strcasecmp(currentDoc->dpHead->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) > 0)
                {
                    newpatient->next = currentDoc->dpHead;
                    currentDoc->dpHead = newpatient;
                }
                else
                {
                    Hospital_patient *currentpatient = currentDoc->dpHead;
                    while (currentpatient->next != NULL && strcasecmp(currentpatient->next->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) < 0)
                    {
                        currentpatient = currentpatient->next;
                    }
                    currentpatient->next = newpatient;
                }
            }

            return true;
        }
        currentDoc = currentDoc->next;
    }
    std::cout << "*******************************************************************************************" << endl;
    std::cout << "Failed to insert patient " << patient->getPatientInfo().getFullname() << " because doctor " << careGiverID << " does not exit in this hospital(" << m_name << "). Available doctors are: " << endl;
    Hospital_doctor *current = hdHead;
    while (current != NULL)
    {
        std::cout << current->m_id << ", " << current->m_doctor->getDoctorInfo().getFullname() << ", " << current->m_doctor->getSpeciality() << endl;
        current = current->next;
    }
    return false;
}

void Hospital::setDoctor_info(char *doc_id, double salary, Date hireDate, Doctor *doctor)
{
    Hospital_doctor* current = hdHead;
    while (current)
    {
        if (strcasecmp(current->m_doctor->getDoctorInfo().getFullname(), doctor->getDoctorInfo().getFullname()) == 0)
        {
            delete[] current->m_id;
            current->m_id = new char[strlen(doc_id)+1];
            strcpy(current->m_id, doc_id);
            current->m_salary = salary;
            current->m_hireDate = hireDate;
            return;
        }
        current = current->next;
        
    }
    std::cerr<<"Setting doctor informations failed: doctor not found"<<endl;
}

bool Hospital::remove_doctor(char *id)
{
    Hospital_doctor *current = hdHead;
    Hospital_doctor *prev = NULL;

    /** Traverse the list to find the doctor with the given ID*/
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, id) == 0)
        {
            /** Doctor found, remove it from the list*/
            if (prev == NULL)
            {
                /** The doctor is the first node in the list*/
                hdHead = current->next;
            }
            else
            {
                /**The doctor is in the middle of the list*/
                prev->next = current->next;
            }

            /**Delete the doctor and free memory*/
            delete[] current->m_id;
            delete current;
            return true;
        }

        /**Move to the next node*/
        prev = current;
        current = current->next;
    }

    return false; // Doctor not found
}

bool Hospital::search_doctor(char *id)
{
    Hospital_doctor *current = hdHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, id) == 0)
        {
            // Doctor found
            std::cout << " Results of doctor " << id << " search:" << endl;
            std::cout << current->m_doctor;
            return true;
        }
        current = current->next;
    }
    std::cout << id << " not found";
    return false; // Doctor not found
}

bool Hospital::search_patient(char *pid, Hospital_doctor *&where)
{
    Hospital_doctor *currentDoc = hdHead;
    while (currentDoc != NULL)
    {
        Hospital_patient *currentPatient = currentDoc->dpHead;
        while (currentPatient != NULL)
        {
            if (strcasecmp(currentPatient->m_id, pid) == 0)
            {
                where = currentDoc; // Assign the matching doctor to 'where' parameter
                return true;        // Patient found
            }
            currentPatient = currentPatient->next;
        }
        currentDoc = currentDoc->next;
    }
    return false; // Patient not found
}

bool Hospital::search_patient(char *id)
{
    Hospital_patient *current = hpHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, id) == 0)
        {
            // Patient found
            std::cout << " Results of patient " << id << " search:" << endl;
            std::cout << current->m_patient;
            std::cout << " Care giver name: " << current->m_doctorName;
            return true;
        }
        current = current->next;
    }
    std::cout << "Patient " << id << " not found";
    return false; // Patient not found
}

void Hospital::printDoctor()
{
    Hospital_doctor *doctor = hdHead;
    std::cout << m_name << " doctors list: " << endl;
    while (doctor != NULL)
    {
        std::cout << "Doctor :" << doctor->m_id << endl;
        std::cout << *doctor->m_doctor << endl;
        std::cout << "Hire date: " << doctor->m_hireDate;
        std::cout << "Salary: " << doctor->m_salary << endl;
        std::cout << endl;
        doctor = doctor->next;
    }
    std::cout << "*******************************************************************************************" << endl;
}

void Hospital::print_doctor_patients_list(char *doc_id)
{
    Hospital_doctor *current = hdHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, doc_id) == 0)
        {
            std::cout << "Hospital: " << m_name << endl;
            Hospital_patient *patient = current->dpHead;
            std::cout << "Doctor  " << doc_id << "(" << current->m_doctor->getDoctorInfo().getFullname() << ") patients:" << endl;
            while (patient != NULL)
            {
                std::cout << "Patient: " << patient->m_id << endl;
                std::cout <<*patient->m_patient << endl;
                patient = patient->next;
            }
            break; // Exit the loop after printing the patients for the specified doctor
        }
        current = current->next;
    }
    std::cout << "*******************************************************************************************" << endl;
}

void Hospital::set_patient_examination(char *pid, char *examinatorID, int bp, int hr, int rr, int tmp)
{
    Hospital_doctor *current = hdHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, examinatorID) == 0)
        {
            Hospital_patient *patient = current->dpHead;
            while (patient != NULL)
            {
                if (strcasecmp(patient->m_id, pid) == 0)
                {
                    // Allocate memory for the Diagnosis object
                    Diagnosis *diagnosis = new Diagnosis();
                    patient->m_diagnosis = diagnosis;
                    patient->m_diagnosis->add_examination(bp, hr, rr, tmp);
                    break;
                }
                patient = patient->next;
            }
            break;
        }
        current = current->next;
    }
}

void Hospital::add_patient_diagnostic(char *pid, char *examinatorID, vector<char *> test, vector<char *> result)
{
    Hospital_doctor *current = hdHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, examinatorID) == 0)
        {
            Hospital_patient *patient = current->dpHead;
            while (patient != NULL)
            {
                if (strcasecmp(patient->m_id, pid) == 0)
                {
                    patient->m_diagnosis->add_diagnosis(test, result);
                    break;
                }
                patient = patient->next;
            }
            break;
        }
        current = current->next;
    }
}

void Hospital::add_patient_treatmentPlan(char *pid, char *examinatorID, char *type, vector<char *> description, Date date)
{
    Hospital_doctor *doctor = NULL;
    bool result = search_patient(pid, doctor);
    if (result && strcasecmp(doctor->m_id, examinatorID) == 0)
    {
        Hospital_patient *patient = doctor->dpHead;
        while (patient != NULL)
        {
            if (strcasecmp(patient->m_id, pid) == 0)
            {
                // Allocate memory for the TreatmentPlan object
                TreatmentPlan *treatmentPlan = new TreatmentPlan();
                patient->m_tPlan = treatmentPlan;
                patient->m_tPlan->add_tPlan(type, description, date);
                break;
            }
            patient = patient->next;
        }
    }
    std::cerr << "Patient " << pid << " not found" << std::endl;
}

void Hospital::getExamination(char *pid)
{
    Hospital_doctor *doctor = NULL;
    bool result = search_patient(pid, doctor);
    if (result)
    {
        Hospital_patient *patient = doctor->dpHead;
        std::cout << "Patient " << pid << " examination: " << endl;
        while (patient != NULL)
        {
            if (strcasecmp(patient->m_id, pid) == 0)
            {
                std::cout << *patient->m_diagnosis;
                std::cout << endl;
                return;
            }
            patient = patient->next;
        }
        return;
    }
    std::cerr << "Patient " << pid << " not found" << std::endl;
}

void Hospital::getPrescription(char *pid)
{
    Hospital_doctor *doctor = NULL;
    bool result = search_patient(pid, doctor);
    if (result)
    {
        Hospital_patient *patient = doctor->dpHead;
        std::cout << "Patient " << pid << " treatment plan: " << endl;
        while (patient != NULL)
        {
            if (strcasecmp(patient->m_id, pid) == 0)
            {
                std::cout << *patient->m_tPlan;
                return;
            }
            patient = patient->next;
        }
    }
    std::cerr << "Patient " << pid << " not found" << std::endl;
}

char* Hospital::getPatientID(Patient* patient){
     Hospital_patient *current = hpHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) == 0)
        {
            return current->m_id;
        }
        current = current->next;
    }
    return NULL; // Patient not found
}

void Hospital::setPatient_info(char* id, char* careGiverName,Patient* patient)
{
    Hospital_patient* current = hpHead;
    while (current)
    {
        if (strcasecmp(current->m_patient->getPatientInfo().getFullname(), patient->getPatientInfo().getFullname()) == 0)
        {
            delete[] current->m_id;
            delete[] current->m_doctorName;

            current->m_id = new char[strlen(id)+1];
            strcpy(current->m_id, id);

            current->m_doctorName = new char[strlen(careGiverName)+1];
            strcpy(current->m_doctorName, careGiverName);

            return;
        }
        current = current->next;
        
    }
    std::cerr<<"Setting patient informations failed: patient not found"<<endl;
}

bool Hospital::remove_DeadPatient(char *id)
{
    Hospital_patient *current = hpHead;
    Hospital_patient *prev = NULL;

    /** Traverse the list to find the doctor with the given ID*/
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, id) == 0)
        {
            /** Patient found, remove it from the list*/
            if (prev == NULL)
            {
                /** The doctor is the first node in the list*/
                hpHead = current->next;
            }
            else
            {
                /**The Patient is in the middle of the list*/
                prev->next = current->next;
            }

            /**Delete the Patient and free memory*/
            delete[] current->m_id;
            delete[] current->m_doctorName;
            delete current;
            return true;
        }

        /**Move to the next node*/
        prev = current;
        current = current->next;
    }

    return false; // Patient not found
}

void Hospital::printPatient()
{
    Hospital_patient *patient = hpHead;
    Hospital_doctor *doctor = hdHead;
    std::cout << m_name << " patients list: " << endl;
    while (patient != NULL)
    {
        std::cout << "Patient: " << patient->m_id << endl;
        std::cout << *patient->m_patient << endl;
        while (doctor != NULL)
        {
            if (strcasecmp(doctor->m_id, patient->m_doctorName) == 0)
            {
                std::cout << doctor->m_doctor->getDoctorInfo().getFullname() << endl;
            }
            doctor = doctor->next;
        }
        patient = patient->next;
    }
    std::cout << "*******************************************************************************************" << endl;
}

bool Hospital::add_nurse(char *id, Nurse *nurse, double salary, Date hDate)
{

    Hospital_nurse *newnurse = new Hospital_nurse;

    newnurse->m_id = new char[strlen(id) + 1];
    strcpy(newnurse->m_id, id);

    newnurse->m_nurse = nurse;

    newnurse->m_salary = salary;
    newnurse->m_hireDate = hDate;

    newnurse->next = NULL;

    if (hnHead == NULL)
    {
        hnHead = newnurse;
    }
    else
    {
        if (strcasecmp(hnHead->m_nurse->getNurseInfo().getFullname(), nurse->getNurseInfo().getFullname()) > 0)
        {
            hnHead = newnurse;
        }
        else if (strcasecmp(hnHead->m_nurse->getNurseInfo().getFullname(), nurse->getNurseInfo().getFullname()) == 0)
        {
            std::cerr << "Nurse " << nurse->getNurseInfo().getFullname() << " duplicated, insertion failed." << endl;
            delete newnurse; // Clean up the allocated memory
            return false;
        }
        else
        {
            Hospital_nurse *current = hnHead;
            while (current->next != NULL && strcasecmp(current->next->m_nurse->getNurseInfo().getFullname(), nurse->getNurseInfo().getFullname()) < 0)
            {
                current = current->next;
            }
            if (current->next != NULL && strcasecmp(current->next->m_nurse->getNurseInfo().getFullname(), nurse->getNurseInfo().getFullname()) == 0)
            {
                std::cerr << "Nurse " << nurse->getNurseInfo().getFullname() << " duplicated, insertion failed." << endl;
                delete newnurse; // Clean up the allocated memory
                return false;
            }
            else
            {
                current->next = newnurse;
            }
        }
    }

    return true;
}

bool Hospital::remove_nurse(char *id)
{
    Hospital_nurse *current = hnHead;
    Hospital_nurse *prev = NULL;

    /** Traverse the list to find the Nurse with the given ID*/
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, id) == 0)
        {
            /** Nurse found, remove it from the list*/
            if (prev == NULL)
            {
                /** The Nurse is the first node in the list*/
                hnHead = current->next;
            }
            else
            {
                /**The Nurse is in the middle of the list*/
                prev->next = current->next;
            }

            /**Delete the Nurse and free memory*/
            delete[] current->m_id;
            delete current;
            return true;
        }

        /**Move to the next node*/
        prev = current;
        current = current->next;
    }

    return false; // Nurse not found
}

bool Hospital::search_nurse(char *id) const
{
    Hospital_nurse *current = hnHead;
    while (current != NULL)
    {
        if (strcasecmp(current->m_id, id) == 0)
        {
            // Doctor found
            std::cout << " Results of nurse " << id << " search:" << endl;
            std::cout << *current->m_nurse;
            return true;
        }
        current = current->next;
    }
    std::cout << id << " not found";
    return false; // Doctor not found
}

void Hospital::printNurse()
{
    Hospital_nurse *nurse = hnHead;
    std::cout << m_name << " nurses list: " << endl;
    while (nurse != NULL)
    {
        std::cout << "Nurse: " << nurse->m_id << endl;
        std::cout << *nurse->m_nurse << endl;
        std::cout << "Hire " << nurse->m_hireDate;
        std::cout << "Salary " << nurse->m_salary << endl;
        std::cout << endl;
        nurse = nurse->next;
    }
    std::cout << "*******************************************************************************************" << endl;
}

ostream &operator<<(ostream &os, const Hospital &hos)
{
    os << "****** HOSPITAL INFO *****";
    os << endl;
    os << "Name: " << hos.m_name << ", address: " << hos.m_address << ", contact: " << hos.m_contact << endl;
    os << endl;
    os << "**** DOCTORS LIST ****** ";
    Hospital::Hospital_doctor *doctor = hos.hdHead;
    os << endl;
    while (doctor != NULL)
    {
        os << "Doctor :" << doctor->m_id << endl;
        os << doctor->m_doctor << endl;
        os << "Hire date: " << doctor->m_hireDate;
        os << "Salary: " << doctor->m_salary << endl;
        os << endl;
        doctor = doctor->next;
    }
    os << "**** NURSES LIST****** ";
    Hospital::Hospital_nurse *nurse = hos.hnHead;
    os << endl;
    while (nurse != NULL)
    {
        os << "Nurse: " << nurse->m_id << endl;
        os << nurse->m_nurse << endl;
        os << "Hire " << nurse->m_hireDate;
        os << "Salary " << nurse->m_salary << endl;
        os << endl;
        nurse = nurse->next;
    }
    os << "**** PATIENTS LIST****** ";
    Hospital::Hospital_patient *patient = hos.hpHead;
    os << endl;
    while (patient != NULL)
    {
        os << "Patient: " << patient->m_id << endl;
        os << patient->m_patient << endl;
        while (doctor != NULL)
        {
            if (strcasecmp(doctor->m_id, patient->m_doctorName) == 0)
            {
                os << doctor->m_doctor->getDoctorInfo().getFullname() << endl;
            }
            doctor = doctor->next;
        }
        patient = patient->next;
    }
    os << "*******************************************************************************************" << endl;
    os << endl;
    return os;
}
