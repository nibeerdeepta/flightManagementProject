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
//virtual ~Flight(){}

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
       // Flight::displayFlightDetails(); // Display base class details
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

int main()
{

//Flight f1;
//DomesticFlight df1;
cout<<"Hello World";
return 0;

}