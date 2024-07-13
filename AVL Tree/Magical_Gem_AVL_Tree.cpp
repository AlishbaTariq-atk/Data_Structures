#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    int height;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        height = 0;
        left = NULL;
        right = NULL;
    }
};

class avl
{
    node *root;

    public:
    avl()
    {
        root = NULL;
    }
    node * getRoot()
    {
        return root;
    }
    int getHeight(node *curr)
    {
        if(curr == NULL)
        {
            return -1;
        }
        return curr->height;  
    }
    void setRoot(node *n)
    {
        root = n;
    }
    node* search(node *curr, int value)
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
    void inorder(node *n)
    {
        if(n == NULL)
        {
            return;
        }
        inorder(n->left);
        cout << n->data << "\t" ;
        inorder(n->right);
    }
    int max(int n, int curr)
    {
        if(n > curr)
        {
            return n;
        }
        else 
        return curr;
    }
    int min(int n, int curr)
    {
        if(n < curr)
        {
            return n;
        }
        else 
        return curr;
    }
    node * min_Value(node* n)
    {
        node *curr = n;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    node * max_Value(node* n)
    {
        node *curr = n;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr;
    }
    node* rightRotate(node *curr)
    {
        node *t1 = curr->left;
        node *t2 = t1->right;

        t1->right = curr;    // Performing rotation
        curr->left = t2;

        curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
        t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;
    
        return t1;
    }
    node *leftRotate(node *curr)
    {
        node *t1 = curr->right;
        node *t2 = t1->left;
    
        t1->left = curr;     // Performing rotation
        curr->right = t2;
    
        curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
        t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;

        return t1;
    }
    int getBalance(node *curr)
    {
        if(curr == NULL)
        {
            return 0;
        }
        return getHeight(curr->left) - getHeight(curr->right);
    }
    node* insert(node *curr, int value)
    {
        if(curr == NULL)
        {
            return new node(value);
        }
        if(value < curr->data)
        {
            curr->left = insert(curr->left, value);
        }
        else if(value > curr->data)
        {
            curr->right = insert(curr->right, value);
        }
        else
        {
            return curr;
        }

        curr->height = 1 + max(getHeight(curr->left) ,  getHeight(curr->right));
        int balance = getBalance(curr);
        //left left case
        if(balance > 1 && value < curr->left->data)
        {
            cout << "Tree is unbalanced. Performing right rotation." << endl;
            return rightRotate(curr);
        }
        //right right
        if(balance < -1 && value > curr->right->data)
        {
            cout << "Tree is unbalanced. Performing left-right rotation." << endl;
            return leftRotate(curr);
        }
        //left right case
        if(balance > 1 && value > curr->left->data)
        {
            cout << "Tree is unbalanced. Performing left rotation." << endl;
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }
        //right left case
        if(balance < -1 && value < curr->right->data)
        {
            cout << "Tree is unbalanced. Performing right-left rotation." << endl;
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }

        return curr;
    }
    node *deletion(node *curr, int value)
    {
        if(curr == NULL)
        {
            return curr;
        }
        if( value < curr->data)
        {
            curr->left = deletion(curr->left, value);
        }
        else if(value > curr->data)
        {
            curr->right = deletion(curr->right, value);
        }
        else
        {
            //no child case or one child case
            if(curr->left == NULL || curr->right == NULL)
            {
                node *temp;
                if(curr->left == NULL)
                {
                    temp = curr->right;
                }
                else
                {
                    temp  = curr->left;
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
            else//two children case
            {
                node* temp = min_Value(curr->right);//inorder successor
                curr->data = temp->data;

                curr->right = deletion(curr->right, curr->data);
            }
        }
        if (curr == NULL)
        {
            return curr;
        }
        curr->height = 1 + max(getHeight(curr->left) ,  getHeight(curr->right));
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
    node* update(node* n, int curr_value, int new_value) 
    {
        n = deletion(n, curr_value);
        n = insert(n , new_value);
        return n;
    }

 
};

int main()
{
    avl t;
    node* root = NULL;

    int option, value, newValue;

    while (1) 
    {
        cout << "\nMenu:\n"
             << "1. Insert a value\n"
             << "2. Delete a value\n"
             << "3. Find minimum value\n"
             << "4. Find maximum value\n"
             << "5. Update a value\n"
             << "6. Search for a value\n"
             << "7. Display the tree\n"
             << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) 
        {
            case 1:
            {
                cout << "Enter the value to insert: ";
                cin >> value;
                root = t.insert(root, value);
                cout << "Inserted successfully" << endl;
                break;
            }
            case 2:
            {
                cout << "AVL TREE:\n";
                t.inorder(root);
                cout << "Enter the value to delete: ";
                cin >> value;
                if(t.search(root, value) != NULL)
                {
                    root = t.deletion(root, value);
                    cout << "Deleted succesfully!" << endl;
                }
                else
                {
                    cout << "Value not found in tree!" << endl;
                }
                
                break;
            }
            case 3:
            {
                cout << "Minimum Value in tree = " << t.min_Value(root)->data << endl;
                break;
            }
            case 4:
            {
                cout << "Maximum Value in tree = " << t.max_Value(root)->data << endl;
                break;
            }
            case 5:
            {
                t.inorder(root);
                cout << "\nEnter the value to update: ";
                cin >> value;
                cout << "Enter the new value: ";
                cin >> newValue;
                if(t.search(root, value) == NULL)
                {
                    cout << "current value not found! Kindly enter a valid current value." << endl;
                }
                else
                {
                    root = t.update(root, value, newValue);
                    cout << "Updated successfully" << endl;
                }
                break;
            }
            case 6:
            {
                cout << "Enter the value to search: ";
                cin >> value;
                if(t.search(root, value) == NULL)
                {
                    cout << value <<" not found in tree!" << endl;
                }
                else
                {
                    cout << value <<" found!" << endl;
                }
                break;

            }  
            case 7:
            {
                cout << "AVL TREE:" << endl;
                t.inorder(root);
                break;

            } 
            case 8:
                return 0;

            default:
                cout << "Invalid option. Please choose a valid option." << endl;
        }
    }
    
    return 0;
}
