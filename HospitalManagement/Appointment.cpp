#include "Appointment.h"
#include <iostream>
using namespace std;

// Constructor
Appointment::Appointment(int appID, int patID, int docID, string date, string time, string status) {
    appointmentID = appID;
    patientID = patID;
    doctorID = docID;
    this->date = date;
    this->time = time;
    this->status = status;
}

// Getter methods
int Appointment::getAppointmentID() const { return appointmentID; }
int Appointment::getPatientID() const { return patientID; }
int Appointment::getDoctorID() const { return doctorID; }
string Appointment::getDate() const { return date; }
string Appointment::getTime() const { return time; }
string Appointment::getStatus() const { return status; }

// Setter methods
void Appointment::setDate(string newDate) { date = newDate; }
void Appointment::setTime(string newTime) { time = newTime; }
void Appointment::setStatus(string newStatus) { status = newStatus; }

// Display Appointment Details
void Appointment::displayAppointmentDetails() const {
    cout << "Appointment ID: " << appointmentID << endl;
    cout << "Patient ID: " << patientID << endl;
    cout << "Doctor ID: " << doctorID << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Status: " << status << endl;
}
