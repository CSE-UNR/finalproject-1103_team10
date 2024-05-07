#include <stdio.h>
#define SIZE 100
#define ROW 12
#define COL 21




int load(char array[][COL]);
void display(char array[][COL]);
void editMenu(char array[][COL]);
void crop(int *cRowPtr, int *cColPtr, char array[][COL], int arrayC[][COL]);
void brighten(char array[][COL]);
void dim(char array[][COL]);
void rotate();
int save(char array[][COL]);

int main() {
    int input;
    char array[ROW][COL];

    do {
        printf("\n**ERINSTAGRAM**\n");
        printf("1: Load image\n");
        printf("2: Display image\n");
        printf("3: Edit image\n");
        printf("0: Exit\n");
        printf("Choose from one of the options above: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                load(array);
                break;
            case 2:
                display(array);
                break;
            case 3:
                editMenu(array);
                break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while (input != 0);

    return 0;
}

int load(char array[][COL]) {
    char name[SIZE];
    char digit;
    int rowNum = 0, colNum = 0;

    printf("\nEnter the name of the image file: ");
    scanf("%s", name);

    FILE *fileIn = fopen(name, "r");
    if (fileIn == NULL) {
        printf("Could not find an image with that filename.\n");
        return 0;
    }

    while (fscanf(fileIn, " %c", &digit) == 1) {
        if (colNum >= COL || rowNum >= ROW) {
            printf("Image dimensions exceed maximum allowed.\n");
            break;
        }
        if (digit >= '0' && digit <= '4') {
            array[rowNum][colNum++] = digit;
        }
        if (colNum == COL) {
            colNum = 0;
            rowNum++;
        }
    }

    fclose(fileIn);
    printf("Image Successfully Loaded\n");
    return 1;
}

void display(char array[][COL]) {
    // Function body remains the same
}

void editMenu(char array[][COL]) {
    int input;

    do {
        printf("\n**EDITING**\n");
        printf("1: Crop image\n");
        printf("2: Brighten image\n");
        printf("3: Dim image\n");
        printf("4: Rotate image\n");
        printf("0: Return to main menu\n");
        printf("Choose from one of the options above: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                crop(array);
                break;
            case 2:
                brighten(array);
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
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while (input != 0);
}

void crop(int *cRowPtr, int *cColPtr, char array[][COL], int arrayC[][COL]){
    display(name[]);
	
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


void brighten(char array[][COL]) {
    for (int rows = 0; rows < ROW; rows++){
		for (int column = 0; column < COL; column++){
			if(array[rows][column] < 4){
				array[rows][column]++;
			}
		}		
	}
}

void dim(char array[][COL]) {
    for (int rows = 0; rows < ROW; rows++){
		for (int column = 0; column < COL; column++){
			if(array[rows][column] > 0){
				array[rows][column]--;
			}
		}
	}
}

void rotate() {
    
}

int save(char array[][COL]) {
    char input;
    char name[SIZE];

    printf("\nWould you like to save the file? (y/n): ");
    scanf(" %c", &input);

    switch (input) {
        case 'y':
        case 'Y':
            printf("Enter the name of the image file: ");
            scanf("%s", name);
            FILE *fileOut = fopen(name, "w");
            if (fileOut == NULL) {
                printf("Could not create the file.\n");
                return 0;
            }
            for (int r = 0; r < ROW; r++) {
                for (int c = 0; c < COL; c++) {
                    fprintf(fileOut, "%c", array[r][c]);
                }
                fprintf(fileOut, "\n");
            }
            fclose(fileOut);
            printf("Image successfully saved as %s.\n", name);
            return 1;
        default:
            printf("Image not saved.\n");
            return 0;
    }
}
