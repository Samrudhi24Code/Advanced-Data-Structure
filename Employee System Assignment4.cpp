/*Design and implement a Employee Management system tree hierarchy using a binary search tree data
structure. The family tree should allow efficient storage, retrieval, and manipulation of information related
to individuals and their relationships within the employee. The insertion of new employee carried out through salary*/

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    string designation;
    double salary;
    Employee* left;
    Employee* right;
};

Employee* createNode() {
    Employee* newNode = new Employee();
    cout << "Enter employee name: ";
    cin >> newNode->name;
    cout << "Enter employee ID: ";
    cin >> newNode->id;
    cout << "Enter employee designation: ";
    cin >> newNode->designation;
    cout << "Enter employee salary: ";
    cin >> newNode->salary;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(Employee*& root, Employee* newNode) {
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Employee* ptr = root;
    while (true) {
        if (newNode->salary < ptr->salary) {
            if (ptr->left == nullptr) {
                ptr->left = newNode;
                return;
            }
            ptr = ptr->left;
        } else {
            if (ptr->right == nullptr) {
                ptr->right = newNode;
                return;
            }
            ptr = ptr->right;
        }
    }
}

Employee* find(Employee* root, double salary) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->salary == salary) {
        return root;
    }

    if (salary < root->salary) {
        return find(root->left, salary);
    } else {
        return find(root->right, salary);
    }
}

Employee* findSuccessor(Employee* node) {
    Employee* current = node->right;
    Employee* successor = nullptr;
    Employee* prev = nullptr;

    while (current != nullptr) {
        prev = successor;
        successor = current;
        current = current->left;
    }

    if (successor != node->right) {
        prev->left = successor->right;
        successor->right = node->right;
    }

    return successor;
}

bool deletion(Employee*& root, double key) {
    if (root == nullptr) {
        return false;
    }

    if (key < root->salary) {
        return deletion(root->left, key);
    } else if (key > root->salary) {
        return deletion(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Employee* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Employee* temp = root;
            root = root->left;
            delete temp;
        } else {
            Employee* successor = findSuccessor(root);
            root->salary = successor->salary;
            deletion(root->right, successor->salary);
        }
        return true;
    }
}

void preorderTraversal(Employee* root) {
    if (root == nullptr) {
        return;
    }
    cout << "Name: " << root->name << ", ID: " << root->id << ", Designation: " << root->designation << ", Salary: " << root->salary << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Employee* root = nullptr;

    int choice;
    double deleteSalary;
    bool deleted;
    Employee* newEmployee;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees (Preorder Traversal)\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                newEmployee = createNode();
                insertNode(root, newEmployee);
                break;
            case 2:
                cout << "Employee Information :" << endl;
                preorderTraversal(root);
                break;
            case 3:
                cout << "Enter the salary to delete: ";
                cin >> deleteSalary;
                deleted = deletion(root, deleteSalary);
                if (deleted) {
                    cout << "Employee deleted successfully." << endl;
                } else {
                    cout << "Employee not found." << endl;
                }
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}