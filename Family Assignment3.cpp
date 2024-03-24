/*Design and implement a family tree hierarchy using a tree data structure. The family tree should allow
efficient storage, retrieval, and manipulation of information related to individuals and their relationships
within a family*/


#include <iostream>
#include <string>
using namespace std;

struct FamilyNode {
    string name;
    char gender;
    string dob;
    string relationship;
    FamilyNode* left;
    FamilyNode* right;
};

FamilyNode* createFamilyNode(string& name, char gender, string& dob, string& relationship) {
    FamilyNode* newNode = new FamilyNode();
    newNode->name = name;
    newNode->gender = gender;
    newNode->dob = dob;
    newNode->relationship = relationship;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertFamilyMember(FamilyNode*& root) {
    cout << "Enter details for the family member:" << endl;
    string name, dob, relationship;
    char gender;
    cout << "Name: ";
    cin >> name;
    cout << "Gender (M/F): ";
    cin >> gender;
    cout << "Date of Birth (YYYY-MM-DD): ";
    cin >> dob;
    cout << "Relationship: ";
    cin >> relationship;

    FamilyNode* newNode = createFamilyNode(name, gender, dob, relationship);
    if (root == nullptr) {
        root = newNode;
    } else {
        FamilyNode* ptr = root;
        char direction;
        while (ptr != nullptr) {
            cout << "Enter direction (L/R) from current family member: ";
            cin >> direction;
            if (direction == 'L' || direction == 'l') {
                if (ptr->left == nullptr) {
                    ptr->left = newNode;
                    break;
                } else {
                    ptr = ptr->left;
                }
            } else if (direction == 'R' || direction == 'r') {
                if (ptr->right == nullptr) {
                    ptr->right = newNode;
                    break;
                } else {
                    ptr = ptr->right;
                }
            } else {
                cout << "Invalid direction! Please enter either 'L' or 'R'." << endl;
            }
        }
    }
}

void displayFamilyTree(FamilyNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->name << " (" << root->gender << ") - " << root->dob << ", Relationship: " << root->relationship << endl;
    displayFamilyTree(root->left);
    displayFamilyTree(root->right);
}

FamilyNode* searchFamilyMember(FamilyNode* root, string& key) {
    if (root == nullptr || root->name == key) {
        return root;
    }
    FamilyNode* foundNode = searchFamilyMember(root->left, key);
    if (foundNode == nullptr) {
        foundNode = searchFamilyMember(root->right, key);
    }
    return foundNode;
}

void deleteFamilyMember(FamilyNode*& root, string& key) {
    if (root == nullptr) {
        return;
    }

    if (root->name == key) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            FamilyNode* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            FamilyNode* temp = root;
            root = root->left;
            delete temp;
        } else {
            FamilyNode* maxLeft = root->left;
            while (maxLeft->right != nullptr) {
                maxLeft = maxLeft->right;
            }
            root->name = maxLeft->name;
            root->gender = maxLeft->gender;
            root->dob = maxLeft->dob;
            root->relationship = maxLeft->relationship;
            deleteFamilyMember(root->left, maxLeft->name);
        }
    } else {
        deleteFamilyMember(root->left, key);
        deleteFamilyMember(root->right, key);
    }
}

int main() {
    FamilyNode* root = nullptr;
    char choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert Family Member" << endl;
        cout << "2. Display Family Tree" << endl;
        cout << "3. Search Family Member" << endl;
        cout << "4. Delete Family Member" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                insertFamilyMember(root);
                break;
            case '2':
                cout << "Family Tree:" << endl;
                displayFamilyTree(root);
                break;
            case '3': {
                cout << "Enter the name of the family member you want to search: ";
                string key;
                cin >> key;
                FamilyNode* foundNode = searchFamilyMember(root, key);
                if (foundNode != nullptr) {
                    cout << "Family member found: " << foundNode->name << " (" << foundNode->gender << ") - " << foundNode->dob << ", Relationship: " << foundNode->relationship << endl;
                } else {
                    cout << "Family member not found." << endl;
                }
                break;
            }
            case '4': {
                cout << "Enter the name of the family member you want to delete: ";
                string key;
                cin >> key;
                deleteFamilyMember(root, key);
                cout << "Family member deleted successfully." << endl;
                break;
            }
            case '5':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 5." << endl;
        }
    } while (choice != '5');
}