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

void saveToFile(const vector<car>& cars) {
    ofstream file("cars.txt");
    if (file.is_open()) {
        for (const auto& car : cars) {
            file << car.maker << "," << car.model << "," << car.makeyear << ","
                 << car.milage << "," << car.owners << endl;
        }
        file.close();
    } else {
        cout << "Unable to save cars to file." << endl;
    }
}

vector<car> loadFromFile() {
    vector<car> cars;
    ifstream file("cars.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string maker, model;
            int makeyear, milage, owners;
            char comma; // To handle the commas in the file
            ss >> maker >> comma >> model >> comma >> makeyear >> comma >> milage >> comma >> owners;
            cars.push_back({makeyear, milage, owners, model, maker});
        }
        file.close();
    } else {
        cout << "No saved cars found. Starting with an empty list." << endl;
    }
    return cars;
}

int main() {
    vector<car> cars = loadFromFile(); // Load cars from file
    int choice;

    while (true) {
        cout << "What would you like to do?\n1. Register a car\n2. View your cars\n3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            car newCar;
            newCar.registration();
            cars.push_back(newCar);
            saveToFile(cars); // Save cars to file after registration
            cout << "Car registered successfully!\n";
        } else if (choice == 2) {
            if (cars.empty()) {
                cout << "No cars registered yet.\n";
            } else {
                cout << "Registered Cars:\n";
                for (const auto& c : cars) {
                    &c.display();
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