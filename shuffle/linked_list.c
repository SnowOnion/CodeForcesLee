#include<stdio.h>
#include<memory.h>

//typedef struct _Val{
//    int value
//}Val;

typedef struct _Node{
    int value;
    struct _Node* next;
}Node;

Node* newNode(int value){
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->value = value;
    nn->next = NULL;
}

typedef struct _LinkedList{
    Node* head;
}LinkedList;

void initLL(LinkedList* ll){
    ll->head=newNode(0);
}

void printLL(LinkedList* ll){
    Node* cursor=ll->head;
    while(cursor->next!=NULL){
        cursor=cursor->next;
        printf("%d ",cursor->value);
    }
    printf("\n");
}

void insertToEnd(LinkedList* ll, int value){
    Node* cursor=ll->head;
    while(cursor->next!=NULL){
        cursor=cursor->next;
    }
    cursor->next=newNode(value);
}

int main(){

    LinkedList ll;
    initLL(&ll);

    insertToEnd(&ll, 1);
    insertToEnd(&ll, 3);
    insertToEnd(&ll, 2);
    insertToEnd(&ll, 4);

    printLL(&ll);

    return 0;
}
