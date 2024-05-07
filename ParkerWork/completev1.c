//Author: Parker Henry & Ellison Domingo
//Due Date: Tuesday May 7
//Project: Final; Image Processing

#include<stdio.h>

#define MAX_ROWS 500
#define MAX_COLUMNS 500
#define FILENAMEMAX 50

int FirstMenu();
void LoadImage(int cols, char image[][cols], char *loadfilenameptr,int* rowptr, int* colsptr);
void DisplayImage(int cols, char image[][cols], char displayfilename[FILENAMEMAX], int rowptr, int colsptr);

int SecondMenu();
void CropImage(int cols, char originalImage[][cols], int rows, int columns, char newcroppedImage[][cols]);
void DimImage(int cols, char originalImage[][cols], int rows, int columns, char newdimImage[][cols]);
void BrightenImage(int cols, char originalImage[][cols], int rowptrb, int colptrb, char newbrightimage[][cols]);
int main()
{
	char originalImage[MAX_ROWS][MAX_COLUMNS];
	char brightenedImage[MAX_ROWS][MAX_COLUMNS];
	char dimnedImage[MAX_ROWS][MAX_COLUMNS];
	char croppedImage[MAX_ROWS][MAX_COLUMNS];
	int firstMenuChoice;
	int secondmenuchoice;
	int rownum;
	int colnum;
	char filename[FILENAMEMAX];
	do
	{
		firstMenuChoice = FirstMenu();
		switch (firstMenuChoice)
		{
			case 1:
			
				LoadImage(MAX_COLUMNS, originalImage, &filename, &rownum, &colnum);
				break;
			case 2:
				
				DisplayImage(MAX_COLUMNS, originalImage, filename, rownum, colnum);
				break;
			case 3:
				
				secondmenuchoice = SecondMenu();
				switch(secondmenuchoice)
				{
					case 1:
				
					CropImage(MAX_COLUMNS, originalImage, rownum, colnum, croppedImage);
					break;
				case 2:
					DimImage(MAX_COLUMNS, originalImage, rownum, colnum, dimnedImage);
					break;
					case 3:
						BrightenImage(MAX_COLUMNS, originalImage, rownum, colnum, brightenedImage);
						break;
				case 4:
					printf("Welcome Back!\n");
					break;
				default:
					printf("\n(improper choice)\n");
					break;	
				}
				break;
			case 4:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("\n(improper choice)");
				break;
		}
	
	}
	while(firstMenuChoice != 4);
	
}

// FirstMenu() definition
int FirstMenu()
{
	int choice;
	
	printf("\n ***Image processing program***\n Please select an option below.");
	printf("\n[1] Load new image");
	printf("\n[2] Display current image");
	printf("\n[3] Edit current image");
	printf("\n[4] Exit the program");
	printf("\n\nEnter the number of your choice here: ");
	scanf("%d", &choice);
	
	return choice;
		
}

// LoadImage() definition
void LoadImage(int cols, char originalImage[][cols],char *loadfilenameptr,int* rowptr, int* colptr)
{
   FILE *filePtr;
    char loadfilename[FILENAMEMAX];
    int rowIndex = 0, columnIndex = 0;
	do{
	printf("Input your file name (no spaces): ");
        scanf("%s", loadfilename);
    	filePtr = fopen(loadfilename, "r");
        if (filePtr == NULL) 
        {
            printf("File error\n");
    	} 
    }
    while (filePtr ==NULL);
    
    char temp;
    fscanf(filePtr, "%c", &temp);
    //printf("Character: %c, ASCII: %d\n", temp, temp);
    while (fscanf(filePtr, "%c", &temp) == 1) 
    {
    	//printf("Character: %c, ASCII: %d\n", temp, temp);
        if (temp == '\n') 
        {
            rowIndex++;
            *colptr = columnIndex;
            //printf("Row %d, Columns: %d\n", rowIndex, columnIndex);
            columnIndex = 0;
        } else {
            originalImage[rowIndex][columnIndex] = temp;
            //printf("\n%c\n",originalImage[rowIndex][columnIndex]); 
            columnIndex++;
        }
    }
    fclose(filePtr);

    *rowptr = rowIndex;
    

    printf("\n\nImage successfully loaded.\n");
   // printf("Row: %d\n", rowIndex);
    //printf("Column: %d\n", *colptr);

}

	
	

// DisplayImage() definition
void DisplayImage(int cols, char originalImage[][cols], char displayfilename[FILENAMEMAX], int rowptr, int colptr)
{
	printf("\nstarting display test...\n");
	printf("\n\n");

	// Printing array to screen:
	for (int i = 0; i < rowptr; i++) {
		for (int j = 0; j < colptr; j++) 
		{
			switch (originalImage[i][j])
			{
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
					break;
			}
    		}
    		printf("\n"); // Move to the next line after printing a row
	}
	

	
}
//second menu def

int SecondMenu()
{
	int choice;
	do
	{
		printf("**EDITING**\n[1]: Crop image\n[2]: Dim image\n[3]: Brighten image\n[4]: Return to main menu\n");
		printf("Choose from one of the options above:");
    		scanf("%d", &choice);
    		if(choice<1 || choice>4)
    		{
      			printf("\nInvalid choice try again.\n ");
  		}
	}
	while( choice > 4 || choice < 1);
 	return choice;
}
	
	
	
	
	
 void CropImage(int cols, char originalImage[][cols], int rows, int columns, char newcroppedImage[][cols])
{
	int left = 0, right = 0, top = 0, bottom = 0;	
		char filename[50];
	DisplayImage(MAX_COLUMNS, originalImage, filename, rows, columns);
	printf("\n\nThe image you want to crop is %d x %d.", rows, columns);
	printf("\nThe row and column values start in the upper lefthand corner.");
	
	printf("\n\nWhich column do you want to be the new left side? ");
	scanf("%d", &left);
	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &right);
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &top);
	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &bottom);
	
	int newRow = 0, newColumn = 0;
	
	for (int i = top; i < bottom; i++)
	{
		for (int j = left; j < right; j++)
		{
			newcroppedImage[newRow][newColumn] = originalImage[i][j];
			newColumn++;
		}
		newColumn = 0;
		newRow++;
	}
	
	printf("\nHere is the cropped image:\n");

	DisplayImage(right-left, newcroppedImage, filename, bottom-top, right-left);
	
	char choicesec;
 	printf("Would you like to save the file? (Y or N): ");
 	scanf(" %c", &choicesec);
	if(choicesec == 'Y' || choicesec == 'y')
	{
 		
 		FILE *fptr;
 		char newfilename[50];
 		printf("Input file name(no spaces, include extension): ");
 		scanf("%s", &newfilename);
 		fptr = fopen(newfilename, "w");
 		 if (fptr == NULL)
 		{
      			 printf("Unable to open file.\n");
  		}
    		else
    		{
    			for (int i = 0; i < rows; i++)
    			{
				for (int j = 0; j < columns; j++) 
				{
        				fprintf(fptr,"%c", newcroppedImage[i][j]);
    				}
    				fprintf(fptr,"\n");
    			}
    			fclose(fptr);
    		}
 		
 	}
}
 
 
 
 
 
 
 
 
  
void DimImage(int cols, char originalImage[][cols], int rows, int columns, char newdimImage[][cols]){

for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			switch (originalImage[i][j])
			{
				case '0':
					printf(" ");
					newdimImage[i][j] = '0';
					break;
				case '1':
					printf(" ");
					newdimImage[i][j] = '0';
					break;
				case '2':
					printf(".");
					newdimImage[i][j] = '1';
					break;
				case '3':
					printf("o");
					newdimImage[i][j] = '2';
					break;
				case '4':
					printf("O");
					newdimImage[i][j] = '3';
					break;
				default:
					break;
			}
    		}
    		printf("\n");
 		}
 		char choicesec;
 		printf("Would you like to save the file? (Y or N): ");
 		scanf(" %c", &choicesec);
 		if(choicesec == 'Y' || choicesec == 'y')
 		{
 		
 			FILE *fptr;
 			char newfilename[50];
 			printf("Input file name(no spaces, include extension): ");
 			scanf("%s", &newfilename);
 			fptr = fopen(newfilename, "w");
 			 if (fptr == NULL)
 			{
       				 printf("Unable to open file.\n");
    			}
    			else
    			{
    				for (int i = 0; i < rows; i++)
    				{
					for (int j = 0; j < columns; j++) 
					{
        					fprintf(fptr,"%c", newdimImage[i][j]);
    					}
    					fprintf(fptr,"\n");
    				}
    				fclose(fptr);
    			}
 		
 		}
 
 
 }
 
 
 void BrightenImage(int cols, char originalImage[][cols], int rowptrb, int colptrb,char newbrightimage[][cols]){
 	for (int i = 0; i < rowptrb; i++) {
		for (int j = 0; j < colptrb; j++) {
			switch (originalImage[i][j])
			{
				case '0':
					printf(".");
					newbrightimage[i][j] = '1';
					break;
				case '1':
					printf("o");
					newbrightimage[i][j] = '2';
					break;
				case '2':
					printf("O");
					newbrightimage[i][j] = '3';
					break;
				case '3':
					printf("0");
					newbrightimage[i][j] = '4';
					break;
				case '4':
					printf("0");
					newbrightimage[i][j] = '4';
					break;
				default:
					break;
			}
    		}
    		printf("\n");
 		}
 		printf("Would you like to save the file? (Y or N): ");
 		char choicesec;
 		scanf(" %c", &choicesec);
 		if(choicesec == 'Y' || choicesec == 'y')
 		{
 			FILE *fptr;
 			char newfilename[50];
 			printf("Input file name(no spaces, include extension): ");
 			scanf("%s", &newfilename);
 			fptr = fopen(newfilename, "w");
 			 if (fptr == NULL)
 			{
       				 printf("Unable to open file.\n");
    			}
    			else
    			{
    				for (int i = 0; i < rowptrb; i++)
    				{
					for (int j = 0; j < colptrb; j++) 
					{
        					fprintf(fptr,"%c", newbrightimage[i][j]);
    					}
    					fprintf(fptr,"\n");
    				}
    				fclose(fptr);
    			}
 		}
 
 }
