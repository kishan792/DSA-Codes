#include<iostream>
#include<queue>
#include<stack>
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
       Node* buildTree();
       void preOrder(Node* root);
       void inOrder(Node* root);
       void postOrder(Node* root);
       void levelOrder(Node *root);
       Node* createTree(Node* &root,int d);
       void preOrderIter(Node* root);
};

void BinaryTree::preOrderIter(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    stack<Node*> st;
    st.push(root);
    Node* cur = NULL;

    while(st.empty()!=true)
    {
        cur = st.top();
        st.pop();

        cout<<cur->data<<"  ";
        if(cur->right!=NULL)
        {
            st.push(cur->right);
        }
        if(cur->left!=NULL)
        {
            st.push(cur->left);
        }
    }

}
Node* BinaryTree::createTree(Node* &root,int d)
{
    Node* temp = new Node;
    temp->data = d;

    if(root==NULL)
    {
        root=temp;
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(q.empty()!=true)
    {
        Node *cur = q.front();
        q.pop();

        if(cur->left==NULL)
        {
            cur->left = temp;
            return root;
        }
        else{
            q.push(cur->left);
        }


        if(cur->right==NULL)
        {
            cur->right = temp;
            return root;
        }
        else{
            q.push(cur->right);
        }
    }
    return root;
}

void BinaryTree::levelOrder(Node *root)
{
    if(root==NULL)
    {
        cout<<"No tree to print the value"<<endl;
        return;
    }
    queue<Node*>q;
    q.push(root);

    while(q.empty()!=true)
    {
        Node *cur = q.front();
        q.pop();

        cout<<cur->data<<"  ";
        if(cur->left!=NULL)
        {
            q.push(cur->left);
        }
        if(cur->right!=NULL)
        {
            q.push(cur->right);
        }
    }
}

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

void BinaryTree::postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"   ";
}
Node* BinaryTree::buildTree()
{
    int d;
    cout<<"Enter the Data"<<endl;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    Node *root = new Node;
    root->data = d;

    root->left = buildTree();
    root->right = buildTree();

    return root;
}
int main()
{
    BinaryTree bt;
    Node* root = NULL;
    int d;
    for(int i = 0;i<6;i++)
    {
        cout<<"Enter the data"<<endl;
        cin>>d;
        root = bt.createTree(root,d);
    }

    cout<<"Pre Order traversal "<<endl;
    bt.preOrder(root);

    cout<<endl;

    cout<<"in Order traversal "<<endl;
    bt.inOrder(root);

    cout<<endl;

    cout<<"Post Order traversal "<<endl;
    bt.postOrder(root);

    cout<<endl;

    cout<<"level Order traversal "<<endl;
    bt.levelOrder(root);

    cout<<endl;
}