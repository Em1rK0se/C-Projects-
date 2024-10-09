// Patient.cpp
#include "Patient.h"
#include <iostream>
using namespace std;

Patient::Patient(int id, string name, int age, string gender, long long cont_info, string add) {
    patientID = id;
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->contact_info = cont_info;
    this->address = add;
}

// Getter methods
int Patient::getPatientID() const { return patientID; }
string Patient::getName() const { return name; }
int Patient::getAge() const { return age; }
string Patient::getGender() const { return gender; }
long long Patient::getContactInfo() const { return contact_info; }
string Patient::getAddress() const { return address; }

// Display Patient Information
void Patient::DisplayPatientDetails() const {
    cout << "Patient ID: " << patientID << endl;
    cout << "Patient Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Contact Information: " << contact_info << endl;
    cout << "Address: " << address << endl;
}
