#include <iostream>
#include <string>
#define MAX 7
using namespace std;

class Medical {
private:
    struct Record {
        int patientID;
        string patientName;
        string medicalHistory;
        string treatmentPlan;
    };

    Record hashTable[MAX][2]; // Each element is a pair to store data and chaining index

public:
    Medical() {
        for (int i = 0; i < MAX; i++) {
            hashTable[i][0].patientID = -1; // Initialize data slot to -1 (indicating empty)
            hashTable[i][1].patientID = -1; // Initialize chaining index to -1 (indicating no chaining)
        }
    }

    void insertRecord() {
        int patientID;
        string patientName;
        string medicalHistory;
        string treatmentPlan;

        cout << "\nEnter patient ID: ";
        cin >> patientID;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, patientName);
        cout << "Enter medical history: ";
        getline(cin, medicalHistory);
        cout << "Enter treatment plan: ";
        getline(cin, treatmentPlan);

        int index = patientID % MAX;
        if (hashTable[index][0].patientID == -1) {
            // If the slot is empty, insert the record directly
            hashTable[index][0].patientID = patientID;
            hashTable[index][0].patientName = patientName;
            hashTable[index][0].medicalHistory = medicalHistory;
            hashTable[index][0].treatmentPlan = treatmentPlan;
        } else {
            // If collision occurs, handle it using linear probing with chaining
            int originalIndex = index;
            while (true) {
                // Handle collision
                cout << "\nTrue Collision Occurs";
                if (hashTable[index][1].patientID == -1) {
                    // If chaining index is empty, find the next available slot
                    int temp = index;
                    while (hashTable[index][0].patientID != -1) {
                        index = (index + 1) % MAX;
                        if (index == temp) {
                            cout << "Overflow";
                            break;
                        }
                    }
                    if (index != temp) {
                        // Insert the record and update chaining index
                        hashTable[index][0].patientID = patientID;
                        hashTable[index][0].patientName = patientName;
                        hashTable[index][0].medicalHistory = medicalHistory;
                        hashTable[index][0].treatmentPlan = treatmentPlan;
                        hashTable[temp][1].patientID = index;
                    }
                    break;
                } else {
                    // Move to the next slot using chaining index
                    if (hashTable[index][1].patientID == -1) {
                        index = originalIndex;
                    } else {
                        index = hashTable[index][1].patientID;
                    }
                    // Check for overflow
                    if (index == originalIndex) {
                        cout << "Overflow";
                        break;
                    }
                }
            }
        }
    }

    void displayRecords() {
        cout << "\nINDEX\tPATIENT ID\tPATIENT NAME\tMEDICAL HISTORY\tTREATMENT PLAN\tCHAINING INDEX";
        for (int i = 0; i < MAX; i++) {
            if (hashTable[i][0].patientID != -1) {
                cout << "\n" << i << "\t" << hashTable[i][0].patientID << "\t\t" 
                     << hashTable[i][0].patientName << "\t\t" << hashTable[i][0].medicalHistory 
                     << "\t\t" << hashTable[i][0].treatmentPlan;
                // If there's a chained record, display it as well
                if (hashTable[i][1].patientID != -1) {
                    cout << "\t\t" << hashTable[i][1].patientID;
                } else {
                    cout << "\t\t-";
                }
            }
        }
    }

    void searchRecord() {
        int patientID;
        cout << "\nEnter patient ID to search: ";
        cin >> patientID;
        int index = patientID % MAX;
        bool found = false;
        while (true) {
            if (hashTable[index][0].patientID == patientID) {
                cout << "\nPatient ID: " << hashTable[index][0].patientID;
                cout << "\nPatient Name: " << hashTable[index][0].patientName;
                cout << "\nMedical History: " << hashTable[index][0].medicalHistory;
                cout << "\nTreatment Plan: " << hashTable[index][0].treatmentPlan;
                found = true;
                break;
            }
            index = hashTable[index][1].patientID;
            if (index == -1) {
                break;
            }
        }
        if (!found) {
            cout << "Not Found";
        }
    }
};

int main() {
    Medical system;
    int choice;
    char press;
    do {
        cout << "\nMedical Record System";
        cout << "\n1. Insert Record";
        cout << "\n2. Display Records";
        cout << "\n3. Search Record";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system.insertRecord();
            break;
        case 2:
            system.displayRecords();
            break;
        case 3:
            system.searchRecord();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nInvalid choice!";
        }
        cout << "\nDo you want to continue (y/n)? ";
        cin >> press;
    } while (press == 'y' || press == 'Y');
    return 0;
}
