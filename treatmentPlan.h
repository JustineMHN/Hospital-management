#ifndef TREATMENTPLAN_H_INCLUDED
#define TREATMENTPLAN_H_INCLUDED

#include <vector>
#include "date.h"
#include "patient.h"

class TreatmentPlan{
private:
    char* m_type;
    vector<char*> m_description;
    Date m_date;

public:
    TreatmentPlan();

    bool add_tPlan(char* type, vector<char*> description, Date date);
    bool update_tPlan(char* type,vector<char*> description, Date date);

    friend ostream& operator<< (ostream&, const TreatmentPlan&);
};

#endif // TREATMENTPLAN_H_INCLUDED
