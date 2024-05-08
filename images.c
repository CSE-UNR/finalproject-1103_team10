//Creators: Evan Closas and Jessi Wilfong
//Team 10_Class 1103
//Final Project

#include <stdio.h>
#define SIZE 100
#define ROW 12
#define COL 21

// Function prototypes
int load(char name[], char array[][COL]);
void display(char array[][COL]);
void editMenu(char array[][COL]);
void crop(char array[][COL]);
void bright(char array[][COL]);
void dim(char array[][COL]);
void rotate(char array[][COL]);
int save(char array[][COL]);

int main() {
    int input;
    char name[SIZE];
    char array[ROW][COL];

    do {
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

        switch (input) {
            case 1:
                if (load(name, array))
                    printf("Image Successfully Loaded\n");
                break;
            case 2:
                display(array);
                break;
            case 3:
                editMenu(array);
                break;
            case 0:
                printf("Goodbye! \n");
                break;
            default:
                printf("Invalid option, please try again. \n");
                break;
        }
    } while (input != 0);

    return 0;
}

int load(char name[], char array[][COL]) {
    FILE *fileIn;
    char digit;
    int rowNum = 0, colNum = 0;

    printf("What is the name of the image file? ");
    scanf("%s", name);

    fileIn = fopen(name, "r");

    if (fileIn == NULL) {
        printf("Could not find an image with that filename. \n");
        return 0;
    }

    while (fscanf(fileIn, " %c", &digit) == 1) {
        if (digit >= '0' && digit <= '4') {
            array[rowNum][colNum] = digit;
            colNum++;
        }
        if (colNum == COL) {
            colNum = 0;
            rowNum++;
        }
        if (rowNum == ROW)
            break;
    }

    fclose(fileIn);

    return 1;
}

void display(char array[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            switch (array[i][j]) {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf(".");
                    break;
                case '2':
                    printf("o");
                    break;
                case '3':
                    printf("O");
                    break;
                case '4':
                    printf("0");
                    break;
                default:
                    printf("?");
            }
        }
        printf("\n");
    }
}

void editMenu(char array[][COL]) {
    int input;

    
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

        switch (input) {
            case 1:
                crop(array);
                break;
            case 2:
                dim(array);
                break;
            case 3:
                bright(array);
                break;
            case 4:
                rotate(array);
                break;
            case 0:
                save(array);
                break;
            default:
                printf("Invalid option, please try again. \n");
                break;
        }
    
}

void crop(char array[][COL]) {
    int row1, row2, col1, col2;

    	display(array);
	
	
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

    if (row1 < 0 || row1 >= ROW || col1 < 0 || col1 >= COL ||
        row2 < 0 || row2 >= ROW || col2 < 0 || col2 >= COL ||
        row2 < row1 || col2 < col1) {
        printf("Invalid coordinates. Please enter valid coordinates within the image dimensions.\n");
        return;
    }

    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            array[i][j] = '0';
        }
    }
}

void bright(char array[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (array[i][j] >= '0' && array[i][j] < '4') {
                array[i][j]++; 
            }
        }
    }
}

void dim(char array[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (array[i][j] > '0') {
                array[i][j]--; 
            }
        }
    }
}

void rotate(char array[][COL]) {
    char temp[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            temp[i][j] = array[i][j];
        }
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            array[i][j] = temp[ROW - 1 - j][i];
        }
    }
}

int save(char array[][COL]) {
    char input;
    char name[SIZE];

    printf("Would you like to save the file? (y/n) ");
    scanf(" %c", &input);

    if (input == 'y' || input == 'Y') {
        printf("What is the name of the image file? ");
        scanf("%s", name);

        FILE *fileOut = fopen(name, "w");

        if (fileOut == NULL) {
            printf("Could not open the file for writing. \n");
            return 0;
        }

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                fprintf(fileOut, "%c", array[i][j]);
            }
            fprintf(fileOut, "\n");
        }

        fclose(fileOut);
        printf("Image successfully saved.\n");
    }

    return 1;
}
