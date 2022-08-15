#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
Node *top;
void push(int new_data)
{
    Node *temp = new Node();
    while(!temp)
    {
        cout<<"STACK OVERFLOW "<<endl;
        exit(1);
    }
    temp->data = new_data;
    temp->next = top;
    top = temp;
}

int isEmpty()
{
    return (top == NULL);
}

int peek()
{
    if(!isEmpty())
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
    Node *temp;
    if(top == NULL)
    {
        cout<<"STACK UNDERFLOW"<<endl;
        exit(1);
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}
void display()
{
    Node *temp;
    if(top == NULL)
    {
        cout<<"STACK IS EMPTY"<<endl;
        exit(1);
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
}

int main()
{
    int n=0;
    cout<<"ENTER HOW MANY LIST ELEMENTS : ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        push(i);
    }
    display();
    pop();
    cout<<"#############################################"<<endl;
    display();
}
