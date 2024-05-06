//Creators: Evan Closas and Jessi Wilfong
//Team 10_Class 1103
//Final Project

#include <stdio.h>

#define SIZE 100
#define ROW 12
#define COL 21

int load(char name[], char array[][COL]);
void display(char name[]);
void editMenu();
void crop();
void dimBright(int brightness, char array [][COL];
void rotate();
int save(char array[][COL]);

int main(){

int input;
char name[SIZE];
char array[ROW][COL];

//menu 1
	do{
	printf("\n");
	printf("**ERINSTAGRAM** \n");
	printf("1: Load image \n");
	printf("2: Display image \n");
	printf("3: Edit image \n");
	printf("0: Exit \n");
	printf("\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &input);
	printf("\n");
	
	switch(input){
	case 1:
		load(name, array);
	break;
	case 2:
		display(name);
	break;
	case 3: 
		editMenu();
	break;
	case 0:
		printf("\n");
		printf("Goodbye! \n");
		printf("\n");
	break;
	default:
		printf("\n");
		printf("Invalid option, please try again. \n");
	break;
	}	
}while (input != 0);


return 0;
}

int load(char name[], char array[][COL]){
	
 
	printf("\n");
	printf("What is the name of the image file? ");
	scanf("%s", name);
	
	FILE *fileIn = fopen(name, "r");
	
	
	if(fileIn == NULL){
	printf("\n");
	printf("Could not find an image with that filename. \n");
	return 0;
	}else{
	printf("\n");
	printf("Image successfully loaded! \n");
	}
	for(int i = 0; i < ROW; i++){
		if(fgets(array[i], COL + 1, fileIn) == NULL){
			printf("Could not find an image with that filename. \n");
			fclose(fileIn);
			return 0;	
			}
			}
		fclose(fileIn);
		return 1;
}


void display(char name[]){
	char image[SIZE];
	FILE *fileIn = fopen(name, "r");
	
	if(fileIn == NULL){
	printf("Sorry, no image to display \n");
	}else{
	while(fgets(image, SIZE, fileIn)){
	for(int i = 0; image[i] != '\0'; i++){
		if (image[i] == '0'){
			printf(" ");
		}else if (image[i] == '1'){
			printf(".");
		}else if(image[i] == '2'){
			printf("o");
		}else if(image[i] == '3'){
			printf("O");
		}else if(image[i] == '4'){
			printf("0");

	}
	}
		printf("\n");
	}
	fclose(fileIn);
}
}
//menu 2
void editMenu (){
int input;
char array[ROW][COL];

	do{
	printf("\n");
	printf("**EDITING** \n");
	printf("1: Crop image \n");
	printf("2: Dim image \n");
	printf("3: Brighten image \n");
	printf("4: Rotate image \n");
	printf("0: Return to main menu \n");
	printf("\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &input);
	
	switch(input){
	case 1: 
	crop();
	break;
	case 2: 
	dimBright();
	break;
	case 3: 
	dimBright(array);
	break;
	case 4: 
	rotate();
	break;
	case 0: 
	save(array);
	break;
	default:
		printf("\n");
		printf("Invalid option, please try again. \n");
	break;
	}
	}while (input != 0);
	
	}
	
void crop(){
	printf("crop \n");
}
void dimBright(char array [][COL]){
	for (int rows = 0; rows < ROW; rows++){
		for (int column = 0; column < COL; column++){
			if(array[rows][column] >= '0' && array[rows][column] <= '4'){
				array[rows][column] += brightness;
			}
		}		
	}
}



void rotate(){
	printf("rotate \n");
}
int save(char array[][COL]){
	char input;
	char name[SIZE];
	
	//vv needs fixed
	display(name);
	//^^
	printf("\n");
	
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &input);
	
	switch(input){
	case 'y':
	case 'Y':
		printf("What is the name of the image file? ");
		scanf("%s", name);
		FILE *fileIn = fopen(name, "w");
		if(fileIn == NULL){
			printf("Could not find the filename. \n");
			return 0;
			}else{
			printf("\n");
			printf("Image successfully loaded! \n");
		}
		for(int r = 0; r < ROW; r++){
			fprintf(fileIn, "%s\n", array[r]);
			}
			fclose(fileIn);
	default:
		return 0;
	break;
}
}

