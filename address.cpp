#include "address.h"

Address::Address() {
    m_building = 0;
    m_street = NULL;
    m_city = NULL;
    m_postalCode = 0;
    m_country = NULL;
}

Address::Address(char* street, char* building, char* postalCode, char* city,  char* country) {
   m_street = new char[strlen(street) + 1];
    strcpy(m_street, street);

    m_building = new char[strlen(building) + 1];
    strcpy(m_building, building);
    
    m_postalCode = new char[strlen(postalCode) + 1];
    strcpy(m_postalCode, postalCode);

    m_city = new char[strlen(city) + 1];
    strcpy(m_city, city);

    m_country = new char[strlen(country) + 1];
    strcpy(m_country, country);
}
Address::Address(const Address& address){
    this->m_building = address.m_building;

    // Allocate memory for the street and copy the content
    this->m_street = new char[strlen(address.m_street) + 1];
    strcpy(this->m_street, address.m_street);

    // Allocate memory for the city and copy the content
    this->m_city = new char[strlen(address.m_city) + 1];
    strcpy(this->m_city, address.m_city);

    this->m_postalCode = address.m_postalCode;

    // Allocate memory for the country and copy the content
    this->m_country = new char[strlen(address.m_country) + 1];
    strcpy(this->m_country, address.m_country);
}

void Address::setAddress(const char* street, char* building, char* postalCode, const char* city, const char* country) {

    /** Deallocate previous memory */
    delete[] m_street;
    delete[] m_building;
    delete[] m_postalCode;
    delete[] m_city;
    delete[] m_country;

    /** Allocate new memory and copy the street, city, and country strings */
    m_street = new char[strlen(street) + 1];
    strcpy(m_street, street);

    m_building = new char[strlen(building) + 1];
    strcpy(m_building, building);
    
    m_postalCode = new char[strlen(postalCode) + 1];
    strcpy(m_postalCode, postalCode);

    m_city = new char[strlen(city) + 1];
    strcpy(m_city, city);

    m_country = new char[strlen(country) + 1];
    strcpy(m_country, country);
}

char* Address::getBuilding() {
    return m_building;
}
char* Address::getStreet() {
    return m_street;
}
char* Address::getCity() {
    return m_city;
}

char* Address::getPostalCode(){
    return m_postalCode;
}

char* Address::getCountry() {
    return m_country;
}
Address& Address::operator=(Address& address) {
    // Check for self-assignment
    if (this == &address) {
        return *this;
    }

    // Perform the assignment
    this->m_street = address.m_street;
    this->m_building = address.m_building;
    this->m_postalCode = address.m_postalCode;
    this->m_city = address.m_city;
    this->m_country = address.m_country;


    // Return the updated object
    return *this;
}

ostream& operator<< (ostream& os, const Address& address){

    os<<address.m_street;
    os<<" ";
    os<<address.m_building;
    os<<", ";
    os<<address.m_postalCode;
    os<<" ";
    os<<address.m_city;
    os<<", ";
    os<<address.m_country;
    os<<" ";

    return os;
}

