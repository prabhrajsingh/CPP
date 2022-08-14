#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void insert(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if(front == NULL)
    {
        rear = new_node;
        front = new_node;
    }
    else 
    {
        rear->next = new_node;
        rear = new_node;
    }
}
bool isEmpty()
{
    return (front == NULL && rear == NULL);
}

void show_front()
{
    if(!isEmpty())
    {
        cout<<" FRONT : "<<front->data<<endl;
    }
}
void show_back()
{
    if(!isEmpty())
    {
        cout<<"REAR : "<<rear->data<<endl;
    }
}

void delete_queue()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY";
        exit(1);
    }
    else
    {
        if(front==rear)
        {
            free(front);
            front = NULL;
            rear = front;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY";
        exit(1);
    }
    else
    {
        Node *traverse = front;
        while(traverse != NULL)
        {
            cout<<traverse->data<<"\t";
            traverse = traverse->next;
        }
    }
}
int main()
{
    int n;
    cout<<"ENTER HOW MANY ELEMENTS : ";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        insert(i);
    }

    display();
    cout<<endl<<endl;
    show_front();
    cout<<endl<<endl;
    show_back();
    cout<<endl<<endl;
    delete_queue();
    cout<<endl<<endl;
    display();
}