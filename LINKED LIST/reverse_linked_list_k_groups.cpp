#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

void insert(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void display(Node *node)
{
    Node *traverse = node;
    while(traverse->next != NULL)
    {
        cout<<traverse->data<<"\t";
        traverse = traverse->next;
    }
}

Node *reverseKGroup(Node *dummy_head, int k)
{
    if(dummy_head == NULL)
    {
        return NULL;
    }
    Node *check = dummy_head;
    for(int i=0; i<k; i++)
    {
        if(check == NULL)
        {
            return dummy_head;
        }
        check = check->next;
    }

    int count = 0;
    Node *current = dummy_head, *previous = NULL, *NEXT = NULL;
    while(current->next != NULL && count<k)
    {
        NEXT = current->next;
        current->next = previous;
        previous = current;
        current = NEXT;
        count++; //<-----------------------------------------very very important
    }

    if (NEXT != NULL)
    {
        dummy_head->next = reverseKGroup(NEXT, k);
    }
    return previous;
    
}
int main()
{
    Node *head = new Node();
    int n;
    cout<<"NO. OF ELEMENTS : ";
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        insert(&head, i);
    }
    display(head);


    head = reverseKGroup(head, 2);
    cout<<endl<<endl;
    display(head);
}