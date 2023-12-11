#include "person.h"

Person::Person(){
    m_fullname = NULL;
    m_gender = NULL;
    m_blood = NULL;
    m_contact = NULL;
    social_security_number = NULL;
}
Person::Person(char* fullname, char* gender, int birth_year, char* blood, Address& address, char* contact,char* ssn){
    m_fullname = new char[strlen(fullname) + 1];
    strcpy(m_fullname, fullname);

    m_gender = new char[strlen(gender) + 1];
    strcpy(m_gender, gender);

    m_birth_year = birth_year;

    m_blood = new char[strlen(blood) + 1];
    strcpy(m_blood, blood);

    m_address = address;

    m_contact = new char[strlen(contact) + 1];
    strcpy(m_contact, contact);

    social_security_number = new char[strlen(ssn) + 1];
    strcpy(social_security_number, ssn);
}

char* Person::getFullname(){
    return m_fullname;
}

char* Person::getGender(){
    return m_gender;
}
void Person::setContact(char* contact){
    delete[] m_contact;
    m_contact = new char[strlen(contact) + 1];
    strcpy(m_contact, contact);
}
char* Person::getContact(){
    return m_contact;
}
int Person::getAge()const{
    int age = 2023 - m_birth_year;
    return age;
}
char* Person::getBloodType(){
    return m_blood;
}
char* Person::getSSN(){
    return social_security_number;
}
Address Person::getAddress(){
    return m_address;
}
ostream& operator<<(ostream& os, const Person& person) {
    os<< "Fullname: ";
    os<<person.m_fullname;
    os<< ", gender: ";
    os<< person.m_gender;
    os<< ", age: ";
    os<<person.getAge();
    os<< ", blood: ";
    os<< person.m_blood;
    os<< ", address: ";
    os<< person.m_address;
    os<< ", contact: ";
    os<< person.m_contact;
    os<<", social security number ";
    os<< person.social_security_number;

    return os;
}
