#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class car {
public:
    int makeyear;
    int milage;
    int owners;
    string model;
    string maker;

    void registration() {
        cout << "Year When The Car Was Made: ";
        cin >> makeyear;
        cout << "Milage in KM: ";
        cin >> milage;
        cout << "Number Of Owners: ";
        cin >> owners;
        cout << "Model Of The Car: ";
        cin >> model;
        cout << "Maker of The Car: ";
        cin >> maker;
    }

    void display() {
        cout << "Maker: " << maker << ", Model: " << model << ", Year: " << makeyear
             << ", Milage: " << milage << " KM, Owners: " << owners << endl;
    }
}; 


int main() {
    int choice;
    vector<car> cars; // Persistent vector to store cars

    while (true) {
        cout << "What would you like to do?\n1. Register a car\n2. View your cars\n3. Exit\n";
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 3.\n";
            continue;
        }

        if (choice == 1) {
            car newCar; // Create a new car object
            newCar.registration(); // Register the new car
            cars.push_back(newCar); // Add new car to the vector
            cout << "Car registered successfully!\n";
        } else if (choice == 2) {
            if (cars.empty()) { // Check if the vector is empty
                cout << "No cars registered yet.\n";
            } else { // Display all registered cars
                cout << "Registered cars:\n";
                for (size_t i = 0; i < cars.size(); ++i) { // Iterate through the vector
                    cout << i + 1 << ". ";
                    cars[i].display();
                }
            }
        } else if (choice == 3) {
            cout << "Exiting the program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}