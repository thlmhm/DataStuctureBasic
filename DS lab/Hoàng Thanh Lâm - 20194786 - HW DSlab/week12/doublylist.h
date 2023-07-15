#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char model[30];
	int memory;
	float scr;
	float price;
}phone;
typedef phone elementtype;
struct node_t{
	elementtype element;
	struct node_t *next;
	struct node_t *prev;
};
typedef struct node_t node;
typedef node* doublelist;
doublelist root, tail, cur;
elementtype *a;
node* makeNewNode(elementtype phone){
	node* new = (node*)malloc(sizeof(node));
	new->element=phone;
	new->next =NULL;
	new->prev =NULL;
	return new;
}

void insertAtHead(elementtype e){
	node* new = makeNewNode(e);
	if (root==NULL) {
		root=new; 
		tail= new;
		cur=new;
		return;
	}
	new->next = root;
	root->prev = new;
	root = new;
	cur = root;
}

void insertAtTail(elementtype e){
	node *new =makeNewNode(e);
	if (tail==NULL){
		root= new;
		tail= new;
		cur = new;
		return;
	}
	tail->next = new;
	new->prev = tail;
	tail = new;
	cur = tail;
}

void insertAfterCurrent(elementtype ele){
	node *new = makeNewNode(ele);
	if(root == NULL){
		root = new;
		tail = new;
		cur = root;
	}else if(cur == NULL){
		printf("Current pointer is NULL!\n");
		return;
	}else{
		new->next = cur->next;
		if(cur->next != NULL){
			cur->next->prev = new;
		}
		else{
			tail = new;
		}
		cur->next = new;
		new->prev = cur;
		cur = new;
	}
}
void insertBeforeCurrent(elementtype ele){
	node *new = makeNewNode(ele);
	if(root == NULL){
		root = new; 
		tail = new;
		cur = root;
	}else if(cur == NULL){
		printf("Current pointer is NULL!\n");
		return;
	}else{		
		new->prev = cur->prev;
		if(cur->prev != NULL){
			cur->prev->next = new;	
		}
		else{
			root = new;
		}
		cur->prev = new;
		new->next = cur;
		cur = new;
		
	}
}
void deleteCurrent(doublelist *root, doublelist *cur){
	node *tmp;
	tmp = *cur;
	if(*root == NULL) printf("Empty list");
	else{
		if(tmp == *root){
			(*root) = (*root)->next;
		}
		else{
			tmp->prev->next = tmp->next;
		}
		if(tmp->next != NULL) tmp->next->prev = tmp->prev;
		free(tmp);
	}
}
void deleteFirst(doublelist *root){
	node *tmp;
	tmp = (*root);
	(*root) = (*root)->next;
	free(tmp);
}
void deleteLast(doublelist tail,doublelist cur){
	node *tmp;
	tmp = tail;
	tail->prev->next = NULL;
	tail = tmp->prev;
	cur = tmp->prev;
	free(tmp);
}
elementtype enterAddr(){
	elementtype *new;
	new = (elementtype*)malloc(sizeof(elementtype));
	printf("Enter model:");
	scanf("%s", new->model);
	while(getchar() != '\n');
	printf("Enter memory:");
	scanf("%d", &new->memory);
	printf("Enter screen size:");
	scanf("%f", &new->scr);
	printf("Enter price:");
	scanf("%f", &new->price);
	return *new;
}
void importdata(FILE*f){
	root = NULL;
	tail = NULL;
	cur = root;
	int i = 0;
	a = (elementtype*)malloc(sizeof(elementtype));
	while(fread(a,sizeof(elementtype),1,f) !=0){
		insertAfterCurrent(*a);
		i++;
	}
	free(a);
}
void printf_node(node * p,int i){
	if(p==NULL){
		printf("Error pointer NULL\n");
		return ;
	}
	elementtype tmp = p->element;
	printf("%-3d%-20s%-10d%-10.2f%-10.2f\n", i,tmp.model, tmp.memory, tmp.scr, tmp.price);
  	
}
void traverse(){
	node*temp;
	int i = 0;
	printf("\n%-3s%-20s%-10s%-10s%-10s\n", "No","Phone Model", "Memory", "Screen","Price");
	for(temp = root; temp != NULL; temp = temp->next){
		i++;
		printf_node(temp,i);
	}
}
void insertAtPosition(int n, doublelist *root, doublelist *cur){
	int i = 0;
	node *tmp;
	for(tmp = (*root); tmp != NULL; tmp = tmp->next){
		i++;
		(*cur) = tmp;
		if(i == n){		
			break;
		}
	}	
	printf("Now you are in :");
	printf_node(tmp,i);
	insertBeforeCurrent(enterAddr());	
}
void deleteAtPosition(int n, doublelist *root, doublelist *cur){
	int i = 0;
	char c;
	node *tmp;
	for(tmp = (*root); tmp != NULL; tmp = tmp->next){
		i++;
		(*cur) = tmp;
		if(i == n){		
			break;
		}
	}	
	printf("Now you are in :");
	printf_node(tmp,n);
	deleteCurrent(root, cur);
}
int searchmodel(char* s, doublelist *root, doublelist *cur){
  	node* temp;
  	int check = 0;
  	int i=0;
  	for(temp=(*root);temp!=NULL;temp=temp->next){
  		i++;
   		if(strcmp(s, temp->element.model)==0){
      			printf_node(temp,i);
      			check =1;
      			break;
      		}	
      	}
  	return check;
}
node * list_reverse(node*root){
	node *temp, *cur2;
	cur2 = root;
	if(cur2 == NULL) return NULL;
	while(cur2 != NULL){
		temp = cur2->prev;
		cur2->prev = cur2->next;
		cur2->next = temp;
		cur2 = cur2->prev;
	}
	if(temp!=NULL) temp = temp->prev;
	return temp;
}
void traverseListFromTail(node*tail){
	int i=0;
	node *p;
	for(p =tail; p!=NULL; p=p->next){
		i++;
		printf_node(p,i);
	}
}
void freelist(){
	doublelist to_free;
	to_free = root;
	while(to_free != NULL){
		root = root->next;
		free(to_free);
		to_free = root;
	}
}
doublelist search_movetofront(char* s){
  	elementtype temp;
  	cur = root;
  	if(strcmp(s, cur->element.model) == 0){
  		return root;
  	}
  	while(cur != NULL && strcmp(s, cur->element.model) != 0){
  		cur = cur -> next;
  	}	
  	if( cur != NULL){	
  		temp = cur->element;
  		deleteCurrent(&root, &cur);
  		insertAtHead(temp);		
  	}
  	return root;
}
doublelist search_transpose(char* s){
	elementtype temp;
  	cur = root;
  	if(strcmp(s, cur->element.model) == 0){
  		return root;
  	}
  	while(cur != NULL && strcmp(s, cur->element.model) != 0){
  		cur = cur -> next;
  	}	
  	if( cur != NULL){	
  		temp = cur->prev->element;
  		cur->prev->element = cur->element;
  		cur->element = temp;
  	}
  	return root;
}

