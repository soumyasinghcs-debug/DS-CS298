#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
    void push(int);
    void pop();
    void peek();
    void display();
int stack[SIZE], top = -1;
void main()
{
    int value,choice;
    while(1){
        printf("***MENU***\n");
        printf("1.push \n 2.pop\n 3.peek\n 4.display\n 5.exit");
        printf("enter your choice:");
        scanf("%d", & choice);
        switch (choice){
            case 1:printf("enter the value:");
            scanf("%d",&value);
            push (value);
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            break;
        default: printf("\n wrong selection!!!");
        }
    }
}
void push (int value){
    if (top == SIZE -1){
        printf("\n stack is full!!!not possible\n stack overflows");
    }
    else{
        top ++;
        stack[top] = value;
        printf("\n insertion success!");

    }
}
void pop(){
    if(top ==-1){
        printf("\n stack is empty, deletion not possible! \n stack underflow\n");
    }
    else{
        printf("\n deleted:%d", stack[top]);
        top --;
    }
}
void peek(){
    if (top == -1)
    {
        printf("underflow\n");
    }
    else{
        printf("%d",stack[top]);
    }
}
void display (){
    if (top == -1){
    printf("\n stack is empty");
    }
else{
    int i;
    printf("\n stack elements are: \n");
    for (i = top; i>0; i --)
        printf("%d\n",stack[i]);
 }
}
