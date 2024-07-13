#include <iostream>
#include <stack>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int power)
    {
        this->data = power;
        left = NULL;
        right = NULL;
    }
};

class bst
{
    node *root;

    public:
    bst()
    {
        root = NULL;
    }
    node * getRoot()
    {
        return root;
    }

    void setRoot(node *head)
    {
        root=head;
    }
    bool isEmpty()
    {
        if(root == NULL)
        {
            cout << "Binary Search Tree is Empty yet!" << endl;
            return true;
        }
        else 
        return false;
    }
    node * insert(node *curr,int value)
    {
        if(curr == NULL)
        {
            return new node(value);
        }
        if( value < curr->data)
        {
            curr->left = insert(curr->left, value);
            return curr;
        }
        else if(value > curr->data)
        {
            curr->right = insert(curr->right, value);
            return curr;
        }
        else //duplication case (curr->power == pows)
        {
            return curr;
        }
    }
    node* search(node *curr, int value)
    {
        if (curr == NULL)
        {
            return NULL; 
        }
        if (value == curr->data)
        {
            return curr; 
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
    void preorder(node *n)
    {
        if(n == NULL)
        {
            return;
        }
        cout << n->data << "\t" ;
        preorder(n->left);
        preorder(n->right);
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
    void postorder(node *n)
    {
        if(n == NULL)
        {
            return;
        }
        postorder(n->left);
        postorder(n->right);
        cout << n->data << "\t" ;
    }
    node * find_predecessor(node *curr) 
    {
       if(curr == NULL)
       {
         return curr;
       }
       if(curr->right == NULL)
       {
         return curr;
       }
       return find_predecessor(curr->right);
    }
    node *parent(node *curr, node *child, node *par) //curr = curr node, child = child for par, par = parent we r looking for
    {
        if(curr == NULL)
        {
            return NULL;
        }
        if(curr == child)
        {
            return par;
        }
        else
        {
            node *t = NULL;
            t = parent(curr->left, child, curr);
            if(t!=NULL)
            {
                return t;
            }
            else
            {
                t = parent(curr->right, child, curr);
                return t;
            }
        }
    }
    node* delete_node(node *curr, int value)
    {
        if (curr == NULL)
        {
            return curr;
        }
        node* this_node = search(curr, value); // child
        node* par = parent(curr, this_node, curr); // parent
        if (this_node == NULL)
        {
            return curr;
        }
        else if (this_node == root) // Deleting the root node
        {
            if (this_node->left != NULL && this_node->right != NULL)
            {
                node* predecessor = find_predecessor(this_node->left);
                int temp = this_node->data;
                this_node->data = predecessor->data;
                this_node->left = delete_node(this_node->left, predecessor->data);
            }
            else
            {
                if (this_node->left != NULL)
                {
                    node* newRoot = this_node->left; 
                    delete this_node;
                    root = newRoot; 
                }
                else
                {
                    node* newRoot = this_node->right; 
                    delete this_node;
                    root = newRoot; 
                }
            }
        }
        else if (this_node->left == NULL && this_node->right == NULL) // Node is a leaf
        {
            if (par->left == this_node)
            {
                delete this_node;
                par->left = NULL;
            }
            else
            {
                delete this_node;
                par->right = NULL;
            }
            return curr; 
        }
        else if (this_node->left != NULL && this_node->right == NULL) // Node with only a left child
        {
            if (par->left == this_node)
            {
                par->left = this_node->left;
            }
            else
            {
                par->right = this_node->left;
            }
            delete this_node;
            return curr; 
        }
        else if (this_node->right != NULL && this_node->left == NULL) // Node with only a right child
        {
            if (par->left == this_node)
            {
                par->left = this_node->right;
            }
            else
            {
                par->right = this_node->right;
            }
            delete this_node;
            return curr; 
        }
        else if (this_node->left != NULL && this_node->right != NULL) // Node with two children
        {
            node* predecessor = find_predecessor(curr->left); //find predecessor as the max number in left subtree of curr node
            int temp = curr->data;  //switching values of curr with its predecessor
            curr->data = predecessor->data;
            predecessor->data = temp;
            this_node->left = delete_node(curr->left, predecessor->data);
            return curr; 
        }
        
        return curr; 
    }

    
 
};

int main()
{
    bst t;
    int option = 0;
    int value;
  

    while(option!= 5)
    {
        cout << "Menu: \n 1.Display bst\n 2. Seacrh for a node\n 3. Insert in bst\n 4. delete from bst\n 5. Exit"<< endl;
        cin >> option;

        switch(option)
        {
            case 1:
            {   if(t.isEmpty()!=true)
                {
                    cout << "Display \n 1. Pre-order\n 2. In-order\n 3. Post-Order" << endl;
                    cin >> option;
                    if(option == 1)
                    {
                        cout << "BST (Pre-order): " ;
                        t.preorder(t.getRoot());
                        cout << endl;
                    }
                    else if(option == 2)
                    {
                        cout << "Magical Tree (In-order): " ;
                        t.inorder(t.getRoot());
                        cout << endl;
                    }
                    else if(option == 3)
                    {
                        cout << "Magical Tree (Post-order): " ;
                        t.postorder(t.getRoot());
                        cout << endl;
                    }
                    else
                    {
                        cout << "Invalid input!" << endl;
                    }
                }
                    
                break;
            }
            case 2:
            {
                if(!t.isEmpty())
                {
                    cout << "Search for a node: ";
                    cin >> value;
                    node* foundgem = t.search(t.getRoot(),value);
                    if(foundgem != NULL)
                    {
                        cout << "Node with value " << value << " found in bst." << endl;
                    }
                    else
                    {
                        cout << "Node with such value not found!" << endl;
                    }
                }
                break;
            }
            case 3:
            {
                cout << "Enter value to insert: ";
                cin >> value;
                t.setRoot(t.insert(t.getRoot(),value)); 
                break;
            }
            case 4:
            {
                cout << "Available values: " << endl;
                t.inorder(t.getRoot());
                cout << "\nWhich value to delete: ";
                cin >> value;
                node* foundGem = t.search(t.getRoot(), value);
                if(t.isEmpty())
                {
                    cout << "Nothing to delete!" << endl;
                }
                else if (foundGem != NULL) 
                {
                    t.setRoot(t.delete_node(t.getRoot(), value));
                    if(t.delete_node(t.getRoot(), value) != NULL)
                    {
                        cout << "Value deleted successfully! " << endl;
                    }  
                   
                } 
                else 
                {
                    cout << "Node with such value not found!" << endl;
                }
                break;
            }
            
        }
    }

    return 0;
}