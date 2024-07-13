#include <iostream>
#include <iomanip>
using namespace std;

class Employee 
{
public:
    int id;
    string name;
    string designation;

    Employee(int id, string name,string designation) 
    {
        this->id = id;
        this->name = name;
        this->designation = designation;
    }
};

class node
{
public:
    int data;
    int height;
    Employee* employee; 
    node* left;
    node* right;

    node(int data, Employee* emp)
    {
        this->data = data;
        this->employee = emp;
        height = 0;
        left = NULL;
        right = NULL;
    }
};

class avl
{
    node* root;

public:
    avl()
    {
        root = NULL;
    }

    node* getRoot()
    {
        return root;
    }

    int getHeight(node* curr)
    {
        if (curr == NULL)
        {
            return -1;
        }
        return curr->height;
    }

    void setRoot(node* n)
    {
        root = n;
    }

    node* search(node* curr, int value)
    {
        if (curr == NULL)
        {
            return NULL; // not found
        }
        if (value == curr->data)
        {
            return curr; // found
        }
        else if (value < curr->data)
        {
            return search(curr->left, value);
        }
        else
        {
            return search(curr->right, value);
        }
    }

    void inorder(node* n)
    {
        if (n == NULL)
        {
            return;
        }
        inorder(n->left);
        cout << n->data << "\t";
        inorder(n->right);
    }

    int max(int n, int curr)
    {
        if (n > curr)
        {
            return n;
        }
        else
            return curr;
    }

    int min(int n, int curr)
    {
        if (n < curr)
        {
            return n;
        }
        else
            return curr;
    }

    node* min_Value(node* n)
    {
        node* curr = n;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    node* max_Value(node* n)
    {
        node* curr = n;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr;
    }

    node* rightRotate(node* curr)
    {
        node* t1 = curr->left;
        node* t2 = t1->right;

        t1->right = curr; // Performing rotation
        curr->left = t2;

        curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
        t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;

        return t1;
    }

    node* leftRotate(node* curr)
    {
        node* t1 = curr->right;
        node* t2 = t1->left;

        t1->left = curr; // Performing rotation
        curr->right = t2;

        curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
        t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;

        return t1;
    }

    int getBalance(node* curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        return getHeight(curr->left) - getHeight(curr->right);
    }

    node* insert(node* curr, Employee* emp)
    {
        if (curr == NULL)
        {
            return new node(emp->id, emp);
        }
        if (emp->id < curr->data)
        {
            curr->left = insert(curr->left, emp);
        }
        else if (emp->id > curr->data)
        {
            curr->right = insert(curr->right, emp);
        }
        else
        {
            return curr;
        }

        curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
        int balance = getBalance(curr);
        // left left case
        if (balance > 1 && emp->id < curr->left->data)
        {
            cout << "Tree is unbalanced. Performing right rotation." << endl;
            return rightRotate(curr);
        }
        // right right
        if (balance < -1 && emp->id > curr->right->data)
        {
            cout << "Tree is unbalanced. Performing left-right rotation." << endl;
            return leftRotate(curr);
        }
        // left right case
        if (balance > 1 && emp->id > curr->left->data)
        {
            cout << "Tree is unbalanced. Performing left rotation." << endl;
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }
        // right left case
        if (balance < -1 && emp->id < curr->right->data)
        {
            cout << "Tree is unbalanced. Performing right-left rotation." << endl;
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }

        return curr;
    }

    node* deletion(node* curr, int value)
    {
        if (curr == NULL)
        {
            return curr;
        }
        if (value < curr->data)
        {
            curr->left = deletion(curr->left, value);
        }
        else if (value > curr->data)
        {
            curr->right = deletion(curr->right, value);
        }
        else
        {
            // no child case or one child case
            if (curr->left == NULL || curr->right == NULL)
            {
                node* temp;
                if (curr->left == NULL)
                {
                    temp = curr->right;
                }
                else
                {
                    temp = curr->left;
                }
                // No child case
                if (temp == NULL)
                {
                    temp = curr;
                    curr = NULL;
                }
                else // One child case
                {
                    *curr = *temp;
                }
                delete temp;
            }
            else // two children case
            {
                node* temp = min_Value(curr->right); // inorder successor
                curr->data = temp->data;

                curr->right = deletion(curr->right, curr->data);
            }
        }
        if (curr == NULL)
        {
            return curr;
        }
        curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
        int balance = getBalance(curr);
        // Left Left Case
        if (balance > 1 && getBalance(curr->left) >= 0)
        {
            cout << "Tree is unbalanced. Performing right rotation." << endl;
            return rightRotate(curr);
        }
        // Left Right Case
        if (balance > 1 && getBalance(curr->left) < 0)
        {
            cout << "Tree is unbalanced. Performing left-right rotation." << endl;
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }
        // Right Right Case
        if (balance < -1 && getBalance(curr->right) <= 0)
        {
            cout << "Tree is unbalanced. Performing left rotation." << endl;
            return leftRotate(curr);
        }
        // Right Left Case
        if (balance < -1 && getBalance(curr->right) > 0)
        {
            cout << "Tree is unbalanced. Performing right-left rotation." << endl;
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }

        return curr;
    }

    bool is_AVL(node* n)
    {
        if (n == NULL)
        {
            return true;
        }
        int balance = getBalance(n);
        if (balance != -1 && balance != 0 && balance != 1)
        {
            return false;
        }
        is_AVL(n->left);
        is_AVL(n->right);
        return true;
    }

    Employee* searchEmployee(node* curr, int id)
    {
        if (curr == NULL)
        {
            return NULL; // Employee not found
        }
        if (id == curr->data)
        {
            return curr->employee; // Found the employee
        }
        else if (id < curr->data)
        {
            return searchEmployee(curr->left, id);
        }
        else
        {
            return searchEmployee(curr->right, id);
        }
    }

    void modifyEmployeeInfo(int id, const string& newName, const string& newDesignation)
    {
        Employee* emp = searchEmployee(root, id);
        if (emp != NULL)
        {
            emp->name = newName;
            emp->designation = newDesignation;
            cout << "Employee information updated successfully" << endl;
        }
        else
        {
            cout << "Employee with ID " << id << " not found!" << endl;
        }
    }

    void removeEmployee(int id)
    {
        root = deletion(root, id);
        cout << "Employee with ID " << id << " removed successfully" << endl;
    }

    void displayOrganizationalChart()
    {
        displayTree(root);
    }

private:
    void displayTree(node* root)
    {
        if (root == NULL) 
        {
            return;
        }


        displayTree(root->right);

        cout << setw(3) << ' ';
        cout << "ID: " << root->data << ", Name: " << root->employee->name
                  << ", Designation: " << root->employee->designation<< endl;

        displayTree(root->left);
    }
};

int main()
{
    avl t;

    // Employee* emp1 = new Employee(101, "John Doe", "Manager");
    // t.setRoot(t.insert(t.getRoot(), emp1));

    // Employee* emp2 = new Employee(102, "Jane Doe", "Supervisor");
    // t.setRoot(t.insert(t.getRoot(), emp2));

    // Employee* emp3 = new Employee(103, "Bob Smith", "Team Lead");
    // t.setRoot(t.insert(t.getRoot(), emp3));

    // Employee* emp4 = new Employee(104, "Alice Johnson", "Developer");
    // t.setRoot(t.insert(t.getRoot(), emp4));

    int option, id;
    string name, designation;

    while (1)
    {
        cout << "\nMenu:\n"
             << "1. Add Employee\n"
             << "2. Search for Employee\n"
             << "3. Generate Organizational Chart\n"
             << "4. Modify Employee Information\n"
             << "5. Remove Employee\n"
             << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "Enter employee ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter employee name: ";
            getline(cin >> ws, name);
            cout << "Enter employee designation: ";
            getline(cin >> ws, designation);
            Employee* newEmployee = new Employee(id, name, designation);
            t.setRoot(t.insert(t.getRoot(), newEmployee));
            break;
        }
        case 2:
        {
            cout << "Enter employee ID to search: ";
            cin >> id;
            Employee* result = t.searchEmployee(t.getRoot() ,id);
            if (result != NULL)
            {
                cout << "Employee found! \nDetails: ID: " << result->id << ", Name: " << result->name
                     << ", Designation: " << result->designation << endl;
            }
            else
            {
                cout << "Employee with ID " << id << " not found!" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Organizational Chart:" << endl;
            t.displayOrganizationalChart();
            break;
        }
        case 4:
        {
            cout << "Enter employee ID to modify: ";
            cin >> id;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin >> ws, name);
            cout << "Enter new designation: ";
            getline(cin >> ws, designation);
            t.modifyEmployeeInfo(id, name, designation);
            break;
        }
        case 5:
        {
            cout << "Enter employee ID to remove: ";
            cin >> id;
            t.removeEmployee(id);
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
            cout << "Invalid option. Please choose a valid option." << endl;
        }
    }

    return 0;
}
