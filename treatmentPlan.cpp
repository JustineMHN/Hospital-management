#include "treatmentPlan.h"

TreatmentPlan::TreatmentPlan(){
    m_type = NULL;
}
bool TreatmentPlan::add_tPlan(char* type, vector<char*> description, Date date){

    m_type = new char[strlen(type) + 1];
    strcpy(m_type, type);

    m_description = description;

    m_date = date;

}
bool TreatmentPlan::update_tPlan(char* type, vector<char*> description, Date date){
    delete[] m_type;

    m_type = new char[strlen(type) + 1];
    strcpy(m_type, type);

    m_description = description;

    m_date = date;
}

ostream& operator<< (ostream& os, const TreatmentPlan& tp) {
    os << "Type: " << tp.m_type << endl;
    os << "Description: "<<endl;
    for (int i = 0; i < tp.m_description.size(); ++i) {
        os << "     "<< tp.m_description[i] << endl;
    }
    os << endl;
    os << "Date: " << tp.m_date << endl;
    return os;
}


