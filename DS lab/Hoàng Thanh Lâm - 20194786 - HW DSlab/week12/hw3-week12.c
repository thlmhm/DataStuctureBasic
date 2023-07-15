#include"tree.h"
void inorderprint(treetype tree){
	if(tree!=NULL){
		inorderprint(tree->left);
		printf("%4d\n", tree->element);
		inorderprint(tree->right);
	}
}
int main(){
	char c;
	char s[10];
	treetype T;
	MakeNullTree(&T);
	printf("Start create node ... \n");
	printf("Creating root node ... \n");
	T = create_node(enter_data());
	printf("Creating  node ... \n");
	T->left = create_node(enter_data());
	T->right = create_node(enter_data());
	T->left->left = create_node(enter_data());
	T->left->right = create_node(enter_data());
	T->right->left = create_node(enter_data());
	T->right->right = create_node(enter_data());	
	//T->left->left->left = create_node(enter_data());
	//T->left->left->right = create_node(enter_data());	
	/*do{	
		while(getchar() != '\n');
		printf("Continue? (y/n)  ");
		scanf("%c", &c);
		if(c == 'y'){
			printf("What position of you want to add?(left or right)");
			scanf("%s", s);
			if(strcmp(s, "left") == 0) Add_Left(&T, enter_data());
			else if(strcmp(s, "right") == 0) Add_Right(&T, enter_data());
			else printf("Wrong syntax! Your must enter left or right!\n");
		}
		else if (c == 'n') break;
		else printf("Wrong syntax! You must enter y or n \n");
	}while(c != 'n');*/
	printf("Number of node: %d \n",nb_nodes(T));
	printf("Height of binary tree: %d \n",height(T));
	printf("Number of leafs: %d \n",nb_leafs(T));
	printf("Number of internal nodes: %d \n",nb_internal_nodes(T));
	printf("Number of right children: %d \n",countRightChild(T));
	printf("Inorder print:\n");
	inorderprint(T);
	free_tree(T);
	return 0;
	
}
