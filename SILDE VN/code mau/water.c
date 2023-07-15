#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct State{
    int x;
    int y;
    struct State* next;
    struct State* par;
    char* action;

}State;

State* head;
State* tail;

int a,b,c;
State* start;
State* target;
int visited[MAX][MAX];

State* makeState(int x, int y){
    State* p = (State*)malloc(sizeof(State));
    p->x = x; p->y = y; p->next = NULL; p->par = NULL;
    return p;
}
void initQueue(){
    head = NULL; tail = NULL;
}
void enQueue(State* s){
    if(empty()){
        head = s; tail = s; return;
    }
    tail->next = s;
    tail = s;
}
State* deQueue(){
    if(empty()) return NULL;
    State* s = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    return s;
}
int empty(){
    return head == NULL && tail == NULL;
}
int finalState(State* s){
    return s->x == c || s->y == c;
}
int fillJug1(State* s){
    int nx = a; int ny = s->y;
    if(visited[nx][ny]) return 0;
    State* ns  = makeState(nx,ny);
    ns->par = s;
    if(empty()) s->next = ns;
    enQueue(ns);
    visited[nx][ny] = 1;
    if(finalState(ns)){target = ns; return 1;}
    return 0;
}
int fillJug2(State* s){
    int nx = s->x; int ny = b;
    if(visited[nx][ny]) return 0;
    State* ns  = makeState(nx,ny);
    ns->par = s;
    if(empty()) s->next = ns;
    enQueue(ns);
    visited[nx][ny] = 1;
    if(finalState(ns)){target = ns; return 1;}
    return 0;
}
int emptyJug1(State* s){
    int nx = 0; int ny = s->y;
    if(visited[nx][ny]) return 0;
    State* ns  = makeState(nx,ny);
    ns->par = s;
    if(empty()) s->next = ns;
    enQueue(ns);
    visited[nx][ny] = 1;
    if(finalState(ns)){target = ns; return 1;}
    return 0;

}
int emptyJug2(State* s){
    int nx = s->x; int ny = 0;
    if(visited[nx][ny]) return 0;
    State* ns  = makeState(nx,ny);
    ns->par = s;
    if(empty()) s->next = ns;
    enQueue(ns);
    visited[nx][ny] = 1;
    if(finalState(ns)){target = ns; return 1;}
    return 0;

}
int pourJug1ToJug2(State* s){
    int nx = 0; int ny = s->x + s->y;
    if(s->x + s->y > b){nx = s->x + s->y - b; ny = b;}
    if(visited[nx][ny]) return 0;
    State* ns  = makeState(nx,ny);
    ns->par = s;
    if(empty()) s->next = ns;
    enQueue(ns);
    visited[nx][ny] = 1;
    if(finalState(ns)){target = ns; return 1;}
    return 0;

}
int pourJug2ToJug1(State* s){
    int ny = 0; int nx = s->x + s->y;
    if(s->x + s->y > a){ny = s->x + s->y - a; nx = a;}
    if(visited[nx][ny]) return 0;
    State* ns  = makeState(nx,ny);
    ns->par = s;
    if(empty()) s->next = ns;
    enQueue(ns);
    visited[nx][ny] = 1;
    if(finalState(ns)){target = ns; return 1;}
    return 0;
}
void printSolution(){
    State* p = target;
    while(p != NULL){
        printf("(%d,%d)\n",p->x,p->y);
        p = p->par;
    }
}
void initVisited(){
	int i,j;
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            visited[i][j] = 0;
}
void solve(){
    initQueue();
    initVisited();
    start = makeState(0,0);
    visited[0][0] = 1;
    enQueue(start);
    while(!empty()){
        State* s = deQueue();
        if(fillJug1(s)) break;
        if(fillJug2(s)) break;
        if(emptyJug1(s)) break;
        if(emptyJug2(s)) break;
        if(pourJug1ToJug2(s)) break;
        if(pourJug2ToJug1(s)) break;

    }
    printSolution();
}
void finalize(){
    // free memory
    State* p = start;
    while(p != NULL){
        State* np = p->next;
        printf("free(%d,%d)\n",p->x,p->y);
        free(p);
        p = np;
    }
}
int main(){
    a = 6; b = 8; c = 4;
    solve();
    finalize();
}
