#include<iostream>
using namespace std;

class Flight{
protected:
string flightNumber;
string departureTime;
double price;

public:
// Constructor for Flight
Flight(string flightNum,string depTime,
double flightPrice){
flightNumber= flightNum;
departureTime= depTime;
price= flightPrice;

}

public:
virtual void displayFlightDetails(){

cout<<"Flight Number: "<<flightNumber<<endl;
cout<<"Departure Time: "<<departureTime<<endl;
cout<<"Flight Price: "<<flightPrice<<endl;

}
virtual ~Flight(){}

};
// Creating derived class
class DomesticFlight : public Flight {
private:
    string departureCity;
    string arrivalCity;
    
public:
    // Constructor for Domestic Flight
    DomesticFlight(string flightNum, string depTime, double flightPrice, string depCity, string arrCity)
        : Flight(flightNum, depTime, flightPrice) {
        departureCity = depCity;
        arrivalCity = arrCity;
    }

    // Override the displayFlightDetails function
    void displayFlightDetails(){
        cout << "Domestic Flight";
        Flight::displayFlightDetails(); // Display base class details
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
    }
};

// Derived Class - InternationalFlight (Inherits from Flight)
class InternationalFlight : public Flight {
private:
    string departureCountry;
    string arrivalCountry;
    
public:
    // Constructor for International Flight
    InternationalFlight(string flightNum, string depTime, double flightPrice, string depCountry, string arrCountry)
        : Flight(flightNum, depTime, flightPrice) {
        departureCountry = depCountry;
        arrivalCountry = arrCountry;
    }

    // Override the displayFlightDetails function
    void displayFlightDetails() override {
        cout << "International Flight";
        Flight::displayFlightDetails(); // Display base class details
        cout << "Departure Country: " << departureCountry << endl;
        cout << "Arrival Country: " << arrivalCountry << endl;
    }
};

// FlightManager Class to handle flights
class FlightManager {
private:
    vector<Flight*> flights;  // A vector to store flights
    
public:
    // Add a flight to the system
    void addFlight(Flight* flight) {
        flights.push_back(flight);
    }

    // Display all flights
    void displayAllFlights() {
        for (auto flight : flights) {
            flight->displayFlightDetails();
            cout << "------------------------------------\n";
        }
    }

    // Destructor to delete all dynamically allocated flights
    ~FlightManager() {
        for (auto flight : flights) {
            delete flight;  // Free memory
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
            DomesticFlight* domesticFlight = new DomesticFlight();
            domesticFlight->inputFlightDetails();
            manager.addFlight(domesticFlight);
            break;
        }
        case 2: {
            InternationalFlight* internationalFlight = new InternationalFlight();
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