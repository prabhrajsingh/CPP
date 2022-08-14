#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};

Node *head = new Node();

void insert(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void display()
{
    Node *traverse = new Node();
    traverse = head;
    while(traverse != NULL)
    {
        cout<<traverse->data<<"\t";
        traverse = traverse->next;
    }
}

void push_starting(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void push_after_a_node(int new_data, int position)
{
    Node *new_node = new Node();
    Node *traverse = head;

    new_node->data = new_data;

    for(int i=0; i<position-1; i++)
    {
        traverse = traverse->next;
    }
    new_node->next = traverse->next;
    traverse->next = new_node;
}

void push_ending(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *traverse = *head_ref; // to go to the last element

    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    while(traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    traverse->next = new_node;
}

void deleteNode(int del) 
{   
    Node *traverse = head;
    for(int i=0; i<del-1; i++)
    {
        traverse = traverse->next;
    }
    traverse->data = traverse->next->data;
    traverse->next = traverse->next->next;
}

int main()
{
    int n = 0;
    cout<<"ENTER ELEMENTS SIZE : ";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        insert(i);
    }

    display();

    int new_data, position;
    cout<<"\nENTER A NODE AFTER CREATION OF THE LINKED LIST : \n";
    
    cout<<"STARTING : "<<endl;
    cin>>new_data;
    push_starting(&head, new_data);
    
    cout<<"IN-BETWEEN : "<<endl;
    cin>>new_data;
    cout<<"WHERE : "<<endl;
    cin>>position;
    push_after_a_node(new_data, position);
    
    cout<<"ENDING : "<<endl;
    cin>>new_data;
    push_ending(&head, new_data);

    display();

    int del;
    cout<<"\nWHICH ELEMENT INDEX TO BE DELETED : ";
    cin>>del;
    deleteNode(del);

    cout<<"\nAFTER DELETION : \n";
    display();

}

