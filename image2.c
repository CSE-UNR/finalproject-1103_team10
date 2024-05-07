//Creators: Evan Closas and Jessi Wilfong
//Team 10_Class 1103
//Final Project

#include <stdio.h>
#define SIZE 100
#define ROW 12
#define COL 21

int load(FILE *fileIn, char array[][COL]);
void display(char name[]);
void editMenu();
void crop(int *cRowPtr, int *cColPtr, char array[][COL], int arrayC[][COL]);
void bright(char array [][COL]);
void dim(char array [][COL]);
void rotate();
int save(char array[][COL]);

int main(){

	int input;
	char name[SIZE];
	char array[ROW][COL];
	int arrayC[ROW][COL];
	FILE *fileIn; 
	int cropRptr, cropCptr;
	
//	cropRptr = crop(&cRowPtr, &cColPtr, array, arrayc);
	
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
		load(fileIn, name, array);
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

int load(FILE *fileIn, char array[][COL]){
	char digit;
	int rowNum = 0, colNum = 0;
 
	printf("\n");
	printf("What is the name of the image file? ");
	scanf("%s", name);
	
	fileIn = fopen(name, "r");
	
	
	if(fileIn == NULL){
		printf("\n");
		printf("Could not find an image with that filename. \n");
		return 0;
	}
	
	while(fscanf(fileIn, "%c", &digit) == 1) {
			if(digit >= '0' || digit <= '4'){
				array[rowNum][colNum] == digit;
			}
	}
	
	if (digit == '\n'){
		if(colNum == 0){
			colNum++;
		}
		rowNum++;
	}
	
	
	fclose(fileIn);
	
	printf("Image Sucessfully Loaded\n");
	
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
cropRptr = crop(&cRowPtr, &cColPtr, array, arrayc);
int input;
	char name[SIZE];
	int arrayC[ROW][COL];
	FILE *fileIn; 
	int cropRptr, cropCptr;
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
	crop(&cRowPtr, &cColPtr, array, arrayc);
	break;
	case 2: 
	bright(array);
	break;
	case 3: 
	dim(array);
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
	
void crop(int *cRowPtr, int *cColPtr, char array[][COL], int arrayC[][COL]){
	
	display(char name[]);
	
	int row1, row2, col1, col2;
	
	printf("The image you want to crop is 12 x 21");
	printf("The row starts at 1 & ends at 21, the column value starts at 1 & ends at 12");
	
	printf("Which column do you want to be the new left?");
	scanf("%d", &col1);
	
	printf("Which column do you want to be the new right?");
	scanf("%d", &col2);

	printf("Which row do you want to be the new top?");
	scanf("%d", &row1);

	printf("Which row do you want to be the new bottom?");
	scanf("%d", &row2);

	row1--; row2--; col1--; col2--;

	 int cRow = row2 - row1 + 1;

   	 int cCol = col2 - col1 + 1;


    if (row1 < 0 || row1 >= ROW || col1 < 0 || col1 >= COL || row2 < 0 || row2 >= ROW || col2 < 0 || col2 >= COL || row2 < row1 || col2 < col1) {
	printf("Invalid coordinates. Please enter valid coordinates within the image dimensions.\n");
	return;
}
	for (int i = 0; i < cRow; i++) {
        	for (int j = 0; j < cCol; j++) {
			array[ROW][COL] = arrayC[row1 + ROW][col1 + COL];

        	}

    	}

	
	
}
void bright(char array [][COL]){
	for (int rows = 0; rows < ROW; rows++){
		for (int column = 0; column < COL; column++){
			if(array[rows][column] < 4){
				array[rows][column]++;
			}
		}		
	}
}

void dim(char array [][COL]){
	for (int rows = 0; rows < ROW; rows++){
		for (int column = 0; column < COL; column++){
			if(array[rows][column] > 0){
				array[rows][column]--;
			}
		}
	}
}


void rotate(){
	
}
int save(char array[][COL]){
	char input;
	char name[SIZE];
	
	//vv needs fixed
	printf("\n");
	printf("\n");
	
	printf("\n");
	
	
	
	
	
	printf("\n");
	printf("\n");
	
	
	printf("\n");
	
	printf("\n");
	
	printf("\n");
	
	
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

