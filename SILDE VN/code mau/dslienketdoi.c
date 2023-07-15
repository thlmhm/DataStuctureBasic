#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int ID;
    struct DNode* next;
    struct DNode* prev;
}DNode;

DNode* first = NULL;
DNode*last = NULL;

DNode* makeNode(int v){
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p->ID = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void insertLast(int v){
    DNode* p = makeNode(v);
    if(first == NULL && last == NULL){
        first = p; last = p; return;
    }
    last->next = p;
    p->prev = last;
    last = p;
}
void insertBefore(int v, int u){
    // tao 1 nut co ID = v, chen vao truoc nut co ID = u
    DNode* q = first;
    while(q!=NULL){
        if(q->ID == u) break;
        q = q->next;
    }
    if(q == NULL) return;
    DNode* p = makeNode(v);
    DNode* q1 = q->prev;
    if(q1 == NULL){
        q->prev = p;
        p->next = q;
        first = p;
    }else{
        q1->next = p;
        q->prev = p;
        p->prev = q1;
        p->next = q;
    }
}
void insertAfter(int v, int u){
    // tao nut co ID = v, chen vao sau nut co ID = u

}

void printLeft2Right(){
	DNode* p;
    for( p = first; p != NULL; p = p->next){
        printf("%d ",p->ID);
    }
    printf("\n");
}
void printRight2Left(){
	DNode* p;
    for( p = last; p != NULL; p = p->prev){
        printf("%d ",p->ID);
    }
    printf("\n");
}
void freeList(){
    DNode* p = first;
    while(p != NULL){
        DNode* pp = p->next;
        free(p);
        p = pp;
    }
}
void removeNode(int v){
    DNode* q = first;
    while(q != NULL){
        if(q->ID == v) break;
        q = q->next;
    }
    if(q == NULL){
        return;
    }
    DNode* q1 = q->prev;
    DNode* q2 = q->next;
    if(q1 == NULL && q2 == NULL){
        first = NULL; last = NULL;
    }else    if(q1 == NULL){
        first = q2; q2->prev = NULL;
    }else if(q2 == NULL){
        last = q1; q1->next = NULL;
    }else{
        q1->next = q2;
        q2->prev = q1;
    }
    free(q);
}
int main(){
    //printf("sizeof(DNode) = %d\n",sizeof(DNode));
    int v;
    for(v = 1; v <= 10; v++){
        insertLast(v);
    }
    printLeft2Right();
    printRight2Left();
    insertBefore(12,100);
    printLeft2Right();
    printRight2Left();

    /*
    for(int k = 1; k <= 20;k++){
        int v = rand()%15-1;
        removeNode(v);
        printf("After removing %d\n",v);
        printLeft2Right();
        printRight2Left();
    }
    */
    freeList();
}
