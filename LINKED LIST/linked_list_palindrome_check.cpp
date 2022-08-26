#include<iostream>
#include<vector>
#include<stack>

using namespace std;
 
class Node 
{
    public:
        int data;
        Node *next;
        Node *next_stack;
};
Node *head = new Node();
Node *top;
void push(int new_data)
{
    Node *temp = new Node();

    while(!temp)
    {
        cout<<"STACK OVERFLOW";
        exit(1);
    }

    temp->data = new_data;
    temp->next_stack = top;
    top = temp;
}
int isempty()
{
    return (top == NULL);
}

int peek()
{
    Node *temp = new Node();
    if(!isempty())
    {
        return top->data;
    }
    else
    {
        exit(1);
    }
}

void pop()
{
    Node *temp = new Node();
    if(isempty())
    {
        cout<<"STACK EMPTY";
        exit(1);
    }
    else
    {
        temp = top;
        top = top->next_stack;
        free(temp);
    }
}
void display_stack()
{
    Node *temp = top;
    if(isempty())
    {
        cout<<"STACK EMPTY";
    }
    else
    {
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next_stack;
        }
    }
}

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

int isPalin()
{
    Node *traverse = head;

    while(traverse->next != NULL)
    {
        push(traverse->data);
        traverse = traverse->next;
    }
    // cout<<endl;
    // cout<<"STACK : \n";
    // cout<<peek();
    // cout<<endl;

    while(head->next != NULL )
    {
        int temp = peek();
        cout<<"\n\nELEMENT : "<<endl;
        cout<<head->data<<endl;
        cout<<"STACK : \n";
        display_stack();
        if(head->data != temp)
        {
            return 0;
        }
        head=head->next;
        pop();
        cout<<endl;
    }
    return 1;
}
int main()
{
    
    // int j=1, k=3;
    // for(int i=1; i<=5; i++)
    // {
    //     if(j<3)
    //     {
    //         insert(j);
    //         j++;
    //     }
    //     else 
    //     {
    //         insert(k);
    //         k--;
    //     }
    // }
    insert(1);
    insert(0);
    insert(1);
    display();
    cout<<endl<<endl;
  
    int result = isPalin();
    
    if(result == 1)
            cout<<"True\n";
    else
        cout<<"Not true\n";
  
    return 0;
}
  