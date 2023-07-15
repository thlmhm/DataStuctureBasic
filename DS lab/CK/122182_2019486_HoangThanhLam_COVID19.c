#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 1000
#define numday 80
typedef struct{
	int day;
	char RegionCode[L];
    int NumOfPatiens;
}keyType;

typedef struct node_type{
    keyType key;
    struct node_type *left;
    struct node_type *right;
}nodeType;
typedef nodeType* treeType;
void makeNULL(treeType *node){
    if(*node != NULL){
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
}
treeType createNewNode(keyType data){
    treeType new = (treeType)malloc(sizeof(nodeType));
    if(new != NULL){
        new->key = data;
        makeNULL(&new);
    }return new;
}
int isLeaf(treeType *r){
    if(*r == NULL){
        return -1;
    }
    if((*r)->left == NULL && (*r)->right == NULL){
        return 1;
    }
    return 0;
}
treeType insert(keyType data, treeType *r){
    if(*r == NULL){
        nodeType* new = createNewNode(data);
        if(new != NULL){
            new->left = NULL;
            new->right = NULL;
            *r = new;
            return new;
        }
        return NULL;
    }
    if(strcmp(data.RegionCode, (*r)->key.RegionCode) < 0){
        insert(data, &(*r)->left);
    }else insert(data, &(*r)->right);
}
treeType check(keyType data, treeType *r){
    if(*r == NULL)
        return NULL;
    if(strcmp(data.RegionCode, (*r)->key.RegionCode) == 0){
        return *r;
    }else if(strcmp(data.RegionCode, (*r)->key.RegionCode) < 0){
        return check(data, &(*r)->left);
    }else 
        return check(data, &(*r)->right);
}

void update(nodeType** r, keyType new){
    nodeType* temp = check(new,r);
    if(temp == NULL)
        insert(new,r);
}
int CountTotal(treeType r){
    if( r == NULL){
        return 0;
    }
    int sum = 0;
    sum += r->key.NumOfPatiens;
    return sum + CountTotal(r->left) + CountTotal(r->right);
}
int CountTotal2(keyType data, treeType r){
    if( r == NULL){
        return 0;
    }
    treeType temp = check(data,&r);
    if(temp != NULL)
        return temp->key.NumOfPatiens;
    return 0;
}
int CountNumberPatientsOfRegion(char* data, treeType r){
    if(r == NULL)
        return 0;
    int sumsum = 0;
    if(strcmp(r->key.RegionCode, data) == 0){
        sumsum += r->key.NumOfPatiens;
    }
    return sumsum + CountNumberPatientsOfRegion(data, r->left) + CountNumberPatientsOfRegion(data, r->right);
}
void destroyTree(treeType *r){
    if(*r != NULL){
        destroyTree(&(*r)->left);
        destroyTree(&(*r)->right);
        free(*r);
    }
}
int main(){
    int isQuit = 0;
    treeType root[numday];
    int i;
    int tong1;
    for(i=1; i<numday;i++){
        root[i] = NULL;
    }
    while(!isQuit){
        char str[100];
        scanf("%s",str);
        if(strcmp(str,"$Update")==0){
            keyType new;
            scanf("%s %d %d", new.RegionCode, &new.day, &new.NumOfPatiens);
            update(&root[new.day], new);
            tong1 += new.NumOfPatiens;
        }
        else if(strcmp(str, "$CountTotalPatients") == 0){
            printf("%d\n", tong1);
        }
        else if(strcmp(str, "$FindNumberPatients") == 0){
            keyType tem;
            scanf("%s %d", tem.RegionCode, &tem.day);
            printf("%d\n", CountTotal2(tem, root[tem.day]));
        }
        else if(strcmp(str, "$CountNumberPatientsOfPeriod") == 0){
            int startDay = 0, endDay = 0;
            scanf("%d %d", &startDay, &endDay);
            int sum3 = 0;
            for(i=startDay; i<=endDay; i++){
                sum3 += CountTotal(root[i]);
            }
            printf("%d\n", sum3);
        }
        else if(strcmp(str, "$CountNumberPatientsOfRegion") == 0){
            char temp2[L];
            scanf("%s", temp2);
            int sum4 = 0;
            for(i=1; i<numday; i++){
                sum4 += CountNumberPatientsOfRegion(temp2,root[i]);
            }
            printf("%d\n", sum4);
        }
        else if(strcmp(str, "***") == 0)
        {
            isQuit = 1;
            for(i=1; i<numday; i++)
                destroyTree(&root[i]);
        }
    }
}


