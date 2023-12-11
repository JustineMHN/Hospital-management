#ifndef PERSON_H
#define PERSON_H

#include <string.h>
#include <ostream>
#include "address.h"

class Person
{
     private:
        char* m_fullname;
        char* m_gender;
        int m_birth_year;
        char* m_blood;
        Address m_address;
        char* m_contact;
        char* social_security_number;

    public:
        /** Constructors */
        Person();
        Person(char* fullname, char* gender, int birth_year, char* blood, Address& address, char* contact,char* ssn);

        /** Default destructor */
        //virtual ~Person();

        /**Getters*/
        char* getFullname();
        char* getGender();
        int getAge() const;
        char* getBloodType();
        char* getContact();
        char* getSSN();
        Address getAddress();
        /**Setters*/
        void setContact(char* contact);

        friend ostream& operator<<(ostream&, const Person&);

};

#endif // PERSON_H
