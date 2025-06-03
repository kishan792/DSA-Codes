#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class BinaryTree
{
    public:
    Node*  createAVL(Node* &root,int d);
    int getHeight(Node* root);
    int getBalance(Node* root);
    Node* leftRotate(Node *x);
    Node* rightRotate(Node *y);
    void preOrder(Node* root);
};
void BinaryTree::preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<"   ";
    preOrder(root->left);
    preOrder(root->right);
}
Node* BinaryTree::leftRotate(Node* x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;


    return y;
}

Node* BinaryTree::rightRotate(Node* y)
{
    Node *x= y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

    return x;

}

int BinaryTree::getBalance(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

int BinaryTree::getHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;
}

Node* BinaryTree::createAVL(Node* &root,int d)
{
    
    if(root==NULL)
    {
        Node *temp = new Node(d);
        return temp;
    }
    else if(root->data<d)
    {
        root->right = createAVL(root->right,d);
    }
    else
    {
        root->left = createAVL(root->left,d);
    }

    root->height = max(getHeight(root->left),getHeight(root->right))+1;

    int balance = getBalance(root);

    if(balance>1 && root->left->data>d)
    {
        return rightRotate(root);
       
    }
    if(balance<-1 && root->right->data<d)
    {
        return leftRotate(root);
    }
    if(balance>1 && root->left->data < d)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && root->right->data>d)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

int main()
{
    Node *root = NULL;
    BinaryTree avl;
    root = avl.createAVL(root,50);
    root = avl.createAVL(root,60);
    root = avl.createAVL(root,55);

    avl.preOrder(root);
}