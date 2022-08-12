#include<iostream>
#include<string>

using namespace std;
#define MAX 1000

class stack
{
        int top;
    public:
        char string_array[MAX];
        stack()
        {
            top = -1;
        } 
        bool push(char x);
        char pop();
        char peek();
        bool isEmpty();
};
bool stack :: push(char x)
{
    if(top >= MAX -1)
    {
        cout<<"OVERFLOW\n";
        return false;
    }
    else
    {
        string_array[++top] = x;
    }
}
char stack :: pop()
{
    if(top < 0 )
    {
        cout<<"STACK EMPTY\n";
        return 0;
    }
    else
    {
        char x = string_array[top--];
        return x;
    }
}
char stack :: peek()
{   
    if(top < 0 )
    {
        cout<<"STACK EMPTY\n";
        return 0;
    }
    else
    {
        char x = string_array[top];
        return x;
    }
}
bool stack :: isEmpty()
{
    return (top < 0 );
}

int main()
{
    class stack s;
    
    char infix[MAX];
    
    cout<<"INFIX : ";
    cin.get(infix, MAX);

    for(int i=0; infix[i]!='\0'; i++)
    {
        // cout<<infix[i]<<" ";
        s.push(infix[i]);
    }
    cout<<"\nLAST CHARACTER : "<<s.peek()<<endl;
    while(!s.isEmpty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
}

//a + b*(c^d-e)^(f+g*h)-i