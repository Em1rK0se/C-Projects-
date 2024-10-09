#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Patient class
class Patient {
private:
    int patientID;
    string name;
    int age;
    string gender;
    long long contact_info;
    string address;

public:
    // Constructor
    Patient(int id, string name, int age, string gender, long long cont_info, string add)
        : patientID(id), name(name), age(age), gender(gender), contact_info(cont_info), address(add) {}

    // Getter methods
    int getPatientID() const { return patientID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    long long getContactInfo() const { return contact_info; }
    string getAddress() const { return address; }

    // Display Patient Information
    void DisplayPatientDetails() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Contact Information: " << contact_info << endl;
        cout << "Address: " << address << endl;
    }
};

// Doctor class
class Doctor {
private:
    int doctorID;
    string name;
    int age;
    string gender;
    string specialty;
    long long contact_info;
    string address;
    vector<int> assignedPatients;

public:
    // Constructor
    Doctor(int id, string name, int age, string gender, string specialty, long long cont_info, string add)
        : doctorID(id), name(name), age(age), gender(gender), specialty(specialty), contact_info(cont_info), address(add) {}

    // Getter methods
    int getDoctorID() const { return doctorID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getSpecialty() const { return specialty; }
    long long getContactInfo() const { return contact_info; }
    string getAddress() const { return address; }
    vector<int> getAssignedPatients() const { return assignedPatients; }

    // Method to assign a patient to the doctor
    void assignPatient(int patientID) {
        assignedPatients.push_back(patientID);
    }

    // Display Doctor's Information
    void DisplayDoctorDetails() const {
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Doctor Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Specialty: " << specialty << endl;
        cout << "Contact Information: " << contact_info << endl;
        cout << "Address: " << address << endl;
        cout << "Assigned Patients: ";
        for (int patientID : assignedPatients) {
            cout << patientID << " ";
        }
        cout << endl;
    }
};

// Appointment class
class Appointment {
private:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;
    string status;

public:
    // Constructor
    Appointment(int appID, int patID, int docID, string date, string time, string status = "Scheduled")
        : appointmentID(appID), patientID(patID), doctorID(docID), date(date), time(time), status(status) {}

    // Getter methods
    int getAppointmentID() const { return appointmentID; }
    int getPatientID() const { return patientID; }
    int getDoctorID() const { return doctorID; }
    string getDate() const { return date; }
    string getTime() const { return time; }
    string getStatus() const { return status; }

    // Setter methods
    void setDate(string newDate) { date = newDate; }
    void setTime(string newTime) { time = newTime; }
    void setStatus(string newStatus) { status = newStatus; }

    // Display Appointment Details
    void displayAppointmentDetails() const {
        cout << "Appointment ID: " << appointmentID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Status: " << status << endl;
    }
};

// HospitalManagementSystem class
class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    // Methods to manage patients, doctors, and appointments
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    void scheduleAppointment(const Appointment& appointment) {
        appointments.push_back(appointment);
    }

    void updateAppointment(int appID, const string& newDate, const string& newTime, const string& newStatus) {
        for (auto& appointment : appointments) {
            if (appointment.getAppointmentID() == appID) {
                appointment.setDate(newDate);
                appointment.setTime(newTime);
                appointment.setStatus(newStatus);
                return;
            }
        }
        cout << "Appointment ID not found." << endl;
    }

    void cancelAppointment(int appID) {
        for (auto it = appointments.begin(); it != appointments.end(); ++it) {
            if (it->getAppointmentID() == appID) {
                appointments.erase(it);
                return;
            }
        }
        cout << "Appointment ID not found." << endl;
    }

    void displayAllPatients() const {
        for (const auto& patient : patients) {
            patient.DisplayPatientDetails();
            cout << endl;
        }
    }

    void displayAllDoctors() const {
        for (const auto& doctor : doctors) {
            doctor.DisplayDoctorDetails();
            cout << endl;
        }
    }

    void displayAllAppointments() const {
        for (const auto& appointment : appointments) {
            appointment.displayAppointmentDetails();
            cout << endl;
        }
    }

    void searchPatientByID(int id) const {
        for (const auto& patient : patients) {
            if (patient.getPatientID() == id) {
                patient.DisplayPatientDetails();
                return;
            }
        }
        cout << "Patient ID not found." << endl;
    }

    void searchDoctorByID(int id) const {
        for (const auto& doctor : doctors) {
            if (doctor.getDoctorID() == id) {
                doctor.DisplayDoctorDetails();
                return;
            }
        }
        cout << "Doctor ID not found." << endl;
    }
};

// Main function
int main() {
    HospitalManagementSystem hms;

    // Create some sample patients, doctors, and appointments
    Patient p1(1, "John Doe", 30, "Male", 1234567890, "123 Main St");
    Patient p2(2, "Jane Smith", 25, "Female", 9876543210, "456 Elm St");

    Doctor d1(101, "Dr. Smith", 45, "Male", "Cardiology", 1234567890, "789 Oak St");
    Doctor d2(102, "Dr. Johnson", 50, "Female", "Neurology", 9876543210, "789 Pine St");

    Appointment a1(1001, 1, 101, "2024-08-15", "10:00 AM");
    Appointment a2(1002, 2, 102, "2024-08-16", "11:00 AM");

    // Add patients, doctors, and appointments to the system
    hms.addPatient(p1);
    hms.addPatient(p2);
    hms.addDoctor(d1);
    hms.addDoctor(d2);
    hms.scheduleAppointment(a1);
    hms.scheduleAppointment(a2);

    // Display all patients, doctors, and appointments
    cout << "All Patients:" << endl;
    hms.displayAllPatients();
    
    cout << "All Doctors:" << endl;
    hms.displayAllDoctors();

    cout << "All Appointments:" << endl;
    hms.displayAllAppointments();

    // Search for a patient and doctor by ID
    cout << "Search for Patient ID 1:" << endl;
    hms.searchPatientByID(1);
    
    cout << "Search for Doctor ID 101:" << endl;
    hms.searchDoctorByID(101);

    // Update and display an appointment
    hms.updateAppointment(1001, "2024-08-20", "02:00 PM", "Rescheduled");
    cout << "Updated Appointments:" << endl;
    hms.displayAllAppointments();

    // Cancel an appointment and display remaining appointments
    hms.cancelAppointment(1002);
    cout << "Remaining Appointments after cancellation:" << endl;
    hms.displayAllAppointments();

    return 0;
}
