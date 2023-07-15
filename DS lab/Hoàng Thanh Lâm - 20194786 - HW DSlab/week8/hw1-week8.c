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
int main(){
	int choice;
	int choice3;
	int check;
	FILE *f1,*f2;
	char product[20];
	int po;
	do{
		printf("\n---------MENU---------\n");
		printf("1. Import from PhoneDB.dat(insertafter).\n");
  		printf("2. Display.\n");
  		printf("3. Add new phone.\n");
  		printf("4. Insert at Position.\n");
  		printf("5. Delete at Position.\n");
  		printf("6. Delete current.\n");
  		printf("7. Delete first.\n");
  		printf("8. Delete last.\n");
  		printf("9. Search and Update.\n");
  		printf("10.Reverse List.\n");
  		printf("11.Save to File\n");
  		printf("12.Quit.\n");
  		printf("---------------------------------------------------------\n");
  		printf("Enter choice:");
  		do{
  			scanf("%d", &choice);
  			if(choice<1||choice>12){
  				printf("Enter again!");
  			}
  		}while(choice<1||choice>12);
  		switch(choice){
  			case 1:
  				if((f1 = fopen("phoneDB.dat","rb")) ==NULL){
  					printf("Cannot open phoneDB.dat\n");
  					return 0;
  				}
  				importdata(f1);
  				printf("\n Success ... \n");
  				fclose(f1);
  				break;
  			case 2:
  				traverse();
  				break;
  			case 3:
  				do{
  					printf("\n---------------\n");
  					printf("1.Insert before current.\n");
  					printf("2.Insert after current.\n");
  					printf("3.Insert at head.\n");
  					printf("4.Insert append.\n");
  					printf("5.Exit.\n");
  					printf("---------------\n");
  					printf("Enter choice:");
  					do{
  						scanf("%d", &choice3);
  						if(choice3<1||choice3>5){
  							printf("Enter again!");
  						}
  					}while(choice3<1||choice3>5);
  					switch(choice3){
  						case 1:
  							insertBeforeCurrent(enterAddr());
  							break;
  						case 2:
  							insertAfterCurrent(enterAddr());
  							break;
  						case 3:
  							insertAtHead(enterAddr());
  							break;
  						case 4:
  							insertAtTail(enterAddr());
  							break; 							
  					}
  				}while(choice3 != 5);
  				break;
  			case 4:
				printf("Enter the position of product you want to insert:(1-20):");
				do{
					scanf("%d", &po);
					if(po<1||po>20){
					printf("Enter Again! (1-20)");
					}
				}while(po<1||po>20);
				insertAtPosition(po,&root,&cur);
  				break;
  			case 5:
  				printf("Enter the position of product you want to delete:(1-20):");
				do{
					scanf("%d", &po);
					if(po<1||po>20){
					printf("Enter Again! (1-20)");
					}
				}while(po<1||po>20);
  				deleteAtPosition(po, &root, &cur);
  				printf("Success! Please check again!");
  				break;
  			case 6:
  				deleteCurrent(&root,&cur);
  				printf("Success! Please check again!");
  				break;
  			case 7:
  				deleteFirst(&root);
  				printf("Success! Please check again!");
  				break;
  			case 8:
  				printf_node(tail, 20);
  				deleteLast(tail,cur);
  				printf("Success! Please check again!");
  				break;
  			case 9:
  				printf("Enter Phone model:");
    				scanf("%s",product);
    				check = searchmodel(product, &root, &cur);
    				switch(check){
    					case 1:
    						printf("Success!");
    						break;
    					case 0:
    						printf("No result!");
    						break;			
    				}
  				break;
  			case 10:
  				list_reverse(root);
  				traverseListFromTail(tail);
  				break;
  			case 11:	
  				break;		
  		}
	}while(choice != 12);
	
}

