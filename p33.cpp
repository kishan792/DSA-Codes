//Binary search tree
#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
    public:
        Node* createTree(Node* &root, int d);
        bool searchInBst(Node* root,int target);
        bool searchBST(Node* root,int target);
        int getMinValue(Node* root);
        void inOrder(Node *root);
        Node* deleteFromBST(Node* root,int target);
};

int BinaryTree::getMinValue(Node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->left==NULL)
    {
        return root->data;
    }

    Node* cur = root;
    while(cur->left!=NULL)
    {
        cur = cur->left;
    }
    return cur->data;
}

Node* BinaryTree::createTree(Node* &root,int d)
{
    if(root==NULL)
    {
        Node* temp = new Node;
        temp->data = d;
        return temp;
    }

    if(root->data<d)
    {
        root->right = createTree(root->right,d);
    }
    else
    {
        root->left = createTree(root->left,d);
    }
    return root;
}

void BinaryTree::inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inOrder(root->left);
    cout<<root->data<<"   ";
    inOrder(root->right);
}

bool BinaryTree::searchInBst(Node* root,int target)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data == target)
    {
        return true;
    }

    if(root->data<target)
    {
        return searchInBst(root->right,target);
    }

    return searchInBst(root->left,target);

}

bool BinaryTree::searchBST(Node* root,int target)
{
    if(root==NULL)
    {
        return false;
    }

   Node *cur = root;

   while(cur!=NULL)
   {
    if(cur->data==target){
        return true;
    }
    if(cur->data<target){
        cur=cur->right;
    }
    else{
       cur=cur->left;
    }
   }
    return false;
}

Node* BinaryTree::deleteFromBST(Node* root,int target)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==target)
    {
        //delete code
        //case 1 -> 0 child case
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //case 2 -> 1 child case 
        //sub case -> left child case
        if(root->left!=NULL && root->right==NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //sub case -> right child case
        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //case 3 --> 2 child case
        if(root->left!=NULL && root->right!=NULL)
        {
            int mn = getMinValue(root->right);
            root->data = mn;
            root->right = deleteFromBST(root->right,mn);
            return root;
        }

    }
    else if(root->data<target)
    {
        root->right = deleteFromBST(root->right,target);
        return root;
    }
    else
    {
       root->left =  deleteFromBST(root->left,target);
        return root;
    }
    return root;
}

int main()
{
    BinaryTree bst;
    Node* root = NULL;
    int d;
    while(true)
    {
        cout<<"Enter the element"<<endl;
        cin>>d;

        if(d==-1)
        {
            break;
        }
        root = bst.createTree(root,d);
    }

    cout<<"Inorder traversal "<<endl;
    bst.inOrder(root);

    cout<<endl;

    // bst.searchInBst(root,80) ? cout<<"Element found"<<endl : cout<<"Element not found"<<endl;
    // bst.searchBST(root,60) ? cout<<"Element found"<<endl : cout<<"Element not found"<<endl;

    // cout<<"Inorder successor of 50"<<endl;
    // cout<<bst.getMinValue(root->right);

    root  = bst.deleteFromBST(root,50);

    cout<<"Inorder traversal "<<endl;
    bst.inOrder(root);

    cout<<endl;
    
    return -1;
}