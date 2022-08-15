#include<iostream>
using namespace std;

#define MAX 10000

class queue
{
        int rear ,front;
    public:
        queue()
        {
            rear = 0;
            front = 0;
        }
        char q_array[MAX];
        bool insert(char x);
        char Delete();
        char peek();
        bool isEmpty();
};
bool queue :: insert(char x)
{
    if(rear >= MAX - 1)
    {
        cout<<"QUEUE IS FULL";
        return false;
    }
    else
    {
        q_array[rear++] = x;
        return true;
    }
}
char queue :: Delete()
{
    if(front == rear)
    {
        cout<<"QUEUE IS EMPTY";
        return 0;
    }
    else
    {
        char x = q_array[front++];
        return x;
    }
}
char queue :: peek()
{
    if(front==rear)
    {
        cout<<"QUEUE IS EMPTY";
        return 0;
    }
    else
    {
        char x = q_array[front];
        return x;
    }
}
bool queue :: isEmpty()
{
    return (front == rear);
}
int main()
{
    class queue q;
    char queue_[MAX];
    cout<<"QUEUE : ";
    cin.get(queue_, MAX);

    for(int i=0; queue_[i] != '\0'; i++)
    {
        q.insert(queue_[i]);
    }
    while(!q.isEmpty())
    {
        cout<<q.peek()<<" \t ";
        q.Delete();
    }
}