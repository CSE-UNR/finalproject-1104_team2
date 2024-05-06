#include<stdio.h>

#define MAX_ROWS 500
#define MAX_COLUMNS 500
#define FILENAMEMAX 50

int FirstMenu();
void LoadImage(int cols, char image[][cols], char loadfilename[FILENAMEMAX], int* rowptr, int* colsptr);
void DisplayImage(int cols,int rows, char displayfilename[FILENAMEMAX], char Imageusing[][cols]);
int SecondMenu();
int main()
{
	char originalImage[MAX_ROWS][MAX_COLUMNS];
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
			//DisplayImage(colnum, rownum, filename, originalImage);
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
	
	
	printf("\n%s", filename);
	
	//DisplayImage(colnum, rownum, filename, originalImage);
	
	
	
	
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
void LoadImage(int cols, char image[][cols], char loadfilename[FILENAMEMAX], int* rowptr, int* colptr)
{
	

	char originalImage[MAX_ROWS][MAX_COLUMNS];

	FILE *filePtr = fopen(loadfilename, "r");
	if (filePtr == NULL)
	{
		printf("file error\n");
	}
	
	int rowIndex = 0, columnIndex = 0;
	
	while(fscanf(filePtr, "%c", &originalImage[rowIndex][columnIndex]) == 1)
	{
		columnIndex = 0;
		while(fscanf(filePtr, "%c", &originalImage[rowIndex][columnIndex]) == 1)
		{
			columnIndex++;
		}
		rowIndex++;
	}
	
	fclose(filePtr);
		
		
	for (int i = 0; i < rowIndex; i++)
	{
		for (int j = 0; j < columnIndex; j++)
		{
			printf("%c", originalImage[i][j]);
		}
		printf("\n");
	}
	
	*rowptr = rowIndex; 
	*colptr = columnIndex;
	printf("%d", columnIndex);
	printf("\n%d", rowIndex);
	printf("\n\nImage successfully loaded.\n");
	
	

	
}
// DisplayImage() definition
void DisplayImage(int cols,int rows,char displayfilename[FILENAMEMAX],char Imageusing[][cols] )
{
	
	printf("\n");
	
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < cols; columnIndex++)
		{
			printf("%d", Imageusing[rowIndex][columnIndex]);
		}
		printf("\n");
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
  
  
 void DimImage(){
 
 
 
 
 }
