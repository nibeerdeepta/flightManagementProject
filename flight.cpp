#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class: Flight
class Flight {
protected:
    string flightNumber;
    string departureTime;
    double price;

public:
    // Constructor for Flight
    Flight(string flightNum, string depTime, double flightPrice)
        : flightNumber(flightNum), departureTime(depTime), price(flightPrice) {}

    // Virtual function to display flight details
    virtual void displayFlightDetails() {
        cout << "\nFlight Number: " << flightNumber << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~Flight() {}
};

// Derived Class: DomesticFlight
class DomesticFlight : public Flight {
private:
    string departureCity;
    string arrivalCity;

public:
    // Constructor for Domestic Flight
    DomesticFlight(string flightNum, string depTime, double flightPrice, string depCity, string arrCity)
        : Flight(flightNum, depTime, flightPrice), departureCity(depCity), arrivalCity(arrCity) {}

    // Override to display flight details
    void displayFlightDetails() override {
        cout << "\n--- Domestic Flight ---\n";
        Flight::displayFlightDetails();
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
    }

    // Input method for Domestic Flight details
    void inputFlightDetails() {
        cout << "Enter Flight Number: ";
        cin >> flightNumber;
        cout << "Enter Departure Time: ";
        cin >> departureTime;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Departure City: ";
        cin >> departureCity;
        cout << "Enter Arrival City: ";
        cin >> arrivalCity;
    }
};

// Derived Class: InternationalFlight
class InternationalFlight : public Flight {
private:
    string departureCountry;
    string arrivalCountry;

public:
    // Constructor for International Flight
    InternationalFlight(string flightNum, string depTime, double flightPrice, string depCountry, string arrCountry)
        : Flight(flightNum, depTime, flightPrice), departureCountry(depCountry), arrivalCountry(arrCountry) {}

    // Override to display flight details
    void displayFlightDetails() override {
        cout << "\n--- International Flight ---\n";
        Flight::displayFlightDetails();
        cout << "Departure Country: " << departureCountry << endl;
        cout << "Arrival Country: " << arrivalCountry << endl;
    }

    // Input method for International Flight details
    void inputFlightDetails() {
        cout << "Enter Flight Number: ";
        cin >> flightNumber;
        cout << "Enter Departure Time: ";
        cin >> departureTime;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Departure Country: ";
        cin >> departureCountry;
        cout << "Enter Arrival Country: ";
        cin >> arrivalCountry;
    }
};

// FlightManager Class
class FlightManager {
private:
    vector<Flight*> flights; // Vector to store flights

public:
    // Add a flight to the system
    void addFlight(Flight* flight) {
        flights.push_back(flight);
    }

    // Display all flights
    void displayAllFlights() {
        if (flights.empty()) {
            cout << "No flights available.\n";
        } else {
            for (auto flight : flights) {
                flight->displayFlightDetails();
                cout << "------------------------------------\n";
            }
        }
    }

    // Destructor to free memory
    ~FlightManager() {
        for (auto flight : flights) {
            delete flight; // Free memory
        }
    }
};

// Main Function
int main() {
    FlightManager manager;

    int choice;
    do {
        cout << "\nFlight Management System\n";
        cout << "1. Add Domestic Flight\n";
        cout << "2. Add International Flight\n";
        cout << "3. Display All Flights\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            DomesticFlight* domesticFlight = new DomesticFlight("", "", 0.0, "", "");
            domesticFlight->inputFlightDetails();
            manager.addFlight(domesticFlight);
            break;
        }
        case 2: {
            InternationalFlight* internationalFlight = new InternationalFlight("", "", 0.0, "", "");
            internationalFlight->inputFlightDetails();
            manager.addFlight(internationalFlight);
            break;
        }
        case 3:
            manager.displayAllFlights();
            break;
        case 4:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
