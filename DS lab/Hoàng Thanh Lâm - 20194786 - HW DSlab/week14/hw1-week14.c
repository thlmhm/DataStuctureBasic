
#include"BST1.h"

void find(char *word, treeType root){
    keyType e;
    strcpy(e.eng, word);
    treeType result = search(e, root);
    if(result != NULL){
        printf("Word found!\n");
        printf("%s : %s\n", result->key.eng, result->key.vie);
        return;
    }
    printf("Word not found!\n");
}

void add(keyType e, treeType *root){
    insertNode(e, root);
    printf("Add words successfully\n");
}

void del(char *word, treeType *root){
    keyType e;
    strcpy(e.eng, word);
    deleteNode(e, root);
}

char *fix(char *a){
    int i = 0;
    while(a[i] != '\0'){
        if(a[i] == '\n')
            a[i] = '\0';
        i ++;
    }
    return a;
}

void divide(char *en, char *vi, char *word){
    int i = 0;
    while(word[i] != '\0' && word[i] != ':'){
        i ++;
    }
    strcpy(vi, word + i + 2);
    strcpy(en, word);
    en[i - 1] = '\0';
}

void importFromFile(treeType *root, FILE *f){
    char word = (char*)malloc(200*sizeof(char));
    keyType e;
    while(!feof(f)){
        fgets(word, 200, f);
        word = fix(word);
        // printf("%s\n", word);
        divide(e.eng, e.vie, word);
        insertNode(e, root);
    }
    printf("Import successfully\n");
}

void printDict(treeType root){
    if(root == NULL)
        return;
    printDict(root->left);
    printf("%s : %s\n", root->key.eng, root->key.vie);
    printDict(root->right);
}

void saveToFile(treeType root, FILE *f){
    if(root == NULL)
        return;
    char en = (char)malloc(200);
    char vi = (char)malloc(200);
    saveToFile(root->left, f);
    fprintf(f, "%s : %s\n", root->key.eng, root->key.vie);
    saveToFile(root->right, f);
}

int main(){
    treeType tree;
    makeNullTree(&tree);
    FILE *f;
    int menu;
    char word[100];
    do{
        printf("\n--------MENU-------\n");
        printf("\n1. Import from file.\n");
        printf("2. Print dictionary.\n");
        printf("3. Search for word.\n");
        printf("4. Add word.\n");
        printf("5. Delete word.\n");
        printf("6. Save to file.\n");
        printf("7. Exit.\n");
        printf("\nEnter choice: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                if( (f = fopen("vnedict.txt", "r")) == NULL){
                    printf("Cannot open: %s\n", "envDict.txt");
                    break;
                }
                importFromFile(&tree, f);
                break;
            case 2:
                printDict(tree);
                break;
            case 3:
                printf("Enter word: ");
                fflush(stdin);
                gets(word);
                find(word, tree);
                break;
            case 4:
                add(enterData(), &tree);
                break;
            case 5:
                printf("Enter word: ");
                fflush(stdin);
                gets(word);
                del(word, &tree);
                break;
            case 6:
                if( (f = fopen("envDict.txt", "w")) == NULL){
                    printf("Cannot open: %s\n", "envDict2.txt");
                    break;
                }
                saveToFile(tree, f);
                fclose(f);
                break;
            case 7:
                destroyTree(&tree);
                break;
            default:
                break;
        }
    }while(menu != 7);

}
