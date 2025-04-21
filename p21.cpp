//Circular linked list
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
};

void LinkedList::insertAtHead(int d)
{
    Node *temp = new Node;
    temp->data = d;
    if(head==NULL)
    {
        head=temp;
        head->next = head;
    }
    else
    {
        Node* cur = head;
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        cur->next = temp;
        temp->next = head;
        head= temp;
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
    do
    {
        cout<<cur->data<<"---->";
        cur = cur->next;
    }while(cur!=head);

}

int main()
{
    LinkedList cll;
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.insertAtHead(30);
    cll.insertAtHead(40);
    cll.insertAtHead(50);

    cll.printList();
}