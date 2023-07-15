#include"doublylist.h"


int main(){
	int choice;
	int check;
	int check2;
	FILE *f1;
	char product[20];
	do{
		printf("\n---------MENU---------\n");
		printf("1. Import from PhoneDB.dat.\n");
  		printf("2. Display.\n");
  		printf("3. Search & Update (movetofront).\n");
  		printf("4. Search & Update (transpose).\n");
  		printf("5. Quit.\n");
  		printf("---------------------------------------------------------\n");
  		printf("Enter choice:");
  		do{
  			scanf("%d", &choice);
  			if(choice<1||choice>5){
  				printf("Enter again!");
  			}
  		}while(choice<1||choice>5);
  		switch(choice){
  			case 1:
  				if((f1 = fopen("phoneDB.dat","rb")) ==NULL){
  					printf("Cannot open phoneDB.dat\n");
  					return 0;
  				}
  				importdata(f1);
  				printf("\n Success ... \n");
  				fclose(f1);
  				break;
  			case 2:
  				traverse();
  				break;
  			case 3:
  				while(getchar() != '\n');
  				printf("Enter Phone model:");
    				scanf("%s",product);
    				check = searchmodel(product, &root, &cur);
    				switch(check){
    					case 1:
    						printf("Success!");
    						break;
    					case 0:
    						printf("No result!");
    						break;			
    				}
    				search_movetofront(product);		
  				break;
  			case 4:
  				while(getchar() != '\n');
  				printf("Enter Phone model:");
    				scanf("%s",product);
    				check = searchmodel(product, &root, &cur);
    				switch(check){
    					case 1:
    						printf("Success!");
    						break;
    					case 0:
    						printf("No result!");
    						break;			
    				}
    				search_transpose(product);
  				break;
  			case 5:
  				freelist();
  				break;
  		}
	}while(choice != 5);
	
}
