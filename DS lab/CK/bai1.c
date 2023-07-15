#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char region_code[1000];
    int day[70];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* root=NULL;

Node* makeNode(char* code, int day, int patients){
    Node* p=(Node*)malloc(sizeof(Node));
    strcpy(p->region_code,code);
    for(int i=1; i<=70;i++){
        p->day[i]=0;
    }
    p->day[day]=patients;
    p->leftChild=NULL;
    p->rightChild=NULL;
    return p;
}

Node* insert(Node*r, char* code, int day, int patients){
    if(r==NULL) return makeNode(code, day, patients);
    int c=strcmp(r->region_code,code);
    if (c<0){
        r->rightChild= insert(r->rightChild,code, day, patients); return r;
    } else{ 
        if(c>0) {
        r->leftChild=insert(r->leftChild,code, day, patients); return r;}
        else {
            r->day[day]=patients;
        } 
    }
}

int count1=0,count2=0;

int FindNumberofPatients(Node *r){
    if(r==NULL) return count1;
    FindNumberofPatients(r->leftChild);
    printf("%s",r->region_code);
    for (int i = 1; i <= 70; i++)
    {
        printf("%d",r->day[i]);
        count1 =+ r->day[i];
    }
    FindNumberofPatients(r->rightChild);
}

int CountNumberPatientsOfPeriod(Node *r, int b, int e){
    if(r==NULL) return count2;
    CountNumberPatientsOfPeriod(r->leftChild,b,e);
    for (int i = b; i <= e; i++)
    {
        count2 =+ r->day[i];
    }
    CountNumberPatientsOfPeriod(r->rightChild,b,e);
}

Node* find(Node *r, char* name){
    int c= strcmp(r->region_code,name);
    if( c==0) return r;
    if(c<0 ) return find(r->rightChild,name);
    return find(r->leftChild,name);
}

int CountNumberPatientsOfRegion(Node *r, char* region){
    if(r==NULL) return 0;
    int count=0;
    Node* p= find(r, region);
    for (int i =1; i <= 70; i++)
    {
        count =+ p->day[i];
    }
}

void freeTree(Node* r){
    if(r==NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
/*
void solve(){
    char str[L];
    init();
    while(1){
        scanf("%s",str);
        if(strcmp(str,"*")==0) break;
        Node* p = find(str,root);
        if(p != NULL){
        }else{
            root = insert(str,root);
        }
    }

    while(1){
        scanf("%s",str);
        if(strcmp(str,"***")==0) break;
        if(strcmp(str,"$find")==0){
            char p[L];
            scanf("%s",p);
            Node* q = find(p,root);
            if(q != NULL){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }else if(strcmp(str,"$insert")==0){
            char p[L]; scanf("%s",p);
            Node* q = find(p,root);
            if(q != NULL){
                printf("0\n");
            }else{
                root = insert(p,root);
                printf("1\n");
            }
        }
    }
}*/
int main(){
    int menu,x,y,z,day,number_of_patients;
    char code[1000],code1[1000];
  printf("---------------\n");
  printf("   MAIN MENU   \n");
  printf("---------------\n");
  printf("1.Insert\n");
  printf("2.Total\n");
  printf("3.Period\n");
  printf("4.Region\n");
  printf("5.Free\n");
  do {
  printf("\nEnter your choice:");
  fseek(stdin,0,SEEK_END);
  scanf("%d",&menu);
  switch(menu){
	 case 1: fseek(stdin,0,SEEK_END);
            scanf("%s",code);
            fseek(stdin,0,SEEK_END);
            scanf("%d",&day);
            scanf("%d",&number_of_patients);
            insert(root,code,day,number_of_patients);
            break;
     case 2: z=FindNumberofPatients(root);
            printf("Total: %d",z);
     		 break;
    case 3:	fseek(stdin,0,SEEK_END);
            scanf("%d",&x);
            scanf("%d",&y);
            z=CountNumberPatientsOfPeriod(root,x,y);
            printf("Total: %d",z);
 			 break;
    case 4: fseek(stdin,0,SEEK_END);
            scanf("%s",code1);
            z=CountNumberPatientsOfRegion(root,code1);
            printf("Total: %d",z);
			break;
     case 5:freeTree(root);break;
    }
   } while(menu !=5);
    return 0;
}