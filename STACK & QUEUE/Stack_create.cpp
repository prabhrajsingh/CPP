#include<iostream>
using namespace std;

#define MAX 1000

class Stack
{
        int top;
    public:
        int array[MAX];
        Stack()
        {
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack :: push(int x)
{
    if(top >= MAX -1)
    {
        cout<<"STACK IS FULL";
        return false;
    }
    else
    {
        array[++top] = x;
        cout<<x<<"  pushed"<<endl;
        return true;
    }
}
int Stack :: pop()
{
    if(top < 0)
    {
        cout<<"STACK EMPTY";
        return 0;
    }
    else
    {
        int x = array[top--];
        cout<<"Popped : "<<endl;
        return x;
    }
}
int Stack :: peek()
{
    if(top < 0)
    {
        cout<<"STACK EMPTY";
        return 0;
    }
    else
    {
        int x = array[top];
        return x;
    }
}
bool Stack :: isEmpty()
{
    return (top < 0 );
}
int main()
{
    class Stack s;
    int n;
    cout<<"ENTER THE NUMBER OF ELEMENTS : ";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        s.push(i);
    }
    
    cout<<"TOP MOST ELEMENT IN STACK : "<<s.peek()<<endl;

    s.pop();

    cout<<"TOP MOST ELEMENT IN STACK : "<<s.peek();

    while(!s.isEmpty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
}