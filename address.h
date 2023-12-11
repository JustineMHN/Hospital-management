#ifndef ADDRESS_H
#define ADDRESS_H

#include <string.h>
#include <string>
#include <ostream>

using namespace std;

class Address
{
    public:
    /** Constructors */
    Address();
    Address(char* street, char* building, char* postalCode, char* city,  char* country);
    Address(const Address& address);

    /** Destructor */
    //~Address();

    /** Method to set address details */
    void setAddress(const char* street, char* building, char* postalCode, const char* city,  const char* country);

    /** Getters */
    char* getBuilding();
    char* getStreet();
    char* getCity();
    char* getPostalCode();
    char* getCountry();
    Address& operator=(Address& address);

    /** Friend function to overload the << operator for output */
    friend ostream& operator<< (ostream& os, const Address& address);

private:
    char* m_street;
    char* m_building;
    char* m_postalCode;
    char* m_city;
    char* m_country;
};

#endif // ADDRESS_H
