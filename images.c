//Creators: Evan Closas and Jessi Wilfong
//Team 10_Class 1103
//Final Project

#include <stdio.h>

#define SIZE 100

int load(char name[]);
void display(char name[]);
void editMenu();
void crop();
void dimBright();
void rotate();
void save();

int main(){

int input;
char name[SIZE];

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
		load(name);
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

int load(char name[]){
	
 
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
	fclose(fileIn);
	return 1;
}
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
	dimBright();
	break;
	case 4: 
	rotate();
	break;
	case 0: 
	save();
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
void dimBright(){
	printf("dim \n");
	printf("bright \n");
}
void rotate(){
	printf("rotate \n");
}
void save(){
	printf("image \n");
	printf("Would you like to save the file? (y/n)");
}

