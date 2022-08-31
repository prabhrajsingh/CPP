#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            data = 0;
            next = NULL;
        }
};

void insert(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}
void display(Node *head)
{
    Node *traverse = head;
    while(traverse->next != NULL)
    {
        cout<<traverse->data<<"\t";
        traverse = traverse->next;
    }
}
Node* add(Node *l1, Node *l2)
{
    Node *l3 = new Node();
    int carry = 0, sum = 0;
    while(l1->next != NULL || l2 != NULL || carry != 0)
    {
        int value1 = 0;
        if(l1 != NULL)
            value1 = l1->data;
        
        int value2 = 0;
        if(l2 != NULL)
            value2 = l2->data;

        sum = carry + value1 + value2;
        carry = sum/10;

        insert(&l3, sum%10);

        if(l1 != NULL)
            l1 = l1->next;

        if(l2 != NULL)
            l2 = l2->next;
    }
    if(carry > 0 )
    {
        insert(&l3, carry);
    }
    return l3;
}
int main()
{
    int n;
    Node *l1 = new Node();
    cout<<"ENTER THE NUMBER OF NODE IN LINKED LIST 1: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        insert(&l1, i);
    }

    Node *l2 = new Node();
    cout<<"ENTER THE NUMBER OF NODE IN LINKED LIST 2: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        insert(&l2, i);
    }

    display(l1);
    cout<<endl;
    display(l2);
    cout<<endl<<endl;

    Node *l3 = add(l1 ,l2);
    display(l3);
}