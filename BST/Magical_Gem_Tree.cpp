#include <iostream>
#include <stack>
using namespace std;

class node
{
    public:
    string name;
    int data;
    node *left;
    node *right;

    node(string name, int power)
    {
        this->name = name;
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
    node * insert(node *curr,string name, int pow)
    {
        if(curr == NULL)
        {
            return new node(name,pow);
        }
        if( pow < curr->data)
        {
            curr->left = insert(curr->left,name, pow);
            return curr;
        }
        else if(pow > curr->data)
        {
            curr->right = insert(curr->right, name, pow);
            return curr;
        }
        else //duplication case (curr->power == pows)
        {
            return curr;
        }
    }
    node* search(node *curr, int pow)
    {
        if (curr == NULL)
        {
            return NULL; // Gem not found
        }
        if (pow == curr->data)
        {
            return curr; 
        }
        else if (pow < curr->data)
        {
            return search(curr->left, pow);
        }
        else
        {
            return search(curr->right, pow);
        }
    }
    void preorder(node *n)
    {
        if(n == NULL)
        {
            return;
        }
        cout << "[" << n->name << ", " << n->data << "]\t" ;
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
        cout << "[" << n->name << ", " << n->data << "]\t" ;
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
        cout << "[" << n->name << ", " << n->data << "]\t" ;
    }
    node * maxpower(node *curr)
    {
       if(curr == NULL)
       {
         return curr;
       }
       if(curr->right == NULL)
       {
         return curr;
       }
       return maxpower(curr->right);
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
    node* delete_node(node *curr, int pow)
    {
        if (curr == NULL)
        {
            return curr;
        }
        node* gem = search(curr, pow); // child
        node* par = parent(curr, gem, curr); // parent
        if (gem == NULL)
        {
            // cout << "Gem not found!" << endl;
            return curr;
        }
        else if (gem->left == NULL && gem->right == NULL) // Node is a leaf
        {
            if (par->left == gem)
            {
                delete gem;
                par->left = NULL;
            }
            else
            {
                delete gem;
                par->right = NULL;
            }
            return curr; 
        }
        else if (gem->left != NULL && gem->right == NULL) // Node with only a left child
        {
            if (par->left == gem)
            {
                par->left = gem->left;
            }
            else
            {
                par->right = gem->left;
            }
            delete gem;
            return curr; 
        }
        else if (gem->right != NULL && gem->left == NULL) // Node with only a right child
        {
            if (par->left == gem)
            {
                par->left = gem->right;
            }
            else
            {
                par->right = gem->right;
            }
            delete gem;
            return curr; 
        }
        else if (gem->left != NULL && gem->right != NULL) // Node with two children
        {
            node* predecessor = maxpower(curr->left); //find predecessor as the max number in left subtree of curr node
            string c_name = curr->name; //switching values of curr with its predecessor
            int c_pow = curr->data;
            curr->name = predecessor->name;
            curr->data = predecessor->data;
            predecessor->name = c_name;
            predecessor->data = c_pow;
            curr->left = delete_node(curr->left, predecessor->data);
            return curr; 
        }
        return curr; 
    }

    
 
};

int main()
{
    bst t;
    int bag_power = 0;
    int bag = 0;
    int option = 0;
    int pow;
    node *root = t.getRoot();
    root = t.insert(root,"Diamond",50);
    root = t.insert(root, "Ruby", 30);
    root = t.insert(root, "Sapphire", 70);
    root = t.insert(root, "Pearl", 40);
    root = t.insert(root, "Opal", 10);
    root = t.insert(root, "Garnet", 60);
    root = t.insert(root, "Zircon", 20);
    root = t.insert(root, "Jade", 5);
  
    cout << "Welcome to the magical forest." << endl;
    cout << "How much magical power you bag can hold?" << endl;
    cin >> bag;

    while(option!= 5)
    {
        cout << "Menu: \n 1.Display the magical tree\n 2. Seacrh for gem by its power\n 3. Find highest power gem\n 4. pluck gem from tree\n 5. Exit"<< endl;
        cin >> option;

        switch(option)
        {
            case 1:
            {
                cout << "Display \n 1. Pre-order\n 2. In-order\n 3. Post-Order" << endl;
                cin >> option;
                if(option == 1)
                {
                    cout << "Magical Tree (Pre-order): " ;
                    t.preorder(root);
                    cout << endl;
                }
                else if(option == 2)
                {
                    cout << "Magical Tree (In-order): " ;
                    t.inorder(root);
                    cout << endl;
                }
                else if(option == 3)
                {
                    cout << "Magical Tree (Post-order): " ;
                    t.postorder(root);
                    cout << endl;
                }
                else
                {
                    cout << "Invalid input!" << endl;
                }
                break;
            }
            case 2:
            {

                cout << "Search for a gem by specifying its power: ";
                cin >> pow;
                node* foundgem = t.search(root,pow);
                if(foundgem != NULL)
                {
                    cout << "[" << foundgem->name << ", " << foundgem->data << "]" << endl;
                }
                else
                {
                    cout << "Gem with such power not found!" << endl;
                }
                break;
            }
            case 3:
            {
                node* curr = t.maxpower(root);
                cout << "Max power gem: " << curr->data  << endl;
                break;
            }
            case 4:
            {
                cout << "Available Gems: " << endl;
                t.inorder(root);
                cout << "\nWhich gem to pluck?(Enter power): ";
                cin >> pow;
                node* foundGem = t.search(root, pow);
                if (foundGem != NULL) 
                {
                    root= t.delete_node(root, pow);
                    if(t.delete_node(root, pow) != NULL)
                    {
                        cout << "Gem plucked successfully! " << endl;
                        bag_power += pow;
                    }
                    else
                    {
                        cout << "Gem not found!" << endl;
                    }
                   
                    if (bag_power == bag) 
                    {
                        cout << "You won! Now take your bag and run from the forest!" << endl;
                        return 0;
                    } 
                    else if (bag_power > bag) 
                    {
                        cout << "You lost as your bag burst! Now run from the forest to save yourself!" << endl;
                        return 0;
                    }
                } 
                else 
                {
                    cout << "Gem with such power not found!" << endl;
                }
                break;
            }
            
        }
    }

    return 0;
}
