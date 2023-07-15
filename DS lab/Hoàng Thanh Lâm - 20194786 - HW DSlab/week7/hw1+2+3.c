#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
};
typedef struct node_t node;
node *root, *cur,*prev,*new;
elementtype *a;
int total = 0;
node* makeNewNode(elementtype phone){
	node*new = (node*)malloc(sizeof(node));
	new->element = phone;
	new->next =NULL;
	return new;
}

void insertAtHead(elementtype a){
	node*new = makeNewNode(a);
	new->next = root;
	root = new;
	cur = root;
}
void insertAfterCurrent(elementtype a){
	node*new = makeNewNode(a);
	if(root == NULL){
		root = new;
		cur = root;
		prev = NULL;
	}else{
		new->element = a;
		new->next = cur->next;
		cur->next = new;
		prev = cur;
		cur = cur->next;
	}
}
void insertBeforeCurrent(elementtype a){
	node*new = makeNewNode(a);
	if(root == NULL){
		root = new;
		cur = root;
		prev = NULL;
	}else{
		new->element = a;
		prev->next = new;
		new->next = cur;
		prev = new;
	}
	
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
void deleteFirstNode(){
	node *del;
	del = root;
	if(del == NULL) return;
	root = root->next;
	free(del);
	cur = root;
}
void deleteCurrentElement(){
	if(cur==NULL) return;
	if(cur==root) deleteFirstNode();
	else{
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
}
int searchmodel(char* s){
  	node* temp;
  	int i=1;
  	for(temp=root;temp!=NULL;temp=temp->next){
   		if(strcmp(s, temp->element.model)==0){
      			printf("%-3d\t%-30s\t%-6d\t%-8.2f\t%-8.2f\n",i,temp->element.model,temp->element.memory,temp->element.scr,temp->element.price);
      		}
      		i++;
      	}
  	return i;
}
node* list_reverse(){
	cur = prev =NULL;
	while(root != NULL){
		cur = root;
		root = root->next;
		cur->next = prev;
		prev = cur;
	}
	root = prev;
	return prev;
}
void op1(FILE*f){
	root = NULL;
	cur = root;
	int i = 0;
	a = (elementtype*)malloc(sizeof(elementtype));
	while(fread(a,sizeof(elementtype),1,f) !=0){
		insertAfterCurrent(*a);
		i++;
	}
	free(a);
}
void op2(){
	node*tmp;
	int i = 0;
	printf("\n%-3s%-20s%-10s%-10s%-10s\n", "No","Phone Model", "Memory", "Screen","Price");
	for(tmp = root; tmp != NULL; tmp = tmp->next){
		i++;
		printf("%-3d%-20s%-10d%-10.2f%-10.2f\n", i,tmp->element.model, tmp->element.memory, tmp->element.scr, tmp->element.price);
	}
}
void op3(){
	char c;
	printf("You are in :");
	if(cur==NULL){
		printf("Error pointer!.\n"); 
    		return ;
    	}
	node *tmp;
	tmp = cur;
	printf("Now you are in:\n");
	printf("%-20s%-10d%-10.2f%-10.2f\n", tmp->element.model, tmp->element.memory, tmp->element.scr, tmp->element.price);
	printf("Do you want to add new phone before or after?");
	do{
		while(getchar() != '\n');
		scanf("%c",&c);
		if(c!='A' && c!='B'){
			printf("Enter again!(A or B):");
		}
	}while(c!='A' && c!='B');
	if(c =='A'){
		
		insertAfterCurrent(enterAddr());
	}
	else{
		insertBeforeCurrent(enterAddr());
	}	
}
void op4(){
	int po,i=0;
	char c;
	printf("Enter the position:(1-20):");
	do{
		scanf("%d", &po);
		if(po<1||po>20){
			printf("Enter Again! (1-20)");
		}
	}while(po<1||po>20);
	node*tmp;
	//tmp = root;
	for(tmp = root; tmp != NULL; tmp = tmp->next){
		i++;
		prev =tmp;
		if(i == po-1){
			cur = tmp->next;
			break;
		}
	}	
	printf("Now you are in :");
	printf("%-20s%-10d%-10.2f%-10.2f\n", tmp->element.model, tmp->element.memory, tmp->element.scr, tmp->element.price);
	insertBeforeCurrent(enterAddr());

}
void op5(){
	int po,i=0;
	printf("Enter the position:(1-20):");
	do{
		scanf("%d", &po);
		if(po<1||po>20){
			printf("Enter Again! (1-20)");
		}
	}while(po<1||po>20);
	node*tmp;
	for(tmp = root; tmp != NULL; tmp = tmp->next){
		i++;
		prev =tmp;
		if(i == po-1){
			cur = tmp->next;
			break;
		}
	}	
	printf("Now you are in :");
	printf("%-20s%-10d%-10.2f%-10.2f\n", tmp->element.model, tmp->element.memory, tmp->element.scr, tmp->element.price);
	deleteCurrentElement();	
}
void op6(){
	node *tmp;
	tmp = cur;
	printf("Now you are in:\n");
	printf("%-20s%-10d%-10.2f%-10.2f\n", tmp->element.model, tmp->element.memory, tmp->element.scr, tmp->element.price);
	deleteCurrentElement();
}
void op7(){
	deleteFirstNode();
}
void op8(){
	int d;
	char string[15];
	printf("Enter Phone model:");
    	scanf("%s",string);
    	d=searchmodel(string);
      	if(d==0){
		printf("No resul!\n");
    	}
}
void op10(){
	list_reverse();
}
/*void op11(FILE*f2){
	node *temp;
	for(tmp = root; tmp != NULL; tmp = tmp->next){
		fwrite(
	}
	
}*/
int main(){
	int choice;
	FILE *f1,*f2;
	do{
		printf("\n---------MENU---------\n");
		printf("1. Import from PhoneDB.dat(insertafter).\n");
  		printf("2. Display.\n");
  		printf("3. Add new phone.\n");
  		printf("4. Insert at Position.\n");
  		printf("5. Delete at Position.\n");
  		printf("6. Delete current.\n");
  		printf("7. Delete first.\n");
  		printf("8. Search and Update.\n");
  		printf("9. Divide and Extract.\n");
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
  				op1(f1);
  				fclose(f1);
  				break;
  			case 2:
  				op2();
  				break;
  			case 3:
  				op3();
  				break;
  			case 4:
  				op4();
  				break;
  			case 5:
  				op5();
  				break;
  			case 6:
  				op6();
  				break;
  			case 7:
  				op7();
  				break;
  			case 8:
  				op8();
  				break;
  			case 9:
  				//op9();
  				break;
  			case 10:
  				op10();
  				break;
  			case 11:
  				
  				break;			
  		}
	}while(choice != 12);
	
}
