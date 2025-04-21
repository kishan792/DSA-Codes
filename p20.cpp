//dpoubly linked lisk....
//Node ---> user defined data structure
//keep a data and address of next Node it will address of previos Node...
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    
    Node()
    {
        prev = NULL;
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

       void reversePrintList();
       bool searchElement(int target);
       void deleteNode(int target);
       

};

bool LinkedList::searchElement(int target)
{
    if(head==NULL)
    {
        return false;
    }

    Node *cur = head;
    while(cur!=NULL)
    {
        if(cur->data==target)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
   
}

void LinkedList::reversePrintList()
{
    if(head==NULL)
    {
        cout<<"No list to print"<<endl;
        return;
    }

    Node* cur = head;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    }

    while(cur!=NULL)
    {
        cout<<cur->data<<"----->";
        cur = cur->prev;
    }
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
    temp->next->prev = cur;
    delete temp;
}

void LinkedList::insertAtHead(int d)
{
   Node *temp = new Node; 
   temp->data = d;
   if(head==NULL)
   {
    head = temp;
   }
   else{
        temp->next =head;
        head->prev = temp;
        head = temp;
   }
}

int main()
{
    LinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtHead(5);
    dll.insertAtHead(8);
    dll.insertAtHead(6);
    dll.insertAtHead(7);

    cout<<"Print in next direction"<<endl;
    dll.printList();
    cout<<endl;
    cout<<"prining in reverse direction"<<endl;
    dll.reversePrintList();

     cout<<endl;
    int target;
    cout<<"Enter the target element"<<endl;
    cin>>target;

    dll.searchElement(target)?cout<<"Element found"<<endl : cout<<"Element not found"<<endl;

    target;
    cout<<"Enter the target element"<<endl;
    cin>>target;

    dll.deleteNode(target);
    cout<<endl;
    dll.printList();
    cout<<endl;

    cout<<endl;
    cout<<"prining in reverse direction"<<endl;
    dll.reversePrintList();

}