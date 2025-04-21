//Singly linked list....
//Node ---> user defined datastructure
//keep a data and address of next Node..
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
    public:
        Node * head;
        
        LinkedList()
        {
            head = NULL;
        }

       void insertAtHead(int d);
       void printList();

       bool searchElement(int target);
       void deleteNode(int target);
       int length();
       Node *middle();
       Node* middleUsingTortosiseAlgo();
       

};

int LinkedList::length()
{
    int len = 0;
    Node *cur = head;
    while(cur!=NULL)
    {
        cur = cur->next;
        len++;
    }
    return len;
}

Node* LinkedList::middle()
{
    int len = length();

    Node *cur = head;

    for(int i = 0;i<len/2;i++)
    {
        cur = cur->next;
    }

    return cur;
}

Node* LinkedList::middleUsingTortosiseAlgo()
{
   
        Node *slow = head;
        Node *fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}

void LinkedList::deleteNode(int target)
{
    if(head==NULL)
    {
        return;
    }

    //first node to be deleted
    if(head->data == target)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node * cur = head;
    while( cur->next!=NULL && cur->next->data!=target)
    {
        cur= cur->next;
    }
    if(cur->next==NULL)
    {
        cout<<"No target present"<<endl;
        return;


    }

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

bool LinkedList::searchElement(int target)
{
    if(head==NULL)
    {
        return false;
    }

    Node *cur = head;
    while(cur!=NULL && cur->data!=target)
    {
        cur = cur->next;
    }
    if(cur==NULL)
    {
        return false;
    }
    return true;
}

void LinkedList::printList()
{
    //Base case.......
    if(head==NULL)
    {
        cout<<"No list to print"<<endl;
        return;
    }

    Node* cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<"---->";
        cur = cur->next;
    }

}

void LinkedList::insertAtHead(int d)
{
    Node *temp = new Node;
    temp->data = d;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

int main()
{
    LinkedList sll;
    sll.insertAtHead(10);
    sll.insertAtHead(5);
    sll.insertAtHead(8);
    sll.insertAtHead(6);
    sll.insertAtHead(7);
    sll.insertAtHead(9);

    sll.printList();

    // cout<<endl;
    // int target;
    // cout<<"Enter the target element"<<endl;
    // cin>>target;

    // sll.searchElement(target)?cout<<"Element found"<<endl : cout<<"Element not found"<<endl;

    // target;
    // cout<<"Enter the target element"<<endl;
    // cin>>target;

    // sll.deleteNode(target);
    // cout<<endl;
    // sll.printList();
    // cout<<endl;
    cout<<endl;
    Node *mid = sll.middle();
    cout<<mid->data<<endl;
}