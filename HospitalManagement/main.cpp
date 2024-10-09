#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "HMS.h"

using namespace std;

int main() {
    // Example of creating a Patient object
    Patient p1(1, "John Doe", 30, "Male", 1234567890, "123 Main St");
    p1.DisplayPatientDetails();

    // Example of creating a Doctor object
    Doctor d1(101, "Dr. Smith", 45, "Male", "Cardiology", 9876543210, "456 Elm St");
    d1.DisplayDoctorDetails();

    // Example of creating an Appointment object
    Appointment a1(201, p1.getPatientID(), d1.getDoctorID(), "2024-08-15", "10:00 AM");
    a1.displayAppointmentDetails();

    // Example of using the HospitalManagementSystem
    HospitalManagementSystem hms;
    hms.addPatient(p1);
    hms.addDoctor(d1);
    hms.scheduleAppointment(a1);

    return 0;
}
