// Doctor.h
#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>
using namespace std;

class Doctor {
private:
    int doctorID;
    string name;
    int age;
    string gender;
    string specialty;
    long long contact_info; // Change to long long
    string address;
    vector<int> assignedPatients;

public:
    // Constructor
    Doctor(int id, string name, int age, string gender, string specialty, long long cont_info, string add);

    // Getter methods
    int getDoctorID() const;
    string getName() const;
    int getAge() const;
    string getGender() const;
    string getSpecialty() const;
    long long getContactInfo() const; // Change to long long
    string getAddress() const;
    vector<int> getAssignedPatients() const;

    // Method to assign a patient to the doctor
    void assignPatient(int patientID);

    // Display Doctor's Information
    void DisplayDoctorDetails() const;
};

#endif
