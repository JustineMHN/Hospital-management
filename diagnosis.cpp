#include "diagnosis.h"

Diagnosis::Diagnosis(){


}
void Diagnosis::add_examination(int bp, int hr, int rr, int tmp){
    m_blood_pressure = bp;
    m_heart_rate = hr;
    m_respiratory_rate = rr;
    m_temperature = tmp;
}
void Diagnosis::add_diagnosis(vector<char*> test, vector<char*> result){
    m_test = test;
    m_result = result;
}
int Diagnosis::getBloodPressure(){

    return m_blood_pressure;
}
int Diagnosis::getHeartRate(){
    return m_heart_rate;
}
int Diagnosis::getRespiratoryRate(){
    return m_respiratory_rate;
}
int Diagnosis::getTemperature(){
    return m_temperature;
}
vector<char*> Diagnosis::getTest(){
    return m_test;
}
vector<char*> Diagnosis::getResult(){
    return m_result;
}
void Diagnosis::setBloodPressure(int blood_pressure){
    m_blood_pressure = blood_pressure;
}
void Diagnosis::setHeartRate(int heart_rate){
    m_heart_rate = heart_rate;
}
void Diagnosis::setRespiratoryRate(int respiratory_rate){
    m_respiratory_rate = respiratory_rate;
}
void Diagnosis::setTemperature(int temperature){
    m_temperature = temperature;
}
ostream& operator<<(ostream& os, const Diagnosis& diagnosis){
    os<<"Blood pressure: "<<diagnosis.m_blood_pressure<<" mmHg, ";/**millimeters of mercury (mmHg)*/
    os<<"heart rate: "<<diagnosis.m_heart_rate<<" bpm, "; /**beats per minute (bpm)*/
    os<<"respiratory rate: "<<diagnosis.m_respiratory_rate<<" bpm, ";/**breaths per minute (bpm)*/
    os<<"temperature: "<<diagnosis.m_temperature<<"°C "<<endl;/**Celsius*/
    if (!diagnosis.m_test.empty())
    {
        os<<"Tests: "<<endl;
        for (int i = 0; i < diagnosis.m_test.size(); i++)
        {
            os<<"   - "<<diagnosis.m_test[i]<<endl;
        }
        os<<"Results: ";
        for (int i = 0; i < diagnosis.m_result.size(); i++)
        {
            os<<" "<<diagnosis.m_result[i];
        }
    }
    os<<endl;
    return os;

}
