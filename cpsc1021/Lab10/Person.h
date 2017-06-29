/* Person.h
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
  private:
    string name;
    string address;
    string city;
    string state;
    int zip;

  public:
    Person(string, string, string, string, int);
    Person();
    void setName(string);
    void setAddress(string);
    void setState(string);
    void setCity(string);
    void setZip(int);

    void printSenderInfo();
    void printRecipientInfo();

};

#endif
