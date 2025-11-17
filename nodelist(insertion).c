#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertFirst(int value) {
    struct node* newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    printf("%d inserted at beginning\n", value);
}

void insertLast(int value) {
    struct node* newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("%d inserted at end\n", value);
}
void insertPos(int value, int pos) {
    struct node* newnode = createNode(value);
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        printf("%d inserted at position %d\n", value, pos);
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("%d inserted at position %d\n", value, pos);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int value, pos, choice;
    while (1) {
        printf("\n 1. Insert At First\n 2. Insert At End\n 3. Insert At Position \n 4. Display\n 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertFirst(value);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertLast(value);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertPos(value, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
