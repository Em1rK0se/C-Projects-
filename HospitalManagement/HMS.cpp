#include "HMS.h"
#include <iostream>
using namespace std;

void HospitalManagementSystem::addPatient(const Patient& patient) {
    patients.push_back(patient);
}

void HospitalManagementSystem::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}

void HospitalManagementSystem::scheduleAppointment(const Appointment& appointment) {
    appointments.push_back(appointment);
}

void HospitalManagementSystem::updateAppointment(int appID, const string& newDate, const string& newTime, const string& newStatus) {
    for (auto &appointment : appointments) {
        if (appointment.getAppointmentID() == appID) {
            appointment.setDate(newDate);
            appointment.setTime(newTime);
            appointment.setStatus(newStatus);
        }
    }
}

void HospitalManagementSystem::cancelAppointment(int appID) {
    for (auto &appointment : appointments) {
        if (appointment.getAppointmentID() == appID) {
            appointment.setStatus("Canceled");
        }
    }
}

void HospitalManagementSystem::displayAllPatients() const {
    for (const auto &patient : patients) {
        patient.DisplayPatientDetails();
    }
}

void HospitalManagementSystem::displayAllDoctors() const {
    for (const auto &doctor : doctors) {
        doctor.DisplayDoctorDetails();
    }
}

void HospitalManagementSystem::displayAllAppointments() const {
    for (const auto &appointment : appointments) {
        appointment.displayAppointmentDetails();
    }
}

void HospitalManagementSystem::searchPatientByID(int id) const {
    for (const auto &patient : patients) {
        if (patient.getPatientID() == id) {
            patient.DisplayPatientDetails();
        }
    }
}

void HospitalManagementSystem::searchDoctorByID(int id) const {
    for (const auto &doctor : doctors) {
        if (doctor.getDoctorID() == id) {
            doctor.DisplayDoctorDetails();
        }
    }
}

