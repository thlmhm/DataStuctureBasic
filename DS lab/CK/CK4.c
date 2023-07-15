#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char region_code[100];
    int day[101];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* root=NULL;

Node* makeNode(char* code, int day, int patients){
    Node* p=(Node*)malloc(sizeof(Node));
    strcpy(p->region_code,code);
    for(int i=1; i<=100;i++){
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
        r->rightChild= insert(r->rightChild,code, day, patients);
    } else{
        if(c>0) {
            r->leftChild=insert(r->leftChild,code, day, patients);
        } else  r->day[day]=patients;
        
    }
    return r;
}

int count1=0,count2=0;

Node* find(Node *r, char* name){
    int c= strcmp(r->region_code,name);
    if( c==0) return r;
    if(c<0 ) return find(r->rightChild,name);
    return find(r->leftChild,name);
}


int FindNumberofPatients(Node *r, char* code, int day){
    if(r==NULL) return 0;
    Node* p=find(r,code);
    return p->day[day];
}


int CountNumberPatientsofPeriod(Node *r, int b, int e){
    int count2=0;
    if(r==NULL) return 0;
    for (int i = b; i <= e; i++)
    {
        count2 = count2 + r->day[i];
    }
    return (count2 + CountNumberPatientsofPeriod(r->leftChild,b,e) + CountNumberPatientsofPeriod(r->rightChild,b,e));
}

int CountNumberPatientsOfRegion(Node *r, char* region){
    if(r==NULL) return 0;
    int count=0;
    Node* p= find(r, region);
    for (int i =1; i <= 100; i++)
    {
        count = count+ p->day[i];
    }
    return count;
}

void freeTree(Node* r){
    if(r==NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

void inorder(Node* r)
{
    if (r != NULL) {
        inorder(r->leftChild);
        printf("%s\n ", r->region_code);
        inorder(r->rightChild);
    }
}


int main(){
    int z;
    char cmd[20];
    char region_code[50];
    int day,ca_nhiem,b,e;
    while(strcmp(cmd,"***")!=0)
        {
        scanf("%s",&cmd);
        if(strcmp(cmd,"$Update")==0)
            {
                scanf("%s",&region_code);
                scanf("%d",&day);
                scanf("%d",&ca_nhiem);
                root=insert(root,region_code,day,ca_nhiem);
                count1 = count1+ ca_nhiem;
            }
            if(strcmp(cmd,"$CountTotalPatients")==0)
                {   
                    printf("%d\n",count1);
                }
            if(strcmp(cmd,"$FindNumberPatients")==0)
                {
                    scanf("%s",&region_code);
                    scanf("%d",&day);
                    z=FindNumberofPatients(root,region_code,day);
                    printf("%d",z);
                }
            else if (strcmp(cmd,"$CountNumberPatientsOfPeriod")==0) 
                {  
                    scanf("%d",&b);
                    scanf("%d",&e);
                    z=CountNumberPatientsofPeriod(root,b,e);
            
                    printf("%d\n",z);
                }
            else if(strcmp(cmd,"$CountNumberPatientsOfRegion")==0)
                {
                    scanf("%s",&region_code);
                    printf("%d\n",CountNumberPatientsOfRegion(root,region_code));
                }
            }
        return 0;
}