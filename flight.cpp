#include<iostream>
using namespace std;

class Flight{
protected:
string flightnumber;
string departureTime;
string destination;
float price;

public:
//virtual void inputFlightDetails()=0;
//virtual void displayFlightDetails()=0;
//virtual ~Flight(){}

};

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
    void displayFlightDetails() override {
        cout << "\n** Domestic Flight **\n";
        Flight::displayFlightDetails(); // Display base class details
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
    }
};

int main()
{

Flight f1;
cout<<"Hello World";
return 0;

}