#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(node *root, int val)
{
    node *n = new node();
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (val == root->data)
        {
            //  cout<<"This Value Is Already Exits";
            return;
        }
        else if (val < root->data)
        {
            root = root->left;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
    }
    if (val < prev->data)
    {
        prev->left = n;
        n->data = val;
    }
    else if (val > prev->data)
    {
        prev->right = n;
        n->data = val;
    }
}

void del(node *root, int val)
{
    node *prev = root;
    while (root->data != val)
    {
        prev = root;
        if (val < root->data)
        {
            root = root->left;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
    }

    if (val < prev->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            prev->left = NULL;
        }
        else if (root->right == NULL)
        {
            prev->left = root->left;
        }
        else if (root->left == NULL)
        {
            prev->left = root->right;
        }
        else
        {
            prev->left = root->left;
            node *temp = prev->left->right;
            prev->left->right = root->right;
            prev->left->right->right = temp;
        }
    }

    else if (val > prev->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            prev->right = NULL;
        }
        else if (root->right == NULL)
        {
            prev->right = root->left;
        }
        else if (root->left == NULL)
        {
            prev->right = root->right;
        }
        else
        {
            prev->right = root->right;
            node *temp = prev->right->left;
            prev->right->left = root->left;
            prev->right->left->left = temp;
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

main()
{

    node *root = new node();
    root->data = 8;
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);
    insert(root, 13);
    insert(root, 10);
    insert(root, 15);
    insert(root, 13);
    insert(root, 18);
    insert(root, 17);
    insert(root, 9);
    insert(root, 0);
    insert(root, 5);
    insert(root, 7);
    insert(root, 2);
    insert(root, -5);
    inorder(root);
    cout << endl;
    del(root, 1);  // middle node deletion at left tree
    del(root, 14); // middle node deletion at right tree

    del(root, 0); // at left tree while root->right null and left has value

    del(root, -5); // at last both child null/leave node at left tree
    del(root, 15); // at last both child null/leave node at right tree
    inorder(root);
}