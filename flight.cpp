#include <iostream>
#include <string>
using namespace std;

// Base Class - Flight
class Flight {
protected:
    string flightNumber;
    string departureTime;
    double price;
    int availableSeats;

public:
    Flight(string flightNum, string depTime, double flightPrice, int seats)
        : flightNumber(flightNum), departureTime(depTime), price(flightPrice), availableSeats(seats) {}

    virtual void displayFlightDetails() {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Price: $" << price << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    void bookSeat() {
        if (availableSeats > 0) {
            availableSeats--;
            cout << "Seat booked successfully! Remaining seats: " << availableSeats << endl;
        } else {
            cout << "No seats available on this flight.\n";
        }
    }

    string getFlightNumber() { return flightNumber; }

    virtual ~Flight() {}
};

// Derived Class - DomesticFlight
class DomesticFlight : public Flight {
private:
    string departureCity;
    string arrivalCity;

public:
    DomesticFlight(string flightNum, string depTime, double flightPrice, int seats, string depCity, string arrCity)
        : Flight(flightNum, depTime, flightPrice, seats), departureCity(depCity), arrivalCity(arrCity) {}

    void displayFlightDetails() override {
        cout << "\n** Domestic Flight **\n";
        Flight::displayFlightDetails();
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
    }
};

// Derived Class - InternationalFlight
class InternationalFlight : public Flight {
private:
    string departureCountry;
    string arrivalCountry;

public:
    InternationalFlight(string flightNum, string depTime, double flightPrice, int seats, string depCountry, string arrCountry)
        : Flight(flightNum, depTime, flightPrice, seats), departureCountry(depCountry), arrivalCountry(arrCountry) {}

    void displayFlightDetails() override {
        cout << "\n** International Flight **\n";
        Flight::displayFlightDetails();
        cout << "Departure Country: " << departureCountry << endl;
        cout << "Arrival Country: " << arrivalCountry << endl;
    }
};

// FlightManager Class to manage flights
class FlightManager {
private:
    Flight* flights[10]; // Array to store up to 10 flights
    int flightCount = 0; // Counter for flights

public:
    // Add a flight
    void addFlight(Flight* flight) {
        if (flightCount < 10) {
            flights[flightCount] = flight;
            flightCount++;
            cout << "Flight added successfully.\n";
        } else {
            cout << "Cannot add more flights. Storage full!\n";
        }
    }

    // Display all flights
    void displayAllFlights() {
        if (flightCount == 0) {
            cout << "No flights available.\n";
            return;
        }

        cout << "\nDisplaying All Flights:\n";
        for (int i = 0; i < flightCount; i++) {
            flights[i]->displayFlightDetails();
            cout << "------------------------------------\n";
        }
    }

    // Search for a flight by flight number
    void searchFlight(string flightNum) {
        for (int i = 0; i < flightCount; i++) {
            if (flights[i]->getFlightNumber() == flightNum) {
                cout << "Flight found:\n";
                flights[i]->displayFlightDetails();
                return;
            }
        }
        cout << "Flight not found.\n";
    }

    // Book a seat on a flight
    void bookSeat(string flightNum) {
        for (int i = 0; i < flightCount; i++) {
            if (flights[i]->getFlightNumber() == flightNum) {
                flights[i]->bookSeat();
                return;
            }
        }
        cout << "Flight not found.\n";
    }

    // Delete a flight by flight number
    void deleteFlight(string flightNum) {
        for (int i = 0; i < flightCount; i++) {
            if (flights[i]->getFlightNumber() == flightNum) {
                delete flights[i];
                for (int j = i; j < flightCount - 1; j++) {
                    flights[j] = flights[j + 1];
                }
                flights[flightCount - 1] = nullptr;
                flightCount--;
                cout << "Flight deleted successfully.\n";
                return;
            }
        }
        cout << "Flight not found.\n";
    }

    ~FlightManager() {
        for (int i = 0; i < flightCount; i++) {
            delete flights[i];
        }
    }
};

// Main function
int main() {
    FlightManager manager;

    int choice;
    do {
        cout << "\nFlight Management System\n";
        cout << "1. Add Domestic Flight\n";
        cout << "2. Add International Flight\n";
        cout << "3. Display All Flights\n";
        cout << "4. Search for a Flight\n";
        cout << "5. Book a Seat\n";
        cout << "6. Delete a Flight\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string flightNum, depTime, depCity, arrCity;
            double price;
            int seats;

            cout << "Enter Flight Number: ";
            cin >> flightNum;
            cout << "Enter Departure Time: ";
            cin >> depTime;
            cout << "Enter Price: $";
            cin >> price;
            cout << "Enter Number of Seats: ";
            cin >> seats;
            cout << "Enter Departure City: ";
            cin >> depCity;
            cout << "Enter Arrival City: ";
            cin >> arrCity;

            manager.addFlight(new DomesticFlight(flightNum, depTime, price, seats, depCity, arrCity));

        } else if (choice == 2) {
            string flightNum, depTime, depCountry, arrCountry;
            double price;
            int seats;

            cout << "Enter Flight Number: ";
            cin >> flightNum;
            cout << "Enter Departure Time: ";
            cin >> depTime;
            cout << "Enter Price: $";
            cin >> price;
            cout << "Enter Number of Seats: ";
            cin >> seats;
            cout << "Enter Departure Country: ";
            cin >> depCountry;
            cout << "Enter Arrival Country: ";
            cin >> arrCountry;

            manager.addFlight(new InternationalFlight(flightNum, depTime, price, seats, depCountry, arrCountry));

        } else if (choice == 3) {
            manager.displayAllFlights();
        } else if (choice == 4) {
            string flightNum;
            cout << "Enter Flight Number to Search: ";
            cin >> flightNum;
            manager.searchFlight(flightNum);
        } else if (choice == 5) {
            string flightNum;
            cout << "Enter Flight Number to Book a Seat: ";
            cin >> flightNum;
            manager.bookSeat(flightNum);
        } else if (choice == 6) {
            string flightNum;
            cout << "Enter Flight Number to Delete: ";
            cin >> flightNum;
            manager.deleteFlight(flightNum);
        } else if (choice != 7) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    cout << "Exiting the system...\n";
    return 0;
}