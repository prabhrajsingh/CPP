#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

Node *head = NULL;

void insert(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;

    Node *traverse = head;

    if(head != NULL)
    {
        while(traverse->next != head)
        {
            traverse = traverse->next;
        }
        traverse->next = new_node;
    }
    else
    {
       new_node->next = new_node;
    }
    head = new_node;
}

void display()
{
    Node *traverse = head;
    if(head != NULL)
    {
        do
        {
            /* code */
            cout<<traverse->data<<"\t";
            traverse = traverse->next;
        } while (traverse != head);
    }
}
int main()
{
    for(int i=1; i<=10; i++)
    {
        insert(i);
    }

    cout<<"CIRCULAR LIST : "<<endl; //line very very important....................

    display();
}

