#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> 

using namespace std;

const string FILE_NAME = "pharmacy_records.txt";

// Base class
class User {
public:
    virtual void menu() = 0; 
    void addMedicine() {
        ofstream file;
        file.open(FILE_NAME, ios::app); 

        string medicineID, name, quantity, price;

        cout << "Enter Medicine ID: ";
        cin >> medicineID;
        cout << "Enter Medicine Name: ";
        cin >> name;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;

        file << medicineID << "," << name << "," << quantity << "," << price << "\n";
        file.close();

        cout << "Medicine added successfully.\n" << endl;
    }

    void viewMedicines() {
        ifstream file;
        file.open(FILE_NAME);

        if (!file.is_open()) {
            cout << "No records found.\n" << endl;
            return;
        }

        string line;
        cout << "Medicine ID | Name | Quantity | Price" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void searchMedicine() {
        ifstream file;
        file.open(FILE_NAME);

        if (!file.is_open()) {
            cout << "No records found.\n" << endl;
            return;
        }

        string searchID;
        cout << "Enter Medicine ID to search: ";
        cin >> searchID;

        string line;
        bool found = false;
        while (getline(file, line)) {  
            if (line.find(searchID) == 0) {
                cout << "Medicine found: " << line << endl;
                found = true;
                break;
            }
        }
        file.close();

        if (!found) {
            cout << "Medicine not found.\n" << endl;
        }
    }
};

// Derived class for Admin
class Admin : public User {
public:
    void menu() override {
        while (true) {
            cout << "\n----------------------------------------------------------------------------";
            cout << "\n                       PHARMACARE - Admin                                  ";
            cout << "\n-----------------------------------------------------------------------------" << endl;

            cout << "1. Add Medicine" << endl;
            cout << "2. View Medicines" << endl;
            cout << "3. Search Medicine" << endl;
            cout << "4. Update Medicine" << endl;
            cout << "5. Delete Medicine" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    addMedicine();
                    break;
                case 2:
                    viewMedicines();
                    break;
                case 3:
                    searchMedicine();
                    break;
                case 4:
                    updateMedicine();
                    break;
                case 5:
                    deleteMedicine();
                    break;
                case 6:
                    return;
                default:
                    cout << "Invalid choice, please try again.\n" << endl;
            }
        }
    }

    void updateMedicine() {
        ifstream file;
        file.open(FILE_NAME);

        if (!file.is_open()) {
            cout << "No records found.\n" << endl;
            return;
        }

        string searchID;
        cout << "Enter Medicine ID to update: ";
        cin >> searchID;

        string line;
        string tempFileName = "temp.txt";
        ofstream tempFile;
        tempFile.open(tempFileName);

        bool found = false;
        while (getline(file, line)) {
            if (line.find(searchID) == 0) {
                found = true;
                cout << "Current record: " << line << endl;
                string name, quantity, price;
                cout << "Enter new Medicine Name: ";
                cin >> name;
                cout << "Enter new Quantity: ";
                cin >> quantity;
                cout << "Enter new Price: ";
                cin >> price;
                tempFile << searchID << "," << name << "," << quantity << "," << price << "\n";
            } else {
                tempFile << line << "\n";
            }
        }
        file.close();
        tempFile.close();

        remove(FILE_NAME.c_str());
        rename(tempFileName.c_str(), FILE_NAME.c_str());

        if (found) {
            cout << "Medicine updated successfully.\n" << endl;
        } else {
            cout << "Medicine ID not found.\n" << endl;
        }
    }

    void deleteMedicine() {
        ifstream file;
        file.open(FILE_NAME);

        if (!file.is_open()) {
            cout << "No records found.\n" << endl;
            return;
        }

        string searchID;
        cout << "Enter Medicine ID to delete: ";
        cin >> searchID;

        string line;
        string tempFileName = "temp.txt";
        ofstream tempFile;
        tempFile.open(tempFileName);

        bool found = false;
        while (getline(file, line)) {
            if (line.find(searchID) != 0) {
                tempFile << line << "\n";
            } else {
                found = true;
            }
        }
        file.close();
        tempFile.close();

        remove(FILE_NAME.c_str());
        rename(tempFileName.c_str(), FILE_NAME.c_str());

        if (found) {
            cout << "Medicine deleted successfully.\n" << endl;
        } else {
            cout << "Medicine ID not found.\n" << endl;
        }
    }
};

// Derived class for Customer
class Customer : public User {
public:
    void menu() override {
        while (true) {
            cout << "\n----------------------------------------------------------------------------";
            cout << "\n                       PHARMACARE - Customer                               ";
            cout << "\n-----------------------------------------------------------------------------" << endl;

            cout << "1. View Medicines" << endl;
            cout << "2. Search Medicine" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    viewMedicines();
                    break;
                case 2:
                    searchMedicine();
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice, please try again.\n" << endl;
            }
        }
    }
};

// Main menu function
void mainMenu() {
    while (true) {
        cout << "\n----------------------------------------------------------------------------";
        cout << "\n                       PHARMACARE                                          ";
        cout << "\n-----------------------------------------------------------------------------" << endl;

        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        User* user;
        switch (choice) {
            case 1:
                user = new Admin();
                user->menu();
                delete user;
                break;
            case 2:
                user = new Customer();
                user->menu();
                delete user;
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again.\n" << endl;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
