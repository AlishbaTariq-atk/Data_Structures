#include <iostream> 

using namespace std;

class node
{
    public:
        int data;
        node *left;
        node *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }   

};

class tree
{
    node *root;

    public:
        tree()
        {
            root = NULL;

        }
        void deleteTree(node *n)
        {
            if(n ==NULL)
            {
                return;
            }
            deleteTree(n->left);
                deleteTree(n->right);
                delete n;
        }
        node * getRoot()
        {
            return root;
        }
        void setLeft(node *n,int value)
        {
            node *curr = new node(value);
            n->left = curr;
            return;
        }
        void setRight(node *n,int value)
        {
            node *curr = new node(value);
            n->right = curr;
            return;
        }
        void insert(int value,int parentValue,int child_pos)
        {
            
            if(root == NULL)
            {
                root = new node(value);
                return;
            }
            else if(child_pos == 0)
            {
                root->data = value;
                return;
            }
            else
            {
                node *parent = search(parentValue,root);
                if(parent == NULL)
                {
                    cout << "Invalid parent!" << endl;
                    return;
                }

                if(child_pos == 1)
                {
                    setLeft(parent, value);
                }
                else
                {
                    setRight(parent, value);
                }
                return;
            }
            
        }
        node *search(int value, node *n)
        {
            if(n == NULL || n->data == value) 
            {
                return n;
            }
            node *found = NULL;
            found = search(value, n->left);
            if(found != NULL)
            {
                return found;
            } 
            return search(value, n->right);
        }
        int find_level(node *n, int value, int level)
        {
            if(n == NULL)
            {
                return 0;
            }
            if(n->data == value)
            {
                return level;
            }
            int l = find_level(n->left,value,level+1);
            if(l != 0)
            {
                return l;
            }
            return find_level(n->right,value, level+1);
        }
        int depth(node *n)
        {
            if(n == NULL)
            {       
                return -1;
            }
            int l = depth(n->left);
            int r = depth(n->right);
            if(l > r)
            {
                return l+1;
            }
            else 
            {
                return r+1;
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
        bool isEmpty()
        {
            if(root == NULL)
            {
                cout << "Tree is Empty Yet!" << endl;
                return true;
            }
            else
            {
                return false;
            }
        }
        void displayTree(node* n, int space)
        {

            if (n == NULL)
                return;

            // Increase distance between levels
            space += 10;

            displayTree(n->right, space);

            // Print current node after space count
            cout << endl;
            for (int i = 10; i < space; i++)
            {
                cout << " ";
            }    
            cout << n->data << "\n";

            displayTree(n->left, space);
        }
        void clearTree()
        {
            deleteTree(root);
            root = NULL;
            return;
        }

      


};

int main()
{
    tree t;
    int option;
    int value;
    int parent;
    int dir;

    while(option!= 7)
    {
        
        if(t.isEmpty() == false)
        {
            cout << "---Tree---: " << endl;
            t.displayTree(t.getRoot(),0);  
            cout << endl;
        }
        cout << "Menu\n 1. Insert\n 2. Traverse Tree\n 3. Find depth\n 4. Find level of a node\n 5. Search value\n 6. Delete tree\n 7. Exit " << endl;
        cin >> option;

        switch(option)
        {
            case 1:
            {
                cout << "Insert as:\n 1. Root\n 2. Child " << endl;
                cin >> option;
                cout << "Enter value of new node: ";
                cin >> value;
                if(option == 1)
                {
                    t.insert(value, 0, 0);
                }
                else
                {
                    cout << "Enter the value of parent to this new node: ";
                    cin >> parent;
                    cout << "New Node should be\n 1. Left\n 2. Right\n of this parent: ";
                    cin >> dir;
                    t.insert(value,parent,dir);
                }
                break;
            }
            case 2:
            {
                if (t.isEmpty())
                {
                    cout << "Nothing to traverse!" << endl;
                    break;
                }

                cout << "Traversal Type:\n 1. Preorder\n 2. Inorder\n 3. Postorder" << endl;
                cin >> option;
                
                if (option == 1)
                {
                    cout << "Pre-Order Traversal:" << endl;
                    t.preorder(t.getRoot());
                    cout << endl << endl;
                }
                else if (option == 2)
                {
                    cout << "In-Order Traversal:" << endl;
                    t.inorder(t.getRoot());
                    cout << endl << endl;
                }
                else if (option == 3)
                {
                    cout << "Post-Order Traversal:" << endl;
                    t.postorder(t.getRoot());
                    cout << endl << endl;
                }
                else
                {
                    cout << "Invalid traversal option!" << endl;
                }
                break;
            }

            case 3:
            {
                cout << "Depth = " << t.depth(t.getRoot()) << endl;
                break;
            }
            case 4:
            {
                t.displayTree(t.getRoot(),0);
                cout << "Enter value of node to get its level: ";
                cin >> value;
                cout << "Level of " << value << "= " << t.find_level(t.getRoot(),value,0) << endl;
                break;
            }
            case 5:
            {
                cout << "Enter Value to check in tree: " ;
                cin >> value;
                if(t.search(value, t.getRoot()) != NULL)
                {
                    cout << value << " found in tree!" << endl;
                    break;
                }
                else
                {
                    cout << value << " not found in tree!" << endl;
                    break;
                }
            }
            case 6:
            {
                t.clearTree();
                cout << "Tree deleted successfully!" << endl;
                break;
            }
            default:
            break;
        }
        
    }


    return 0;
}