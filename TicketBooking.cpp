#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a Bus
class Bus {
private:
    int busId;
    string destination;
    string time;
    int maxSeats;
    int bookedSeats;
    int fare; // Ticket cost

public:
    Bus(int id, string dest, string t, int fareAmount) 
        : busId(id), destination(dest), time(t), maxSeats(50), bookedSeats(0), fare(fareAmount) {}

    int getBusId() const {
        return busId;
    }

    string getDestination() const {
        return destination;
    }

    int getAvailableSeats() const {
        return maxSeats - bookedSeats;
    }

    void bookSeat() {
        if (bookedSeats < maxSeats) {
            bookedSeats++;
            cout << "Seat booked successfully." << endl;
        } else {
            cout << "No seats available!" << endl;
        }
    }

    void displayBusInfo() const {
        cout << "Bus ID: " << busId 
             << " | Destination: " << destination 
             << " | Time: " << time 
             << " | Fare: $" << fare 
             << " | Available Seats: " << getAvailableSeats() 
             << endl;
    }
};

// Class representing a Ticket
class Ticket {
private:
    string customerName;
    Bus bus;

public:
    Ticket(string name, Bus b) : customerName(name), bus(b) {}

    void displayTicketInfo() const {
        cout << "\nTicket Information:\n";
        cout << "Customer Name: " << customerName << endl;
        bus.displayBusInfo();
    }
};

// Class representing the Bus Reservation System
class BusReservationSystem {
private:
    vector<Bus> buses;
    vector<Ticket> tickets;

public:
    void addBus(const Bus& bus) {
        buses.push_back(bus);
    }

    void bookTicket(string customerName, int busId) {
        for (Bus& bus : buses) {
            if (bus.getBusId() == busId) {
                if (bus.getAvailableSeats() > 0) {
                    bus.bookSeat();
                    Ticket ticket(customerName, bus);
                    tickets.push_back(ticket);
                    ticket.displayTicketInfo();
                } else {
                    cout << "Sorry, the bus is full!" << endl;
                }
                return;
            }
        }
            cout << "Bus with ID " << busId << " not found." << endl;
    }

    void displayBuses() const {
        cout << "\nAvailable Buses:\n";
        for (const auto& bus : buses) {
            bus.displayBusInfo();
        }
    }

    void displayTickets() const {
        cout << "\nAll Booked Tickets:\n";
        for (const auto& ticket : tickets) {
            ticket.displayTicketInfo();
        }
    }
};

// Main function demonstrating the bus reservation system
int main() {
    BusReservationSystem system;

    // Adding some buses
    system.addBus(Bus(1, "New York", "10:00 AM", 100));
    system.addBus(Bus(2, "Los Angeles", "2:00 PM", 150));
    system.addBus(Bus(3, "Chicago", "5:00 PM", 120));

    int choice;
    do {
        cout << "\nBus Reservation System\n";
        cout << "1. Display Buses\n";
        cout << "2. Book a Ticket\n";
        cout << "3. Display Booked Tickets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayBuses();
                break;
            case 2: {
                string customerName;
                int busId;
                cout << "Enter Customer Name: ";
                cin >> customerName;
                cout << "Enter Bus ID: ";
                cin >> busId;
                system.bookTicket(customerName, busId);
                break;
            }
            case 3:
                system.displayTickets();
                break;
            case 4:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
