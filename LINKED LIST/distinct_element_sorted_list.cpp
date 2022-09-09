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
    while(traverse->next != NULL)
    {
        cout<<traverse->data<<"\t";
        traverse = traverse->next;
    }
}
void distinct()
{
    Node *traverse = head;
    while(traverse->next != NULL)
    {
        if(traverse->data == traverse->next->data)
        {
            traverse->next = traverse->next->next;
        }
        else
        {
            traverse = traverse->next;
        }
    }
    cout<<endl<<endl;
    display();
}

int main()
{
    int x;
    cout<<"ENTER ELEMENTS : \n";
    for(int i=0; i<10; i++)
    {
        cin>>x;
        insert(x);
    }
    cout<<endl<<endl;
    display();
    distinct();
}