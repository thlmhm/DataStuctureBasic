#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int ID;
    struct Node* next;
}Node;

Node* first;

void printList(Node* h){
    // print ID of nodes of the list h
    Node* p = h;
    while(p != NULL){
        printf("%d ",p->ID);
        p = p->next;
    }
    printf("\n");
}
Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->ID = v;
    p->next = NULL;
    return p;
}
Node* insertLast(Node* h, int v){
    // create a new node, insert at last position of the list
    Node* p = makeNode(v);
    if(h == NULL) return p;

    Node* q = h;
    while(q->next != NULL)
        q = q->next;
    q->next = p;
    return h;
}
Node* insertLastRecursive(Node* h, int v){
    if(h == NULL) return makeNode(v);
    h->next = insertLastRecursive(h->next,v);
    return h;
}
void freeList(Node* h){
    Node* p = h;
    while(p != NULL){
        Node* pp = p->next;
        free(p);
        p = pp;
    }
}
int count(Node* h){
    int cnt = 0;// khoi tao bien dem = 0
    Node* p = h;// con tro duyet tro vao phan tu dau tien
    while(p != NULL){// trong khi p chua tro vao NULL
        cnt++;// tang bien dem len 1
        p = p->next;// cho p tro vao phan tu tiep theo
    }
    return cnt;
}
int countRecursive(Node* h){
    if(h == NULL) return 0;
    return 1 + countRecursive(h->next);
}

Node* insert(Node* h, int v, int u){
    // create a node having ID = v
    // insert this node before node ID = u
    // return pointer to the head of the list
    if(h == NULL) return NULL;
    if(h->ID == u){
        Node* p = makeNode(v);
        p->next = h;
        return p;
    }
    Node* q = h;
    while(q->next != NULL){
        if(q->next->ID == u) break;
        q = q->next;
    }
    if(q->next == NULL){
            return h;
    }else{
        Node* p = makeNode(v);
        p->next = q->next;
        q->next = p;
        return h;
    }
}
Node* insertRecursive(Node* h, int v, int u){
    if(h == NULL) return NULL;
    if(h->ID == u){
        Node* p = makeNode(v);
        p->next = h;
        return p;
    }
    h->next = insertRecursive(h->next,v,u);
    return h;
}

Node* removeNode(Node* h, int v){
    // remove a node having ID = v
    if(h == NULL) return NULL;
    if(h->ID == v){
        Node* p = h->next;
        free(h);
        return p;
    }
    Node* q= h;
    while(q->next != NULL){
        if(q->next->ID == v) break;
        q = q->next;
    }
    if(q->next == NULL){
        return h;
    }else{
        Node* p = q->next;
        q->next = p->next;
        free(p);
    }
    return h;
}

Node* removeNodeRecursive(Node* h, int v){
    // remove node having ID = v
    // return the pointer to the first node of the resulting list
    if(h == NULL) return NULL;
    if(h->ID == v){
        Node* p = h->next;
        free(h);
        return p;
    }
    h->next = removeNodeRecursive(h->next,v);
    return h;
}

int main(){
    first = NULL;
    int v;
    for( v = 1;  v<= 10; v++) {
        first = insertLastRecursive(first,v);
    }

    printList(first);
    int k;
    for(k  = 1; k <= 20; k++){
            int v = rand()%15;
        first = removeNodeRecursive(first,v);
        printf("after removing %d: ",v);
        printList(first);
    }
    //printf("so phan tu=%d\n",countRecursive(first));
    freeList(first);
}
