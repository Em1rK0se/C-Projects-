#ifndef HOSPITALMANAGEMENTSYSTEM_H
#define HOSPITALMANAGEMENTSYSTEM_H

#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include <vector>

class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    // Methods to manage patients, doctors, and appointments
    void addPatient(const Patient& patient);
    void addDoctor(const Doctor& doctor);
    void scheduleAppointment(const Appointment& appointment);
    void updateAppointment(int appID, const string& newDate, const string& newTime, const string& newStatus);
    void cancelAppointment(int appID);
    void displayAllPatients() const;
    void displayAllDoctors() const;
    void displayAllAppointments() const;
    void searchPatientByID(int id) const;
    void searchDoctorByID(int id) const;
};

#endif
