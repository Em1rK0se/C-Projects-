// Doctor.cpp
#include "Doctor.h"
#include <iostream>
using namespace std;

Doctor::Doctor(int id, string name, int age, string gender, string specialty, long long cont_info, string add) {
    doctorID = id;
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->specialty = specialty;
    this->contact_info = cont_info;
    this->address = add;
}

// Getter methods
int Doctor::getDoctorID() const { return doctorID; }
string Doctor::getName() const { return name; }
int Doctor::getAge() const { return age; }
string Doctor::getGender() const { return gender; }
string Doctor::getSpecialty() const { return specialty; }
long long Doctor::getContactInfo() const { return contact_info; }
string Doctor::getAddress() const { return address; }
vector<int> Doctor::getAssignedPatients() const { return assignedPatients; }

// Method to assign a patient to the doctor
void Doctor::assignPatient(int patientID) {
    assignedPatients.push_back(patientID);
}

// Display Doctor's Information
void Doctor::DisplayDoctorDetails() const {
    cout << "Doctor ID: " << doctorID << endl;
    cout << "Doctor Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Contact Information: " << contact_info << endl;
    cout << "Address: " << address << endl;
    cout << "Assigned Patients: ";
    for (int id : assignedPatients) {
        cout << id << " ";
    }
    cout << endl;
}
