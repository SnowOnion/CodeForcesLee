#include<stdio.h>
#include<stdlib.h>
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
    return nn;
}

/**
precon: src != NULL
*/
void mount(Node* src, Node* tar){
    src->next=tar;
}

/**
true 1 false 0
*/
int isLast(Node* node){
    return node->next == NULL;
}

/**
尽量在 LinkedList 操作中屏蔽 Node 的实现 (比如露出next君)
*/

typedef struct _LinkedList{
    Node* head;
}LinkedList;

void initLL(LinkedList* ll){
    ll->head=newNode(0);
}

void printLL(LinkedList* ll){
    Node* cursor=ll->head;
    while(cursor->next!=NULL){
        cursor = cursor->next;
        printf("%d ",cursor->value);
    }
    printf("\n");
}

Node* findLast(LinkedList* ll){
    Node* cursor = ll->head;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    return cursor;
}

void insertToEnd(LinkedList* ll, int value){
    Node* last=findLast(ll);
    mount(newNode(value),last);
}

Node* linearSearchPreceeder(LinkedList* list, int tarVal){
    Node* pre = list->head;
    while(pre->next != NULL){
        if(pre->next->value == tarVal){
            return pre;
        }
    }
    return NULL;
}

Node* linearSearch(LinkedList* list, int tarVal){
    Node* pre;
    if((pre=linearSearchPreceeder(list,tarVal)) != NULL){
        return pre->next;
    }
    else{
        return NULL;
    }
}

void swapNode_inside(Node* preA, Node* preB){
    Node* a=preA->next;
    Node* b=preB->next;
    Node* tmp;

    preA->next=b;
    preB->next=a;

    tmp=a->next;
    a->next=b->next;
    b->next=tmp;
}

void swapByValue(LinkedList* list, int aVal, int bVal){
    Node* preA=NULL;
    Node* preB=NULL;
    Node* cur=list->head;
    while(cur->next!=NULL){
        if(cur->next->value==aVal){
            preA=cur;
        }
        if(cur->next->value==bVal){
            preB=cur;
        }
        cur=cur->next;
    }
    swapNode_inside(preA,preB);
}

int main(){

    LinkedList ll;
    initLL(&ll);

    insertToEnd(&ll, 1);
    insertToEnd(&ll, 3);
    insertToEnd(&ll, 2);
    insertToEnd(&ll, 4);

    printLL(&ll);

    swapByValue(&ll,3,4);

    printLL(&ll);


    return 0;
}
