// Patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient {
private:
    int patientID;
    string name;
    int age;
    string gender;
    long long contact_info; // Change to long long
    string address;

public:
    // Constructor
    Patient(int id, string name, int age, string gender, long long cont_info, string add);

    // Getter methods
    int getPatientID() const;
    string getName() const;
    int getAge() const;
    string getGender() const;
    long long getContactInfo() const; // Change to long long
    string getAddress() const;

    // Display Patient Information
    void DisplayPatientDetails() const;
};

#endif
