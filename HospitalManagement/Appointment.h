#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
using namespace std;

class Appointment {
private:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;
    string status;

public:
    Appointment(int appID, int patID, int docID, string date, string time, string status = "Scheduled");
    
    // Getter methods
    int getAppointmentID() const;
    int getPatientID() const;
    int getDoctorID() const;
    string getDate() const;
    string getTime() const;
    string getStatus() const;

    // Setter methods
    void setDate(string newDate);
    void setTime(string newTime);
    void setStatus(string newStatus);

    // Display Appointment Details
    void displayAppointmentDetails() const;
};

#endif
