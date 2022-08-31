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

void display(Node *head)
{
    if(head == NULL)
    {
        cout<<"EMPTY";
    }
    else
    {
        Node *traverse = head;
        while(traverse->next != NULL)
        {
            cout<<traverse->data<<"\t";
            traverse = traverse->next;
        }
    }
}
Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // mid point of a link list
}
Node *merge(Node *left, Node *right)
{
    Node *new_head = new Node();
    Node *traverse = new_head;
    if (left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }
    while(left->next != NULL && right->next != NULL)
    {
        if(left->data < right->data)
        {
            traverse->next = left;
            traverse = left;
            left = left->next;
        }
        else
        {
            traverse->next = right;
            traverse = right;
            right = right->next;
        }
    }
    while(left->next != NULL)
    {
        traverse->next = left;
        traverse = left;
        left = left->next;
    }
    while(right->next != NULL)
    {
        traverse->next = right;
        traverse = right;
        right = right->next;
    }
    new_head = new_head->next;
    return new_head;
}
Node *merge_sort(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findmid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = merge_sort(left);
    right = merge_sort(right);

    Node *result = merge(left, right);

    return result;
}


int main()
{
    Node *head = new Node();
    int n = 0;
    cout<<"HOW MANY ELEMENTS : ";
    cin>>n;
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 1);
    insert(&head, 0);
    insert(&head, 3);
    display(head);

    Node *ans = merge_sort(head);

    display(ans);
}
