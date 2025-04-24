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
        Node *head;
        
        LinkedList()
        {
            head = NULL;
        }

       void insertAtHead(int d);     
       int length();
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
