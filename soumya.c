#include<stdio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue(){
    int x;
    printf("enter a element to insert: ");
    scanf("%d",&x);

    if ((rear +1) % N == front){
        printf("queue is full\n");
        return;
    }
    else if (front == -1 && rear == -1){
    front = 0;
    rear = 0;
    queue[rear] = x;
    }else{
    rear = (rear + 1 )% N;
    queue [rear]= x;
}
printf("inserted : %d\n", x);

}

void dequeue(){
    if (front == -1){
        printf("queue is empty\n");
        return;
    }
    int deletedx = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % N;
    }

    printf("Deleted: %d\n", deletedx);
}
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue Elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}
int main() {
    int choice;
    while (1){
        printf("\n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);

        switch (choice){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4:
            return 0;
            default: printf("invalid choice\n");
        }
    }
}

