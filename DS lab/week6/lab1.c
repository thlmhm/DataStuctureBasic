#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct address_t{
    char name[20];
    char phone[11];
    char email[25];
}address;
struct list_el{
    address data;
    struct list_el *next;
};
typedef struct list_el node_addr;
node_addr *root, *cur, *prev;

address enterAddr(){
    address *addlist;
    addlist = (address*)malloc(sizeof(address));
    printf("Enter name: ");
    fflush(stdin);
    gets(addlist->name);
    printf("Enter phone number: ");
    scanf("%s", addlist->phone);
    printf("Enter email: ");
    scanf("%s", addlist->email);
    return *addlist;
}

node_addr *makeNewNode(address data){
    node_addr *new = (node_addr*)malloc(sizeof(node_addr));
    strcpy(new->data.name, data.name);
    strcpy(new->data.phone, data.phone);
    strcpy(new->data.email, data.email);
    new->next = NULL;
    return new;
}

void displayNode(node_addr *p){
    if(p == NULL){
        printf("Empty data\n");
        return;
    }
    address temp;
    printf("%-20s %-11s %-25s\n", "Name", "Phone", "Email");
    temp = p->data;
    printf("%-20s %-11s %-25s\n", temp.name, temp.phone, temp.email);
    
}

void traversingList(){
    if(root == NULL){
        printf("Empty data\n");
        return;
    }
    node_addr *p;
    printf("%-20s %-11s %-25s\n", "Name", "Phone", "Email");
    for(p = root; p != NULL; p = p->next){
        printf("%-20s %-11s %-25s\n", p->data.name, p->data.phone, p->data.email);
    }
}

void insertAtHead(address e){           //Current pointer move to root
    node_addr *new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
    prev = NULL;
}

void insertAfterCurrent(address e){     //Current pointer move to the next node
    node_addr *new = makeNewNode(e);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    }else{
        new->data = e;
        new->next = cur->next;
        cur->next = new;
        prev = cur;
        cur = new;
    }
}

void insertBeforeCurrent(address e){    //Current pointer is unchanged
    node_addr *new = makeNewNode(e);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    }else{
        new->data = e;
        prev->next = new;
        new->next = cur;
        prev = new;
    }
}

void deleteFirstNode(){
    node_addr *del;
    del = root;
    root = del->next;
    free(del);
}

void deleteMiddle(){                    //Current move to the next node
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
}

int main(){
    int n,i;
    address *addlist;
    addlist = (address*)malloc(sizeof(address));
    printf("Enter number of contact: ");
    scanf("%d", &n);
    root = makeNewNode(enterAddr());
    cur = root;
    prev = NULL;
    displayNode(root);
    for( i = 1; i < n; i ++){
        insertAfterCurrent(enterAddr());
    }
    traversingList();
    deleteFirstNode();
    traversingList();
}
