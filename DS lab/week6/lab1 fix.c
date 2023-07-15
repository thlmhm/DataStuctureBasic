#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct address_t{
	char name[20];
	char tel[11];
	char email[25];
}address;

struct list_el{
	address addr;
	struct list_el *next;
};

typedef struct list_el node_addr;
node_addr *root, *cur, *prev;

node_addr* makenewnode(address addr){
	node_addr* new = (node_addr*)malloc(sizeof(node_addr));
	/*strcpy(new->addr.name, addr.name);
	strcpy(new->addr.tel, addr.tel);
	strcpy(new->addr.email, addr.email);*/
	new->addr = addr;
	new->next = NULL;
	return new;
}

address readNode(){
	address tmp;
	while(getchar() != '\n');
	printf("Enter name:");
	scanf("%s", tmp.name);
	while(getchar() != '\n');
	printf("Enter tel:");
	scanf("%s", tmp.tel);
	while(getchar() != '\n');
	printf("Enter email:");
	scanf("%s", tmp.email);
	return tmp;
}

void printf_node(node_addr * p){
	if(p==NULL){
		printf("Error pointer NULL\n");
		return ;
	}
	address temp = p->addr;
	//printf("%-20s%-20s%-20s\n", "Name", "Phone", "Email");
	printf("%-20s%-20s%-20s\n", temp.name,temp.tel,temp.email);
  	
}

void insertAtHead(address a){
	node_addr* new = makenewnode(a);
	new->next = root;
	root = new;
	cur = root;
	prev = NULL;
}
void insertAfterCurrent(address a){
	node_addr *new = makenewnode(a);
	if (root == NULL){
		root = new;
		cur = root;
		prev = NULL;
	}
	else{
		new->addr = a;
		new->next=cur->next;
		cur->next=new;
		prev=cur;
		cur=cur->next;
	}
}
void deleteFirstNode(){
	node_addr *del;
	del = root;
	root = del->next;
	free(del);
}

void deleteMiddle(){
	prev->next = cur->next;
	free(cur);
	cur = prev->next;
}

void traversingList(){
	node_addr *p;
	printf("%-20s%-20s%-20s\n", "Name", "Phone", "Email");
	for(p = root; p!=NULL; p = p->next){
		printf_node(p);
	}
}
void freelist(){
	node_addr *p;
	p = root;
	while(p != NULL){
		root = root->next;
		free(p);
		p = root;	
	}
}

int main(){
	int n;
	printf("Enter the number of contact:");
	scanf("%d", &n);
	address *addlist;
	addlist =(address*)malloc(sizeof(address));
	root = makenewnode(readNode());
	cur  = root;
	prev = NULL;
	int i;
	for(i = 1; i<n;i++){
		insertAfterCurrent(readNode());
	}
	traversingList();
	//deleteFirstNode();
	freelist();
	
	
}
