#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define REGION 1000
#define COMMAND 100
#define NAME 50
typedef struct Covid{
    int day;
    char region[REGION];
    int patients;
}Covid;

typedef Covid KeyType;

typedef struct Node
{
    KeyType key;
    struct Node *left, *right;
}Node;

typedef Node Tree;

int isEmpty(Node** tree)
{
    if(*tree == NULL)
        return 1;
    return 0;
}

void makeNULL(Node** node)
{
    if(*node != NULL)
    {
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
}

Node* createNewNode(KeyType data)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if(new != NULL)
    {
        new->key = data;
        makeNULL(&new);
    }
    return new;
}

Node* leftChild(Node** tree)
{
    if(*tree == NULL || (*tree)->left == NULL)
        return NULL;
    return (*tree)->left;
}

Node* rightChild(Node** tree)
{
    if(*tree == NULL || (*tree)->right == NULL)
        return NULL;
    return (*tree)->right;
}

int isLeaf(Node** tree)
{
    if(isEmpty(tree))
        return -1;
    if((*tree)->left == NULL && (*tree)->right == NULL)
        return 1;
    return 0;
}

Node* insertKey(KeyType data, Node **root)
{
    if(*root == NULL)
    {
        Node* new = createNewNode(data);
        if(new != NULL)
        {
            new->left = NULL;
            new->right = NULL;
            *root = new;
            return new;
        }
        return NULL;
    }
    if(strcmp(data.region,(*root)->key.region) > 0)
        return insertKey(data, &(*root)->right);
    else if(strcmp(data.region, (*root)->key.region) < 0)
        return insertKey(data, &(*root)->left);
    else if(strcmp(data.region, (*root)->key.region) == 0)
        if(data.day > (*root)->key.day)
            return insertKey(data, &(*root)->right);
        else
            return insertKey(data, &(*root)->left);
}

Node* searchKey(KeyType data, Node **root)
{
    if(*root == NULL)
        return NULL;
    if(strcmp(data.region, (*root)->key.region) == 0 && data.day == (*root)->key.day)
        return *root;
    if(isLeaf(root))
        return NULL;
    if(strcmp(data.region, (*root)->key.region) > 0)
        return searchKey(data, &(*root)->right);
    else if(strcmp(data.region, (*root)->key.region) < 0)
        return searchKey(data, &(*root)->left);
    else if(strcmp(data.region, (*root)->key.region) == 0)
        if(data.day > (*root)->key.day)
            return searchKey(data, &(*root)->right);
        else
            return searchKey(data, &(*root)->left);
}

void destroyTree(Node** tree)
{
    if(*tree != NULL)
    {
        destroyTree(&(*tree)->left);
        destroyTree(&(*tree)->right);
        free(*tree);
    }
}

int findNumberPatients(Tree* covid, Covid findObject)
{
    Tree* temp = searchKey(findObject, &covid);
    if(temp != NULL)
        return temp->key.patients;
    return 0;
}

void update(Tree** covid, Covid new)
{
    Tree * temp = searchKey(new, covid);
    if(temp == NULL)
        insertKey(new, covid);
}

int count(Tree* covid)
{
    if(covid == NULL)
        return 0;
    int sum = 0;
    sum += covid->key.patients;
    return sum + count(covid->left) + count(covid->right);
}

int countNumberPatientsOfPeriod(Tree* covid, int startDay, int endDay)
{
    if(covid == NULL)
        return 0;
    int sum = 0;
    if(covid->key.day >= startDay && covid->key.day <= endDay)
        sum += covid->key.patients;
    return sum + countNumberPatientsOfPeriod(covid->left, startDay, endDay)
     + countNumberPatientsOfPeriod(covid->right, startDay, endDay);
}

int countNumberPatientsOfRegion(Tree* covid, char region[])
{
    if(covid == NULL)
        return 0;
    int sum = 0;
    if(strcmp(covid->key.region, region) == 0)
        sum += covid->key.patients;
    return sum + countNumberPatientsOfRegion(covid->left, region) 
    + countNumberPatientsOfRegion(covid->right, region);
}

int main()
{
    Tree *covid = NULL;
    int isQuit = 0;
    while(1)
    {
        char command[COMMAND] = {};
        scanf("%s", command);
        if(strcmp(command, "***") == 0) break;
        else if(strcmp(command, "$Update") == 0)
        {
            Covid new;
            scanf("%s %d %d", new.region, &new.day, &new.patients);
            update(&covid, new);
        }else if(strcmp(command, "$CountTotalPatients") == 0)
        {
            printf("%d\n", count(covid));
        }else if(strcmp(command, "$FindNumberPatients") == 0)
        {
            Covid temp;
            scanf("%s %d", temp.region, &temp.day);
            printf("%d\n", findNumberPatients(covid, temp));
        }else if(strcmp(command, "$CountNumberPatientsOfPeriod") == 0)
        {
            int startDay = 0, endDay = 0;
            scanf("%d %d", &startDay, &endDay);
            printf("%d\n", countNumberPatientsOfPeriod(covid, startDay, endDay));
        }else if(strcmp(command, "$CountNumberPatientsOfRegion") == 0)
        {
            char region[REGION] = {};
            scanf("%s", region);
            printf("%d\n", countNumberPatientsOfRegion(covid, region));
        }else if(strcmp(command, "***") == 0)
        {
            isQuit = 1;
            destroyTree(&covid);
        }
    }

    return 0;
}

 
