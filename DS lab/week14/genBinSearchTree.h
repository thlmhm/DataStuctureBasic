#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node_type{
    keyType key;
    struct node_type *left;
    struct node_type *right;
}nodeType;
typedef nodeType* treeType;

void makeNullTree(treeType *t){
    (*t) = NULL;
}

keyType enterData(){
    printf("Enter English word: ");
    char eng[100], vie[200];
    fflush(stdin);
    gets(eng);
    printf("Enter Vietnamese word: ");
    fflush(stdin);
    gets(vie);
    keyType e;
    strcpy(e.eng, eng);
    strcpy(e.vie, vie);
    return e;
}

int emptyTree(treeType t){
    return (t == NULL);
}

treeType leftChild(treeType n){
    if(n != NULL)
        return n->left;
    return NULL;
}

treeType rightChild(treeType n){
    if(n != NULL)
        return n->right;
    return NULL;
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

int isLeaf(treeType n){
    if(n != NULL){
        return(leftChild(n) == NULL && rightChild(n) == NULL);
    }
    return -1;
}

treeType creatFrom2(keyType e, treeType l, treeType r){
    treeType n = (treeType)malloc(sizeof(nodeType));
    n->key = e;
    n->left = l;
    n->right = r;
    return n;
}

char *firstName(char *name){
    char* fname = (char*)malloc(30 * sizeof(char));
    int i = 0;
    while(name[i] != '\0'){
        if(name[i] == ' '){
            fname = name + i + 1;
        }
        i ++;
    }
    return fname;
}

int compare(keyType a, keyType b){
    if(strcmp(a.eng, b.eng) > 0){
        return 1;
    }
    if(strcmp(a.eng, b.eng) < 0){
        return -1;
    }
    return 0;
}

void insertNode(keyType k, treeType *root){
    if(*root == NULL){
        *root = makeNode(k);
        return;
    }
    if(compare(k, (*root)->key) > 0){
        insertNode(k, &(*root)->right);
    }
    if(compare(k, (*root)->key) < 0){
        insertNode(k, &(*root)->left);
    }
  
}

keyType deleteMin(treeType *root){
    keyType k;
    if((*root)->left == NULL){
        k = (*root)->key;
        *root = (*root)->right;
        return k;
    }
    else return deleteMin(&(*root)->left);      

}

void deleteNode(keyType x, treeType *root){
    if(*root != NULL){
        if(compare(x, (*root)->key) < 0){
            deleteNode(x, &(*root)->left);
        }
        else if(compare(x, (*root)->key) > 0){
            deleteNode(x, &(*root)->right);
        }
        else if(isLeaf(*root)){
            *root = NULL;
            printf("Item deleted!\n");
        }
        else if((*root)->left == NULL){
            *root = (*root)->right;
        }
        else if((*root)->right == NULL){
            *root = (*root)->left;
        }
        else 
            (*root)->key = deleteMin(root);
            // printf("Item deleted!\n");
    }
    else{
        printf("Cannot delete\n");
    }
}

treeType search(keyType k, treeType root){
    if(root == NULL){
        // printf("Empty tree!\n");
        return NULL;
    }

    if(compare(k, root->key) == 0){
        return root;
    }
    if(compare(k, root->key) < 0){
        return search(k, root->left);
    }
    if(compare(k, root->key) > 0){
        return search(k, root->right);
    }
}

treeType addLeft(treeType *t, keyType data){
    nodeType *newNode = makeNode(data);
    if(*t == NULL){
        *t = newNode;
        return *t;
    }

    while((*t)->left != NULL){
        *t = (*t)->left;
    }
    (*t)->left = newNode;
    return newNode;
}

treeType addRight(treeType *t, keyType data){
    nodeType *newNode = makeNode(data);
    if(*t == NULL){
        *t = newNode;
        return *t;
    }
    treeType temp = *t;
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->right = newNode;
    return newNode;
}


int height(treeType t){
    int h = 0;
    if(t != NULL){
        h ++;
    }
    else{
        return h;
    }
    h += __max(height(leftChild(t)), height(rightChild(t)));
    return h;
}

int countLeaf(treeType t){
    int count = 0;
    if(t == NULL)
        return count;

    if(isLeaf(t)){
        count ++;
    }
    
    count += countLeaf(leftChild(t));
    count += countLeaf(rightChild(t));

    return count;
}

int countInternalNode(treeType t){
    int count= 0;
    if(t == NULL){
        return count;
    }

    if(!isLeaf(t)){
        count ++;
    }

    count += countInternalNode(leftChild(t));
    count += countInternalNode(rightChild(t));
    return count;
}

int countRightChild(treeType t){
    int count = 0;
    if(t == NULL){
        return count;
    }

    if(rightChild(t) != NULL){
        count ++;
    }

    count += countRightChild(leftChild(t));
    count += countRightChild(rightChild(t));
    return count;
}

void inorderPrint(treeType t){
    if(t == NULL)
        return;
    inorderPrint(t->left);
    printf("%s\n", t->key);
    inorderPrint(t->right);
}

void preorderPrint(treeType t){
    if(t == NULL)
        return;
    printf("%s\n", t->key);
    inorderPrint(t->left);
    inorderPrint(t->right);
}

void postorderPrint(treeType t){
    if(t == NULL)
        return;
    inorderPrint(t->left);
    inorderPrint(t->right);
    printf("%s\n", t->key);
}

void destroyTree(treeType *root){
    if(*root != NULL){
        destroyTree(&(*root)->left);
        destroyTree(&(*root)->right);
        *root = NULL;
    }
}


