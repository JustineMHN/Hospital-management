#ifndef DIAGNOSIS_H_INCLUDED
#define DIAGNOSIS_H_INCLUDED

#include <vector>
#include <ostream>

using namespace std;

class Diagnosis{
private:
    int m_blood_pressure;
    int m_heart_rate;
    int m_respiratory_rate;
    int m_temperature;
    vector<char*> m_test;
    vector<char*> m_result;


public:
    Diagnosis();

    void add_examination(int bp, int hr, int rr, int tmp);
    void add_diagnosis(vector<char*> test, vector<char*> result);

    /**Getters*/
    int getBloodPressure();
    int getHeartRate();
    int getRespiratoryRate();
    int getTemperature();
    vector<char*> getTest();
    vector<char*> getResult();

    /**Setters*/
    void setBloodPressure(int blood_pressure);
    void setHeartRate(int heart_rate);
    void setRespiratoryRate(int respiratory_rate);
    void setTemperature(int temperature);

    friend ostream& operator<<(ostream& os, const Diagnosis& diagnosis);

};


#endif // DIAGNOSIS_H_INCLUDED
