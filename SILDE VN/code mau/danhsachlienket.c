#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int ID;
    struct Node* next;
}Node;

Node* first;// pointer to the first element of the list

void printList(Node* h){
    // print elements of the list headed by h
    Node* p = h;//
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
    // create a node having ID = v, insert into last position
    Node* p = makeNode(v);
    if(h == NULL) return p;

    Node* q = h;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
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
    // return number of nodes of the given linked list
    int cnt = 0;
    Node* p;
    for(p = h; p != NULL; p = p->next){
        cnt++;
    }
    return cnt;
}
Node* insertLastRecursive(Node* h, int v){
    if(h == NULL){
        return makeNode(v);
    }
    h->next = insertLastRecursive(h->next,v);
    return h;
}

Node* insertBefore(Node* h, int v, int u){
    // tao 1 nut co ID = v, chen vao truoc nut co ID = u
    // tra ve con tro den dau danh sach thu duoc
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
Node* insertBeforeRecursive(Node* h, int v, int u){
    if(h == NULL) return NULL;
    if(h->ID == u){
        Node* p= makeNode(v);
        p->next  = h;
        return p;
    }
    h->next = insertBeforeRecursive(h->next,v,u);
    return h;
}
Node*insertAfter(Node* h, int v, int u){
    // TODO homework
}
Node* removeNode(Node* h, int v){
    // loai bo nut co ID = v ra khoi danh sach h
    // tra ve con tro den dau danh sach thu duoc
    if(h == NULL) return NULL;
    if(h->ID == v){
        Node* p = h->next;
        free(h);
        return p;
    }
    Node* q = h;
    while(q->next != NULL){
        if(q->next->ID == v)
            break;
        q  = q->next;
    }
    if(q->next == NULL){
        return h;
    }
    Node* p = q->next;
    q->next = p->next;
    free(p);
    return h;
}

Node* removeNodeRecursive(Node* h, int v){
        if(h == NULL) return NULL;
        if(h->ID == v){
            Node* p = h;
            h = h->next;
            free(p);
            return h;
        }
        h->next = removeNodeRecursive(h->next,v);
        return h;
}
int main(){
    first = NULL;
    int v;
    for(v = 1; v <= 10; v++){
        first = insertLastRecursive(first,v);
        //if(v%1000==0) printf("size = %d\n",v);
    }
    printList(first);
    first = insertBeforeRecursive(first,13,4);
    printList(first);
    for(v = -2; v <= 20; v++){
        first = removeNodeRecursive(first,v);
        printf("after removing node %d: ",v);
        printList(first);
    }

    printf("count = %d\n",count(first));
    freeList(first);
}
