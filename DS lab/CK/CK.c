#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 1100
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


/*
void makeNullTree(treeType *t){
    (*t) = NULL;
}
*/
int emptyTree(treeType t){
    return (t == NULL);
}

treeType makeNode(keyType data){
    treeType n = (treeType)malloc(sizeof(nodeType));
    if(n != NULL){
        n->left = NULL;
        n->right = NULL;
        n->key = data;
    }
    return n;
}

void insertNode(keyType k, treeType *root){
    if(*root == NULL){
        *root = makeNode(k);
        return;
    }
    if(k.NumOfPatiens > (*root)->key.NumOfPatiens){
        insertNode(k, &(*root)->right);
    }
    if(k.NumOfPatiens < (*root)->key.NumOfPatiens){
        insertNode(k, &(*root)->left);
    }
  
}

int checkdata(treeType *t, keyType datacheck){
	if(t == NULL) return 0;
	int check;
	
	
	if(((*t)->key.day == datacheck.day) &&(strcmp((*t)->key.RegionCode, datacheck.RegionCode) == 1)){
		return 1;	
	}
	check = checkdata(&((*t)->left), datacheck);
	check = checkdata(&((*t)->right), datacheck);
	return check;
}
void solve(){
	char str[L];
	treeType T;
    T = NULL;
    keyType data;
    while(1){
    	scanf("%s",str);
        if(strcmp(str,"***")==0) break;
        if(strcmp(str,"$Update")==0){
        	scanf("%s", data.RegionCode);
        	scanf("%d", &data.day);
        	scanf("%d", &data.NumOfPatiens);
        	if(checkdata(&T, data) == 0){
        		inserNode(data, &T);
			}else{
				//do nothing
			}
		}
	}  
}
int main(){
    solve();
    return 0;
}
