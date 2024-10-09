#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a car
class Car {
private:
    string licensePlate;
    string brand;
    string model;
    double rentalPricePerDay;
    bool isAvailable;

public:
    Car(string lp, string br, string mdl, double price)
        : licensePlate(lp), brand(br), model(mdl), rentalPricePerDay(price), isAvailable(true) {}

    string getLicensePlate() const {1
        return licensePlate;
    }

    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    double getRentalPricePerDay() const {
        return rentalPricePerDay;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }

    void displayCarInfo() const {
        cout << "Car: " << brand << " " << model
             << " | License Plate: " << licensePlate
             << " | Price per Day: $" << rentalPricePerDay
             << " | Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Class to represent a customer
class Customer {
private:
    string name;
    string driverLicense;

public:
    Customer(string nm, string dl) : name(nm), driverLicense(dl) {}

    string getName() const {
        return name;
    }

    string getDriverLicense() const {
        return driverLicense;
    }

    void displayCustomerInfo() const {
        cout << "Customer: " << name << " | Driver License: " << driverLicense << endl;
    }
};

// Class to represent a rental transaction
class Rental {
private:
    Customer customer;
    Car* car;
    int rentalDays;

public:
    Rental(Customer cust, Car* c, int days) : customer(cust), car(c), rentalDays(days) {}

    void processRental() {
        if (car->getAvailability()) {
            car->setAvailability(false);
            cout << "Rental processed for " << rentalDays << " days." << endl;
            cout << "Total cost: $" << rentalDays * car->getRentalPricePerDay() << endl;
        } else {
            cout << "Sorry, this car is not available." << endl;
        }
    }

    void displayRentalInfo() const {
        customer.displayCustomerInfo();
        car->displayCarInfo();
        cout << "Rental Days: " << rentalDays << endl;
    }
};

// Class to manage the entire car rental system
class CarRentalSystem {
private:
    vector<Car> cars;
    vector<Customer> customers;
    vector<Rental> rentals;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void displayCustomers() const {
        cout << "\nAll Customers:" << endl;
        for (const auto& customer : customers) {
            customer.displayCustomerInfo();
        }
    }

    void displayAvailableCars() const {
        cout << "\nAvailable Cars:" << endl;
        for (const auto& car : cars) {
            if (car.getAvailability()) {
                car.displayCarInfo();
            }
        }
    }

    void displayAllRentals() const {
        cout << "\nAll Rentals:" << endl;
        for (const auto& rental : rentals) {
            rental.displayRentalInfo();
            cout << "---------------------------------" << endl;
        }
    }

    void rentCar(string licensePlate, string driverLicense, int rentalDays) {
        Car* car = findCar(licensePlate);
        Customer* customer = findCustomer(driverLicense);

        if (car && customer) {
            Rental rental(*customer, car, rentalDays);
            rental.processRental();
            rentals.push_back(rental);
        } else {
            cout << "Car or Customer not found." << endl;
        }
    }

private:
    Car* findCar(const string& licensePlate) {
        for (auto& car : cars) {
            if (car.getLicensePlate() == licensePlate) {
                return &car;
            }
        }
        return nullptr;
    }

    Customer* findCustomer(const string& driverLicense) {
        for (auto& customer : customers) {
            if (customer.getDriverLicense() == driverLicense) {
                return &customer;
            }
        }
        return nullptr;
    }
};

// Main function to demonstrate the car rental system
int main() {
    CarRentalSystem system;

    // Adding some cars
    system.addCar(Car("ABC123", "Toyota", "Camry", 50.0));
    system.addCar(Car("XYZ789", "Honda", "Civic", 45.0));

    // Adding some customers
    system.addCustomer(Customer("John Doe", "D123456"));
    system.addCustomer(Customer("Jane Smith", "S654321"));

    int choice;
    do {
        cout << "\nCar Rental System" << endl;
        cout << "1. Display Available Cars" << endl;
        cout << "2. Display Customers" << endl;
        cout << "3. Rent a Car" << endl;
        cout << "4. Display All Rentals" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.displayAvailableCars();
            break;
        case 2:
            system.displayCustomers();
            break;
        case 3: {
            string licensePlate, driverLicense;
            int rentalDays;
            cout << "Enter License Plate of the car: ";
            cin >> licensePlate;
            cout << "Enter Driver License: ";
            cin >> driverLicense;
            cout << "Enter Rental Days: ";
            cin >> rentalDays;
            system.rentCar(licensePlate, driverLicense, rentalDays);
            break;
        }
        case 4:
            system.displayAllRentals();
            break;
        case 5:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
