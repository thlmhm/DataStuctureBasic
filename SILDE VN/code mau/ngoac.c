#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char info;
    struct Node* next;
}Node;

Node* top = NULL;

Node* makeNode(char c){
    Node* p = (Node*)malloc(sizeof(Node));
    p->info = c;
    p->next = NULL;
    return p;
}
void push(char x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}
char pop(){
    if(empty()) return '-';
    char x = top->info;
    Node* p = top->next;
    free(top);
    top = p;
    return x;
}
int empty(){
    return top == NULL;
}
int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}
int check(char* s){
	int i;
    for(i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                push(s[i]);
        }else{
            if(empty()) return 0;
            char c = pop();
            if(!match(c,s[i])) return 0;
        }
    }
    return empty();
}

int main(){
    char* s = "[({}[]()[()((({[][][]})))])]()";
    if(check(s)) printf("OK\n"); else printf("KO\n");
}
