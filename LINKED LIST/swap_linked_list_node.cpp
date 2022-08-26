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
void swap(Node **head_ref, int x, int y)
{
    if(x==y)
    {
        return;
    }

    Node *previous_x = NULL;
    Node *current_x = *head_ref;
    while(current_x != NULL && current_x->data != x)
    {
        previous_x = current_x;
        current_x = current_x->next;
    }
    
    Node *previous_y = NULL;
    Node *current_y = *head_ref;
    while(current_y != NULL && current_y->data != y)
    {
        previous_y = current_y;
        current_y = current_y->next;
    }

    if (current_x == NULL || current_y == NULL)
    {
        return;
    }

    if (previous_x != NULL)
    {
        previous_x->next = current_y;
    }
    else
    {
        *head_ref = current_y;
    }

    if(previous_y != NULL)
    {
        previous_y->next = current_x;
    }
    else
    {
        *head_ref = current_x;
    }

    Node *temp = current_y->next;
    current_y->next = current_x->next;
    current_x->next = temp;
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

    int x = 0, y = 0;
    cout<<"\n\nENTER THE VALUES FOR WHICH SWAP NEED TO BE DONE : \n";
    cin>>x;
    cin>>y;
    swap(&head, x, y);
    cout<<endl;
    display();
    return 0;
}