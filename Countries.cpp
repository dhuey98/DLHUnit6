#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Task 1
class Country {
public:
    virtual void displayInfo() const = 0; // pure virtual function
    virtual ~Country() { // the virtual destructor
        cout << "Country object destroyed." << endl;
    }
};

// Task 2
class USA : public Country {
public:
    void displayInfo() const override {
        cout << "Country Name: USA" << endl;
        cout << "Capital: Washington, D.C." << endl;
        cout << "Population: 331 million" << endl;
    }
};

class Japan : public Country {
public:
    void displayInfo() const override {
        cout << "Country Name: Japan" << endl;
        cout << "Capital: Tokyo" << endl;
        cout << "Population: 126 million" << endl;
    }
};

// Task 4
class Germany : public Country {
public:
    void displayInfo() const override {
        cout << "Country Name: Germany" << endl;
        cout << "Capital: Berlin" << endl;
        cout << "Population: 83 million" << endl;
    }
};

class India : public Country {
public:
    void displayInfo() const override {
        cout << "Country Name: India" << endl;
        cout << "Capital: New Delhi" << endl;
        cout << "Population: 1.366 billion" << endl;
    }
};

// Task 3
int main() {
    int numCountries;
    cout << "Enter the number of countries: ";
    cin >> numCountries;

    // The dynamic array of Country* pointers
    vector<Country*> countries;

    // Dynamically set aside objects based on a user's input
    for (int i = 0; i < numCountries; ++i) {
        int choice;
        cout << "Choose country to add (1 = USA, 2 = Japan, 3 = Germany, 4 = India): ";
        cin >> choice;

        switch (choice) {
            case 1:
                countries.push_back(new USA());
                break;
            case 2:
                countries.push_back(new Japan());
                break;
            case 3:
                countries.push_back(new Germany());
                break;
            case 4:
                countries.push_back(new India());
                break;
            default:
                cout << "Invalid choice!" << endl;
                --i; // Decrement to retry the entry
                break;
        }
    }

    // Task 5
    cout << "\nDisplaying country information:\n" << endl;
    for (const auto& country : countries) {
        country->displayInfo();
        cout << endl;
    }

    // Free the dynamically memory that was set aside
    for (const auto& country : countries) {
        delete country;
    }

    return 0;
}