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
    Node *traverse = head;
    while(traverse != NULL)
    {
        cout<<traverse->data<<"\t";
        traverse = traverse->next;
    }
}

void reverse_iterative()
{
    Node *current_node, *previous_node, *next_node;
    previous_node = NULL;

    if(head == NULL)
    {
        cout<<"LIST EMPTY";
    }
    else
    {
        current_node = head;
        while(current_node != NULL)
        {
            next_node = current_node->next;

            current_node->next = previous_node;

            previous_node = current_node;
            current_node = next_node;
        }
        head = previous_node;
    }
}

void reverse_recursive(Node *traverse)
{
    if(traverse->next == NULL)
    {   
        head = traverse;
        return ;
    }
    reverse_recursive(traverse->next);

    Node *temp = traverse->next;
    temp->next = traverse;
    traverse->next = NULL;
}
int main()
{
    for(int i=1; i<=5; i++)
    {
        insert(i);
    }
    display();
    cout<<endl;

    reverse_iterative();
    cout<<endl;
    display();

    cout<<endl;    
    reverse_recursive(head);
    cout<<endl;
    display();
}

