#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enque(int x)
{
    if(rear ==N-1)
    {
        printf("queue overflow");
    }
    else if(front == -1 && rear == -1)
    {
        front=rear=0;
        queue[rear] = x;
    }
    else
    {
        rear ++;
        queue[rear]=x;
    }
}
void deque()
{
    if ( front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("deleted elements= %d",queue[front]);
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf(" the queue is empty");
    }
    else
    {
        for( i = front; i<= rear ++; i++)
    {
        printf("%d",queue[i]);
    }
    }
}
void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else{
        printf("%d", queue[front]);
    }
}

int main ()
{
    int choice, val;
    while(1)
    {
        printf("\n queue menu \n");
        printf("1.Enque \n");
        printf("2.Dequeue \n");
        printf("3.Display \n");
        printf("4.Peek \n");
        printf("5.Exit \n");
        printf("6.Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("enter the value to enque: ");
                scanf("%d", &val);
                enque(val);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                return 0;
            default:
                printf("invalid choice \n");
        }
    }
    return 0;
}
