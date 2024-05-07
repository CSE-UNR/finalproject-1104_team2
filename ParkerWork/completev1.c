#include<stdio.h>

#define MAX_ROWS 500
#define MAX_COLUMNS 500
#define FILENAMEMAX 50

int FirstMenu();
void LoadImage(int cols, char image[][cols], char loadfilename[FILENAMEMAX], int* rowptr, int* colsptr);
void DisplayImage(int cols, char image[][cols], char displayfilename[FILENAMEMAX], int rowptr, int colsptr);

int SecondMenu();
void DimImage(int cols, char originalImage[][cols], int rows, int columns, char newdimImage[][cols])
void BrightenImage(int cols, char originalImage[][cols], int rowptrb, int colptrb, char newbrightimage[][cols]);
int main()
{
	char originalImage[MAX_ROWS][MAX_COLUMNS];
	char brightenedImage[MAX_ROWS][MAX_COLUMNS];
	int firstMenuChoice;
	int rownum;
	int colnum;
	char filename[FILENAMEMAX];
	
	firstMenuChoice = FirstMenu();
	switch (firstMenuChoice)
	{
		case 1:
			printf("Input your file name (no spaces)");
			scanf(" %s", &filename);
			LoadImage(MAX_COLUMNS, originalImage, filename, &rownum, &colnum);
			break;
		case 2:
			printf("\n(supposed to display image)\n");
			
			break;
		case 3:
			printf("\n(supposed to edit image)\n");
			break;
		case 4:
			printf("\n(supposed to exit program)\n");
			break;
		default:
			printf("\n(improper choice)\n");
			break;
	}
	
	
	printf("\n%s\n", filename);
	
	DisplayImage(MAX_COLUMNS, originalImage, filename, rownum, colnum);
	BrightenImage(MAX_COLUMNS, originalImage, rownum, colnum, brightenedImage);
	DimImage(int cols, char originalImage[][cols], int rows, int columns, char newdimImage[][cols])
	
	
}

// FirstMenu() definition
int FirstMenu()
{
	int choice;
	
	printf("\nWelcome to the image processing program. Please select an option below.");
	printf("\n[1] Load new image");
	printf("\n[2] Display current image");
	printf("\n[3] Edit current image");
	printf("\n[4] Exit the program");
	printf("\n\nEnter the number of your choice here: ");
	scanf("%d", &choice);
	
	return choice;
		
}

// LoadImage() definition
void LoadImage(int cols, char originalImage[][cols], char loadfilename[FILENAMEMAX], int* rowptr, int* colptr)
{
	FILE *filePtr = fopen(loadfilename, "r");
	if (filePtr == NULL)
	{
		printf("file error\n");
	}
	
	int rowIndex = 0, columnIndex = 0;
	//this counts column index:
	while(fscanf(filePtr, "%c", &originalImage[rowIndex][columnIndex]) == 1 && originalImage[rowIndex][columnIndex] != '\n')
	{
	columnIndex++;
	}
	//this counts row index:
	int columnrowIndex =0;
	  while (fscanf(filePtr, "%c", &originalImage[rowIndex][columnrowIndex]) == 1) {
        if (originalImage[rowIndex][columnrowIndex] == '\n') {
            rowIndex++;
            columnrowIndex = 0; // Reset columnIndex for each new row
        } else {
            columnrowIndex++;
	}
	}
	
	
	fclose(filePtr);
	

	rowIndex++;//must increment by one bc last line doesnt have endline
	//columnIndex--; (may use idk yet)
	*rowptr = rowIndex; 
	*colptr = columnIndex;
	printf("%d", columnIndex);
	printf("\n%d", rowIndex);
	printf("\n\nImage successfully loaded.\n");
	
	
	

	
}
// DisplayImage() definition
void DisplayImage(int cols, char originalImage[][cols], char displayfilename[FILENAMEMAX], int rowptr, int colptr)
{
	printf("\nstarting display test...\n");
	printf("%d", colptr);
	printf("\n%d", rowptr);
	printf("\n\n");
	
	
	

	// Printing array to screen:
	for (int i = 0; i < rowptr; i++) {
		for (int j = 0; j < colptr; j++) {
        	printf("%c", originalImage[i][j]);
    		}
    		printf("\n"); // Move to the next line after printing a row
	}
	// Printing array to screen:
	for (int i = 0; i < rowptr; i++) {
		for (int j = 0; j < colptr; j++) {
		switch (originalImage[i][j])
		{
			case '0':
				printf(" ");
				//originalImage[i][j] = 
				break;
			case '1':
				printf(".");
				//originalImage[i][j] = 
				break;
			case '2':
				printf("o");
				//originalImage[i][j] = 
				break;
			case '3':
				printf("O");
				//originalImage[i][j] = 
				break;
			case '4':
				printf("0");
				//originalImage[i][j] = 
				break;
			default:
				break;
		}
    		}
    		printf("\n"); // Move to the next line after printing a row
	}
	

	
}
//second menu def

int SecondMenu(){
  int choice;
  do{
    printf("**EDITING**\n1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\n");
    printf("Choose from one of the options above:");
    scanf("%d", &choice);
    if(choice<1 || choice>4){
      printf("\nInvalid choice try again.\n ");
  }
  }while( choice > 4 || choice < 1);
  return choice;
  }
  
  
void DimImage(int cols, char originalImage[][cols], int rows, int columns, char newdimImage[][cols]){
for (int i = 0; i < rowptrb; i++) {
		for (int j = 0; j < colptrb; j++) {
		switch (originalImage[i][j])
		{
			case '0':
				printf(".");
				newdimImage[i][j] = '0';
				break;
			case '1':
				printf("o");
				newdimImage[i][j] = '0';
				break;
			case '2':
				printf("O");
				newdimImage[i][j] = '1';
				break;
			case '3':
				printf("0");
				newdimImage[i][j] = '2';
				break;
			case '4':
				printf("0");
				newdimImage[i][j] = '3';
				break;
			default:
				break;
		}
    		}
    		printf("\n");
 		}
 		char choice;
 		scanf(" %c", choice);
 		if(choice == 'Y' || choice == 'y')
 		{
 		
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
 		printf("Would you like to save the file? (Y or N)");
 		char choice;
 		scanf(" %c", choice);
 		if(choice == 'Y' || choice == 'y')
 		{
 		
 		}
 
 }
