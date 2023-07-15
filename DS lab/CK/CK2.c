#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 1000
typedef struct{
	int day;
	char RegionCode[L];
}dayre;
typedef struct{
	dayre dayreg;
    int NumOfPatiens;
}keyType;

typedef struct node_type{
    keyType key;
    struct node_type *left;
    struct node_type *right;
}nodeType;
typedef nodeType* treeType;

treeType root;
void init(){
    root = NULL;
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

treeType insert(keyType x, treeType r){
	if(r == NULL){
		nodeType* new = makeNode(x);
		if( new != NULL){
			new->left = NULL;
            new->right = NULL;
            r = new;
            return new;
		}
		return NULL;
	}
	else if(strcmp(x.dayreg.RegionCode, r->key.dayreg.RegionCode) < 0){
		r->left = insert(x, r->left);
	}else if(strcmp(x.dayreg.RegionCode, r->key.dayreg.RegionCode) > 0){
		r->right= insert(x, r->right);
	}else{
		if(x.dayreg.day < r->key.dayreg.day){
			r->left = insert(x, r->left);
		}else{
			r->right= insert(x, r->right);
		}		
	}
}
treeType checkdata(keyType x, treeType r){
	if(r == NULL){
		return NULL;
	}
	if((x.dayreg.day == r->key.dayreg.day) && (strcmp(x.dayreg.RegionCode, r->key.dayreg.RegionCode) == 0)){
		return r;
	}else if(strcmp(x.dayreg.RegionCode, r->key.dayreg.RegionCode) < 0){
		return checkdata(x, r->left);
	}else if(strcmp(x.dayreg.RegionCode, r->key.dayreg.RegionCode) > 0){
		return checkdata(x, r->right);
	}else{
		return NULL;
	}
}
int calsum(treeType r){
	int sum = 0;
	if(r == NULL) return 0;
	sum += r->key.NumOfPatiens;
	return sum + calsum(r->left) +calsum(r->right);
}
int calsumday(treeType r, int s_d, int e_d){
	int sum =0;
	if(r == NULL) return 0;
	if(r->key.dayreg.day >= s_d && r->key.dayreg.day <= e_d){
		sum += r->key.NumOfPatiens;
	}
	return sum + calsumday(r->left, s_d, e_d) + calsumday(r->right, s_d, e_d);	
}
int calsumre(treeType r, char * re){
	if(r == NULL) return 0;
	int sum = 0;
	if(strcmp(re ,r->key.dayreg.RegionCode) == 0){
		sum += r->key.NumOfPatiens;
	}
	return sum + calsumre(r->left, re) + calsumre(r->right ,re);
}
int main(){
	char str[50];
	char rg[50];
    init();
    keyType data;
    nodeType *mock;
    int s_d, e_d;
    
    while(1){
    	scanf("%s",str);
        if(strcmp(str,"***")==0) break;
        if(strcmp(str,"$Update")==0){
        	scanf("%s", data.dayreg.RegionCode);
        	scanf("%d", &data.dayreg.day);
        	scanf("%d", &data.NumOfPatiens);
        	if(checkdata(data, root) == NULL){
        		root = insert(data, root);
			}
		}
		else if(strcmp(str,"$CountTotalPatients") == 0){
			printf("%d\n", calsum(root));			
		}else if(strcmp(str,"$FindNumberPatients") == 0){
			scanf("%s", data.dayreg.RegionCode);
        	scanf("%d", &data.dayreg.day);
        	mock = checkdata(data, root);
        	if(mock == NULL) printf("0\n");
        	else printf("%d\n", mock->key.NumOfPatiens);
		}else if(strcmp(str,"$CountNumberPatientsOfPeriods") == 0){
			scanf("%d", &s_d);
			scanf("%d", &e_d);
			printf("%d\n", calsumday(root, s_d, e_d));
		}else if(strcmp(str,"$CountNumberPatientsOfRegion") == 0){
			scanf("%s", rg);	
			printf("%d\n", calsumre(root, rg));
		}
	}
	return 0;	 
}
